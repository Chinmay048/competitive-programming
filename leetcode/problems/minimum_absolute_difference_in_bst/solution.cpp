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
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        int diff=INT_MAX;
        int prev=-1;
        stack<TreeNode*> stk;
        TreeNode* curr=root;
        while(curr || !stk.empty()){
            while(curr){
                stk.push(curr);
                curr=curr->left;
            }
            curr=stk.top();
            stk.pop();
            if(prev!=-1)
                diff=min(diff,abs(curr->val-prev));
            prev=curr->val;
            curr=curr->right;    
        }
        return diff;
    }
};