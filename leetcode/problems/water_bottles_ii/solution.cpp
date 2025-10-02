class Solution {
public:
    int maxBottlesDrunk(long long int numBottles,long long int numExchange) {
        int empty=numBottles,sum=numBottles;
        while(empty>=numExchange){
            empty=empty-numExchange+1;
            numExchange++;
            sum++;
        }
        return sum;
    }
};