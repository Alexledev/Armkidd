
import asyncio

from fastapi import APIRouter, WebSocket
from fastapi.websockets import WebSocketState

class ImageSenderWS:
    def __init__(self):

        self.clients = set()

    async def runWS(self, ws: WebSocket):
        await ws.accept()
        self.clients.add(ws)      

        try:
            while True:

                recv = await ws.receive()

                if recv.get("type") == "websocket.disconnect":
                    break         

                await ws.send_json({"status": "ok", "value": 1})
                
        finally:
            self.clients.remove(ws)
        

    async def sendImg(self, imgBytes):
        # print(f"Sending an Img with {len(imgBytes)}")
        try:                
            for _ws in self.clients:
                await _ws.send_bytes(imgBytes)
                
        except Exception as e:
            print(f"Something happened in sendImg callback: {e}")
