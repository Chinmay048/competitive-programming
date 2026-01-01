#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int temp;
        for(int i=0;i<nums.size();i++){
            temp=target-nums[i];
            for(int j=i+1;j<nums.size();j++)
                if(temp==nums[j]){
                    vector<int> a={i,j};
                    return a;
                }     
        }
        return {0};
    }
};
int main(){
    vector<int> v={2,7,11,15};
    Solution object;
    vector<int> sol=object.twoSum(v,9);
    for (auto i:sol)
        cout<<i<<" ";
    return 0;
}