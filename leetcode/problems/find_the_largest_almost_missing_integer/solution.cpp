class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i:nums)
            mp[i]++;
        if(k==1){
            int flag=-1;
            for(auto i:mp)
                if(i.second==1) flag=max(flag, i.first);
            return flag;
        }
        if(k == n) return *max_element(nums.begin(), nums.end());
        int flag=-1;
        if(mp[nums[0]] == 1) flag= max(flag, nums[0]);
        if(mp[nums[n-1]] == 1) flag= max(flag, nums[n-1]);
        return flag;
    }
};