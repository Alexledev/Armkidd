
import asyncio
import json

import numpy as np

# import imageSenderNode
from imageSenderWS import ImageSenderWS
from commandSenderWS import CommandSenderWS

from fastapi import APIRouter, WebSocket
from fastapi.websockets import WebSocketState




class WebSocketServer:
    def __init__(self):
        self.streamingWS = ImageSenderWS()
        self.detectionWS = ImageSenderWS()
        self.commandWS = CommandSenderWS()

        self.router = APIRouter()
        self.register_routes()

    def register_routes(self):
        self.router.websocket("/ws/streaming")(self.streamingWS.runWS)
        self.router.websocket("/ws/detection")(self.detectionWS.runWS)
        self.router.websocket("/ws/commands")(self.commandWS.runWS)
