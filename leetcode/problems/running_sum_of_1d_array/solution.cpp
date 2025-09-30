class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> temp;
        int j=0;
        while(j<nums.size()){
            int sum=0;
            for(int i=0;i<=j;i++)
                sum+=nums[i];
            temp.insert(temp.begin()+j,sum);
            j++;
        }
        return temp;
    }
};