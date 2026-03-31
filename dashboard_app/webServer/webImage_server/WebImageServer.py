from io import BytesIO
import json
import grpc
from concurrent import futures

from . import WebImageService_pb2
from . import WebImageService_pb2_grpc
from config.ipAddrConfig import IPAddressConfig

class WebImageStreamService(WebImageService_pb2_grpc.WebImageStreamServiceServicer):

    webImageStreamServer = None
    onStreamRecvCallback = None

    def SendImageStream(self, request_iterator, context):
        for msg in request_iterator:
            if (WebImageStreamService.onStreamRecvCallback is not None):
                WebImageStreamService.onStreamRecvCallback(msg.image)

        return WebImageService_pb2.Ack(status="OK")
    
    
class WebImageEventService(WebImageService_pb2_grpc.WebImageEventServiceServicer):

    webImageEventServer = None
    onEventRecvCallback = None
    
    def SendImageEvent(self, request, context):
        if (WebImageEventService.onEventRecvCallback is not None):
            WebImageEventService.onEventRecvCallback(request.image)

        return WebImageService_pb2.Ack(status="OK")
    

def singletonStream():
    if WebImageStreamService.webImageStreamServer == None:
        WebImageStreamService.webImageStreamServer = WebImageStreamService()
    
    return WebImageStreamService.webImageStreamServer

def singletonEvent():
    if WebImageEventService.webImageEventServer == None:
        WebImageEventService.webImageEventServer = WebImageEventService()
    
    return WebImageEventService.webImageEventServer

def runWebImageServer():
   
    webImgStreamServer = singletonStream()
    webImgStreamEvent = singletonEvent()

    addr = IPAddressConfig("web_server", "insecure_port").getIP()

    server = grpc.server(futures.ThreadPoolExecutor(max_workers=4), options=[
        ('grpc.max_send_message_length', 50 * 1024 * 1024),
        ('grpc.max_receive_message_length', 50 * 1024 * 1024),
    ])
    
    WebImageService_pb2_grpc.add_WebImageStreamServiceServicer_to_server(webImgStreamServer, server)
    WebImageService_pb2_grpc.add_WebImageEventServiceServicer_to_server(webImgStreamEvent, server)
    
    server.add_insecure_port(addr)
    server.start()
    print(f"WebImage SERVER STARTED at {addr}")
    server.wait_for_termination()
