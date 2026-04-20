class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size()-1,max=0;
        if(colors[0]!=colors[n])
            return n;
        else {
            for(int i=0,j=n;i<=j;j--){
                if(colors[i]!=colors[j]){
                    max=j-i;
                    break;
                }
            }
            for(int i=0,j=n;i<=j;i++){
                if(colors[i]!=colors[j])
                    if(max<j-i){    
                        max=j-i;
                        return max;
                    }
            }
            return max;
        }
    }
};