#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/utilities.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class MoveAndAvoidCollisionNode : public rclcpp::Node {
public:
  MoveAndAvoidCollisionNode()
      : rclcpp::Node("topics_quiz_node"), _curr_turn_decision(0) {

    _driver_pub =
        this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    _laser_sub = this->create_subscription<sensor_msgs::msg::LaserScan>(
        "scan", 10,
        std::bind(&MoveAndAvoidCollisionNode::laser_callback, this, _1));

    timer_ = this->create_wall_timer(
        500ms, std::bind(&MoveAndAvoidCollisionNode::timer_callback, this));
  }

private:
  void laser_callback(sensor_msgs::msg::LaserScan::SharedPtr msg) {

    auto range_max = msg->range_max;
    auto range_min = msg->range_min;

    std::vector<float> range =
        std::vector<float>(std::begin(msg->ranges), std::end(msg->ranges));

    // make sure we get all values in correct range (not sure it is required for
    // task)
    auto remove_result = std::remove_if(
        range.begin(), range.end(), [range_max, range_min](float value) {
          return value > range_max || value < range_min;
        });
    range.erase(remove_result, range.end());

    _curr_laser_range = range;

    int range_len = std::size(range);
    int scan_zone_range =
        std::max((int)((float)range_len * 0.2f), 1); // 20% from range
    int middle_range = range_len / 2;                // divide by 2
    int middle_range_low = std::max(middle_range - scan_zone_range, 0);
    int middle_range_high =
        std::min(middle_range + scan_zone_range, range_len - 1);

    float min_dist_to_rotate = 1.0; // meters

    float frond_dist_to_obstackle =
        get_min_dist_to_obstacle(middle_range_low, middle_range_high);
    // RCLCPP_INFO(this->get_logger(), "frond_dist_to_obstacle: %.2f",
    // frond_dist_to_obstackle);

    bool is_obstackle_in_front = frond_dist_to_obstackle < min_dist_to_rotate;

    bool is_obstackle_left =
        get_min_dist_to_obstacle(0, scan_zone_range) < min_dist_to_rotate;

    bool is_obstackle_right =
        get_min_dist_to_obstacle(range_len - scan_zone_range - 1,
                                 range_len - 1) < min_dist_to_rotate;

    int turn_mode = 0; // 0 - forward, -1 - left, +1 - right
    if (is_obstackle_in_front) {
      turn_mode = -1;
    }

    if (is_obstackle_right) {
      turn_mode = -1;
    }

    if (is_obstackle_left) {
      turn_mode = 1;
    }

    if (_curr_turn_decision != turn_mode)
      RCLCPP_INFO(this->get_logger(), "Robot avoid collision: %d", turn_mode);
    _curr_turn_decision = turn_mode;
  }

  float get_min_dist_to_obstacle(int start_range_id, int end_range_id) {
    auto minValue =
        std::min_element(std::begin(_curr_laser_range) + start_range_id,
                         std::begin(_curr_laser_range) + end_range_id);

    if (minValue != std::end(_curr_laser_range)) {
      return *minValue;
    } else {
      // Range invalid
      return std::numeric_limits<float>::max();
    }
  }

  void timer_callback() {
    auto message = geometry_msgs::msg::Twist();
    message.linear.x = 0.3;
    message.angular.z = -0.5 * _curr_turn_decision;
    _driver_pub->publish(message);

    // RCLCPP_INFO(this->get_logger(), "Move robot %d", _curr_turn_decision);
  }

  void stop_robot() {
    auto message = geometry_msgs::msg::Twist();
    message.linear.x = 0;
    message.angular.z = 0;
    _driver_pub->publish(message);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr _driver_pub;
  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr _laser_sub;

  std::vector<float> _curr_laser_range;
  int _curr_turn_decision;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);

  auto node = std::make_shared<MoveAndAvoidCollisionNode>();
  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}