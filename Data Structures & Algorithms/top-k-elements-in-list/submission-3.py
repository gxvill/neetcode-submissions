class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # dict
        count = {}
        freq = [[] for i in range(len(nums) + 1)]

        # hashmp
        for num in nums:
            count[num] = 1 + count.get(num, 0)

        # bucket sort
        for num, cnt in count.items():
            freq[cnt].append(num)

        res = []

        for i in range(len(freq) - 1, 0 ,-1):
            for num in freq[i]:
                res.append(num)
                if len(res) == k:
                    return res

