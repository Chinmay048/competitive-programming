class Solution {
public:
    int smallestNumber(int n, int t) {
        int i=n;
        while(true){
            int pro=1;
            int temp=i;
            while(temp>0){
                pro*=(temp%10);
                temp/=10;
            }
            if(pro%t==0)
                return i;
            i++;
        }
        return i;
    }
};