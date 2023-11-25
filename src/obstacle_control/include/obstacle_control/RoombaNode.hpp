#pragma once
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "geometry_msgs/msg/twist.hpp"

class Roomba : public rclcpp::Node {
 public:

  Roomba();

 private:

  void detect_obstacle(const sensor_msgs::msg::Image& image);

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;

  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber;
};