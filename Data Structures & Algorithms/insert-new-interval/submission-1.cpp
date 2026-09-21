class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> res;

        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        for(int i = 0; i < intervals.size(); i++){
            vector<int>& cur = intervals[i];
            // case 1 (end):
            // newinterval ends before the start of the current interval
            if(newEnd < cur[0]){
                res.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(res));
                return res;
            }
            // case 2:
            // newinterval starts after the end of the current interval
            else if(newInterval[0] > cur[1]){
                res.push_back(cur);
            }
            // case 3:
            // newinterval overlaps the  start of the current interval
            else{
                newInterval[0] = min(newInterval[0], cur[0]);
                newInterval[1] = max(newInterval[1], cur[1]);
            }
        }

        res.push_back(newInterval);
        return res;
    }
};



