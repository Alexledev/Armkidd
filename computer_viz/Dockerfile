FROM ros:jazzy-ros-base

ENV ROS_DOMAIN_ID=10
ENV RMW_IMPLEMENTATION=rmw_cyclonedds_cpp

ENV ROS_AUTOMATIC_DISCOVERY_RANGE=SUBNET

ENV DEBIAN_FRONTEND=noninteractive
ENV TRANSFORMERS_NO_TF=1
ENV PYTHONUNBUFFERED=1

RUN apt update && apt install -y \
    python3 \
    python3-dev \
    python3-pip \
    python3-venv \
    python3-empy \
    ros-jazzy-std-msgs \
    ros-jazzy-sensor-msgs \
    ros-jazzy-geometry-msgs \
    ros-jazzy-vision-msgs \
    ros-jazzy-tf2 \
    ros-jazzy-tf2-ros \
    ros-jazzy-pcl-conversions \
    ros-jazzy-geometry-msgs \
    ros-jazzy-lifecycle-msgs \
    ros-jazzy-pcl-conversions \
    ros-jazzy-rmw-cyclonedds-cpp \
    git \
    ffmpeg \
    build-essential \
    libopencv-dev \
    && rm -rf /var/lib/apt/lists/*

COPY cyclone.xml /workspace/run/cyclone.xml
WORKDIR /workspace/run
ENV CYCLONEDDS_URI=cyclone.xml

RUN python3 -m venv /opt/venv
ENV PATH="/opt/venv/bin:$PATH"

RUN pip3 install --no-cache-dir --upgrade pip 

RUN pip3 install --no-cache-dir \
    # torch==2.2.1 \
    protobuf==4.25.3 \
    grpcio==1.62.1 \
    grpcio-tools==1.62.1 \
    python-multipart \
    "uvicorn[standard]" \
    fastapi \
    pyyaml \
    numpy \
    pillow \
    soundfile \
    librosa \
    sounddevice \
    numpy==1.26.4 \
    opencv-python-headless \
    empy \
    catkin_pkg \
    lark
    # --break-system-packages

CMD ["bash", "-c", "\
  /bin/bash \
"]


#   source /opt/ros/jazzy/setup.bash && \
#   source /workspace/ros2_ws/install/setup.bash && \

# docker build -t computer_viz .
# docker run -p 8181:8181 -it --gpus all -v $(pwd):/workspace/run -v /mnt/wslg:/mnt/wslg -e PULSE_SERVER=unix:/mnt/wslg/PulseServer --device /dev/snd  armkidd_cv
