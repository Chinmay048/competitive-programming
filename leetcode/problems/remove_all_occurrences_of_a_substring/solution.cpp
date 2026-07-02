class Solution {
public:
    string removeOccurrences(string s, string part) {
        string stk = ""; 
        int m = part.length();
        for (char c : s) {
            stk.push_back(c);
            if (stk.length() >= m) {
                if (stk.substr(stk.length() - m) == part) 
                    stk.erase(stk.length() - m); 
            }
        }
        return stk;
    }
};