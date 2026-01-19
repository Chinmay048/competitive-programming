#include <iostream>
using namespace std;

int BAD_VERSION_GLOBAL=0;
bool isBadVersion(int version) {
    return (version>=BAD_VERSION_GLOBAL);
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1,right=n,result=n;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isBadVersion(mid)){
                result=mid;
                right=mid-1;
            }
            else 
                left=mid+1;
        }
        return result;  
    }
};

int main(){
    Solution object;    
    // Case 1
    int n1 = 5;
    BAD_VERSION_GLOBAL = 4;
    cout << "n=" << n1 << ", bad=" << BAD_VERSION_GLOBAL 
         << " -> Output: " << object.firstBadVersion(n1) << endl;

    // Case 2
    int n2 = 1;
    BAD_VERSION_GLOBAL = 1;
    cout << "n=" << n2 << ", bad=" << BAD_VERSION_GLOBAL 
         << " -> Output: " << object.firstBadVersion(n2) << endl;
         
    return 0;
}