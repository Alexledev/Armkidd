import asyncio
import io
import json
import os
from SoundDev import SoundDev
from WhisperInferenceOnnx import WhisperInference

from stt_server.STTServer import STTServer, runSTTServer

from Utilities import Utilities
from loadConfig import ConfigLoader
import random

from watchdog.events import FileSystemEventHandler
from FileWatcher import runFileWatcher


class YamlChangeHandler(FileSystemEventHandler):
    def __init__(self, targetFile, onModified):
        self.targetFile = os.path.abspath(targetFile)
        self.onModified = onModified

        print(f"target file {self.targetFile} && on Mod {self.onModified}")

    def on_modified(self, event):
        print("Oh? Something changed")
        if os.path.abspath(event.src_path) == self.targetFile:
            print("config.yaml changed")
            self.onModified()

class App:
    def __init__(self):
       
        self.whisper = None

        # self.switchWhisperState()

        self.soundDev = SoundDev()
        
        self.readyForAsk = False
        self.proccessing = False

        self.updateConfigs()

        self.currentConfirmComment = ""

        self.loop = asyncio.get_running_loop()       

        self.soundDev.onReceiveCallback = lambda audio: self.loop.call_soon_threadsafe(self.loop.create_task, self.inferenceAsync(audio))
        STTServer.onReceiveCallback = lambda msg : self.loop.call_soon_threadsafe(self.loop.create_task, self.onSTTRecvMsg(msg))
        self.onConfigChangeHandler = YamlChangeHandler("config.yaml", self.updateConfigs)

    

    def afterFinishCallback(self):
          print("Cleanup whisper")
   
    
    async def onSTTRecvMsg(self, msg):

        dataJson = json.loads(msg)  

        if ("comment" in dataJson and dataJson["comment"] == self.currentConfirmComment):
            print(">> Command ready")
            self.soundDev.resume()
            self.currentConfirmComment = ""
            self.loop.call_soon_threadsafe(asyncio.create_task, self.checkReady())

        elif ("status" in dataJson and dataJson["status"] == "complete_task"):
            print("completed task")
            self.proccessing = False
            self.readyForAsk = False
            self.soundDev.resume()


    async def runListenAsync(self):
        while True:

            print("Waiting for soundDev to be running")

            await asyncio.to_thread(self.soundDev.listen)
            await asyncio.sleep(5.0)

    async def inferenceAsync(self, audio):  

        if ( self.proccessing == True ):
            return       
        
        txt = self.whisper.infer(audio)    

        if (txt is None):
            print("[Skipped: invalid speech]")
            return
        
        print(txt + "\n")
        
        return await self.processData(txt) 

    async def processData(self, txt):
        
        if ( self.proccessing == True ):
            return       
        
        if (Utilities.fuzzyMatch(txt, self.confirmComments, self.confirmHallucinateThresh)):
            print("[Detected Confirm Comment repeat, Skipping]")
            return        

        if (self.readyForAsk == False and Utilities.fuzzyMatch(txt, self.actionList,  self.confirmThresh)): # Hey, arm kid
            print(">>> Yes?")
            self.readyForAsk = True      
            self.soundDev.pause()

            self.currentConfirmComment = random.choice(self.confirmComments)
            STTServer.SendDataToClient(f"""{{"comment": "{self.currentConfirmComment}"}}""", "stt_whisper_client")    

        elif (self.readyForAsk == True):             
            print(f"Heard {txt}") 
            if (len(txt) > 0 and "[" not in txt and "(" not in txt ): # and self.imgStore is not None
                self.proccessing = True 

                self.soundDev.pause()
                STTServer.SendDataToClient(f"""{{"action": "{txt}"}}""", "stt_whisper_client")

            
    async def checkReady(self):
        await asyncio.sleep(self.talkDuration)
        if (self.proccessing == False):             
            self.readyForAsk = False
            print(" Ready Timeout ")


    def updateConfigs(self):
        print("change settings ya")

        modelPathsConfig = ConfigLoader("stt_server", "infer_settings")

        self.actionList = modelPathsConfig.get("action_list")
        self.confirmComments = modelPathsConfig.get("confirm_comments")
        self.confirmThresh = modelPathsConfig.get("confirm_thresh")
        self.confirmHallucinateThresh = modelPathsConfig.get("confirm_hallucinate_thresh")
        self.processTime = modelPathsConfig.get("time_to_proc")
        self.talkDuration = modelPathsConfig.get("max_talk_duration")


        print(self.actionList, self.confirmComments, self.confirmHallucinateThresh, self.confirmThresh, self.processTime, self.talkDuration)

        self.soundDev.MAX_SILENCE_SEC = self.processTime

        # miscConfig = ConfigLoader("chat_commands", "chat_settings")
        self.soundDev.running = self.isVoice() # miscConfig.get("chat_type") == "voice"

        self.switchWhisperState()

    def switchWhisperState(self):

        if (self.isVoice()):
            self.initWhisper()
        else:
            self.disposeWhisper()

    def isVoice(self):
        return ConfigLoader("chat_commands", "chat_settings").get("chat_type") == "voice"

    def initWhisper(self):
        modelPathsConfig = ConfigLoader("stt_server", "models")
        encoderOnnx = modelPathsConfig.get("whisper_encoder")
        decoderOnnx = modelPathsConfig.get("whisper_decoder")
        self.whisper = WhisperInference(encoderOnnx, decoderOnnx)

    def disposeWhisper(self):
        if self.whisper is not None:            
            self.whisper.destroy()
            self.whisper = None


    def runConfigWatcher(self):
        print("run conf watcher")
        runFileWatcher(self.onConfigChangeHandler)

    async def startFileWatcher(self):
        print("start file watcher")
        await asyncio.to_thread(self.runConfigWatcher)

    async def startSTTServer(self):
        await asyncio.to_thread(runSTTServer)



async def main():
    app = App()
    
    try:
        await asyncio.gather(
            # app.runClient(),
            app.runListenAsync(),
            app.startSTTServer(),
            app.startFileWatcher()
        )

    finally:        
        app.afterFinishCallback()

if __name__ == "__main__":  
    asyncio.run(main())  
