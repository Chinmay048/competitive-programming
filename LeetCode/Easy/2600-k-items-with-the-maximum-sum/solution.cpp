#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k<numOnes)
            return k;
        else if(k<numZeros)
            return numOnes;
        else if(k>numOnes+numZeros){
            int temp=k-(numOnes+numZeros);
            return numOnes-temp;
        }
        else
            return numOnes;
    }
};
int main() {
  Solution object;
  //case1
  int numOnes1=3,numZeros1=2,numNegOnes1=0,k1=2;
  cout<<object.kItemsWithMaximumSum(numOnes1,numZeros1,numNegOnes1,k1)<<endl;

  //case2
  int numOnes2=3,numZeros2=2,numNegOnes2=0,k2=4;
  cout<<object.kItemsWithMaximumSum(numOnes2,numZeros2,numNegOnes2,k2);

  return 0;
}