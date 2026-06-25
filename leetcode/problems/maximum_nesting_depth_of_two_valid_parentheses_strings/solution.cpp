class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> v;
        int depth=0;
        for(char c:seq){
            if(c=='('){
                depth++;
                v.push_back(depth%2);
            }
            else{
                v.push_back(depth%2);
                depth--;
            }
        }
        return v;
    }
};