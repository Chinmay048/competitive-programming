class Solution {
public:
    int longestSubarray(vector<int>& nums) {
  int c=0,a=0;
  for(int i=0;i<nums.size()-2;i++){
    if(nums[i]+nums[i+1]==nums[i+2])
        c++;
    else
      c=0;
    if(c>0&&c>a)
      a=c;
  }
  return a+2;
}
};