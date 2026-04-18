class Solution {
public:
    int mirrorDistance(int n) {
        int temp=n,sum=0,digit;
        while(temp>0){
            digit=temp%10;
            temp=temp/10;
            sum=sum*10+digit;
        }
        if(sum>n)
            return sum-n;
        else 
            return n-sum;

        
    }
};