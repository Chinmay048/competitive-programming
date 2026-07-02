class Solution {
public:
    int removePairs(string& s, char first, char second, int points) {
        string stk = ""; 
        int score = 0;
        
        for (char c : s) {
            if (!stk.empty() && stk.back() == first && c == second) {
                stk.pop_back();
                score += points;
            } 
            else 
                stk.push_back(c);
            
        }
        s = stk; 
        return score;
    }

    int maximumGain(string s, int x, int y) {
        int total_points = 0;
        if (x > y) {
            total_points += removePairs(s, 'a', 'b', x); 
            total_points += removePairs(s, 'b', 'a', y); 
        } else {
            total_points += removePairs(s, 'b', 'a', y); 
            total_points += removePairs(s, 'a', 'b', x);
        }
        
        return total_points;
    }
};