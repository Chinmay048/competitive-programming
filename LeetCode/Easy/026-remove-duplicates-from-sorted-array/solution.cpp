#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for (int j=1;j<nums.size();j++)
            if (nums[i]!=nums[j])
                nums[++i]=nums[j];
        return i+1;
    }
};
int main(){
    Solution object;

    //case 1:
    vector<int> nums1={1,1,2};
    int ans1=object.removeDuplicates(nums1);
    cout<<"Output: "<<ans1<<endl;
    cout<<"Expected Output: 2"<<endl;

    //case 2:
    vector<int> nums2={0,0,1,1,1,2,2,3,3,4};
    int ans2=object.removeDuplicates(nums2);
    cout<<"Output: "<<ans2<<endl;
    cout<<"Expected Output: 5"<<endl;
    return 0;
}