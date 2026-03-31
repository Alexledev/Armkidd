import sounddevice as sd
from loadConfig import ConfigLoader

def choose_pipewire_device():
    devices = sd.query_devices()
    print(f"Available Devices: {devices}")

    for idx, dev in enumerate(devices):
        if dev["max_input_channels"] > 0 and "pipewire" in dev["name"].lower():
            print("Using PipeWire device:", dev["name"])
            return idx
        
    cfgl = ConfigLoader("stt_server", "devices")
    id = cfgl.get("mic_index")
    return id