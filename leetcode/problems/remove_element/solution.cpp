class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0,right=nums.size()-1;
        while(left<=right)
            if(val!=nums[left])
                left++;
            else{
                    nums[left]=nums[left]+nums[right];
                    nums[right]=nums[left]-nums[right];
                    nums[left]=nums[left]-nums[right];
                    nums.pop_back();
                    right--;
                }
        return left;
    }
};