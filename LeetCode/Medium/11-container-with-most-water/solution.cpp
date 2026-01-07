#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1,result=0;
        for(int i=0;i<height.size()&&left!=right;i++){
            int temp=(right-left)*((height[left]<=height[right])?height[left]:height[right]);
            if(result<temp)
                result=temp;
            if(height[left]<=height[right])
                left++;
            else
                right--;
        }
        return result;
    }
};
int main() {
  Solution object;
  //case 1:
  vector<int> height1={1,8,6,2,5,4,8,3,7};
  cout << object.maxArea(height1)<<endl;

  //case 2:
  vector<int> height2={1,1};
  cout << object.maxArea(height2)<<endl;
  return 0;
}