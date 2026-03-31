from config.load_config import ConfigLoader

from urdfCamEditor import UrdfCamEditor

class ArmTargetOffsetConfig(ConfigLoader):
    def __init__(self, path="config/config.yaml"):
        super().__init__("runtime_ros2", "target_offsets", path)

    def getOffset(self):
        xOffset = self.get("x_offset")
        yOffset = self.get("y_offset")
        zOffset = self.get("z_offset")

        return xOffset, yOffset, zOffset 
    
    def setOffset(self, x, y, z, d):
        self.set("x_offset", x)
        self.set("y_offset", y)
        self.set("z_offset", z)
        self.set("cam_angle", d)
        self.save()

class ArmRuntimeConfig(ConfigLoader):
    def __init__(self, path="config/config.yaml"):
        super().__init__("runtime_ros2", "arm_settings", path)

    def getSettings(self):
        reachForward = self.get("reach_forward")
        raiseDistance = self.get("raise_distance")
        gripTimeout = self.get("grip_timeout")

        return reachForward, raiseDistance, gripTimeout

    def setSettings(self, reachFwd, raiseDist, gripTout):
        self.set("reach_forward", reachFwd)
        self.set("raise_distance", raiseDist)
        self.set("grip_timeout", gripTout)
        self.save()

class STTConfig(ConfigLoader):
    def __init__(self, path="config/config.yaml"):
        super().__init__("stt_server", "infer_settings", path)

    def getInfo(self):
        procTime = self.get("time_to_proc")
        talkDuration = self.get("max_talk_duration")
        confirmThresh = self.get("confirm_thresh")
        actionList = self.get("action_list")
        confirmComments = self.get("confirm_comments")

        return procTime, talkDuration, confirmThresh, actionList, confirmComments

    def setInfo(self, inputTimeProc, inputTalkDuration, inputConfirmThresh, inputActionList, inputConfirmComments):
        self.set("time_to_proc", inputTimeProc)
        self.set("max_talk_duration", inputTalkDuration)
        self.set("confirm_thresh", inputConfirmThresh)
        self.set("action_list", inputActionList)
        self.set("confirm_comments", inputConfirmComments)
        self.save()


class SettingsHelper:
    def __init__(self):       

        self.targetConf = ArmTargetOffsetConfig()
        self.armSettingsConf = ArmRuntimeConfig()
        self.camUrdfEditor = UrdfCamEditor()

        self.whisperConf = STTConfig()

    def loadSettings(self):

        xOffset, yOffset, zOffset = self.targetConf.getOffset()        

        forwardReach, raiseDistance, gripperTimeout = self.armSettingsConf.getSettings()

        procTime, talkDuration, confirmThresh, actionList, confirmComments = self.whisperConf.getInfo()

        camXOffset, camYOffset, camZOffset, cameraAngle = self.camUrdfEditor.getCameraPose()

        return {'XOffset': xOffset, 'YOffset': yOffset, 'ZOffset': zOffset, 
                'inputForwardReach': forwardReach, 'inputRaiseDistance': raiseDistance, 'inputGripperTimeout': gripperTimeout, 
                'inputTimeProc': procTime, 'inputTalkDuration': talkDuration, 'inputConfirmThresh': confirmThresh, "inputReadyPhrases": actionList, "inputConfirmComments":confirmComments,
                'inputCameraAngle': cameraAngle, 'inputCamXOffset': camXOffset, 'inputCamYOffset': camYOffset, 'inputCamZOffset': camZOffset}

    def saveSettings(self, data: dict):

        xOffset = float(data["XOffset"]) 
        yOffset = float(data["YOffset"]) 
        zOffset = float(data["ZOffset"]) 

        inputForwardReach = float(data["inputForwardReach"])
        inputRaiseDistance = float(data["inputRaiseDistance"])
        inputGripperTimeout = float(data["inputGripperTimeout"])

        inputTimeProc = float(data["inputTimeProc"]) 
        inputTalkDuration = float(data["inputTalkDuration"]) 
        inputConfirmThresh = float(data["inputConfirmThresh"]) 
        inputActionList = data["inputReadyPhrases"]
        inputConfirmComments = data["inputConfirmComments"]

        cameraAngle = float(data["inputCameraAngle"])
        camXOffset  = float(data["inputCamXOffset"])
        camYOffset  = float(data["inputCamYOffset"])
        camZOffset  = float(data["inputCamZOffset"])

        self.targetConf.setOffset(xOffset, yOffset, zOffset, cameraAngle)
        self.armSettingsConf.setSettings(inputForwardReach, inputRaiseDistance, inputGripperTimeout)
        self.whisperConf.setInfo(inputTimeProc, inputTalkDuration, inputConfirmThresh, inputActionList, inputConfirmComments)
        
        if self.camUrdfEditor.setCameraPose(camXOffset, camYOffset, camZOffset, cameraAngle):
            self.camUrdfEditor.update()

        return {"status": "saved", "value": 1}
        