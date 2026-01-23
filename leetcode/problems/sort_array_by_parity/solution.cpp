class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[j]%2!=0){
                if(nums[i]%2==0){
                    int temp=nums[i];
                    nums[i]=nums[j];
                    nums[j]=temp;
                    j++;
                }}
            else
                j++;
        }   
        return  nums;      
    }
};