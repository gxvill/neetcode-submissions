class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort invervals
        sort(intervals.begin(), intervals.end());

        int prevEnd = intervals[0][1];
        int ret = 0;
        for(int i = 1; i < intervals.size(); i++){
            // overlap
            if(prevEnd > intervals[i][0]){
                prevEnd = min(prevEnd, intervals[i][1]);
                ret++;
            }
            else{
                prevEnd = intervals[i][1];
            }
        }
        return ret;
    }
};
