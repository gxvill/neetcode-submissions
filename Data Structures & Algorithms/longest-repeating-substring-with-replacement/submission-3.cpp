class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        if(len == 1){
            return 1;
        }

        unordered_map<char,int> freq;
        int left = 0;
        int max_freq = 0;
        int greatest = 0;

        for(int right = 0; right < len; right++){
            char c = s[right];
            freq[c]++;

            max_freq = max(max_freq, freq[c]);

            while(right - left + 1 > max_freq + k){
                freq[s[left]]--;
                left++;
            }
            greatest = max(greatest, right - left + 1);
        }

        return greatest;
    }
};
