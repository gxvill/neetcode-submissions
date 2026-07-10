class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []

        def dfs(i, cur, total):
            # base case of success
            if total == target:
                res.append(cur.copy())
                return
            # base case of OOB or past target
            if i >= len(nums) or total > target:
                return

            # recursive steps

            # inclusion
            cur.append(nums[i])
            dfs(i, cur, total + nums[i])
            cur.pop()

            # exclusion
            dfs(i + 1, cur, total)

        dfs(0,[],0)
        return res
