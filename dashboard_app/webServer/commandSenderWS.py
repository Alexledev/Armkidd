
import json

from fastapi import APIRouter, WebSocket
from fastapi.websockets import WebSocketState

from config.load_config import ConfigLoader

class CommandSenderWS:
    def __init__(self):

        self.clients: set[WebSocket] = set()
        self.chatConf = ConfigLoader("chat_commands", "chat_settings")
        self.sendChatCB = None

    async def runWS(self, ws: WebSocket):
        await ws.accept()
        self.clients.add(ws)      
        
        await ws.send_json({"status": "init", "value": self.chatConf.get("chat_type")})

        try:
            while True:

                recv = await ws.receive_json()

                if recv.get("type") == "websocket.disconnect":
                    break        

                if (recv.get("name") == "setChatType"):
                    print(recv["chatType"])
                    
                    self.chatConf.setAndSave("chat_type", recv["chatType"])

                    await ws.send_json({"status": "ok", "value": "setChatType"})

                if (recv.get("name") == "sendChatMsg"):
                    print(recv)

                    await self.handleChatInput(recv["message"], recv["msgType"])                    

                    await ws.send_json({"status": "ok", "value": "sendChatMsg"})
                
        finally:            
            self.clients.remove(ws)

    async def handleChatInput(self, msg, msgType):

        # Handle dynamic responses later

        if (self.sendChatCB is None):
            print("sendChatCB is not specified yet")
            return
        
        if msgType == "ready":
            self.sendChatCB(f"""{{ "comment": "Yes, I'm here!" }}""") #{recv["message"]}

        elif msgType == "action":
            self.sendChatCB(f"""{{ "action": "{msg}" }}""")

    async def agentRecv(self, msg):

        try:
            print(f"sending {msg} ...")
            jsonfied = json.loads(msg)

            if jsonfied.get("comment") == "Yes, I'm here!":
                for ws in self.clients:
                    await ws.send_json({"status": "ready"})
            
            if jsonfied.get("status") == "complete_task":
                for ws in self.clients:
                    await ws.send_json({"status": "complete"})

        except Exception as e:
            print(f"Smth went wrong in sendInfo {e}")
        


