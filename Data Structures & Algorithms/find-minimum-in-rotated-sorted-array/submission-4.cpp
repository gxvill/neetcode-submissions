class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int m = (r + l) / 2;

        int smol = nums[m];

        while(l <= r){
            m = (r + l) / 2;
            smol = min(nums[m], smol);

            // 4 possibilities
            if(m - 1 >= 0 && nums[m - 1] > nums[m]){
                return nums[m];
            }
            else if(nums[r] < nums[m]){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }

        return smol;
    }
};



