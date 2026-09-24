class Solution {
public:
    int smallestIndex(vector<int>& nums) {
      for(int i=0;i<nums.size();i++){
            int digit=0;
            while(nums[i]>0){
                digit+=nums[i]%10;
                nums[i]=nums[i]/10;
            }
            if(i==digit)
                return i;
        }
        return -1;  
    }
};