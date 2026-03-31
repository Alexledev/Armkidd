from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.launch_description_sources import PythonLaunchDescriptionSource

import os

def generate_launch_description():

    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("armkidd_description"),
                "launch",
                "gazebo.launch.py"
            )
        ),
        launch_arguments={"is_sim" : "True"}.items()
    )

    controller = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("armkidd_controller"),
                "launch",
                "controller.launch.py"
            )
        ),
        launch_arguments={"is_sim" : "True"}.items()
    )

    moveit = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("armkidd_moveit"),
                "launch",
                "moveit.launch.py"
            )
        ),
        launch_arguments={"is_sim" : "True"}.items()
    )

    nuwacam_scaler = Node(
        package="armkidd_command",
        executable="nuwacam_scaler",
        name='nuwacam_scaler',       # node name (optional)
        output="screen",
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

    return LaunchDescription([
        gazebo,
        static_tf,
        controller,
        moveit,
        nuwacam_scaler,
        # arm_command_junction
    ])
    