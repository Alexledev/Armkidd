#!/usr/bin/env python3
import asyncio
import json
import threading
import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from std_msgs.msg import ByteMultiArray
# from std_msgs.msg import String
from armkidd_interfaces.msg import WorldTarget  
from armkidd_interfaces.srv import MarkImg
from ImageClient import ImageClient
from AgentClient import AgentClient
from load_config import ConfigLoader
from  cv_helpers import CVHelpers

import cv2


class CVProcesserNode(Node):

    def __init__(self):
        super().__init__("cv_processer_node")

        confLoader = ConfigLoader("image_servers", "insecure_port")
        ip = confLoader.get("ip")
        port = confLoader.get("port")

        self.imageClient = ImageClient(address=f"{ip}:{port}")
        self.get_logger().info(f"imageClient {ip}:{port}")

        self.frame_timer = self.create_timer(0.2, self.imageTimerCallback) 
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
 
        self.imgPub =  self.create_publisher(Image, "computer_viz/cam_img", 10)
        self.imgCVPub = self.create_publisher(Image, "computer_viz/cv_img", 10)
        self.coordPub = self.create_publisher(WorldTarget, "computer_viz/world_target", 10)

        self.getBoxedImageSrv = self.create_service(MarkImg, 'computer_viz/get_boxed_img', self.getBoxedImgCallback)

        self.get_logger().info("cv_processer_node started 2")


    def depthCallback(self, msg: Image) -> None:
        if not self.camInfoReady:
            return
    
        cv_image = CVHelpers.ImgToCv2(msg)
        self.latestDepth = cv_image
        self.depthEncoding = msg.encoding

    def cameraInfoCallback(self, msg: CameraInfo) -> None:

        self.fx = msg.k[0]
        self.fy = msg.k[4]
        self.cx = msg.k[2]
        self.cy = msg.k[5]

        if not self.camInfoReady:
            self.camInfoReady = True

    def imageCallback(self, img):

        if (self.lock):
            return

        cvImg = CVHelpers.ImgToCv2(img)
        
        self.lock = True
        self.latestImageCv2 = cvImg

        # print("self.latestImageCv2", len(self.latestImageCv2))

        self.imgPub.publish(img)

    def imageTimerCallback(self):
        self.lock = False
        
    def getBoxedImgCallback(self, req, res):

        try:
            x1 = req.x1
            y1 = req.y1
            x2 = req.x2
            y2 = req.y2

            choke_x = req.choke_x
            choke_y = req.choke_y

            imgBytes = b""

            if (req.is_valid):                
                imgBytes = self.processBoxInfo((x1, y1, x2, y2, choke_x, choke_y), "Yes", color=(0, 255, 0))
            else:
                imgBytes = self.processBoxInfo((x1, y1, x2, y2, choke_x, choke_y), "No", color=(0, 0, 255))

            print(f"img bytes: {len(imgBytes)}")

            bma = ByteMultiArray()
            bma.data = imgBytes

            res.image = bma
                
        except Exception as e:
            print(f"Smth went wrong in getBoxedImgCallback: {e}")

        finally:
            return res

    def processBoxInfo(self, boundingBox, label, color=(0, 255, 0)):

        x1, y1, x2, y2, choke_x, choke_y = boundingBox

        choke_x = x1+choke_x
        choke_y = y1+choke_y

        print("Four coords:", x1, y1, x2, y2, " |  The Neck:", choke_x, choke_y, " ---> ", choke_x, choke_y)

        boxWidth = (x2 - x1)
        boxHeight = (y2 - y1)

        # centerX = int(x1 + boxWidth / 2)
        # centerY = int(y1 + boxHeight / 2)

        # print(f"----->>> {necklineY}")

        pos = CVHelpers.getPointDepth(choke_x, choke_y, self.depthEncoding, self.latestDepth, self.cx, self.cy, self.fx, self.fy)

        # cv2.circle(self.latestImageCv2, (centerX, centerY), 5, color, thickness=-1)
        cv2.circle(self.latestImageCv2, (choke_x, choke_y), 5, color, thickness=1)
        cv2.putText(self.latestImageCv2, f"{pos[2]:.2f}", (choke_x, choke_y+14), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 1)
        cv2.putText(self.latestImageCv2, f"{label}", (x1, y1-7), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 1)
        cv2.rectangle(self.latestImageCv2, (x1, y1), (x2, y2), color, 2)

        w, h = CVHelpers.getPhysicalSize(pos[2], boxWidth, boxHeight, self.fx, self.fy)

        if (label == "Yes"):           

            msg = WorldTarget()
            msg.target_x = pos[0]
            msg.target_y = pos[1]
            msg.depth = pos[2]
            msg.width = w
            msg.height = h
            self.coordPub.publish(msg)     

        self.imgCVPub.publish(CVHelpers.Cv2ToImg(self.latestImageCv2))

        ok, buf = cv2.imencode(".jpg", self.latestImageCv2)
        return buf.tobytes()
 

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


async def main():
    await mainAsync()

if __name__=='__main__':
    asyncio.run(main())