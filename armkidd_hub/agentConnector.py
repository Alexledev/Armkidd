
import asyncio
import json

# from stt_client.STTClient import STTClient
from inputClient import InputClient
from agent_client.AgentClient import AgentClient
from agentNode import AgentNode

class AgentConnector:
    def __init__(self, agentClient : AgentClient):

        self.loop = asyncio.get_running_loop()   

        self.agentClient : AgentClient = agentClient
        self.agentClient.onRecvCallback = lambda msg : self.loop.call_soon_threadsafe(self.loop.create_task, self.onAgentRecvMsg(msg))

        self.inputClient : InputClient = None
        self.agentNode : AgentNode = None

        self.currentImgBuf = b""
        # self.retrievedImgBytes = b""
        
        self.onDetectionImageRecvCallbackAsync = None
        self.onStreamImageRecvCallback = None


    def addConnection(self, client):
        self.inputClient = client
        self.inputClient.onRecvCallback = lambda msg : self.loop.call_soon_threadsafe(self.loop.create_task, self.onInputRecvMsg(msg))
        
    def addNodeConnection(self, node):
        self.agentNode = node
        self.agentNode.onRecvImgCallback = self.onImgRecvMsg  

    async def onInputRecvMsg(self, msg):

        print(f"msg: {msg}")

        jsonfied = json.loads(msg)

        if (jsonfied.get("comment")):
            await self.agentClient.send(b"", msg)
        elif (jsonfied.get("action")):
            await self.agentClient.send(self.currentImgBuf, jsonfied.get("action"))
        else:
            raise Exception(f"Error in onSTTRecvMsg: > {msg} < is not valid json")


    async def onAgentRecvMsg(self, msg):
        print(f"Agent receive: {msg} \n")

        if (self.inputClient == None):
            raise Exception("Error in onAgentRecvMsg: Must have STT client")

        jsonfied = json.loads(msg)

        if (jsonfied.get("answer") and jsonfied.get("bbox")):
            hasItem = jsonfied.get("answer")
            boundingBox = jsonfied.get("bbox")
            
            p1, p2, cent = boundingBox.split(";")

            x1, y1 = map(int, p1.strip("()").split(","))
            x2, y2 = map(int, p2.strip("()").split(","))
            centX, centY = map(int, cent.strip("()").split(","))

            chunks = await self.agentNode.getMarkedImg(x1, y1, x2, y2, centX, centY, hasItem=="Yes")

            retrievedImgBytes = b"".join(chunks)

            print(f"retrievedImgBytes: {len(retrievedImgBytes)} of type {type(retrievedImgBytes)}")

            if (self.onDetectionImageRecvCallbackAsync):
                await self.onDetectionImageRecvCallbackAsync(retrievedImgBytes)

        
        elif (jsonfied.get("comment") or jsonfied.get("status")):
            print(f"Got comment or status {msg}")
            await self.inputClient.send(msg)


    def onImgRecvMsg(self, img): 
        self.currentImgBuf = img.tobytes()

        if (self.onStreamImageRecvCallback):
            self.onStreamImageRecvCallback(self.currentImgBuf)

