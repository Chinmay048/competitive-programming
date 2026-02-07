#include<bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int left=0,right=nums.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target)
            right=mid-1;
        else
            left=mid+1;
    }
    return left;
}
int main(){
    //case1
    vector<int> nums1={1,3,5,6};
    cout<<"Output: "<<searchInsert(nums1,5)<<endl;

    //case2
    vector<int> nums2={1,3,5,6};
    cout<<"Output: "<<searchInsert(nums2,2)<<endl;

    //case3
    vector<int> nums3={1,3,5,6};
    cout<<"Output: "<<searchInsert(nums3,7)<<endl;
    return 0;
}