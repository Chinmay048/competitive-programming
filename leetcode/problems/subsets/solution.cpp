class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int total_Subsets=1<<n;
        vector<vector<int>> v;
        for(int mask=0;mask<total_Subsets;mask++){
            vector<int> curr;
            for(int i=0;i<n;i++)
                if((mask>>i)&1)
                    curr.push_back(nums[i]);
            v.push_back(curr);
        }
        return v;
    }
};