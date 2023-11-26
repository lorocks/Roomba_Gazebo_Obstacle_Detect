
/**
 * @file obstacle_controller.cpp
 * @author Lowell Lobo
 * @brief Call and spin the Roomba node
 * @version 0.1
 * @date 2023-11-25
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "RoombaNode.hpp"

/**
 * @brief Main implementation
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Roomba>());
  rclcpp::shutdown();
  return 0;
}
