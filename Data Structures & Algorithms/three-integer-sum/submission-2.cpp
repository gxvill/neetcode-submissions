class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the list
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); i++){
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -1 * nums[i];
            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k){
                if(target == nums[j] + nums[k]){
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j - 1]){
                        j++;
                    }
                }
                else if(target < nums[j] + nums[k]){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return res;
    }
};


