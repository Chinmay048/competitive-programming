class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root) return paths;
        stack<pair<TreeNode*, string>> stk;
        stk.push({root, to_string(root->val)});
        
        while (!stk.empty()) {
            auto [curr, path] = stk.top();
            stk.pop();
            
            if (!curr->left && !curr->right) {
                paths.push_back(path);
            }
            if (curr->right) {
                stk.push({curr->right, path + "->" + to_string(curr->right->val)});
            }
            if (curr->left) {
                stk.push({curr->left, path + "->" + to_string(curr->left->val)});
            }
        }
        
        return paths;
    }
};