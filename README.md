# Locally Hosted AI Agent powered Robotic Arm with Voice control
## -- Agent Client --
#### Agent Server code: https://github.com/Alexledev/armkidd_agents

![License](https://img.shields.io/badge/license-MIT-blue.svg)


![ROS 2 Jazzy](https://img.shields.io/badge/ROS2-Jazzy-22314E?logo=ros&logoColor=white)
![MoveIt 2](https://img.shields.io/badge/MoveIt-2-5C3EE8?logo=ros&logoColor=white)
![Docker](https://img.shields.io/badge/Docker-Containerized-2496ED?logo=docker&logoColor=white)

![OpenCV](https://img.shields.io/badge/OpenCV-Computer%20Vision-5C3EE8?logo=opencv&logoColor=white)
![ONNX](https://img.shields.io/badge/ONNX-005CED?logo=onnx&logoColor=white)
![Whisper STT](https://img.shields.io/badge/OpenAI-Whisper%20STT-412991?logo=openai&logoColor=white)

![Nginx](https://img.shields.io/badge/Nginx-Web%20Server-009639?logo=nginx&logoColor=white)
![WebSockets](https://img.shields.io/badge/WebSockets-Real--time-010101?logo=socket.io&logoColor=white)
![Web API](https://img.shields.io/badge/Web%20API-REST-FF6F00?logo=fastapi&logoColor=white)
![gRPC](https://img.shields.io/badge/gRPC-Enabled-333333?logo=gRPC&logoColor=white)

![Arduino Uno](https://img.shields.io/badge/Arduino-Uno-00979D?logo=arduino&logoColor=white)
![Jetson Orin Nano](https://img.shields.io/badge/NVIDIA-Jetson%20Orin%20Nano-green?logo=nvidia&logoColor=white)
![HP-60C Depth Camera](https://img.shields.io/badge/Depth%20Camera-HP--60C-blue)



A robotic arm controlled via voice commands using a locally ran multimodel AI agent using depth camera and Moveit2 to pick up recognizable objects at the user's request and description.

Made on Nvidia Jetson Orin Nano. Uses an Arduino as motor controller for arm.

The arm features:

- Moveit2 integration and kinematics to control the arm's 6 DOF movement.
- Depth Camera integration and perception of objects.
- Locally ran AI agents via Docker:
   - Voice commands and feedback with Whisper and Piper.
   - Computer Vision and Multimodal reasoning with YOLO and Phi Vision.
   
- gRPC communication between agent and host/app containers.


## Link for the Depth Cam, Arduino code, and AI:
https://github.com/Alexledev/ComputerViz

~~https://github.com/Alexledev/RoboticArm_Ros2Control~~
https://github.com/Alexledev/RoboticArm_Arduino

https://github.com/Alexledev/armkidd_agents

### Youtube Demonstration:


## Installation
1. Install all the following Ros2 packages and their associated packages:
- Ros2 Jazzy (in general)
- Moveit2
- Rviz2
- URDF/Xacro
- Gazebo
2. Pull down the github code


## Explanations/Usage
1. Build and Source the workspace.
2. Attach Arduino and Depth Cam. 
3. Start the agent client containers with `docker compose up`.
4. Run `ros2 launch armkidd_bringup armkidd_real.launch.py`.
5. Make sure to run the ComputerViz package's end as well (`ros2 launch nuwacam hp60c.launch.py`).

6. Once everything is running, Open up the webpage at `localhost/stream`.
7. If using speech mode, say "Hey arm kid" to the microphone then specify your command. If using chat/text mode, put "Hey arm kid" on the first box and your command on the second.
8. It should pick the first visible object that matches your criteria.

## Execution diagram

![Diagram](Armkidd.drawio.svg)

Notes:
- Not included: Configuration flow
- The TTS is on supposed to be on the arm like in the diagram but here it's on the server due to performance.


## License
MIT License
