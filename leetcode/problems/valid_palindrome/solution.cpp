class Solution {
public:
    bool isPalindrome(string s) {
        string ch;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48&&s[i]<=57)
            ch+=s[i];
        else if(s[i]>=65&&s[i]<=90)
            ch+=tolower(s[i]);
        else if(s[i]>=97&&s[i]<=122)
            ch+=s[i];
    }
    for(int i=0,j=ch.size()-1;i<ch.size(),j>=0;i++,j--) {
        if(ch[i]!=ch[j])
            return 0;
    }
    return 1;
    }
};