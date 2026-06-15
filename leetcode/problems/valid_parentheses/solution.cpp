class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0) return false;
        vector<char> str;
        for(char c:s){
            if(c=='('||c=='{'||c=='[') str.push_back(c);
            else{
                if(str.empty()) return false;
                char top=str.back();
                if((c == ')'&&top=='(')||(c =='}'&&top=='{')||(c==']'&&top=='['))
                    str.pop_back();
                else 
                    return false;
            }
        }
        return str.empty();
        
    }
};