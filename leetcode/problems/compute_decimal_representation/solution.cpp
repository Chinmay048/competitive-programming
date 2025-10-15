class Solution {
public:
    vector<int> decimalRepresentation(int n) {
       vector<int> result;
        long long power=1;
        while(power<=n) power*=10;
        while(power>1){
            power/=10;
            int d=n/power;
            if(d!=0)
                result.push_back(d*power);  
            n=n%power; 
        }
        return result;
    }
};