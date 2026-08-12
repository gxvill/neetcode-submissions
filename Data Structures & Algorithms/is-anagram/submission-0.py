class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        ds = {}
        dt = {}

        for c in s:
            if c in ds:
                ds[c] += 1
            else :
                ds[c] = 1

        for c in t:
            if c in dt:
                dt[c] += 1
            else :
                dt[c] = 1

        return ds == dt
        
