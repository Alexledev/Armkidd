FROM python:3.11-slim

# install htpasswd
RUN apt-get update && apt-get install -y \
    nginx \
    apache2-utils \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace/run/
# COPY . /home/app/static

RUN pip install --no-cache-dir \
    python-multipart \
    "uvicorn[standard]" \
    grpcio==1.62.1 \
    grpcio-tools==1.62.1 \
    fastapi \
    pyyaml \
    numpy \
    pillow \
    opencv-python-headless

# create htpasswd file
ARG PASSWORD=ARM41D3
RUN htpasswd -bc /etc/nginx/.htpasswd armkidd "$PASSWORD"

COPY  webUI/nginx.conf /etc/nginx/nginx.conf
RUN rm -f /etc/nginx/conf.d/default.conf

COPY webUI/run.sh /workspace/run/webUI/run.sh
RUN chmod +x /workspace/run/webUI/run.sh

# CMD ["nginx", "-g", "daemon off;"]
CMD ["/bin/bash"]

# docker build -t dashboard_app .
