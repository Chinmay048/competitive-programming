class Solution {
public:
    bool solve(vector<int> nums,int k,int target){
        int i=0,j=-1;
        while(i<nums.size()){
            if(nums[i]==target)
                if(abs(i-j)<=k && j!=-1)
                    return true;
                else 
                    j=i;

            i++;
        }
        return false;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
            if(mp[i]>=2){
                if(solve(nums,k,i))
                    return true;                
            }
        }
        return false;
        
    }
};