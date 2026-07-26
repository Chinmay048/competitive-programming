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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int s = q.size();
            vector<int> temp(s); // Pre-size vector to assign via index directly

            for (int i = 0; i < s; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                int index = leftToRight ? i : (s - 1 - i);
                temp[index] = curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            result.push_back(temp);
            leftToRight = !leftToRight; 
        }

        return result;
    }
};