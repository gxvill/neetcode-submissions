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
    int kthSmallest(TreeNode* root, int k) {
        int ret = -1;
        
        dfs(root, ret, k);

        return ret;
    }
    void dfs(TreeNode* node, int& ret, int& k){
        if(!node) return;
        if(ret != -1 || k < 0) return;

        dfs(node->left, ret, k);

        
        k--; // decrement k when processing
        // processing
        if(k == 0){
            ret = node->val;
            k = -1;
            return;
        }

        dfs(node->right, ret, k);
        return;
    }
};



