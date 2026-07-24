/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res = true;
        dfs(p,q,res);
        return res;
    }

    void dfs(TreeNode* p, TreeNode* q, bool& res){
        if(!res){
            return;
        }
        if((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)){
            res = false;
            return;
        }
        if(p == nullptr && q == nullptr){
            return;
        }

        dfs(p->left, q->left, res);

        if(p->val != q->val){
            res = false;
        }

        dfs(p->right, q->right, res);
    }
};
