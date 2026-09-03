class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> m2 = {{')','('},{'}','{'},{']','['}};

        string str;

        for(auto c : s){
            if(m2.contains(c)){
                if(str.size() == 0){
                    return false;
                }
                char temp = str[str.size() - 1];
                if(m2[c] != temp){
                    return false;
                }
                str.pop_back();
            }
            else{
                str += c;
            }
        }
        return str.size() == 0;
    }
};
