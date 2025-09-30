class Solution {
public:
    int newNums(vector<int>& v){
        vector<int> temp;
        if(v.size()==1)
            return v[0];
        else
            for(int i=0;i<v.size()-1;i++)
                temp.push_back((v[i]+v[i+1])%10);
        
        return newNums(temp);
    }
    int triangularSum(vector<int>& nums) {
        return newNums(nums);
    }
};