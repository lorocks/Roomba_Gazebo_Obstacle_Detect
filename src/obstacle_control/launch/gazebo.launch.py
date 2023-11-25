from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration

"""@brief Generate the launch descriptions for ROS
"""
def generate_launch_description():
    desc = LaunchDescription()

    walker = Node(
        package="obstacle_control",
        executable="walker",
    )

    desc.add_action(walker)

    return desc