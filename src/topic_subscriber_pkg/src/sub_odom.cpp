/**
"header:
  stamp:
    sec: 0
    nanosec: 0
  frame_id: ''
child_frame_id: ''
pose:
  pose:
    position:
      x: 0.0
      y: 0.0
      z: 0.0
    orientation:
      x: 0.0
      y: 0.0
      z: 0.0
      w: 1.0
  covariance:
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
twist:
  twist:
    linear:
      x: 0.0
      y: 0.0
      z: 0.0
    angular:
      x: 0.0
      y: 0.0
      z: 0.0
  covariance:
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
  - 0.0
"
*/

#include "nav_msgs/msg/detail/odometry__struct.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/node.hpp"
#include "rclcpp/rclcpp.hpp"
#include <functional>

using std::placeholders::_1;

class OdomentrySubscriberNode : public rclcpp::Node {
public:
  OdomentrySubscriberNode() : rclcpp::Node("odometry_listener") {
    _subscriber = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odom", 10,
        std::bind(&OdomentrySubscriberNode::_callback_odometryData, this, _1));
  }

private:
  void _callback_odometryData(nav_msgs::msg::Odometry::SharedPtr msg) {
    RCLCPP_INFO(
        this->get_logger(), "ODOMETRY. Position: '%f' Orientation: '%f'",
        msg.get()->pose.pose.position.x, msg.get()->pose.pose.orientation.y);
  }

  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr _subscriber;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);

  OdomentrySubscriberNode::SharedPtr node =
      std::make_shared<OdomentrySubscriberNode>();

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}