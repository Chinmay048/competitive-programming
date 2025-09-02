class Solution {
public:
    bool isPalindrome(int x) {
        if(x>=0){
            long long temp=x,num=0,d;
            while(x!=0){
                d=x%10;
                x/=10;
                num=num*10+d;
            }
            if(num>INT_MAX||num<INT_MIN)
                return false;
            else
                if(num==temp)
                    return true;
                else 
                    return false;
        }
        else
            return false;
    }
};