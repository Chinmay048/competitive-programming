class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0,j=0;i<=nums.size(),j<nums.size();i++,j++){
            if(nums[j]!=i)
                return i;
        }
        return nums.size();
    }
};