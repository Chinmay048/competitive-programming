class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<int> vs;
        vector<int> vt;
        for(auto i:s){
            if (i != '#') vs.push_back(i); 
            else if (!vs.empty()) vs.pop_back(); 
        }
        for(auto i:t){
            if (i != '#') vt.push_back(i); 
            else if (!vt.empty()) vt.pop_back();
        }
        if(vs==vt)
            return true;
        return false;
    }
};