
import numpy as np
from sensor_msgs.msg import Image, CameraInfo
import cv2

class CVHelpers:

    @staticmethod
    def ImgToCv2(msg):
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
        
    @staticmethod
    def Cv2ToImg(img, encoding="bgr8"):
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

    @staticmethod
    def getPointDepth(pixelX: int, pixelY: int, depthEncoding : str, latestDepth, 
                      cx : float, cy : float, fx : float, fy : float) -> list[float]:
        """
        Convert a depth pixel to 3D coordinates in meters.
        """
        u = pixelX
        v = pixelY

        if depthEncoding == "16UC1":
            # uint16 depth in mm → meters
            Z = latestDepth[v, u] / 1000.0
        elif depthEncoding == "32FC1":
            # float32 depth in meters
            Z = latestDepth[v, u]
        else:
            raise ValueError(f"Unsupported depth encoding: {depthEncoding}")

        # Pixel → 3D coordinates
        X = (u - cx) * Z / fx
        Y = (v - cy) * Z / fy

        return [X, Y, Z]

    @staticmethod
    def getPhysicalSize(depth: float, size_x: int, size_y: int, fx: float, fy: float):
        Z = depth

        if (Z == 0):
            print("Depth is a zero value in getPhysicalSize.")
            return 0, 0

        W = round((size_x / fx) * Z, 4)
        H = round((size_y / fy) * Z, 4)
        return (W, H)

    @staticmethod
    def getVirtualSize(depth: float, size_x: float, size_y: float, fx: float, fy: float): # cm -> pixel
        Z = depth  # meters

        if (Z == 0):
            print("Depth is a zero value in getVirtualSize.")
            return 0, 0

        size_x_m = size_x / 100.0
        size_y_m = size_y / 100.0

        W = round((size_x_m * fx) / Z)
        H = round((size_y_m * fy) / Z)

        return (W, H)


    