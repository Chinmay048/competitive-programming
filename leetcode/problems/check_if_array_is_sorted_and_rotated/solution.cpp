class Solution {
public:
    bool check(vector<int>& nums) {
        int c=0;
        if(nums.size()>1){
            for(int i=0;i<nums.size()-1;i++)
                if(nums[i]<=nums[i+1])
                    c++;
                else if(nums[i]>nums[i+1]&&nums[0]<nums[nums.size()-1])
                    return false;
        if(c>=nums.size()-2)
            return true;
        else
            return false;
        }   
        else
            return true; 

    }
};