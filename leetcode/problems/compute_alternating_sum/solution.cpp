class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i+=2)
            sum+=nums[i];
        for(int i=1;i<nums.size();i+=2)
            sum-=nums[i];
        return sum;
    }
};