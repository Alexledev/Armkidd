import asyncio
import os

from loadConfig import ConfigLoader
import rclpy
# from rclpy.executors import MultiThreadedExecutor

from agentNode import AgentNode

from stt_client.STTClient import STTClient
from agent_client.AgentClient import AgentClient
from webImage_client.WebImageClient import WebImageClient
from webChat_client.WebChatClient import WebChatClient

from agentConnector import AgentConnector

# from loadConfig import ConfigLoader
from ipAddrConfig import IPAddressConfig

from asyncio.queues import Queue

from inputClientFactory import InputClientFactory

from watchdog.events import FileSystemEventHandler
from FileWatcher import runFileWatcher

class YamlChangeHandler(FileSystemEventHandler):
    def __init__(self, targetFile, onModified):
        self.targetFile = os.path.abspath(targetFile)
        self.onModified = onModified

        print(f"target file {self.targetFile} && on Mod {self.onModified}")

    def on_modified(self, event):
        print("A file changed smwhere")
        if os.path.abspath(event.src_path) == self.targetFile:
            print("config.yaml changed")
            self.onModified()

class ArmkiddMain:
    def __init__(self):

        self.loop = asyncio.get_running_loop() 

        self.agentNode = None     
    

        agentConf = IPAddressConfig("agent_servers", "config_site").getIP()
        self.agentClient = AgentClient(agentConf)

        webImageAddr = IPAddressConfig("web_server", "insecure_port").getIP()
        self.webImageClient = WebImageClient(webImageAddr)

        self.agentConnector = AgentConnector(self.agentClient)
        self.agentConnector.onStreamImageRecvCallback = self.webImageClient.sendStreamImg
        self.agentConnector.onDetectionImageRecvCallbackAsync = self.onDetectionImageRecvCallbackAsync

        self.currInputClient = None

        self.imageQueue = Queue(1)

        config_path = os.path.abspath("../shared/config.yaml")
        self.watch_dir = os.path.dirname(config_path)
        self.onConfigChangeHandler = YamlChangeHandler(config_path, self.updateConfigs)
        self.updateConfigs()

        print("ArmkiddMain started")


    async def onDetectionImageRecvCallbackAsync(self, imgBytes):
        print(f"Sending a detect event with {len(imgBytes)} ")
        asyncio.create_task(self.webImageClient.sendEvent(imgBytes))
        print("sent")

 
    def afterFinishCallback(self):
        print("ArmkiddMain finish")
  

    async def runAgentClient(self):
        try:
            print("run agent client")
            await self.agentClient.runAsync()
        except:
            await self.agentClient.close()


    async def runAgentRos2Node(self):
        rclpy.init()
        self.agentNode = AgentNode()
        self.agentConnector.addNodeConnection(self.agentNode)

        while rclpy.ok():
            rclpy.spin_once(self.agentNode, timeout_sec=0.1)
            await asyncio.sleep(0)  # yield control

        self.agentNode.destroy_node()
        rclpy.shutdown()


    def updateConfigs(self):
        self.loop.call_soon_threadsafe(self.loop.create_task, self.updateConfigsAsync())

    async def updateConfigsAsync(self):
        print("updConfigs")

        inputType = ConfigLoader("chat_commands", "chat_settings").get("chat_type")

        await self.setInputClient(inputType)
        

    async def setInputClient(self, inputType):

        currentType = self.getInputType(inputType)

        if self.currInputClient is not None and InputClientFactory.currentType is currentType: 
            print("Nothing changed")
            return        

        if self.currInputClient != None:
            await InputClientFactory.stopClient()

        self.currInputClient = InputClientFactory.createInputClient(currentType)
        self.agentConnector.addConnection(self.currInputClient)
        
        await InputClientFactory.runInputClient()

    def getInputType(self, inputType):
        currentType = None
        if inputType == "voice":
            currentType = STTClient
        elif inputType == "chat":
            currentType = WebChatClient
        else:
            raise Exception(f"Error in updateConfigs: Invalid inputType")
        
        return currentType


    def runConfigWatcher(self):
        print("run conf watcher")
        runFileWatcher(self.onConfigChangeHandler, self.watch_dir)

    async def startFileWatcher(self):
        print("start file watcher")
        await asyncio.to_thread(self.runConfigWatcher)


async def main():
    app = ArmkiddMain()
    
    try:
        await asyncio.gather(            
            app.runAgentClient(),
            app.runAgentRos2Node(),
            app.webImageClient.startStream(),
            app.startFileWatcher()
        )

    finally:        
        app.afterFinishCallback()

if __name__ == "__main__":  
    asyncio.run(main())  
