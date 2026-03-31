from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from moveit_configs_utils import MoveItConfigsBuilder
import os
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node

def generate_launch_description():

    
    is_sim = LaunchConfiguration("is_sim")
    
    is_sim_arg = DeclareLaunchArgument(
        "is_sim",
        default_value="True"
    )
    
    moveit_config = (
        MoveItConfigsBuilder("armkidd", package_name="armkidd_moveit")
        .robot_description(file_path=os.path.join(get_package_share_directory("armkidd_description"), "urdf", "armkidd.urdf.xacro"))
        .robot_description_semantic(file_path=os.path.join(get_package_share_directory("armkidd_moveit"), "config", "armkidd.srdf"))
        .robot_description_kinematics(file_path=os.path.join(get_package_share_directory("armkidd_moveit"), "config", "kinematics.yaml"))
        .trajectory_execution(file_path=os.path.join(get_package_share_directory("armkidd_moveit"), "config", "moveit_controllers.yaml"))
        .joint_limits(file_path=os.path.join(get_package_share_directory("armkidd_moveit"), "config", "joint_limits.yaml"))
        .pilz_cartesian_limits(file_path=os.path.join(get_package_share_directory("armkidd_moveit"), "config", "pilz_cartesian_limits.yaml"))        
        .planning_pipelines(pipelines=["ompl", "pilz_industrial_motion_planner", "stomp"], default_planning_pipeline="ompl")
        .planning_scene_monitor(publish_robot_description=False, publish_robot_description_semantic=True, publish_planning_scene=True,)
        .to_moveit_configs()
    )

    move_group_node = Node(
        package="moveit_ros_move_group",
        executable="move_group",
        output="screen",        
        parameters=[moveit_config.to_dict(), 
                    moveit_config.robot_description_kinematics, 
                    {"use_sim_time": is_sim}, 
                    {"publish_robot_description_semantic": True},
                    {"capabilities": "move_group/ExecuteTaskSolutionCapability"},], 
        arguments=["--ros-args", "--log-level", "info"]
    )

    rviz_config = os.path.join(get_package_share_directory("armkidd_moveit"), "config", "moveit.rviz")
    # rviz_config = os.path.join(get_package_share_directory("armkidd_mtc_demos"), "rviz", "mtc_demos.rviz")

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="log",
        arguments=["-d", rviz_config],
        parameters=[moveit_config.robot_description,
                    moveit_config.robot_description_semantic,
                    moveit_config.planning_pipelines,
                    moveit_config.robot_description_kinematics,
                    moveit_config.joint_limits,
                    {'use_sim_time': is_sim}]
    )

    return LaunchDescription([
        is_sim_arg,
        move_group_node,
        rviz_node
    ])

