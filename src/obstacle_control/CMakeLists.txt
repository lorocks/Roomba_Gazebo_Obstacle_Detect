cmake_minimum_required(VERSION 3.8)
project(obstacle_control)

# clangd support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
execute_process(COMMAND "rm" "-f" "${CMAKE_SOURCE_DIR}/compile_commands.json")
execute_process(COMMAND "ln" "-s" "-r" "${CMAKE_BINARY_DIR}/compile_commands.json" "${CMAKE_SOURCE_DIR}/")

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)


include_directories(include/obstacle_control)


add_executable(walker src/obstacle_controller.cpp src/RoombaNode.cpp)
ament_target_dependencies(walker rclcpp sensor_msgs geometry_msgs)


install(TARGETS
  walker
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
launch
DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  find_package(ament_lint_auto REQUIRED)

  # un-comment the following lines skip linters (TRUE = skip that test)
  set(ament_cmake_cppcheck_FOUND TRUE)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  set(ament_cmake_flake8_FOUND TRUE)
  set(ament_cmake_uncrustify_FOUND TRUE)
  

  # Run all lint tests in package.xml except those listed above
  # ament_lint_auto_find_test_dependencies()

  # Add a gtest executable
  # set(TESTFILES
  #   test/integrated_test.cpp)
  # ament_add_gtest(${PROJECT_NAME}_test ${TESTFILES})
  # ament_target_dependencies(${PROJECT_NAME}_test rclcpp rclcpp_action geometry_msgs)
endif()

ament_export_dependencies(rosidl_default_runtime)

ament_package()
