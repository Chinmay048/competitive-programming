class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        else {
            vector<bool> a(n,true);
            int sum=0;
            a[0]=a[1]=false;
            for(int i=2;i*i<n;i++){
                if(a[i])
                    for(int j=i*i;j<n;j+=i)
                        a[j]=false;}
            for(int i=2;i<n;i++)
                if(a[i])
                    sum++;
            return sum;}
    }
};