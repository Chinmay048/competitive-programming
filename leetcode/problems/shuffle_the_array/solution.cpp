class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int x=0;
        while(x<n){
            ans.push_back(nums[x]);
            ans.push_back(nums[x+n]);
            x++;
        }
        return ans;
    }
};