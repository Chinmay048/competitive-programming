class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[nums.size()-1]<target)
            return nums.size();
        else if(nums[0]>target)
            return 0;
        else {
            int left=0,right=nums.size()-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(nums[mid]==target)
                    return mid;
                else if(nums[mid]>target)
                    right=mid-1;
                else 
                    left=mid+1;
            }
            if(left>right)  {
                if(nums[right]>target)
                    return right-1;
                else 
                    return right+1;}

        }
        return -1;
    }
};