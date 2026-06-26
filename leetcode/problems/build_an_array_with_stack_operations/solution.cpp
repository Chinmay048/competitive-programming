class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> stk;
        for(int i=1,j=0;j<target.size() && i<=n;i++){
            if(i==target[j]){
                stk.push_back("Push");
                j++;
            }
            else{
                stk.push_back("Push");
                stk.push_back("Pop");
            }
        }
        return stk;
    }
};