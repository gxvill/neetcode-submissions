class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;

        int len = 1;
        int prev = nums[0];

        map<int, int> m;

        for(auto& n : nums){
            m[n] += 1;
            prev = min(prev, n);
        }

        int count = 1;
        for(auto& [curr, val] : m){
            if(prev + 1 == curr){
                count ++;
            }
            else{
                len = max(len, count);
                count = 1;
            }
            prev = curr;
        }
        len = max(len, count);

        return len;
    }
};



