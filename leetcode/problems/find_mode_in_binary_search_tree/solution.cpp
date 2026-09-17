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
private:
    int currVal = 0;
    int currCount = 0;
    int maxCount = 0;
    vector<int> modes;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (root->val == currVal) {
            currCount++;
        } else {
            currVal = root->val; 
            currCount = 1;
        }
    
        if (currCount > maxCount) {
            maxCount = currCount;
            modes = {currVal}; 
        } else if (currCount == maxCount) {
            modes.push_back(currVal);
        }
        inorder(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
};