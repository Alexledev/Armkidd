from loadConfig import ConfigLoader

class IPAddressConfig(ConfigLoader):
    def __init__(self, root, dir, path="../shared/config.yaml"):
        super().__init__(root, dir, path)

    def getIP(self):
        addr, port = self.getIPPort()
        
        return f"{addr}:{port}"


    def getIPPort(self):
        addr = self.get("ip")
        port = self.get("port")

        self.verify(addr, port)
        
        return addr, port
    
    def verify(self, addr, port):
        if not (isinstance(addr, str) and addr.strip() and isinstance(port, int)):
            raise Exception("Invalid configuration for ip or port")
        