from inputClient import InputClient
from stt_client.STTClient import STTClient
from webChat_client.WebChatClient import WebChatClient
from ipAddrConfig import IPAddressConfig


class InputClientFactory:
    currentInputClient : InputClient = None
    currentType = None

    @staticmethod
    def createInputClient(_type):
        InputClientFactory.currentType = _type

        if _type is STTClient:
            sttConf = IPAddressConfig("stt_server", "insecure_port").getIP()
            InputClientFactory.currentInputClient = STTClient(sttConf)
            return InputClientFactory.currentInputClient
        
        if _type is WebChatClient:
            webChatAddr = IPAddressConfig("web_chat_server", "insecure_port").getIP()
            InputClientFactory.currentInputClient = WebChatClient(webChatAddr)
            return InputClientFactory.currentInputClient
        
        raise Exception(f"InputClientFactory: No matching type of {_type}.")
    
    @staticmethod
    async def runInputClient():
        if InputClientFactory.currentInputClient is None:
            raise Exception("InputClientFactory: missing currentInputClient in runInputClient")

        try:
            print(f"run {type(InputClientFactory.currentInputClient)}")
            await InputClientFactory.currentInputClient.runAsync()
        except:
            await InputClientFactory.currentInputClient.close()

    @staticmethod
    async def stopClient():
        if InputClientFactory.currentInputClient is None:
            return
        
        await InputClientFactory.currentInputClient.close()
        InputClientFactory.currentInputClient = None

        print("currentInputClient closed")
