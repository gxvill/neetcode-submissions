class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        int goal = n - 1;
        int cur = n - 2;

        while (cur >= 0){
            if (cur + nums[cur] >= goal){
                goal = cur;
            }
            cur--;
        }

        if(goal == 0) return true;

        return false;
    }
};
