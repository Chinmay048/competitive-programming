class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left_rem = 0, right_rem = 0;
        
        for (char c : s) {
            if (c == '(') left_rem++;
            else if (c == ')') {
                if (left_rem > 0) left_rem--;
                else right_rem++;
            }
        }
        
        unordered_set<string> valid_results;
        string current = ""; // Single allocation
        backtrack(s, 0, current, left_rem, right_rem, 0, valid_results);
        
        return vector<string>(valid_results.begin(), valid_results.end());
    }

private:
    void backtrack(const string& original, int index, string& current, 
                   int left_rem, int right_rem, int balance, 
                   unordered_set<string>& valid_results) {
        
        if (left_rem + right_rem > original.length() - index) return;

        if (index == original.length()) {
            if (left_rem == 0 && right_rem == 0 && balance == 0) {
                valid_results.insert(current);
            }
            return;
        }
        
        char c = original[index];
        if (c == '(' && left_rem > 0) {
            backtrack(original, index + 1, current, left_rem - 1, right_rem, balance, valid_results);
        }
        if (c == ')' && right_rem > 0) {
            backtrack(original, index + 1, current, left_rem, right_rem - 1, balance, valid_results);
        }
        
        current.push_back(c); 
        
        if (c == '(') {
            backtrack(original, index + 1, current, left_rem, right_rem, balance + 1, valid_results);
        } else if (c == ')') {
            if (balance > 0) {
                backtrack(original, index + 1, current, left_rem, right_rem, balance - 1, valid_results);
            }
        } else {
            backtrack(original, index + 1, current, left_rem, right_rem, balance, valid_results);
        }
        
        current.pop_back(); 
    }
};