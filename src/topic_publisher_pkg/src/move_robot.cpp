#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/node.hpp"
#include "rclcpp/rclcpp.hpp"
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/utilities.hpp"

using namespace std::chrono_literals;

class SimpleMovementNode : public rclcpp::Node {
public:
  SimpleMovementNode() : rclcpp::Node("move_robot") {
    publisher_ =
        this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    timer_ = this->create_wall_timer(
        5s, std::bind(&SimpleMovementNode::timer_callback, this));
  }

private:
  void timer_callback() {
    auto message = geometry_msgs::msg::Twist();
    message.linear.x = 0.2;
    message.angular.z = 0.2;
    publisher_->publish(message);

    RCLCPP_INFO(this->get_logger(), "Move robot!");
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SimpleMovementNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}