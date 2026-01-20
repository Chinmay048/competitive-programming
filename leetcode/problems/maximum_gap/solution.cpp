class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()!=1){
            sort(nums.begin(),nums.end());
            int diff=0;
            for(int i=0;i<nums.size()-1;i++)
                if(nums[i+1]-nums[i]>diff)
                    diff=nums[i+1]-nums[i];
            return diff;
        }
        return 0;
    }
};