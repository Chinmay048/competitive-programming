class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr1=0,ptr2=0;
        if(s.length()==0)
            return true;
        else if(s.length()==1&&t.length()==1)
            return s[0]==t[0]?true:false;
        while(ptr2<=t.length()){
            if(ptr1==s.length())
                return true;
            else if(s[ptr1]==t[ptr2]){
                ptr1++;
                ptr2++;
            }
            else 
                ptr2++;
        }
        return false;
    }
};