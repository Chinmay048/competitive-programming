class Solution {
public:
    int maxDepth(string s) {
        stack<char> stk;
        int depth=0,max=0;
        for(char c:s){
            if(c=='('){
                depth++;
                stk.push(c);
            }
            else if(c==')'){
                if(!stk.empty()){
                    if(max<depth)
                        max=depth;
                    depth--;
                    stk.pop();
                }
            }
            
        }
        return max;
    }
};