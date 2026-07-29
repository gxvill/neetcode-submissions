class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int left = 0;
        int right = 1;
        int maxLength = 1;
        int l = s.size();

        while(right <= l){
            string temp = s.substr(left, right - left);
            unordered_set<char> chars(temp.begin(), temp.end());

            int len = chars.size();

            if(len != right - left){
                left++;
            }
            else{
                maxLength = max(maxLength, right - left);
                right++;
            }
        }
        return maxLength;
    }
};
