/**
TO DO: Create a Service named /rotate.
This Service receives a custom Service interface to make the robot spin:

To a specified direction (left or right)
With a specified angular velocity (in radians/second)
For a specified duration (time) (in seconds).

Spin :
string direction               # Direction to spin (right or left)
float64 angular_velocity       # Angular Velocity (in rad/s)
int32 time                     # Duration of the spin (in seconds)
---
bool success                   # Did it achieve it?

*/

#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "services_quiz_srv/srv/spin.hpp"

#include <cstdint>
#include <memory>

using SpinMessage = services_quiz_srv::srv::Spin;
using TwistMessage = geometry_msgs::msg::Twist;
using std::placeholders::_1;
using std::placeholders::_2;

enum ENODE_STATE {
  ENODE_STATE_NONE = 0,
  ENODE_STATE_WAIT_FOR_ORDERS = 1,
  ENODE_STATE_ROTATE = 2
};

using namespace std::literals::chrono_literals;

class ServerNode : public rclcpp::Node {
public:
  ServerNode() : Node("server_node") {

    state_ = ENODE_STATE_WAIT_FOR_ORDERS;
    timer_ = this->create_wall_timer(
        100ms, std::bind(&ServerNode::_callback_timer, this));

    srv_ = create_service<SpinMessage>(
        "rotate", std::bind(&ServerNode::_callback_server, this, _1, _2));
    publisher_ = this->create_publisher<TwistMessage>("cmd_vel", 10);
  }

private:
  rclcpp::Service<SpinMessage>::SharedPtr srv_;
  rclcpp::Publisher<TwistMessage>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;

  float timer_counter_;

  ENODE_STATE state_;

  void start_rotation(std::int32_t time) {
    /*if (state_ == ENODE_STATE_ROTATE) {
      RCLCPP_INFO(this->get_logger(), "Robot is rotating. Stop rotation!",
                  timer_counter_);
      stop_rotation();
    }*/

    state_ = ENODE_STATE_ROTATE;
    this->timer_counter_ = (float)(time);
    RCLCPP_INFO(this->get_logger(), "start_rotation: %d sec!", time);
  }

  void stop_rotation() {
    state_ = ENODE_STATE_WAIT_FOR_ORDERS;
    this->timer_counter_ = 0;
    RCLCPP_INFO(this->get_logger(),
                "stop_rotation. Server ready to accept new commands");

    auto message = geometry_msgs::msg::Twist();
    message.angular.z = 0;
    publisher_->publish(message);
  }

  void _callback_timer() {
    if (state_ == ENODE_STATE_ROTATE) {
      this->timer_counter_ -= 0.1f;
      RCLCPP_INFO(this->get_logger(), "rotating: %f ms left!",
                  this->timer_counter_);
      if (this->timer_counter_ <= 0) {
        stop_rotation();
        return;
      }
    }
  }

  void _callback_server(const std::shared_ptr<SpinMessage::Request> request,
                        const std::shared_ptr<SpinMessage::Response> response) {

    if (state_ == ENODE_STATE_ROTATE) {
      response->success = false;
      return;
    }

    auto message = geometry_msgs::msg::Twist();
    if (request->direction == "left") {
      message.angular.z = request->angular_velocity;
      publisher_->publish(message);
      start_rotation(request->time);
      response->success = true;

    } else if (request->direction == "right") {
      message.angular.z = -request->angular_velocity;
      publisher_->publish(message);
      start_rotation(request->time);
      response->success = true;

    } else {
      response->success = false;
    }
  }
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ServerNode>());
  rclcpp::shutdown();
  return 0;
}