class Solution {
public:
    int evalRPN(vector<string>& tokens){
        vector<int> stack;
        for (auto s : tokens){
            if (s == "+" || s == "-" || s == "*" ||s == "/"){
                int num2 = stack.back();
                stack.pop_back();
                int num1 = stack.back();
                stack.pop_back();
                if (s == "+") stack.push_back(num1 + num2);
                else if (s == "-") stack.push_back(num1 - num2);
                else if (s == "*") stack.push_back(num1* num2);
                else if (s == "/") stack.push_back(num1 / num2);
            } 
            else stack.push_back(stoi(s));
        }
        return stack.back();
    }
};
