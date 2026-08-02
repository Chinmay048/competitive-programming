class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
       long long int max_strength=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long g=std::gcd(nums[i],nums[j]);
                long long temp=(1LL*nums[i]*nums[j])/(g*g);
                max_strength=max(max_strength,temp);
                
            }
        }
        return max_strength;
    }
};