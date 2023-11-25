
/**
 * @file RoombaNode.cpp
 * @author Lowell Lobo
 * @brief Function implementation for Roomba node library
 * @version 0.1
 * @date 2023-11-25
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "RoombaNode.hpp"

/**
 * @brief Construct a new Roomba:: Roomba object
 *
 */
Roomba::Roomba() : Node("Roomba_walker") {
  publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

  subscriber = this->create_subscription<sensor_msgs::msg::Image>(
      "camera/depth/image_raw", 10,
      std::bind(&Roomba::detect_obstacle, this, std::placeholders::_1));
}

/**
 * @brief add implementation to Roomba detect_obstacle function
 *
 * @param image
 */
void Roomba::detect_obstacle(const sensor_msgs::msg::Image& image) {
  auto velocity = geometry_msgs::msg::Twist();
  velocity.linear.x = 0.25;
  velocity.angular.z = 0.0;
  auto imagedata = (float*)image.data.data();
  for (unsigned int i = 0; i < image.height / 2; i++) {
    for (unsigned int j = (unsigned int)(image.width / 4);
         j < (unsigned int)(image.width * 3 / 4); j++) {
      if (imagedata[(i * image.height) + j] < 0.5) {
        velocity.linear.x = 0.0;
        velocity.angular.z = -0.5;
      }
    }
  }

  RCLCPP_INFO(this->get_logger(), "Linear Speed: '%f', Angular Speed: '%f'",
              (float)velocity.linear.x, (float)velocity.angular.z);
  publisher_->publish(velocity);
}