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
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        int val=root->val;
        q.push(root);
        while(!q.empty()){
            TreeNode* newNode=q.front();
            q.pop();
            if(val!=newNode->val)
                return false;
            if(newNode->left) q.push(newNode->left);
            if(newNode->right) q.push(newNode->right);
        }   
        return true;
    }
};