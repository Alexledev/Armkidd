from fastapi import APIRouter, HTTPException
from fastapi.params import Body
from settingsHelper import SettingsHelper

class WebAPIServer:
    def __init__(self):
        self.router = APIRouter()

        self.settingsHelper = SettingsHelper()

        self.registerRoutes()

    def registerRoutes(self):
        
        self.router.add_api_route("/api/main/load", self.loadSettings, methods=["GET"])
        self.router.add_api_route("/api/main/save", self.saveSettings, methods=["POST"])

    def loadSettings(self):
        return self.settingsHelper.loadSettings()

    def saveSettings(self, data: dict = Body(...)):
        try:
            self.settingsHelper.saveSettings(data)
        except Exception as e:
            print("Something went wrong while saving the settings:", data, " -----> ", str(e))
            raise HTTPException(status_code=400, detail=str(e))
    
        
        