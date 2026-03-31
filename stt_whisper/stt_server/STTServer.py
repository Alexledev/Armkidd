from io import BytesIO
import json
import grpc
import queue
from concurrent import futures
from collections import defaultdict

from . import STTServiceStream_pb2
from . import STTServiceStream_pb2_grpc
from loadConfig import ConfigLoader


class STTServer(STTServiceStream_pb2_grpc.STTStreamServiceServicer):

    msgServer = None
    onReceiveCallback = None

    def __init__(self):
        self.clients = defaultdict(list)

    
    def ClientSend(self, request_iterator, context):
        try:
            for msg in request_iterator:

                if (STTServer.onReceiveCallback is not None):
                    STTServer.onReceiveCallback(msg.msg)

            return STTServiceStream_pb2.Ack(status="OK")
        except Exception as e:
            print(f"Smth went wrong in ClientSend: {e}")
    
    def ServerSend(self, request, context):
        q = queue.Queue()
        self.clients[request.client_id].append(q)

        try:
           while context.is_active():
                try:
                    data = q.get(timeout=1)
                except queue.Empty:
                    continue
                yield STTServiceStream_pb2.STTMessage(response=data)
        finally:
            self.clients[request.client_id].remove(q)
            if not self.clients[request.client_id]:
                del self.clients[request.client_id]

    def pushToClient(self, client_id, data):
        if client_id in self.clients:
            for q in self.clients[client_id]:
                q.put(data)

    @staticmethod
    def SendDataToClient(data, clientId):
        STTServer.msgServer.pushToClient(clientId, data)
        
def runSTTServer():
    
    STTServer.msgServer = STTServer()

    loadConf = ConfigLoader("stt_server", "insecure_port")
    addr = loadConf.get("ip")
    port = loadConf.get("port")

    if not (isinstance(addr, str) and addr.strip() and isinstance(port, int)):
        raise Exception("Invalid configuration for ip or port")
    
       
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=4))
    STTServiceStream_pb2_grpc.add_STTStreamServiceServicer_to_server(STTServer.msgServer, server)
    server.add_insecure_port(f"{addr}:{port}")
    server.start()
    print(f"STT SERVER STARTED at {addr}:{port}")
    server.wait_for_termination()