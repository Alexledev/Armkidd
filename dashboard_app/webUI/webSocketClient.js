
export class WebSocketClientStreaming {
    constructor() {
        this.websocket = new WebSocket((location.protocol === "https:" ? "wss://" : "ws://") + location.host + "/ws/streaming");
        this.websocket.binaryType = "arraybuffer";

        this.imgBuffer = null;
        this.srcImg = null;

        this.websocket.addEventListener("message", async (e) => {

            this.imgBuffer = new Blob([e.data], { type: "image/webp" });
            this.srcImg = URL.createObjectURL(this.imgBuffer)

            if (this.srcImg)
                this.updateIMG(this.srcImg);       
           
        });

        window.addEventListener("beforeunload", () => {
            if (this.websocket?.readyState === WebSocket.OPEN) {
                console.log("closing /ws/streaming socket")
                this.websocket.close(1000);
            }
        });
    }

    updateIMG = (srcImg) => {};

    saveImg () 
    {
        const filename = `frame_${Date.now()}.jpg`;

        const a = document.createElement("a");
        a.href = this.srcImg;
        a.download = filename;   // filename

        document.body.appendChild(a);
        a.click();

        document.body.removeChild(a);
        URL.revokeObjectURL(this.srcImg);
    }
}

export class WebSocketClientDetection {
    constructor() {
        this.websocket = new WebSocket((location.protocol === "https:" ? "wss://" : "ws://") + location.host + "/ws/detection");
        this.websocket.binaryType = "arraybuffer";

        this.imgBuffer = null;
        this.srcImg = null;

        this.websocket.addEventListener("message", async (e) => {

            this.imgBuffer = new Blob([e.data], { type: "image/webp" });
            this.srcImg = URL.createObjectURL(this.imgBuffer)

            if (this.srcImg)
                this.updateIMG(this.srcImg);       
           
        });

        window.addEventListener("beforeunload", () => {
            if (this.websocket?.readyState === WebSocket.OPEN) {
                console.log("closing /ws/streaming socket")
                this.websocket.close(1000);
            }
        });
    }

    updateIMG = (srcImg) => {};

    saveImg () 
    {
        const filename = `frame_${Date.now()}.jpg`;

        const a = document.createElement("a");
        a.href = this.srcImg;
        a.download = filename;   // filename

        document.body.appendChild(a);
        a.click();

        document.body.removeChild(a);
        URL.revokeObjectURL(this.srcImg);
    }
}
export class WebSocketClientChatCommands {
    constructor() {
        this.websocket = new WebSocket(`${location.protocol === "https:" ? "wss://" : "ws://"}${location.host}/ws/commands`);

        this.websocket.addEventListener("message", async (e) => {
            const m = JSON.parse(e.data);

            this.onReceiveMessage(m);
        });

        window.addEventListener("beforeunload", () => {
            if (this.websocket?.readyState === WebSocket.OPEN) {
                console.log("closing /ws/chat socket")
                this.websocket.close(1000);
            }
        });

    }

    onReceiveMessage = (jsonOBJ) => {};

    setChatType (ctype)
    {
        this.websocket.send(JSON.stringify({ "name": "setChatType", "chatType": ctype }));
    }   
    
    sendChatMsg (msg, msgType) 
    {
        this.websocket.send(JSON.stringify({ "name": "sendChatMsg", "message": msg, "msgType": msgType}));
    }
}


// export class WebSocketClientControl {
//     constructor() {
//         this.websocket = new WebSocket(`${location.protocol === "https:" ? "wss://" : "ws://"}${location.host}/ws/control`);

//         this.websocket.addEventListener("message", async (e) => {
//             const m = JSON.parse(e.data);
           
//             if (m.value === "saved_map") {
//                 this.onMapSaved();
//             }

//             this.onReceiveMessage(m);
//         });

//         window.addEventListener("beforeunload", () => {
//             if (this.websocket?.readyState === WebSocket.OPEN) {
//                 console.log("closing /ws/control socket")
//                 this.websocket.close(1000);
//             }
//         });

//     }

//     onReceiveMessage = (message) => {};

//     onMapSaved = () => {};

//     requestReset () {
//         this.websocket.send(JSON.stringify({ name: "reset", value: 0})); 
//     }

//     saveMap (nameMap) {
//         this.websocket.send(JSON.stringify({ name: "save_map", value: nameMap}));
//     }

//     sendDpadInput (direction, speed)
//     {
//         this.websocket.send(JSON.stringify({ name: direction, value: speed }));
//     }
// }


// export class WebSocketClientMapping {
//     constructor() {
//         this.websocket = new WebSocket((location.protocol === "https:" ? "wss://" : "ws://") + location.host + "/ws/mapping");
//         this.websocket.binaryType = "arraybuffer";

//         this.imgBuffer = null;
//         this.pose = [];
//         this.points = [];

//         this.websocket.addEventListener("message", async (e) => {
//             let buf = new Uint8Array(e.data);
//             const type = buf[0];
//             const payload = buf.slice(1); // First byte is identifier

//             if (type === 0x01){
//                 this.imgBuffer = new Blob([payload], { type: "image/webp" });
//             }
//             else if (type === 0x02){ 
//                 const floats = new Float32Array(payload.buffer);
//                 this.pose = floats.slice(0, 3);
//                 this.points = floats.slice(3);  
//             }

//             if (this.imgBuffer)
//                 await this.updateSlamIMG(this.imgBuffer, this.pose, this.points);       
           
//         });

//         window.addEventListener("beforeunload", () => {
//             if (this.websocket?.readyState === WebSocket.OPEN) {
//                 console.log("closing /ws/mapping socket")
//                 this.websocket.close(1000);
//             }
//         });
//     }

//     updateSlamIMG = async (imgBuffer, pose, points) => {};
// }


// export class WebSocketClientNavMap {
//     constructor() {
//         this.websocket = new WebSocket((location.protocol === "https:" ? "wss://" : "ws://") + location.host + "/ws/navmap");   
//         this.websocket.binaryType = "arraybuffer";

//         this.websocket.addEventListener("message", async (e) => {

//             const data = e.data;
//             if ( data instanceof ArrayBuffer) 
//             {
//                 // const buf = await data.arrayBuffer();
//                 const f = new Float32Array(data);

//                 const P = 3;            // MUST be known
//                 const pose = f.slice(0, P);
//                 const points = f.slice(P); // [x0,y0,x1,y1,...]

//                 this.dataPosAndPointcloud(pose, points);
//             }
//             else if (typeof data === "string") 
//             {                          
//                 const json = JSON.parse(data);

//                 if (json["status"] === "setgoal" && json["value"] instanceof Array)
//                 {
//                     console.log(`Flag returned ${json["value"]}`)
//                     this.setGoalMarker(json["value"][0], json["value"][1])
//                 }

//                 this.onMessageString(json);                
//             }
//             else
//             {
//                 throw new TypeError("data must be a string/json");
//             }
//         });   

//         window.addEventListener("beforeunload", () => {
//             if (this.websocket?.readyState === WebSocket.OPEN) {
//                 console.log("closing /ws/navmap socket")
//                 this.websocket.close(1000);
//             }
//         });
//     }

//     dataPosAndPointcloud = (pose, points) => {};
//     dataStartup = (data) => {};
//     checkGoal = (data) => {};
//     reloadMap = () => {};
//     startFinish = () => {};
//     setGoalMarker = (x, y) => {};

//     static validatePosxPclData(data) {
//         return Array.isArray(data) && data.length === 2 && Array.isArray(data[1]);
//     }

//     onMessageString(json) {
//         if (json["status"] == "startup")
//         {      
//             this.dataStartup(json["value"]);  
//         }
//         else if (json["status"] == "check")
//         {
//             this.checkGoal(json["value"]);
//         }
//         else if (json["status"] == "reload")
//         {
//             this.reloadMap();
//         }
//         else if (json["status"] == "ok" && json["value"] == "ready")
//         {
//             this.startFinish();
//         }
//     }

//     setGoalOnMap (coordsData) 
//     {
//         this.websocket.send(JSON.stringify({ name: "map_coords", value: coordsData }));
//     }

//     requestStart ()
//     {
//         this.websocket.send(JSON.stringify({ name: "start_bot_pos"}));
//     }

//     setMap(mapName)
//     {
//         this.websocket.send(JSON.stringify({ name: "set_map", value: mapName}));
//     }
// }