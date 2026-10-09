class Solution {
public:
    int minInsertions(string s) {
        int insert=0;
        int req_right=0;
        for(char c:s){
            if(c=='('){
                if(req_right%2!=0){
                    req_right--;
                    insert++;
                }
                req_right+=2;
            }
            else{
                req_right--;
                if(req_right<0){
                    insert++;
                    req_right=1;
                }
            }
        }
        return insert+req_right;
    }
};