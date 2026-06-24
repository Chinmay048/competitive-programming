class Solution {
public:
    string removeDuplicates(string s) {
        string str="";
        for(char c:s){
            if(str.empty()||str.back()!=c)
                str.push_back(c);
            else 
                str.pop_back();
        }
        return str;
    }
};