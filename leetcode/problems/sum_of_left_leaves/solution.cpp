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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        stack<TreeNode*> stk;
        stk.push(root);
        int sum=0;
        while(!stk.empty()){
            TreeNode* curr=stk.top();
            stk.pop();

            if(curr->left!=nullptr && curr->left->left==nullptr && curr->left->right==nullptr)
                sum+=curr->left->val;
            
            if(curr->left) stk.push(curr->left);
            if(curr->right) stk.push(curr->right);
        }
        return sum;
    }
};