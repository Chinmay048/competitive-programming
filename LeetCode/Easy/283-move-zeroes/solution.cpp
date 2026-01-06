#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }

    }
};
int main() {
  Solution object;
  //case1:
    vector<int> nums1={0,1,0,3,12};
    for(int i=0;i<nums1.size();i++)
        cout<<nums1[i]<<" ";
    cout<<"\n";

    //case2:
    vector<int> nums2={0};
    for(int i=0;i<nums2.size();i++)
        cout<<nums2[i]<<" ";

    return 0;
}