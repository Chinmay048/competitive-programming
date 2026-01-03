class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        int max_c = 0, curr = 0;
        for(int n : nums) {
            if(n == 1) {
                curr++;
                if(curr > max_c) max_c = curr;
            } else {
                curr = 0;
            }
        }
        return max_c;
    }
};
