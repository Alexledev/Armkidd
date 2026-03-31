
import grpc
from concurrent import futures

import queue
from . import WebChatService_pb2
from . import WebChatService_pb2_grpc
from collections import defaultdict
from config.ipAddrConfig import IPAddressConfig


class WebChatServer(WebChatService_pb2_grpc.WebChatStreamServiceServicer):

    webChatServer = None
    onReceiveCallback = None

    def __init__(self):
        # self.clients = {}  # client_id -> Queue
        self.clients = defaultdict(list)

    
    # def ClientSend(self, request_iterator, context):

    #     for msg in request_iterator:
    #         if (WebChatServer.onReceiveCallback is not None):
    #             WebChatServer.onReceiveCallback(msg.prompt)

    #     return WebChatService_pb2.Ack(status="OK")
    def ClientSend(self, request, context):

        if WebChatServer.onReceiveCallback is not None:
            WebChatServer.onReceiveCallback(request.prompt)

        return WebChatService_pb2.Ack(status="OK")
    
    
    def ServerSend(self, request, context):
        q = queue.Queue()
        self.clients[request.client_id].append(q)

        try:
           while context.is_active():
                try:
                    data = q.get(timeout=1)
                except queue.Empty:
                    continue
                yield WebChatService_pb2.ChatMessage(response=data)
        finally:
            self.clients[request.client_id].remove(q)
            if not self.clients[request.client_id]:
                del self.clients[request.client_id]

    def pushToClient(self, client_id, data):
        if client_id in self.clients:
            for q in self.clients[client_id]:
                q.put(data)

    @staticmethod
    def SendData(data, clientId):
        WebChatServer.webChatServer.pushToClient(clientId, data)


    @staticmethod
    def SendDataChatClient(data):
        WebChatServer.webChatServer.pushToClient("web_chat_client", data)

        
def runWebChatServer():
   
    WebChatServer.webChatServer = WebChatServer()

    addr = IPAddressConfig("web_chat_server", "insecure_port").getIP()

    server = grpc.server(futures.ThreadPoolExecutor(max_workers=4))
    WebChatService_pb2_grpc.add_WebChatStreamServiceServicer_to_server(WebChatServer.webChatServer, server)
    server.add_insecure_port(addr)
    server.start()
    print(f"WEBCHAT SERVER STARTED AT {addr}")
    server.wait_for_termination()
