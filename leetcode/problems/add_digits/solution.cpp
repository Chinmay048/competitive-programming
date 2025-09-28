class Solution {
public:
    int AddDigits(int num){
        if(num!=0){
            int d=floor(log10(num))+1;
            long long sum=0,flag;
            if(d<=1)
                return num;
            for(int i=0;i<d;i++){
                    flag=num%10;
                    num/=10;
                    sum+=flag;
                }
            return AddDigits(sum);
        }
        return 0;   
    }
    int addDigits(int num) {
        return AddDigits(num);
    }
};