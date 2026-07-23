class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        goal = n - 1
        curr = n - 2
        while curr >= 0:
            if curr + nums[curr] >= goal:
                goal = curr
            curr = curr - 1

        if goal == 0:
            return True
        return False


            



            
