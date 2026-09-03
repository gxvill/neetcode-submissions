class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> m1 = {{'(', 1},{'{', 1},{'[',1}};
        unordered_map<char,char> m2 = {{')','('},{'}','{'},{']','['}};

        stack<char> st;

        for(auto c : s){
            if(m1.contains(c)){
                st.push(c);
            }
            else if(m2.contains(c)){
                if(st.empty()){
                    return false;
                }
                char temp = st.top();
                if(m2[c] != temp){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
