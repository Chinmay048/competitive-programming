class Solution {
public:
    string resultingString(string s) {
        string str="";
        for(char c:s){
            if(str.empty())
                str.push_back(c);
            else if((str.back()=='z'&& c=='a')||(str.back()=='a'&& c=='z') ||str.back()==c+1 || str.back()==c-1)
                str.pop_back();
            else 
                str.push_back(c);
        }
        return str;
    }
};