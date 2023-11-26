# Roomba_Gazebo_Obstacle_Detect
## Overview
Implementation of Obstacle Avoiding Roomba in Gazebo using Turtlebot3 Package

## Dependencies
 - Ubuntu 22.04
 - ROS2 Humble
 - ros-humble-turtlebot3*

## Assumption
 - The implementation assumes that depth camera has already been set-up for the turtlebot3
 - The implementation uses waffle model
 - The turtlebot3 project with depth camera has been sourced

## Clone Repository
```bash
  git clone git@github.com:lorocks/Roomba_Gazebo_Obstacle_Detect.git
```
## Build Project
```bash
# cd into project directory
  cd Roomba_Gazebo_Obstacle_Detect
# build project
  colcon build
# source underlay
  source install/setup.sh
```

## Run Commands
```bash
# Run the walker node
  ros2 run obstacle_control walker

# Run launch file
  ros2 launch obstacle_control gazebo.launch.py

# Run launch file with ros2 bag
  ros2 launch obstacle_control gazebo.launch.py ros_bag:=True

# Inspect ros2 bag
  ros2 bag info results/ros2bag/

# Play the ros2 bag file
  ros2 bag play results/ros2bag/
```