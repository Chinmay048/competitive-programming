#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0,right=nums.size()-1;
        while(left<=right)
            if(val!=nums[left])
                left++;
            else{
                nums[left]=nums[left]+nums[right];
                nums[right]=nums[left]-nums[right];
                nums[left]=nums[left]-nums[right];
                nums.pop_back();
                right--;
            }
        return left;
    }
};
int main(){
    Solution object;

    //case1:
    vector<int> nums1={3,2,2,3};
    int val1=3;
    cout<<"Output: "<<object.removeElement(nums1,val1)<<endl;
    cout<<"Expected Output: 2"<<endl;

    //case2:
    vector<int> nums2={0,1,2,2,3,0,4,2};
    int val2=2;
    cout<<"Output: "<<object.removeElement(nums2,val2)<<endl;
    cout<<"Expected Output: 5"<<endl;
    return 0;
}