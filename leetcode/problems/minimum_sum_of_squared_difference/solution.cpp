class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
       long long sum=0;
       long long k=k1+k2;
       vector<int> v(100001,0);
       for(int i=0;i<nums1.size();i++){
            long long diff=abs(nums1[i]-nums2[i]);
            v[diff]++;
       }
       for(long long i=100000;i>0;i--){
            if(k==0 || v[i]==0) continue;
            else {
                long long reduce=min((long long)v[i],k);
                v[i]-=reduce;
                v[i-1]+=reduce;
                k-=reduce;
            }
       }
       for(int i=0;i<v.size();i++){
            if(v[i]==0) continue;
            else{
                sum+=(long long)v[i]*i*i;
            }
       }
       return sum;
    }
};