import os
from pathlib import Path

from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, LaunchConfiguration
import os
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    armkidd_description_dir = get_package_share_directory("armkidd_description")

    model_arg = DeclareLaunchArgument(
        name="model",
        default_value=os.path.join(
            armkidd_description_dir, "urdf", "armkidd.urdf.xacro"),
        description="Absolute path to robot urdf file"
        )
    
    gazebo_resource_path = SetEnvironmentVariable(
        name="GZ_SIM_RESOURCE_PATH",
        value=[
            str(Path(armkidd_description_dir).parent.resolve())
        ]
    )

    robot_description = ParameterValue(Command(["xacro ", LaunchConfiguration("model")]), value_type=str)

    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"robot_description":robot_description,
                     "use_sim_time": True}]
    ) 
    
    world_path = os.path.join(armkidd_description_dir, "worlds", "default.sdf")

    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            os.path.join(
                get_package_share_directory("ros_gz_sim"),
                "launch",
            ), "/gz_sim.launch.py"
        ]),
        launch_arguments=[
            ("gz_args", [f"-v 4 -r {world_path}"]) # --physics-engine gz-physics-dartsim-plugin
        ],
    )

    gz_spawn_entity = Node(
        package="ros_gz_sim",
        executable="create",
        output="screen",
        arguments=["-topic", "robot_description",
                   "-name", "armkidd"]
    )

    gz_ros2_bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        arguments=[
            "/head_camera/depth_registered/image@sensor_msgs/msg/Image@gz.msgs.Image",
            "/head_camera/depth_registered/depth_image@sensor_msgs/msg/Image@gz.msgs.Image",
            "/head_camera/depth_registered/points@sensor_msgs/msg/PointCloud2@gz.msgs.PointCloudPacked",
            "/head_camera/depth_registered/camera_info@sensor_msgs/msg/CameraInfo@gz.msgs.CameraInfo",
            "/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock",
            

            # "camera_head/depth/camera_info@sensor_msgs/msg/CameraInfo@gz.msgs.CameraInfo",
            # "camera_head/depth/color/points@sensor_msgs/msg/PointCloud2@gz.msgs.PointCloudPacked"
        ],
        output="screen"
    )

    return LaunchDescription([
        model_arg,
        gazebo_resource_path,
        robot_state_publisher,
        gazebo,
        gz_spawn_entity,
        # static_tf,
        gz_ros2_bridge
    ])
