# 1. Two Sum

**Difficulty**: 🟢 Easy  
**Topics**: `Array`, `Hash Table`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/two-sum/)  
**Language**: C++

---

##  Problem Description

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

### Example 1:
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

### Example 2:
```
Input: nums = [3,2,4], target = 6
Output:  [1,2]
```

### Example 3:
```
Input: nums = [3,3], target = 6
Output: [0,1]
```

### Constraints:
- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- Only one valid answer exists.

---

##  My Approach (Brute Force)

###  Intuition

Since I haven't learned hash maps yet, I'm using a straightforward nested loop approach:
- For each element, check if any element after it adds up to the target
- When found, return both indices

This is the most intuitive solution and helps me understand the problem well!

###  Algorithm

1. Loop through each element with index `i`
2. Calculate `temp = target - nums[i]` (the number we're looking for)
3. Loop through remaining elements with index `j` (where j > i)
4. If `nums[j] == temp`, we found our pair!
5. Return `[i, j]`

###  Why This Works

- We check every possible pair of numbers
- By starting the inner loop from `i+1`, we avoid:
    - Using the same element twice
    - Checking pairs we've already seen
- Simple and correct!

---

##  Complexity Analysis

- **Time Complexity**: `O(n²)`
    - Outer loop runs n times
    - Inner loop runs (n-1), (n-2), ..., 1 times
    - Total: n × (n-1) / 2 comparisons ≈ O(n²)

- **Space Complexity**: `O(1)`
    - Only using a few variables (temp, i, j)
    - Result vector doesn't count toward space complexity

---

##  Current Solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int temp;
        
        for(int i = 0; i < nums.size(); i++) {
            temp = target - nums[i];
            
            for(int j = i + 1; j < nums.size(); j++) {
                if(temp == nums[j]) {
                    vector<int> a = {i, j};
                    return a;
                }
            }
        }
        
        return {0};
    }
};
```

**See `solution.cpp` for complete code with test cases.**

---

##  Key Learnings

1. **Nested Loops**:  Useful for checking all pairs in an array
2. **Complement Logic**: For sum problems, think "what do I need to find?"
3. **Index Management**: Starting inner loop from `i+1` avoids duplicates
4. **Trade-offs**: Simple code but slower for large inputs

---

##  Future Optimization

> **Note**: This solution works but is O(n²). Once I learn **hash maps**, I can optimize this to **O(n)** time complexity!

### Optimized Approach (To Learn):
- Use a hash map to store seen numbers
- Check in O(1) time if complement exists
- Only need single pass through array

**I'll update this solution once I master hash maps!** 📚

---

##  Alternative Approaches

### Current:  Brute Force (Nested Loops)
- **Time**: O(n²)
- **Space**: O(1)
- **Pros**: Simple, easy to understand, no extra data structures
- **Cons**:  Slow for large inputs

### Future: Hash Map (To Implement)
- **Time**: O(n)
- **Space**: O(n)
- **Pros**: Much faster
- **Cons**: Uses extra memory, requires understanding hash maps

---

##  Submission Results

- **Status**: Accepted 
- **Runtime**:  Beats ~30-40% of C++ submissions (brute force)
- **Memory**: Beats ~70-80% of C++ submissions (low memory usage)
- **Date Solved**: 2026-01-01

---


## Tags

`#array` `#bruteforce` `#twopointers` `#easy` `#to-optimize` `#learning`

---

**Version**:  1.0 (Brute Force)  
**Last Updated**: 2026-01-01  
**Author**: [Chinmay048](https://github.com/Chinmay048)

---

>  "Start with what you know, optimize as you grow!"*