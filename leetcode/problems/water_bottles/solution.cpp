class Solution {
public:
    int numWaterBottles(int bottle, int exchange) {
        if(exchange!=0){
            int sum=bottle;
            while(bottle>=exchange){
                sum+=bottle/exchange;
                bottle=(bottle%exchange)+bottle/exchange;
            }
            return sum;
        }
        return bottle;
    }
};