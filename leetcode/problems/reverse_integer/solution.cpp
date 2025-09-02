class Solution {
public:
    int reverse(int x) {
        long long num=0,d;
        while(x!=0){

            d=x%10;
            x/=10;
            num=num*10+d;
            if(num<INT_MIN||num>INT_MAX){return 0;}
        }
        return num;
    }
};