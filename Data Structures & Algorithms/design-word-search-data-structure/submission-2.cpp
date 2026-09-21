class TrieNode{
public:
    vector<TrieNode*> children;
    bool isLeaf;

    TrieNode() : children(26, nullptr) , isLeaf(false){}
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->children[c-'a']){
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->isLeaf = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
private:
    bool dfs(TrieNode* root, string word, int j){
        TrieNode* curr = root;

        for(int i = j; i < word.size(); i ++){
            char c = word[i];
            if(c == '.'){
                for(TrieNode* child : curr->children){
                    if(child != nullptr && dfs(child, word,  i + 1)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(curr->children[c - 'a'] == nullptr){
                    return false;
                }
                curr = curr->children[c - 'a'];
            }
        }

        return curr->isLeaf;

    }
};
