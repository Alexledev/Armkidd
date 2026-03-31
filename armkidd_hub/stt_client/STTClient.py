import os
import asyncio
import grpc
from . import STTServiceStream_pb2
from . import STTServiceStream_pb2_grpc
from typing import override
from inputClient import InputClient


class STTClient(InputClient):
    def __init__(self, address):
        super().__init__()
        self.address = address      
        self.channel = grpc.aio.insecure_channel(self.address)
        self.stub = STTServiceStream_pb2_grpc.STTStreamServiceStub(self.channel)
        # self.onRecvCallback = None

    async def send(self, msg):
        async def gen():
            yield STTServiceStream_pb2.StatusMessage(msg=msg)

        try:
            await self.stub.ClientSend(gen())
        except Exception as e:
            print("Upload failed:", e)
 

    async def receive(self):
        async for resp in self.stub.ServerSend(STTServiceStream_pb2.SubscribeRequest(client_id="stt_whisper_client")):
            if resp.response:
                if self.onRecvCallback is not None:                   
                    self.onRecvCallback(resp.response)

    @override
    async def runAsync(self):       
        await self.receive()

    @override
    async def close(self):
        await self.channel.close()