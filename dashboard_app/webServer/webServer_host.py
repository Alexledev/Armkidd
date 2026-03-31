import asyncio
import threading

from webImage_server.WebImageServer import WebImageStreamService, WebImageEventService, runWebImageServer
from webChat_server.WebChatServer import WebChatServer, runWebChatServer

from webAPIServer import WebAPIServer
from webSocketServer import WebSocketServer

from config.ipAddrConfig import IPAddressConfig

from fastapi import FastAPI

import uvicorn


app = FastAPI()

eventLoop = None
executor = None
spinThread : threading.Thread = None


def testa(imgBytes):
    print(f"Recved:", len(imgBytes))

@app.on_event("startup")
async def startup():
    global eventLoop
    asyncio.create_task(asyncio.to_thread(runWebImageServer))
    asyncio.create_task(asyncio.to_thread(runWebChatServer))
    eventLoop = asyncio.get_running_loop()

    WebChatServer.onReceiveCallback = lambda msg: eventLoop.call_soon_threadsafe(asyncio.create_task, webSocket.commandWS.agentRecv(msg))

    WebImageStreamService.onStreamRecvCallback = lambda imgBytes: eventLoop.call_soon_threadsafe(asyncio.create_task, webSocket.streamingWS.sendImg(imgBytes))
    WebImageEventService.onEventRecvCallback = lambda imgBytes: eventLoop.call_soon_threadsafe(asyncio.create_task, webSocket.detectionWS.sendImg(imgBytes))
    webSocket.commandWS.sendChatCB = WebChatServer.SendDataChatClient
    

if __name__ == "__main__":

    print("Yahhooooooo")

    ip, port = IPAddressConfig("sites", "config_site").getIPPort()

    webAPI = WebAPIServer() #url_webRTC
    webSocket = WebSocketServer() #url_webRTC

    app.include_router(webAPI.router)
    app.include_router(webSocket.router)

    uvicorn.run(app, host=ip, port=port)


