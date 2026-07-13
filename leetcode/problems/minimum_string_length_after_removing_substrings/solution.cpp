class Solution {
public:
    int minLength(string s) {
        string stk = "";
        for (char c : s) {
            if (!stk.empty() && stk.back() == 'A' && c == 'B') {
                stk.pop_back();
            } 
            else if (!stk.empty() && stk.back() == 'C' && c == 'D') {
                stk.pop_back();
            } 
            else {
                stk.push_back(c);
            }
        }
        
        return stk.length();
    }
};