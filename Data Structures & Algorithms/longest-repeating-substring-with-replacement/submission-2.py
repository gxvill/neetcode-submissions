class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        if len(s) == 1: 
            return 1

        greatest = 0
        left = 0
        max_freq = 0

        # init the dict
        freq = {}

        for right in range(len(s)):
            char = s[right]

            freq[char] = freq.get(char,0) + 1

            max_freq = max(max_freq, freq[char])

            while right - left + 1 > max_freq + k:
                freq[s[left]] -= 1
                left += 1

            greatest = max(greatest, right - left + 1)

        return greatest

