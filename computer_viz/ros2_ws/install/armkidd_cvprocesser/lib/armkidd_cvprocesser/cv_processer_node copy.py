#!/usr/bin/env python3
import asyncio
import json
import threading
import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
# from std_msgs.msg import String
from armkidd_interfaces.msg import ArmkiddTarget  
from ImageClient import ImageClient
from AgentClient import AgentClient
from load_config import ConfigLoader

import cv2


class CVProcesserNode(Node):

    def __init__(self):
        super().__init__("cv_processer_node")

        confLoader = ConfigLoader("image_servers", "insecure_port")
        ip = confLoader.get("ip")
        port = confLoader.get("port")

        self.imageClient = ImageClient(address=f"{ip}:{port}")
        self.get_logger().info(f"imageClient {ip}:{port}")

        self.frame_timer = self.create_timer(0.5, self.timerCallback) 
        self.lock = True      

        self.imgSub = self.create_subscription(Image, "/ascamera_hp60c/camera_publisher/rgb0/image", self.imageCallback, 10)
        self.depthSub = self.create_subscription(Image, "/ascamera_hp60c/camera_publisher/depth0/image_raw",self.depthCallback,10)
        self.camInfoSub = self.create_subscription(CameraInfo, "/ascamera_hp60c/camera_publisher/depth0/camera_info",self.cameraInfoCallback,10)

        self.camInfoReady = False

        self.latestImageCv2 = None
        self.latestDepth = None
        self.depthEncoding = None

        self.fx = 0
        self.fy = 0
        self.cx = 0
        self.cy = 0
 
        self.imgPub = self.create_publisher(Image, "armkidd_img", 10)
        self.coordPub = self.create_publisher(ArmkiddTarget, "armkidd_bbox_target", 10)
        self.get_logger().info("cv_processer_node started")

        AgentClient.onReceiveCallback = self.onAgentRecv

    def onAgentRecv(self, data):
        # print(f"agent sent {data}")
        
        try:
            loadedData = json.loads(data)

            hasItem = loadedData.get("answer")
            boundingBox = loadedData.get("bbox")

            if (hasItem is not None and boundingBox is not None):
                print(f"Answer {hasItem} && Box {boundingBox}")
                if (hasItem == "Yes"):                
                    self.processBoxInfo(boundingBox, "Yes", color=(0, 255, 0))
                if (hasItem == "No"):
                    self.processBoxInfo(boundingBox, "No", color=(0, 0, 255))
        except:
            pass

    def processBoxInfo(self, boundingBox, label, color=(0, 255, 0)):
        p1, p2 = boundingBox.split(";")

        x1, y1 = map(int, p1.strip("()").split(","))
        x2, y2 = map(int, p2.strip("()").split(","))

        print("Four coords:", x1, y1, x2, y2)

        boxWidth = (x2 - x1)
        boxHeight = (y2 - y1)

        centerX = int(x1 + boxWidth / 2)
        centerY = int(y1 + boxHeight / 2)

        necklineY = int(y1 + 20)
        pos = self.getPointDepth(centerX, necklineY)
        print(f"----- {necklineY}")
        if (pos[2] == 0):
            print("All black here, going further")
            necklineY += 20
            pos = self.getPointDepth(centerX, necklineY)
            print(f"-----> {pos[2]}")

        print(f"----->> {necklineY}")

        necklineY += self.getVirtualSize(pos[2], 0, 1.0)[1]

        print(f"----->>> {necklineY}")

        pos = self.getPointDepth(centerX, necklineY)

        cv2.circle(self.latestImageCv2, (centerX, necklineY), 5, color, thickness=-1)
        cv2.putText(self.latestImageCv2, f"{pos[2]:.2f}", (centerX, necklineY+14), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 1)
        cv2.putText(self.latestImageCv2, f"{label}", (x1, y1-7), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 1)
        cv2.rectangle(self.latestImageCv2, (x1, y1), (x2, y2), color, 2)

        w, h = self.getPhysicalSize(pos[2], boxWidth, boxHeight)

        self.imgPub.publish(self.Cv2ToImg(self.latestImageCv2))

        if (label == "No"):
            return

        msg = ArmkiddTarget()
        # msg.data = f"""Center: {{ {centerX}, {centerY} }} With Depth of {posZ}"""
        msg.target_x = pos[0]
        msg.target_y = pos[1]
        msg.depth = pos[2]
        msg.width = w
        msg.height = h

        # print(msg.data)

        self.coordPub.publish(msg)     

    def depthCallback(self, msg: Image) -> None:
        if not self.camInfoReady:
            return
    
        cv_image = self.ImgToCv2(msg)
        self.latestDepth = cv_image
        self.depthEncoding = msg.encoding

    def cameraInfoCallback(self, msg: CameraInfo) -> None:

        self.fx = msg.k[0]
        self.fy = msg.k[4]
        self.cx = msg.k[2]
        self.cy = msg.k[5]

        if not self.camInfoReady:
            self.camInfoReady = True

    def getPointDepth(self, pixelX: int, pixelY: int) -> list[float]:
        """
        Convert a depth pixel to 3D coordinates in meters.
        """
        u = pixelX
        v = pixelY

        if self.depthEncoding == "16UC1":
            # uint16 depth in mm → meters
            Z = self.latestDepth[v, u] / 1000.0
        elif self.depthEncoding == "32FC1":
            # float32 depth in meters
            Z = self.latestDepth[v, u]
        else:
            raise ValueError(f"Unsupported depth encoding: {self.depthEncoding}")

        # Pixel → 3D coordinates
        X = (u - self.cx) * Z / self.fx
        Y = (v - self.cy) * Z / self.fy

        return [X, Y, Z]

    def getPhysicalSize(self, depth: float, size_x: int, size_y: int):
        Z = depth
        W = round((size_x / self.fx) * Z, 2)
        H = round((size_y / self.fy) * Z, 2)
        return (W, H)

    def getVirtualSize(self, depth: float, size_x: float, size_y: float): # cm -> pixel
        Z = depth  # meters

        size_x_m = size_x / 100.0
        size_y_m = size_y / 100.0

        W = round((size_x_m * self.fx) / Z)
        H = round((size_y_m * self.fy) / Z)

        return (W, H)


    
    def imageCallback(self, img):

        if (self.lock):
            return

        cvImg = self.ImgToCv2(img)
        ok, buf = cv2.imencode(".jpg", cvImg)

        if not ok:
            return
        
        self.lock = True
        self.latestImageCv2 = cvImg
        asyncio.create_task(self.imageClient.send(buf.tobytes()))

    def timerCallback(self):
        self.lock = False

    def ImgToCv2(self, msg):
        if msg.encoding in ("bgr8", "rgb8"):
            data = np.frombuffer(msg.data, dtype=np.uint8)
            img = data.reshape((msg.height, msg.width, 3))

            if msg.encoding == "rgb8":
                img = img[:, :, ::-1]

            return img

        elif msg.encoding == "mono8":
            data = np.frombuffer(msg.data, dtype=np.uint8)
            return data.reshape((msg.height, msg.width))

        elif msg.encoding == "16UC1":
            data = np.frombuffer(msg.data, dtype=np.uint16)
            return data.reshape((msg.height, msg.width))

        else:
            raise ValueError(f"Unsupported encoding: {msg.encoding}")
        
    def Cv2ToImg(self, img, encoding="bgr8"):
        msg = Image()

        if img.ndim == 2:
            # mono image
            msg.height, msg.width = img.shape
            msg.encoding = "mono8" if encoding is None else encoding
            msg.step = msg.width
        elif img.ndim == 3:
            msg.height, msg.width, channels = img.shape
            
            if encoding is None:
                encoding = "bgr8"  # default for OpenCV
            
            if encoding == "rgb8":
                # Convert BGR (OpenCV default) → RGB
                img = img[:, :, ::-1]

            msg.encoding = encoding
            msg.step = msg.width * channels
        else:
            raise ValueError("Unsupported image shape")

        msg.is_bigendian = 0
        msg.data = img.tobytes()

        return msg

async def mainAsync():
    rclpy.init()
    
    node = CVProcesserNode()
    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.1)
            await asyncio.sleep(0)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

async def runAgentClient():         

    confLoader = ConfigLoader("agent_servers", "config_site")
    ip = confLoader.get("ip")
    port = confLoader.get("port")

    agentClient = AgentClient(agentIp=ip, agentPort=port, clientId="client_armkidd_voice")
    print(f"agentClient grpc {ip}:{port}")

    try:
        await agentClient.runAsync()
    finally:
        print("Closed agent client")
        await agentClient.close()


async def main():
    task1 = asyncio.create_task(mainAsync())
    task2 = asyncio.create_task(runAgentClient())

    await asyncio.gather(task1, task2) #

if __name__=='__main__':
    asyncio.run(main())