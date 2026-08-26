class Solution:
    def isPalindrome(self, s: str) -> bool:
        # clean the string
        clean = ""
        for char in s:
            if char.isalnum():
                clean += char

        left = 0
        right = len(clean) - 1

        clean = clean.lower()

        while left <= right:
            if(clean[left] != clean[right]):
                return False
            left += 1
            right -= 1
        return True
