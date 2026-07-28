class Solution {
public:
    string smallestPalindrome(string s) {
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }

        string left = "", middle = "";
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                left += string(count[i] / 2, 'a' + i);
                if (count[i] % 2 != 0) {
                    middle = string(1, 'a' + i);
                }
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        return left + middle + right; 
    }
};