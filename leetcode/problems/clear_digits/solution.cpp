class Solution {
public:
    string clearDigits(string s) {
        string v="";
        for(char i:s){
            if(isdigit(i)){
                if (!v.empty()) v.pop_back();}
            else 
                v.push_back(i);
        }
        return v;
    }
};