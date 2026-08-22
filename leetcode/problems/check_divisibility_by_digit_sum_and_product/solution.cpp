class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int sum=0;
        int product=1;
        while(temp>0){
            sum+=temp%10;
            product*=temp%10;
            temp=temp/10;
        }
        return n%(sum+product)==0? true:false;
    }
};