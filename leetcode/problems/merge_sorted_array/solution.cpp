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