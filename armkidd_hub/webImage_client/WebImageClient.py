import os
import asyncio
import grpc
from . import WebImageService_pb2
from . import WebImageService_pb2_grpc
from asyncio.queues import Queue

class WebImageClient:
    def __init__(self, address):
        self.address = address      
        self.channel = grpc.aio.insecure_channel(self.address, options=[
            ('grpc.max_send_message_length', 50 * 1024 * 1024),
            ('grpc.max_receive_message_length', 50 * 1024 * 1024),
        ])

        self.streamStub = WebImageService_pb2_grpc.WebImageStreamServiceStub(self.channel)
        self.eventStub = WebImageService_pb2_grpc.WebImageEventServiceStub(self.channel)
        self.onRecvCallback = None

        self.streamQueue = Queue(maxsize=1)

    def sendStreamImg(self, img):
        if (not self.streamQueue.empty()):
            self.streamQueue.get_nowait()

        self.streamQueue.put_nowait(img)

    async def startStream(self):
        async def gen():
            while True:
                img = await self.streamQueue.get()
                yield WebImageService_pb2.ImageMessage(image=img)
                
        async def run_stream():
            try:
                await self.streamStub.SendImageStream(gen())
            except Exception as e:
                print("Stream Upload failed:", e)

        self.stream_task = asyncio.create_task(run_stream())

    async def sendEvent(self, img):
        try:
            await self.eventStub.SendImageEvent(WebImageService_pb2.ImageMessage(image=img))
        except Exception as e:
            print("Event Upload failed:", e)


    async def close(self):
        await self.channel.close()