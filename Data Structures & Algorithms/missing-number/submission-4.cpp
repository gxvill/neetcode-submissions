class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int len = nums.size();

        int t1 = 0;
        for(auto n : nums){
            t1 += n;
        }

        int t2 = (len * (len + 1)) / 2;

        return t2 - t1;
        
    }
};
