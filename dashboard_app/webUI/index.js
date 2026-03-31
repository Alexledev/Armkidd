import { WebAPIClient } from "./webAPIClient.js";
import { SpinnerControl } from "./UIControl.js"

export class MainDashboard {
    constructor () {
        this.webClient = new WebAPIClient();

        this.fieldset = document.getElementById("arm_container_fieldset");

        this.initOffsetInputs();

        this.initArmInputs();
        
        this.initWhisperInputs();

        this.initCameraInputs();

        this.btnSave = document.getElementById("save");
        this.saveSpinner = new SpinnerControl(this.btnSave);
        this.btnSave.onclick = this.save.bind(this);
    }

    initOffsetInputs() 
    {
        this.XOffset = document.getElementById("XOffset");
        this.XOffsetLabel = document.getElementById("XOffsetLabel");
        this.YOffset = document.getElementById("YOffset");
        this.YOffsetLabel = document.getElementById("YOffsetLabel");
        this.ZOffset = document.getElementById("ZOffset");
        this.ZOffsetLabel = document.getElementById("ZOffsetLabel");

        this.XOffset.oninput = this.onchangeOffset.bind(this);
        this.YOffset.oninput = this.onchangeOffset.bind(this);
        this.ZOffset.oninput = this.onchangeOffset.bind(this);

        this.currentXOffset = 0
        this.currentYOffset = 0
        this.currentZOffset = 0
    }

    initArmInputs() 
    {
        this.inputForwardReach = document.getElementById("inputForwardReach");
        this.inputRaiseDistance = document.getElementById("inputRaiseDist");
        this.inputGripperTimeout = document.getElementById("inputGripTimeout");

        this.inputForwardReach.oninput = this.onchangeArmSettings.bind(this);
        this.inputRaiseDistance.oninput = this.onchangeArmSettings.bind(this);
        this.inputGripperTimeout.oninput = this.onchangeArmSettings.bind(this);

        this.currentForwardReach = 0
        this.currentRaiseDistance = 0
        this.currentGripperTimeout = 0
    }

    initWhisperInputs() 
    {
        this.inputTimeProc = document.getElementById("inputTimeProc");
        this.inputTalkDuration = document.getElementById("inputTalkDuration");
        this.inputConfirmThresh = document.getElementById("inputConfirmThresh");
        this.inputReadyPhrases = document.getElementById("inputReadyPhrases");
        this.inputConfirmComments = document.getElementById("inputConfirmComments");

        this.inputTimeProc.oninput = this.onchangeWhisper.bind(this);
        this.inputTalkDuration.oninput = this.onchangeWhisper.bind(this);
        this.inputConfirmThresh.oninput = this.onchangeWhisper.bind(this);
        this.inputReadyPhrases.oninput = this.onchangeWhisper.bind(this);
        this.inputConfirmComments.oninput = this.onchangeWhisper.bind(this);

        this.currentInputTimeProc = 0
        this.currentInputTalkDuration = 0
        this.currentInputConfirmThresh = 0
        this.currentReadyPhrases = ""
        this.currentConfirmComments = ""
    }

    initCameraInputs() 
    {
        this.inputCameraAngle = document.getElementById("inputCameraAngle");
        this.cameraAngleLabel = document.getElementById("cameraAngleLabel");
        this.inputCamXOffset = document.getElementById("inputCamXOffset");
        this.inputCamYOffset = document.getElementById("inputCamYOffset");
        this.inputCamZOffset = document.getElementById("inputCamZOffset");

        this.inputCameraAngle.oninput = this.onchangeCamera.bind(this);
        this.inputCamXOffset.oninput = this.onchangeCamera.bind(this);
        this.inputCamYOffset.oninput = this.onchangeCamera.bind(this);
        this.inputCamZOffset.oninput = this.onchangeCamera.bind(this);

        this.currentCameraAngle = 0
        this.currentCamXOffset = 0
        this.currentCamYOffset = 0
        this.currentCamZOffset = 0
        
    }

    async onInit() {
        let data = await this.webClient.loadSettings();
        console.log(data);

        this.XOffset.value = data.XOffset;
        this.YOffset.value = data.YOffset;
        this.ZOffset.value = data.ZOffset;
        this.onchangeOffset();

        this.inputForwardReach.value = data.inputForwardReach;
        this.inputRaiseDistance.value = data.inputRaiseDistance;
        this.inputGripperTimeout.value = data.inputGripperTimeout;
        this.onchangeArmSettings();

        this.inputTimeProc.value = data.inputTimeProc;
        this.inputTalkDuration.value = data.inputTalkDuration;
        this.inputConfirmThresh.value = data.inputConfirmThresh;
        this.inputReadyPhrases.value = data.inputReadyPhrases.join(";");
        this.inputConfirmComments.value = data.inputConfirmComments.join(";");
        this.onchangeWhisper();

        this.inputCameraAngle.value = data.inputCameraAngle;
        this.inputCamXOffset.value = data.inputCamXOffset;
        this.inputCamYOffset.value = data.inputCamYOffset;
        this.inputCamZOffset.value = data.inputCamZOffset;
        this.onchangeCamera();

        this.fieldset.disabled = false;        
    }

    onchangeOffset() 
    {
        this.currentXOffset = parseFloat(this.XOffset.value);
        this.XOffsetLabel.textContent = this.currentXOffset.toFixed(2);

        this.currentYOffset = parseFloat(this.YOffset.value);
        this.YOffsetLabel.textContent = this.currentYOffset.toFixed(2);

        this.currentZOffset = parseFloat(this.ZOffset.value);
        this.ZOffsetLabel.textContent = this.currentZOffset.toFixed(2);
    }

    onchangeArmSettings()
    {
        this.currentForwardReach = parseFloat(this.inputForwardReach.value)
        this.currentRaiseDistance = parseFloat(this.inputRaiseDistance.value)
        this.currentGripperTimeout = parseFloat(this.inputGripperTimeout.value)
    }

    onchangeWhisper()
    {
        this.currentInputTimeProc = parseFloat(this.inputTimeProc.value);
        this.currentInputTalkDuration = parseFloat(this.inputTalkDuration.value);
        this.currentInputConfirmThresh = parseFloat(this.inputConfirmThresh.value);
        this.currentReadyPhrases = this.inputReadyPhrases.value
        this.currentConfirmComments = this.inputConfirmComments.value
    } 

    onchangeCamera()
    {
        this.currentCameraAngle = parseFloat(this.inputCameraAngle.value);
        this.cameraAngleLabel.textContent = this.currentCameraAngle.toFixed(2);

        this.currentCamXOffset = parseFloat(this.inputCamXOffset.value);
        this.currentCamYOffset = parseFloat(this.inputCamYOffset.value);
        this.currentCamZOffset = parseFloat(this.inputCamZOffset.value);
    }

    async save() {

        this.fieldset.disabled = true;

        const obj = {
            XOffset: this.currentXOffset,
            YOffset: this.currentYOffset,
            ZOffset: this.currentZOffset,

            inputForwardReach: this.currentForwardReach,
            inputRaiseDistance: this.currentRaiseDistance,
            inputGripperTimeout: this.currentGripperTimeout,

            inputTimeProc: this.currentInputTimeProc,
            inputTalkDuration: this.currentInputTalkDuration,
            inputConfirmThresh: this.currentInputConfirmThresh,
            inputReadyPhrases: this.currentReadyPhrases.split(";"),
            inputConfirmComments: this.currentConfirmComments.split(";"),
            
            inputCameraAngle : this.currentCameraAngle,
            inputCamXOffset : this.currentCamXOffset,
            inputCamYOffset : this.currentCamYOffset,
            inputCamZOffset : this.currentCamZOffset,
        };

        this.saveSpinner.setSpin("Saving...");

        try 
        {
            await this.webClient.saveSettings(obj);
        } 
        finally 
        {
            // restore button
            this.fieldset.disabled = false;
            this.saveSpinner.stopSpin();
        }
    }
}


window.dashboard = new MainDashboard();
await window.dashboard.onInit();
