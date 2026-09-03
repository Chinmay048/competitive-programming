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
    int findSecondMinimumValue(TreeNode* root) {
        long min1=root->val;
        long min2=LONG_MAX;
        if(!root) return -1;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* curr=stk.top();
            stk.pop();
            if(min2>curr->val && min1<curr->val)
                min2=curr->val;
            else if(min1==curr->val){
                if(curr->right) stk.push(curr->right);
                if(curr->left) stk.push(curr->left);
            }
        }
        return min2==LONG_MIN? -1:min2;

    }
};