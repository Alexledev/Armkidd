from launch import LaunchDescription
from launch.actions import TimerAction
from launch.actions import IncludeLaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():

    controller = IncludeLaunchDescription(
        os.path.join(
            get_package_share_directory("armkidd_controller"),
            "launch",
            "controller.launch.py"
        ),
        launch_arguments={"is_sim" : "False"}.items()
    )

    moveit = IncludeLaunchDescription(
        os.path.join(
            get_package_share_directory("armkidd_moveit"),
            "launch",
            "moveit.launch.py"
        ),
        launch_arguments={"is_sim" : "False"}.items()
    )

    static_tf = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="hp60c_mount_tf",
        arguments=[
            "0", "0", "0",   # x y z (meters)   <- replace once measured
            "-1.57", "0", "0",   # roll pitch yaw (radians)
            "camera_head_adj",
            "ascamera_hp60c_camera_link_0"
        ]
    )

    pcl_obs = Node(
        package = "armkidd_command",
        executable = "pcl_obstacles",
        name = "pcl_obstacles",
        output = "screen"
    )

    bt_coord_mover = Node(
        package="armkidd_command",
        executable="bt_coord_mover",
        name='bt_coord_mover',       # node name (optional)
        output="screen",
    )

    nuwacam_scaler = Node(
        package="armkidd_command",
        executable="nuwacam_scaler",
        name='nuwacam_scaler',       # node name (optional)
        output="screen",
    )

    # camera = IncludeLaunchDescription(
    #     os.path.join(get_package_share_directory("nuwacam"), "launch", "hp60c.launch.py"),
    # )
    
    return LaunchDescription([
        static_tf,
        controller,
        moveit,
        pcl_obs,
        TimerAction(period=5.0, actions=[nuwacam_scaler]),
        TimerAction(period=8.0, actions=[bt_coord_mover]),
        # TimerAction(period=10.0, actions=[camera]),
    ])
    