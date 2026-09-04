class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;

        for(auto n : nums){
            if(!m.contains(n)){
                m[n] += 1;
            }
            else{
                return true;
            }
        }
        return false;
        
    }
};
