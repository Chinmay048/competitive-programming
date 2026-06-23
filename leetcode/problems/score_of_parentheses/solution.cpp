class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> v;
        v.push_back(0);
        for(char i:s){
            if(i=='(')
                v.push_back(0);
            else {
                int innerScore=v.back();
                v.pop_back();
                int score=max(2*innerScore,1);
                v.back()+=score;
            }
            
        }
        return v.back();
    }
};