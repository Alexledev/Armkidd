import json

from difflib import SequenceMatcher

class Utilities:

    @staticmethod 
    def extractLastJson(text: str) -> str:
        start = text.rfind("{")
        if start == -1:
            raise ValueError("No JSON object found")

        json_str = text[start:]
        obj = json.loads(json_str)   # validates JSON
        return json.dumps(obj)       # normalized JSON string


    @staticmethod
    def addKeyJson(jsonVal, key, value):
        data = json.loads(jsonVal)

        data[key] = value

        return json.dumps(data)
    
    
    @staticmethod
    def similarity(a, b):
        return SequenceMatcher(None, a, b).ratio()

    @staticmethod
    def fuzzyMatch(msg, msgList, thresh):
        msg_clean = msg.strip().lower()

        best_score = 0
        best_match = None

        for phrase in msgList:
            score = Utilities.similarity(msg_clean, phrase.lower())
            if score > best_score:
                best_score = score
                best_match = phrase

        # if best_score > 0.75:   # adjust threshold as needed

        return best_score > thresh