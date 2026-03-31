import yaml

class ConfigLoader:
    def __init__(self, root="", dir="", path="../shared/config.yaml"):
        self.path = path       
        self.root = root
        self.dir = dir

        with open(self.path, "r") as f:
            self.cfg = yaml.safe_load(f)
    
    def get(self, name):
        if (self.dir == ""):
            return self.cfg[self.root][name]

        return self.cfg[self.root][self.dir][name]

    def set(self, name, value):
        self.cfg.setdefault(self.root, {}).setdefault(self.dir, {})[name] = value

    def save(self):
        with open(self.path, "w") as f:
            yaml.safe_dump(self.cfg, f, sort_keys=False)

    def setAndSave(self, name, value):
        self.set(name, value)
        self.save()
    