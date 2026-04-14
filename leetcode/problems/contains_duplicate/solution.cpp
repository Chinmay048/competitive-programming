class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int element=nums[i];
            mp[element]++;
            if(mp[element]>1)
                return true;
        }
        return false;
    }
};