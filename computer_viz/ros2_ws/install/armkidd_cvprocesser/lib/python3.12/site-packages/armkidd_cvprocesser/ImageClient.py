import grpc
import ImageServiceStream_pb2
import ImageServiceStream_pb2_grpc

class ImageClient:
    def __init__(self, address):
        self.address = address      
        self._recvCallback = None

        try:
            self.channel = grpc.aio.insecure_channel(self.address)
            self.stub = ImageServiceStream_pb2_grpc.ImageStreamServiceStub(self.channel)
        except Exception as e:
            print("Smth went wrong in armkidd_cvprocesser -> ImageClient: Couldn't connect to server")

    async def send(self, image):
        async def gen():
            yield ImageServiceStream_pb2.ImagePromptMessage(image=image)

        try:
            await self.stub.ClientSend(gen())
        except Exception as e:
            print("Send failed:", e)
