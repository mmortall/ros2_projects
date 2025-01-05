#include <cmath>
#include <functional>
#include <memory>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/subscription_base.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include "actions_quiz_msg/action/distance.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "std_msgs/msg/detail/int32__struct.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::placeholders;

class MyActionServer : public rclcpp::Node {
public:
  using DistanceAction = actions_quiz_msg::action::Distance;
  using GoalHandleDistanceAction =
      rclcpp_action::ServerGoalHandle<DistanceAction>;
  using Point = geometry_msgs::msg::Point;

  explicit MyActionServer(
      const rclcpp::NodeOptions &options = rclcpp::NodeOptions())
      : Node("actions_server_node", options) {

    publisher_ =
        this->create_publisher<std_msgs::msg::Int32>("total_distance", 10);

    _subscriber = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odom", 10,
        std::bind(&MyActionServer::_callback_odometryData, this, _1));

    this->action_server_ = rclcpp_action::create_server<DistanceAction>(
        this, "distance_as",
        std::bind(&MyActionServer::handle_goal, this, _1, _2),
        std::bind(&MyActionServer::handle_cancel, this, _1),
        std::bind(&MyActionServer::handle_accepted, this, _1));
  }

private:
  rclcpp_action::Server<DistanceAction>::SharedPtr action_server_;

  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr _timer;

  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr _subscriber;

  Point _curr_robot_position;    // inited by (0 0 0) by default
  Point _measure_start_position; // inited by (0 0 0) by default

  void _callback_odometryData(nav_msgs::msg::Odometry::SharedPtr msg) {
    _curr_robot_position = msg.get()->pose.pose.position;
  }

  rclcpp_action::GoalResponse
  handle_goal(const rclcpp_action::GoalUUID &uuid,
              std::shared_ptr<const DistanceAction::Goal> goal) {
    RCLCPP_INFO(this->get_logger(), "Received goal request with secs %d",
                goal->seconds);
    (void)uuid;
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse
  handle_cancel(const std::shared_ptr<GoalHandleDistanceAction> goal_handle) {
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void
  handle_accepted(const std::shared_ptr<GoalHandleDistanceAction> goal_handle) {
    using namespace std::placeholders;
    // this needs to return quickly to avoid blocking the executor, so spin up a
    // new thread
    std::thread{std::bind(&MyActionServer::execute, this, _1), goal_handle}
        .detach();
  }

  void publish_total_distance(float distance) {
    auto msg = std_msgs::msg::Int32();
    msg.data = (int32_t)distance;

    RCLCPP_INFO(this->get_logger(), "Publish to topic %d", msg.data);

    publisher_->publish(msg);
  }

  float get_curr_distance() {
    return std::sqrt((_measure_start_position.x - _curr_robot_position.x) *
                         (_measure_start_position.x - _curr_robot_position.x) +
                     (_measure_start_position.y - _curr_robot_position.y) *
                         (_measure_start_position.y - _curr_robot_position.y) +
                     (_measure_start_position.z - _curr_robot_position.z) *
                         (_measure_start_position.z - _curr_robot_position.z));
  }

  // Goal is to measure the distance robot pased for time parameter
  void execute(const std::shared_ptr<GoalHandleDistanceAction> goal_handle) {
    RCLCPP_INFO(this->get_logger(), "Executing goal");
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<DistanceAction::Feedback>();
    auto result = std::make_shared<DistanceAction::Result>();

    rclcpp::Rate loop_rate(1);

    // check that we receive data from /odom topic
    while (_curr_robot_position.x == _curr_robot_position.y &&
           _curr_robot_position.x == _curr_robot_position.z &&
           _curr_robot_position.x == 0) {
      loop_rate.sleep();
    }

    _measure_start_position = _curr_robot_position;
    float total_distance = 0;

    for (int i = 0; (i < goal->seconds) && rclcpp::ok(); ++i) {
      total_distance = get_curr_distance();

      // Check if there is a cancel request
      if (goal_handle->is_canceling()) {
        result->status = false;
        result->total_dist = total_distance;
        goal_handle->canceled(result);
        RCLCPP_INFO(this->get_logger(), "Goal canceled");
        return;
      }

      publish_total_distance(total_distance);
      feedback->current_dist = total_distance;

      goal_handle->publish_feedback(feedback);
      RCLCPP_INFO(this->get_logger(), "Publish feedback %f", total_distance);

      loop_rate.sleep();
    }

    // Check if goal is done
    if (rclcpp::ok()) {
      result->status = true;

      total_distance = get_curr_distance();
      result->total_dist = total_distance;
      goal_handle->succeed(result);
      RCLCPP_INFO(this->get_logger(), "Goal succeeded");
    }
  }
}; // class MyActionServer

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  auto action_server = std::make_shared<MyActionServer>();

  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(action_server);
  executor.spin();

  rclcpp::shutdown();
  return 0;
}