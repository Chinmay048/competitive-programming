#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++){
      int n = count(nums.begin(), nums.end(), nums[i]);
      if(n > nums.size()/2)
        return nums[i];
    }
    return -1;
  }
};
int main(){
  Solution object;
  //case 1
  vector<int> nums1={3,2,3};
  cout<<"Output: "<<object.majorityElement(nums1)<<endl;
  cout<<"Expected output: 3"<<endl;


  //case 2
  vector<int> nums2={2,2,1,1,1,2,2};
  cout<<"Output: "<<object.majorityElement(nums2)<<endl;
  cout<<"Expected output: 2"<<endl;
  return 0;
}