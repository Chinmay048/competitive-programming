#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;i++)
      if(nums[i]==nums[i+1]){return true;}
    return false;
  }
};
int main(){
  Solution object;

  //case1
  vector<int> nums1={1,2,3,1};
  cout<<"Output: "<<object.containsDuplicate(nums1)<<endl;
  cout<<"Expected: 1"<<endl;

  //case2
  vector<int> nums2={1,2,3,4};
  cout<<"Output: "<<object.containsDuplicate(nums2)<<endl;
  cout<<"Expected: 0"<<endl;

  return 0;
}