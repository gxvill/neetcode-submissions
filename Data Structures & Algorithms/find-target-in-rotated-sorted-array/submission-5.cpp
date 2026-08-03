class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int r = len - 1;
        int l = 0;
        while(l <= r){
            int m = (r + l) / 2;
            // best cases
            if(nums[m] == target){
                return m;
            }
            if(nums[l] == target){
                return l;
            }
            if(nums[r] == target){
                return r;
            }

            if(target < nums[m]){
                // go left
                if(target > nums[l] || nums[l] > nums[m]){
                    r = m - 1;
                }
                // go right
                else{
                    l = m + 1;
                }
            }
            else{
                // go right
                if(target < nums[r] || nums[r] < nums[m]){
                    l = m + 1;
                }
                // go left
                else{
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};
