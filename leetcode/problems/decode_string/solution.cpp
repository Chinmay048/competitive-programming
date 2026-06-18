class Solution {
public:
    string decodeString(string s) {
        stack<int> intstack;
        stack<string> strstack;
        int num = 0;
        string str = "";
        for (char c : s) {
            if (c == '[') {
                intstack.push(num);
                num = 0;
                strstack.push(str);
                str = "";
            } else if (isdigit(c))
                num = num * 10 + (c - '0');
            else if (c == ']') {
                int k = intstack.top();
                intstack.pop();
                string temp = strstack.top();
                strstack.pop();
                while (k-- > 0) {
                    temp += str;
                }
                str = temp;
            } else
                str += c;
        }
        return str;
    }
};