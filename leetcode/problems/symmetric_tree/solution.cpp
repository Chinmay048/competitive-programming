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
    bool isValid(TreeNode* p,TreeNode* q){
        if(!p && !q) return true;
        if(!q || !p || p->val!=q->val) return false;
        return isValid(p->left,q->right) && isValid(p->right,q->left); 
    }
    bool isSymmetric(TreeNode* root) {
        if(isValid(root->left,root->right)) return true;
        return false;
    }
};