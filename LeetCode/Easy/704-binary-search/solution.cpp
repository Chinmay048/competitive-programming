#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
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
        return -1;
    }
};
int main(){
    Solution object;
    //case 1:
    vector<int> nums1={-1,0,3,5,9,12};
    cout<<"Output: "<<object.search(nums1,9)<<endl;

    //case 2:
    vector<int> nums2={-1,0,3,5,9,12};
    cout<<"Output: "<<object.search(nums2,2)<<endl;
    return 0;
}