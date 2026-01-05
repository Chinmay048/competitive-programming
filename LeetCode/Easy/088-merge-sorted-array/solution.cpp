#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            nums1=nums2;
            return;}
        else if(m+n==1)
            return;
        else{
            int ptr1=0,ptr2=0,i=0;
            vector<int> ans;
            while(i<nums1.size()){
                if(ptr1==m)
                    ans.push_back(nums2[ptr2++]);
                else if(ptr2==n)
                    ans.push_back(nums1[ptr1++]);
                else if(nums1[ptr1]>nums2[ptr2]){
                    if(ptr2>=n)
                        ptr2=n-1;
                    ans.push_back(nums2[ptr2++]);
                }
                else if(nums1[ptr1]<=nums2[ptr2]){
                    if(ptr2>=n)
                        ptr2=n-1;
                    ans.push_back(nums1[ptr1++]);
                }
                i++;
            }
            nums1=ans;
        }
    }
};
int main() {
    Solution object;
    //case 1
    vector<int> nums1={1,2,3,0,0,0};
    vector<int> nums2={2,5,6};
    int m1=3,n1=3;
    object.merge(nums1,m1,nums2,n1);
    for(int i=0;i<nums1.size();i++){
    cout<<nums1[i]<<" ";
    }
    cout<<endl;
    //case 2
    vector<int> nums11={1};
    vector<int> nums22={};
    int m11=1,n22=0;
    object.merge(nums11,m11,nums22,n22);
    for(int i=0;i<nums11.size();i++){
        cout<<nums11[i]<<" ";
    }

    cout<<endl;
    //case 3
    vector<int> nums111={0};
    vector<int> nums222={1};
    int m111=0,n222=1;
    object.merge(nums111,m111,nums222,n222);
    for(int i=0;i<nums111.size();i++){
        cout<<nums111[i]<<" ";
    }
    return 0;

}