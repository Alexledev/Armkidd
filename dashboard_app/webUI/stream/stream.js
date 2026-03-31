import { WebSocketClientStreaming, WebSocketClientDetection, WebSocketClientChatCommands } from "/webUI/webSocketClient.js"
import { SpinnerControl } from "/webUI/UIControl.js"

export class CameraStream {
    constructor(imgObj, imgObj2, snapshotBtn) 
    {
        console.log("CameraStream created")

        if (!imgObj)
            throw Error("missing imgObj")

        if (!snapshotBtn)
            throw Error("missing snapshotBtn")

        this.imgObj = imgObj;
        this.streamWS = new WebSocketClientStreaming();
        this.streamWS.updateIMG = (srcImg) => { this.imgObj.src = srcImg; }

        this.imgObj2 = imgObj2
        this.streamWS2 = new WebSocketClientDetection();
        this.streamWS2.updateIMG = (srcImg) => { this.imgObj2.src = srcImg; }

        this.snapshotBtn = snapshotBtn
        this.snapshotBtn.onclick = this.streamWS.saveImg.bind(this.streamWS);
    }
}

export class ChatCommands {
    constructor(chVoice, chChat, readyInput, commandInput, sendBtn)
    {
        this.cmdWS = new WebSocketClientChatCommands();
        this.cmdWS.onReceiveMessage = this.onReceiveMessage.bind(this);

        this.currentType = "voice";

        this.chVoice = chVoice;
        this.chVoice.onclick = () => {this.setChatType(this.chVoice.value)};

        this.chChat = chChat;
        this.chChat.onclick = () => {this.setChatType(this.chChat.value)};

        this.readyInput = readyInput
        this.commandInput = commandInput
        this.commandInput.disabled = true
        this.sendBtn = sendBtn
        this.sendBtn.onclick = () => {this.sendMsg()}

        this.spinner = new SpinnerControl(this.sendBtn)

        this.readyInput.classList.add("highlight");
        this.isReady = false
    }

    setChatType(value)
    {
        if (value == this.currentType)
            return

        this.sendBtn.disabled = this.chVoice.checked

        console.log(value);
        this.cmdWS.setChatType(value);

        this.currentType = value;
    }

    sendMsg()
    {
        // console.log(`inputs: ${this.readyInput.value} && ${this.commandInput.value}`);

        if (this.isReady == false)
        {
            this.cmdWS.sendChatMsg(this.readyInput.value, "ready");
            this.enableInput(this.readyInput, false);
        }
        else
        {
            this.cmdWS.sendChatMsg(this.commandInput.value, "action");
            this.enableInput(this.commandInput, false);
        }           

        this.spinner.setSpin("Waiting ...")
    }

    enableInput(element, enable)
    {
        if (enable)
        {
            element.disabled = false
            element.classList.add("highlight");
        }
        else
        {
            element.disabled = true
            element.classList.remove("highlight");
        }
    } 

    onInit(jsonOBJ)
    {
        this.currentType = jsonOBJ.value;

        this.chVoice.checked = (this.currentType === "voice");
        this.chChat.checked  = (this.currentType === "chat");
        this.sendBtn.disabled = this.chVoice.checked

        console.log(`Recv ${jsonOBJ.value}`);
    }

    readyUp()
    {
        this.isReady = true
        this.enableInput(this.commandInput, true);

        console.log("Ready Up")

        this.spinner.stopSpin()
    }

    complete()
    {
        this.isReady = false
        this.enableInput(this.readyInput, true);

        console.log("Task Complete")

        this.spinner.stopSpin()
    }

    onReceiveMessage(jsonOBJ)
    {
        console.log(jsonOBJ)

        if (!jsonOBJ.status)
            return

        if (jsonOBJ.status=="init")
        {
            this.onInit(jsonOBJ);
        }      
        else if (jsonOBJ.status=="ready")
        {
            this.readyUp()
        }      
        else if (jsonOBJ.status=="complete")
        {
            this.complete()
        }
    }
}