#include "custom_interfaces/msg/age.hpp"
#include "rclcpp/node.hpp"
#include "rclcpp/publisher.hpp"
#include "rclcpp/rclcpp.hpp"
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/timer.hpp"
#include <chrono>

using namespace std::chrono_literals;

class AgePublishingNode : public rclcpp::Node {
public:
  AgePublishingNode() : rclcpp::Node("publish_age_node") {
    _publisher =
        this->create_publisher<custom_interfaces::msg::Age>("robot_age", 10);

    _timer = this->create_wall_timer(
        1s, std::bind(&AgePublishingNode::_callback_publishing, this));
  }

private:
  void _callback_publishing() {
    auto msg = custom_interfaces::msg::Age();
    msg.years = 4;
    msg.months = 11;
    msg.days = 21;

    _publisher->publish(msg);
  }

  rclcpp::Publisher<custom_interfaces::msg::Age>::SharedPtr _publisher;
  rclcpp::TimerBase::SharedPtr _timer;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AgePublishingNode>());
  rclcpp::shutdown();
  return 0;
}