/**
Create another C++ script that contains the Service Client code.
This Client calls the Service /rotate, and makes the robot spin with the
following specifications:

It will spin to the right.
It will spin at an angular velocity of 0.2 rad/s.
It will spin for 10 seconds.

Spin:
string direction               # Direction to spin (right or left)
float64 angular_velocity       # Angular Velocity (in rad/s)
int32 time                     # Duration of the spin (in seconds)
---
bool success                   # Did it achieve it?
*/

#include "rclcpp/rclcpp.hpp"
#include "services_quiz_srv/srv/spin.hpp"
#include <chrono>
#include <cstdlib>
#include <future>
#include <memory>

using SpinMessage = services_quiz_srv::srv::Spin;
using std::placeholders::_1;
using std::placeholders::_2;

using namespace std::chrono_literals;

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("client_node");
  rclcpp::Client<SpinMessage>::SharedPtr client =
      node->create_client<SpinMessage>("rotate");

  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),
                   "Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
                "service not available, waiting again...");
  }

  auto request = std::make_shared<SpinMessage::Request>();
  request->direction = "right";
  request->angular_velocity = 0.2;
  request->time = 10;

  auto result_future = client->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(node, result_future) ==
      rclcpp::FutureReturnCode::SUCCESS) {
    auto result = result_future.get();
    if (result->success == true) {
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
                  "Service returned success: Start Moving");
    } else if (result->success == false) {
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service returned false");
    }
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),
                 "Failed to call service /moving");
  }

  // wait for service done
  while (true) {
    request->angular_velocity = 0.0;
    request->time = 0;

    result_future = client->async_send_request(request);
    result_future.wait_for(1s);
    if (rclcpp::spin_until_future_complete(node, result_future) ==
        rclcpp::FutureReturnCode::SUCCESS) {

      auto result = result_future.get();
      if (result->success == true) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
                    "Service done with movement!");
        break;
      } else {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service is busy...");
      }
    }
  }

  rclcpp::shutdown();
  return 0;
}