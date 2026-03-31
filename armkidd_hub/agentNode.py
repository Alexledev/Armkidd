import asyncio

import cv2
import numpy as np

from rclpy.node import Node
from std_msgs.msg import String
from sensor_msgs.msg import Image
from armkidd_interfaces.msg import WorldTarget
from armkidd_interfaces.srv import MarkImg

class AgentNode(Node):
    def __init__(self):
        super().__init__('agent_node')  

        self.imgSub = self.create_subscription(Image, "computer_viz/cam_img", self.onRecvImg, 10)
        self.targetsub = self.create_subscription(WorldTarget, "computer_viz/world_target", self.repubTarget, 10)
        self.targetRepub = self.create_publisher(WorldTarget, "armkidd_bbox_target", 10)

        self.getMarkedImgSrv = self.create_client(MarkImg, "computer_viz/get_boxed_img")

        self.onRecvImgCallback = None

        print("= Agent Node started =")

    def repubTarget(self, msg):
        self.targetRepub.publish(msg)

    def onRecvImg(self, img):

        ok, buf = cv2.imencode(".jpg", self.ImgToBytes(img))

        if not ok:
            return
        
        if (self.onRecvImgCallback):
            self.onRecvImgCallback(buf)

    async def getMarkedImg(self, x1, y1, x2, y2, centX, centY, isValid):

        print("Get marked img")
        await self.awaitService(self.getMarkedImgSrv)

        print("Got service, sending", x1, y1, x2, y2, isValid)

        req = MarkImg.Request()
        req.x1 = x1
        req.y1 = y1
        req.x2 = x2
        req.y2 = y2
        req.choke_x = centX
        req.choke_y = centY
        req.is_valid = isValid
        response = await self.getMarkedImgSrv.call_async(req)
        print("service returned")
        return response.image.data

    def ImgToBytes(self, msg):
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
        
    async def awaitService(self, client):
        while not client.wait_for_service(timeout_sec=0.1):
            await asyncio.sleep(0.1)
            