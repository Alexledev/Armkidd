import asyncio
# from WhisperInference import WhisperInference
import sounddevice as sd
import soundfile as sf
import queue
import sys
import numpy as np
import io
import micfinder

class SoundDev:
    def __init__(self):
              
        self.device =  micfinder.choose_pipewire_device()
        self.SAMPLE_RATE = 16000
        self.CHANNELS = 1
        self.BLOCK_SIZE = 1024
        self.DTYPE = "float32"

        self.SILENCE_THRESHOLD = 0.1
        self.MAX_SILENCE_SEC = 2.0

        self.queue = queue.Queue()

        self.speech_started = False
        self.audio_buffer = []
        self.silence_time = 0.0

        self.paused = False

        self.running = False

        self.onReceiveCallback = None
        # self.afterFinishCallback = None
    
    def audio_callback(self, indata, frames, time_info, status):
        if (self.paused):
            return

        if status:
            print(status, file=sys.stderr)
        self.queue.put(indata.copy())

    def rms(self, x):
        return np.sqrt(np.mean(x ** 2))
    
    def clear_queue(self):
        while not self.queue.empty():
            self.queue.get_nowait()
            
    def reset_state(self):
        self.audio_buffer = []
        self.silence_time = 0.0
        self.speech_started = False        

    def pause(self):
        print("Paused")
        self.paused = True
        self.reset_state()
        self.clear_queue()

    def resume(self):
        print("Resume")
        self.paused = False


    def listen(self):
      
        if (self.running == False):
            return

        print("Recording... (auto-stop after 2s silence)")
        
        block_duration = self.BLOCK_SIZE / self.SAMPLE_RATE

        try:
            with sd.InputStream(device=self.device, samplerate=self.SAMPLE_RATE,channels=self.CHANNELS,
                                blocksize=self.BLOCK_SIZE,dtype=self.DTYPE,callback=self.audio_callback,)  as stream:          
                while self.running:
                    block = self.queue.get()
                    block = block[:, 0]  # mono

                    energy = self.rms(block)

                    if energy >= self.SILENCE_THRESHOLD:
                        self.speech_started = True
                        self.silence_time = 0.0
                        self.audio_buffer.append(block)

                    elif self.speech_started:
                        self.silence_time += block_duration
                        self.audio_buffer.append(block)

                        if self.silence_time >= self.MAX_SILENCE_SEC:
                            stream.stop()
                            self.clear_queue()

                            audio = np.concatenate(self.audio_buffer).astype(np.float32)

                            # extra safety: skip ultra-short audio
                            if len(audio) > self.SAMPLE_RATE * 0.3:
                                self.onReceiveCallback(audio)
                                
                            self.reset_state()

                            stream.start()
        
        except Exception as e:
            print(f"Smth went REALLY wrong {e}")
       
       
          