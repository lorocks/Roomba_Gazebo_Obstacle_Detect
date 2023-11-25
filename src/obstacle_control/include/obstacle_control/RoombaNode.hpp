/**
 * @file RoombaNode.hpp
 * @author Lowell Lobo
 * @brief Description file for Roomba node as a library
 * @version 0.1
 * @date 2023-11-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "geometry_msgs/msg/twist.hpp"

/**
 * @brief Roomba class that inherits from rclcpp Node to create a custom node
 * 
 */
class Roomba : public rclcpp::Node {
 public:

/**
 * @brief Construct a new Roomba object
 * The constructor initializes the Node, publisher and subscriber for the implementation
 */
  Roomba();

 private:

/**
 * @brief Algorithm to detect and dodge obstacles
 * The algorithm uses depth camera to find obstacles.
 * If there is no obstacle the bot will move 
 * If there is a obstacle the bot stops moving and turns to avoid obstacle
 * 
 * @param image subscriber callback message
 */
  void detect_obstacle(const sensor_msgs::msg::Image& image);

/**
 * @brief publisher variable used to publish roomba movement to /cmd_vel
 * 
 */
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;

/**
 * @brief subscriber variable used to get depth information from roomba depth camera
 * 
 */
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber;
};