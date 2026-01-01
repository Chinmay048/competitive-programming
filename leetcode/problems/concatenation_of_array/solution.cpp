class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> temp;    
        for(int i=0;i<2*nums.size();i++)
            if(i<nums.size())
                temp.push_back(nums[i]);
            else 
                temp.push_back(nums[i-nums.size()]);
        return temp;

    }
};