from launch_ros.actions import Node
from launch.actions import ExecuteProcess, RegisterEventHandler
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, FindExecutable
from launch.conditions import IfCondition
from ament_index_python.packages import get_package_share_directory
import os

"""@brief Generate the launch descriptions for ROS
"""
def generate_launch_description():
    desc = LaunchDescription()

    x_pose = LaunchConfiguration('x_pose', default='-6.0')
    y_pose = LaunchConfiguration('y_pose', default='-0.5')
    ros_bag = DeclareLaunchArgument(name="ros_bag", default_value='False', choices=['True', 'False'])

    launch_file_dir = os.path.join(get_package_share_directory('turtlebot3_gazebo'), 'launch')

    delete_bag = ExecuteProcess(
        condition=IfCondition(LaunchConfiguration('ros_bag')),
        cmd=["rm -rf ./results/ros2_bag"],
        shell = True
    )

    ros2_bag = ExecuteProcess(
        condition=IfCondition(LaunchConfiguration('ros_bag')),
        cmd=[[
            FindExecutable(name='ros2'),
            ' bag record -o ./results/ros2bag -a -x /camera/*'
        ]],
        shell = True
    )

    spawn_turtlebot = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(launch_file_dir, 'turtlebot3_house.launch.py')
        ),
        launch_arguments={
            'x_pose': x_pose,
            'y_pose': y_pose
        }.items()
    )

    walker = Node(
        package="obstacle_control",
        executable="walker",
    )

    desc.add_action(ros_bag)
    desc.add_action(delete_bag)
    desc.add_action(spawn_turtlebot)
    desc.add_action(walker)
    desc.add_action(ros2_bag)

    return desc