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
    int Recursion(TreeNode* root){
        if(!root) return 0;
        int leftDepth=Recursion(root->left);
        if(leftDepth==-1) return -1;
        int rightDepth=Recursion(root->right);
        if(rightDepth==-1) return -1;
        if(abs(rightDepth-leftDepth)>1) return -1;
        return 1+max(leftDepth,rightDepth);
    }
    bool isBalanced(TreeNode* root) {
        return Recursion(root)!=-1;
    }
};