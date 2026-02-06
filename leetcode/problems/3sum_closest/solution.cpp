class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum=nums[0]+nums[1]+nums[2];
        int diff=abs(target-sum);
        for(int i=0;i<nums.size();i++){
            int left=i+1,right=nums.size()-1;
            while(left<right){
                int lsum=nums[i]+nums[left]+nums[right];
                int ldiff=abs(target-lsum);
                if(ldiff<=diff){
                    diff=ldiff;
                    sum=lsum;
                }
            
                if(lsum<target)
                    left++;
                else    
                    right--;
            }
            
        }
        return sum;
    }
};