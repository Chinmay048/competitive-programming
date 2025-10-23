class Solution {
public:
    bool operation1(string s){
        if(s.length()!=2){
            string temp="";
            int sum;
            for(int i=0;i<s.length()-1;i++){
                sum=((s[i]-'0')+(s[i+1]-'0'))%10;
                temp+=char('0'+sum);
            }
            return operation1(temp);
        }
        if(int(s[0])-'0'==int(s[1])-'0')
                return true;
        return false;
    }
    bool hasSameDigits(string s) {
        return operation1(s);
    }
};