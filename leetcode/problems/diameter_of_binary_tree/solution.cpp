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
    int max_diameter = 0;

    int getDepth(TreeNode* root) {
        if (!root) return 0;
        
  
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        
        
        max_diameter = max(max_diameter, leftDepth + rightDepth);
        
       
        return 1 + max(leftDepth, rightDepth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);
        return max_diameter;
    }
};

