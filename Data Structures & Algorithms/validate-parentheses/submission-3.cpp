class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> m1 = {{'(', 1},{'{', 1},{'[',1}};
        unordered_map<char,char> m2 = {{')','('},{'}','{'},{']','['}};

        string str;

        for(auto c : s){
            if(m1.contains(c)){
                str += c;
            }
            else if(m2.contains(c)){
                if(str.size() == 0){
                    return false;
                }
                char temp = str[str.size() - 1];
                if(m2[c] != temp){
                    return false;
                }
                str.pop_back();
            }
        }
        return str.size() == 0;
    }
};
