class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> LIS(len, 1);

        for(int i = len - 1; i >= 0; i--){

            for(int j = i + 1; j < len; j++){
                if(nums[i] < nums[j]){
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
        }
        return *max_element(LIS.begin(), LIS.end());
    }
};
