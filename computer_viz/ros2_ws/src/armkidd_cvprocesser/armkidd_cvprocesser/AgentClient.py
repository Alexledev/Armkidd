import os
import asyncio
import grpc
import AgentServiceStream_pb2
import AgentServiceStream_pb2_grpc


class AgentClient:

    onReceiveCallback = None

    def __init__(self, agentIp, agentPort, clientId):

        if not (isinstance(agentIp, str) and agentIp.strip() and isinstance(agentPort, int)):
            raise Exception("Invalid agentIp or agentPort for armkidd_piper AgentClient")
        
        self.clientId = clientId
        self.address = f"{agentIp}:{agentPort}"      
        self.channel = grpc.aio.insecure_channel(self.address)
        self.stub = AgentServiceStream_pb2_grpc.AgentStreamServiceStub(self.channel)
        # self.onReceiveCallback = None

    async def send(self, img, prompt):
        async def gen():
            yield AgentServiceStream_pb2.ImagePromptMessage(image=img, prompt=prompt)

        try:
            await self.stub.ClientSend(gen())
        except Exception as e:
            print("Upload failed:", e)
 

    async def receive(self):
        async for resp in self.stub.ServerSend(AgentServiceStream_pb2.SubscribeRequest(client_id=self.clientId)):
            if resp.response:
                print("ClientReceive:", resp.response)
                if AgentClient.onReceiveCallback is not None:
                    AgentClient.onReceiveCallback(resp.response)


    async def runAsync(self):       
        await self.receive()

    async def close(self):
        await self.channel.close()