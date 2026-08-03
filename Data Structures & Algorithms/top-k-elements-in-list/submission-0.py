class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = dict(Counter(nums))
        sorted_items = sorted(freq.items(), key=lambda item: item[1], reverse=True)

        ret = []

        for i in range(k):
            ret.append(sorted_items[i][0])
        
        return ret

        

        
