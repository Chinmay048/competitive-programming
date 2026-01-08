#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<nums.size();i++)
            if(n%(i+1)==0)
                sum+=nums[i]*nums[i];
        return sum;
    }
};
int main(){
  Solution object;
  //case1
  vector<int> nums1={1,2,3,4};
  cout<<object.sumOfSquares(nums1)<<endl;

  //case2
  vector<int> nums2={2,7,1,19,18,3};
  cout<<object.sumOfSquares(nums2);
  return 0;
}