class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        
        double sum=0.0;
        int n=prices.size();
        int m=discounts.size();

        for(int i=0;i<prices.size();i++){
            if(i<m)
                sum+=prices[i]*(100.0-discounts[i])/100.0;
            else 
                sum+=prices[i];
        }
        return sum;
    }
};