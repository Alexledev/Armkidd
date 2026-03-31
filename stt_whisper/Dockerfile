
FROM nvidia/cuda:12.6.0-runtime-ubuntu24.04

ENV DEBIAN_FRONTEND=noninteractive
ENV TRANSFORMERS_NO_TF=1
ENV PYTHONUNBUFFERED=1

RUN apt-get update && apt-get install -y \
    python3 \
    python3-pip \
    python3-venv \
    libportaudio2 \
    portaudio19-dev \
    libasound2-dev \
    libsndfile1 \
    && rm -rf /var/lib/apt/lists/*

RUN python3 -m venv /opt/venv
ENV PATH="/opt/venv/bin:$PATH"

# Upgrade pip
RUN pip3 install --no-cache-dir --upgrade pip 

# Python packages
RUN pip3 install --no-cache-dir \
    torch==2.2.1 \
    protobuf==4.25.3 \
    grpcio==1.62.1 \
    grpcio-tools==1.62.1 \
    pyyaml \
    pyaudio \
    tqdm \
    soundfile \
    librosa \
    sounddevice \
    openai-whisper==20250625 \
    numpy==1.26.4 \
    pillow \
    watchdog


# onnxruntime-gpu==1.18.1 \  onnx is mounted
WORKDIR /workspace/run
COPY on_startup.sh .

ENTRYPOINT ["/workspace/run/on_startup.sh"]

# Default command
CMD ["/bin/bash"]

# run in terminal with:
# docker build -t whisper_onnx .
# docker run -p 8182:8182 -it --gpus all -v $(pwd):/workspace/run -v /mnt/wslg:/mnt/wslg -e PULSE_SERVER=unix:/mnt/wslg/PulseServer --device /dev/snd  whisper_onnx

# docker 
