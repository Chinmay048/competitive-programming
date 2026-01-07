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