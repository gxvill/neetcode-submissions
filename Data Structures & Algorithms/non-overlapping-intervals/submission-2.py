class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # sort 
        intervals.sort()

        ret = 0
        prevEnd = intervals[0][1]

        for i in range(1,len(intervals)):
            if prevEnd > intervals[i][0]:
                prevEnd = min(prevEnd, intervals[i][1])
                ret = ret + 1
            else:
                prevEnd = intervals[i][1]
        return ret
