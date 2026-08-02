class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int total_count=0;
        for(int i=0;i<nums.size();i++){
            long long even_count=0;
            long long odd_count=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0)
                    even_count++;
                else 
                    odd_count++;
                if(odd_count>0 && even_count*b<=odd_count*a)
                    total_count++;
            }
        }
        return total_count;
    }
};