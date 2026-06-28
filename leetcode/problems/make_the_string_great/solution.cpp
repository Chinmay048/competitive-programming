class Solution {
public:
    string makeGood(string s) {
        string str=""; 
        for(char c:s){
            if(str.empty()) 
                str.push_back(c);
            else if(abs(str.back() - c)==32)
                str.pop_back();
            else 
                str.push_back(c);

        }
        return str;
    }
};