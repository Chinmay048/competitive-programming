#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        return ((nums.size()*(nums.size()+1))/2)-sum;
    }
};
int main(){
    Solution object;
    //case1:
    vector<int> nums1={3,0,1};
    cout<<"Output: "<<object.missingNumber(nums1)<<endl;
    cout<<"Expected output: 2"<<endl;

    //case2:
    vector<int> nums2={0,1};
    cout<<"Output: "<<object.missingNumber(nums2)<<endl;
    cout<<"Expected output: 2"<<endl;

    return 0;
}