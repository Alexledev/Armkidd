import os
import asyncio
import grpc
from . import AgentServiceStream_pb2
from . import AgentServiceStream_pb2_grpc


class AgentClient:
    def __init__(self, address="localhost:8183"):
        self.address = address      
        self.channel = grpc.aio.insecure_channel(self.address)
        self.stub = AgentServiceStream_pb2_grpc.AgentStreamServiceStub(self.channel)
        self.onRecvCallback = None

    async def send(self, img, prompt):
        async def gen():
            yield AgentServiceStream_pb2.ImagePromptMessage(image=img, prompt=prompt)

        try:
            await self.stub.ClientSend(gen())
        except Exception as e:
            print("Upload failed:", e)
 

    async def receive(self):
        async for resp in self.stub.ServerSend(AgentServiceStream_pb2.SubscribeRequest(client_id="client_armkidd_prompt")):
            if resp.response:
                if self.onRecvCallback is not None:                   
                    self.onRecvCallback(resp.response)


    async def runAsync(self):       
        await self.receive()

    async def close(self):
        await self.channel.close()