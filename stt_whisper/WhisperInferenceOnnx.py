import onnxruntime as ort
import numpy as np
import torch

import whisper

from whisper.tokenizer import LANGUAGES

so = ort.SessionOptions()
so.log_severity_level = 4

print(ort.get_available_providers())
print(np.__version__)

class WhisperInference:
    def __init__(self, encoderOnnx, decoderOnnx):      

        self.initialise(encoderOnnx, decoderOnnx)

        # print("NumPy:", np.__version__)
        # print("Whisper:", whisper.__version__)

        print("Whisper ONNX Inference started\n")

    def initialise(self, encoderOnnx, decoderOnnx):
        self.encoderSession = ort.InferenceSession(encoderOnnx, providers=["CUDAExecutionProvider"])

        self.decoderSession = ort.InferenceSession(decoderOnnx, providers=["CUDAExecutionProvider"])

        self.tokenizer = whisper.tokenizer.get_tokenizer(multilingual=False)

        # Start/End tokens
        self.sot = self.tokenizer.sot 
        self.eot = self.tokenizer.eot
        self.notimestamps = self.tokenizer.encoding.encode_single_token("<|notimestamps|>")


        print(">> Whisper ONNX enc/dec created <<\n")

    def infer(self, audio):

        try:

            if (self.encoderSession == None or self.decoderSession == None or self.tokenizer == None):
                return

            convAudio = whisper.pad_or_trim(audio)

            mel = whisper.log_mel_spectrogram(convAudio)
            mel = mel.unsqueeze(0).to(dtype=torch.float32)
            mel = mel.numpy()

        
            languageTokenIds = []
            self.tokenizeLanguages(languageTokenIds)

            audioFeatures = self.runEncoder(mel)

            logits = self.runDecoder(audioFeatures)

            text = self.processTokensSmall(audioFeatures, languageTokenIds, logits)

            return text
        
        except Exception as e:
            print("Error in ONNX Whisper Infer:", e)

    def destroy(self): 
        self.encoderSession = None
        self.decoderSession = None
        self.tokenizer = None

    def processTokens(self, audioFeatures, languageTokenIds, logits):

        print("aud shape:", audioFeatures.shape)


        lang_token = max(languageTokenIds, key=lambda t: logits[0, 0, t])
        
        task = self.tokenizer.encoding.encode_single_token("<|transcribe|>")

        tokens = np.array([[self.sot, lang_token, task]], dtype=np.int64)
        # tokens = np.array([[self.sot, self.lang_token, self.task_token]], dtype=np.int64)

        for _ in range(448):
            logits = self.decoderSession.run(["logits"], {"tokens": tokens, "audio_features": audioFeatures})[0]
            next_token = int(np.argmax(logits[0,-1]))
            if next_token == self.tokenizer.eot:
                break

            # tokens = np.concatenate([tokens, [[next_token]]], axis=1)
            tokens = np.zeros((1, 448), dtype=np.int64)
            tokens[0,0] = self.sot
            tokens[0,1] = self.notimestamps

            length = 2

            for _ in range(446):
                logits = self.decoderSession.run(["logits"], {"tokens": tokens[:, :length], "audio_features": audioFeatures})[0]

                next_token = int(np.argmax(logits[0, -1]))
                if next_token == self.eot:
                    break

                tokens[0, length] = next_token
                length += 1


        filtered = [t for t in tokens[0].tolist() if t < self.eot]

        return self.tokenizer.decode(filtered)

    def processTokensSmall(self, audioFeatures, languageTokenIds, logits):
        tokens = np.array([[self.sot, self.notimestamps]], dtype=np.int64)

        for _ in range(448):
            logits = self.decoderSession.run(
                ["logits"],
                {"tokens": tokens, "audio_features": audioFeatures}
            )[0]

            next_token = int(np.argmax(logits[0, -1]))
            if next_token == self.eot:
                break

            tokens = np.concatenate([tokens, [[next_token]]], axis=1)

        # return self.tokenizer.decode(tokens[0].tolist()[1:])
        special_ids = set(self.tokenizer.special_tokens.values())
        decoded_tokens = [t for t in tokens[0] if t not in special_ids]

        return self.tokenizer.decode(decoded_tokens)


    def tokenizeLanguages(self, languageTokenIds):

        for token, tok_id in self.tokenizer.special_tokens.items():
            if token.startswith("<|") and token.endswith("|>"):
                code = token[2:-2]
                if code in LANGUAGES:
                    languageTokenIds.append(tok_id)

    def runEncoder(self, mel):
        audioFeatures = self.encoderSession.run(["audio_features"], {"mel": mel})[0]

        return audioFeatures
    
    def runDecoder(self, audioFeatures):
        langInit = np.array([[self.sot]], dtype=np.int64)

        logits = self.decoderSession.run(["logits"],{"tokens": langInit, "audio_features": audioFeatures})[0]

        return logits

