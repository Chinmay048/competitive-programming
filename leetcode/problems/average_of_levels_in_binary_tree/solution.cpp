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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        if (!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long sum=0;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* curr=q.front();
                q.pop();

                sum+=(double)curr->val;
            
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            v.push_back((double)sum/s);
        }
        return v;
    }
};