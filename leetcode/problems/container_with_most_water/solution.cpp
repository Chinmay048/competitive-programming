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