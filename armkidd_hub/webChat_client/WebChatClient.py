
import grpc
from typing import override
from . import WebChatService_pb2
from . import WebChatService_pb2_grpc
from inputClient import InputClient


class WebChatClient(InputClient):
    def __init__(self, address):
        super().__init__()
        self.address = address      
        self.channel = grpc.aio.insecure_channel(self.address)
        self.stub = WebChatService_pb2_grpc.WebChatStreamServiceStub(self.channel)
        
    async def send(self, msg):
        try:
            await self.stub.ClientSend(WebChatService_pb2.TextMessage(prompt=msg))
        except Exception as e:
            print("Upload failed:", e)
 

    async def receive(self):
        async for resp in self.stub.ServerSend(WebChatService_pb2.SubscribeRequest(client_id="web_chat_client")):
            if resp.response:
                if self.onRecvCallback is not None:                   
                    self.onRecvCallback(resp.response)

    @override
    async def runAsync(self):       
        await self.receive()

    @override
    async def close(self):
        await self.channel.close()