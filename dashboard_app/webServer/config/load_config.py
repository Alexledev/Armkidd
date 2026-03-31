import yaml

class ConfigLoader:

    pathName = None
    cfgFile = None

    def __init__(self, root="", dir="", path="config/config.yaml"):
        self.path = path
        self.root = root
        self.dir = dir
        self.cfgFile = ConfigLoader.initFileObj(path)
        
    @staticmethod
    def initFileObj(path):
        if (ConfigLoader.pathName == path):
            return ConfigLoader.cfgFile
        
        ConfigLoader.pathName = path

        with open(ConfigLoader.pathName, "r") as f:
            ConfigLoader.cfgFile = yaml.safe_load(f)

        return ConfigLoader.cfgFile

    def get(self, name):
        if (self.dir == ""):
            return self.cfgFile[self.root][name]

        return self.cfgFile[self.root][self.dir][name]

    def set(self, name, value):
        self.cfgFile.setdefault(self.root, {}).setdefault(self.dir, {})[name] = value

    def save(self):
        with open(self.path, "w") as f:
            yaml.safe_dump(self.cfgFile, f, sort_keys=False)

    def setAndSave(self, name, value):
        self.set(name, value)
        self.save()
    