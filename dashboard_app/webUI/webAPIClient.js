
export class WebAPIClient {
    constructor() {
        
    }

    isOK(res, msg, displayPopup=false) {
        if (!res.ok) {
            if (displayPopup === true){
                alert(msg);
            }
            
            throw new Error(msg);        
        }
    }

    async loadSettings() {
        const res = await fetch("/api/main/load");

        this.isOK(res, "Couldn't load settings");

        const data = await res.json();
        return data;
    }

    async saveSettings(dataSettings) {
        const res = await fetch("/api/main/save", {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify(dataSettings) 
        });
        this.isOK(res, "Save failed");

        const data = await res.json();
    }
}
