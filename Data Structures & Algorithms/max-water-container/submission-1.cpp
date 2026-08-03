class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int l = 0;
        int r = heights.size() - 1;
        int area = 0;

        while(l < r){
            area = (r - l) * min(heights[l], heights[r]);
            res = max(res, area);
            (heights[l] < heights[r]) ? l++ : r--;
        }
        return res;
    }
};
