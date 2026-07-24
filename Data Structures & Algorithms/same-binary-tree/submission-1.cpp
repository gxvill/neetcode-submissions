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

class Solution{
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        // both are nullptr, so they both match
        if(!p && !q) return true;

        // both exist and have same value
        // explore the subtrees
        if(p && q && p->val == q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        // there is a mismatch somehwere
        else return false;
    }
};
