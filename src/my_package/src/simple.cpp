#include "rclcpp/logging.hpp"
#include "rclcpp/node.hpp"
#include "rclcpp/rclcpp.hpp"
// RCL - Robot Communication Library

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/utilities.hpp"

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);

  auto node = rclcpp::Node::make_shared("ObiWan");

  rclcpp::WallRate loop_rate(2);

  // Endless loop until Ctrl + C
  while (rclcpp::ok()) {

    RCLCPP_INFO(node->get_logger(),
                "Help me Obi-Wan Kenobi, you're my only hope");
    rclcpp::spin_some(node);
    // We sleep the needed time to maintain the Rate fixed above
    loop_rate.sleep();
  }

  rclcpp::shutdown();
  return 0;
}