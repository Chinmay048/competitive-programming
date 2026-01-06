#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    k=k%nums.size();
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
  }
};
int main(){
  Solution object;
  //case1:
  vector<int> nums1={1,2,3,4,5,6,7};
  int k1=3;
  object.rotate(nums1,k1);
  for(int i=0;i<nums1.size();i++)
    cout<<nums1[i]<<" ";
  cout<<"\n";

  //case2:
  vector<int> nums2={-1,-100,3,99};
  int k2=2;
  object.rotate(nums2,k2);
  for(int i=0;i<nums2.size();i++)
    cout<<nums2[i]<<" ";
  cout<<"\n";

  return 0;
}