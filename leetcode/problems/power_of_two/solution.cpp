class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long int pro=1;
        int i=0;
        while(pro<=n){
            if(n==pro)
                return true;
            else if(n<pro)
                return false;
            else 
                pro*=2;
        }
        return false;
    }
};