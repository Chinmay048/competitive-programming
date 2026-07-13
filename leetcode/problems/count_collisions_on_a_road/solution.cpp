class Solution {
public:
    int countCollisions(string directions) {
        int left = 0;
        int right = directions.length() - 1;
        while (left <= right && directions[left] == 'L')
            left++;
        
        while (left <= right && directions[right] == 'R') 
            right--;
        int collisions = 0;
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') 
                collisions++;
            
        }
        
        return collisions;
    }
};