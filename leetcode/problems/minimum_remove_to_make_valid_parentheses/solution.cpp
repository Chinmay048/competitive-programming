class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (!stk.empty()) stk.pop();
                else s[i] = '*';
            }
        }
        while(!stk.empty()){
            s[stk.top()]='*';
            stk.pop();
        }
        int write = 0;
        for (int read= 0; read< s.size(); ++read) {
            if (s[read] != '*')
                s[write++] = s[read];
        }
        s.resize(write); 
        return s;

    }
};