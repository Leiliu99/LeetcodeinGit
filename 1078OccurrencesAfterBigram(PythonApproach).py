class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        res = []
        stringProcess = text.split(" ")
        i = 0
        while i < len(stringProcess) - 2:
            if stringProcess[i] == first:
                if stringProcess[i + 1] == second:
                    res.append(stringProcess[i + 2])
            i = i + 1
        return res