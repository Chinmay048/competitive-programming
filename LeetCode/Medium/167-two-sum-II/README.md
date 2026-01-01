# 167.  Two Sum II - Input Array Is Sorted

**Difficulty**:  🟡 Medium  
**Topics**: `Array`, `Two Pointers`, `Binary Search`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)  
**Language**: C++

---

## Problem Description

Given a **1-indexed** array of integers `numbers` that is already **sorted in non-decreasing order**, find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.

Return the indices of the two numbers, `index1` and `index2`, **added by one** as an integer array `[index1, index2]` of length 2.

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

Your solution must use only constant extra space.

### Example 1:
```
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
```

### Example 2:
```
Input: numbers = [2,3,4], target = 6
Output:  [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
```

### Example 3:
```
Input: numbers = [-1,0], target = -1
Output:  [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
```

### Constraints:
- `2 <= numbers.length <= 3 * 10^4`
- `-1000 <= numbers[i] <= 1000`
- `numbers` is sorted in **non-decreasing order**
- `-1000 <= target <= 1000`
- The tests are generated such that there is **exactly one solution**

---

## My Approach (Two Pointers)

### Intuition

Since the array is **already sorted**, we can take advantage of this property!

Instead of checking every pair (which would be O(n²)), we can use **two pointers**:
- One pointer starts at the **beginning** (smallest number)
- One pointer starts at the **end** (largest number)

If the sum is:
- **Too small** → move left pointer right (increase sum)
- **Too large** → move right pointer left (decrease sum)
- **Exactly target** → found it!

This works because the array is sorted, so we know which direction to move!

###  Algorithm

1. Initialize two pointers: `left = 0`, `right = n - 1`
2. While `left < right`:
    - Calculate `sum = numbers[left] + numbers[right]`
    - If `sum == target`: return `[left + 1, right + 1]` (1-indexed)
    - If `sum > target`: decrease sum by moving `right--`
    - If `sum < target`: increase sum by moving `left++`
3. Return result

### Why This Works

- **Sorted array** means moving pointers changes sum predictably
- **Two pointers** eliminate need to check all pairs
- **Constant space** - only using two variables
- **Guaranteed solution** means we'll always find it

---

##  Complexity Analysis

- **Time Complexity**: `O(n)`
    - We traverse the array at most once
    - Each pointer moves at most n times
    - Much better than O(n²) brute force!

- **Space Complexity**: `O(1)`
    - Only using two pointer variables
    - No extra data structures needed
    - Meets the "constant extra space" requirement 

---

## Solution Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            
            if(sum == target)
                return {left + 1, right + 1};
            else if(sum > target)
                right--;
            else
                left++;
        }
        
        return {0};
    }
};
```

**See `solution.cpp` for complete implementation with test cases.**

---

##  Key Learnings

1. **Two Pointers Pattern**: Perfect for sorted arrays
2. **Leverage Sorting**: Use sorted property to optimize from O(n²) to O(n)
3. **1-Indexed vs 0-Indexed**: Remember to return `left + 1` and `right + 1`
4. **Space Constraint**: Two pointers use O(1) space (vs hash map's O(n))
5. **Pointer Movement Logic**:
    - Sum too small → need bigger numbers → move left pointer right
    - Sum too large → need smaller numbers → move right pointer left

---

## Alternative Approaches

### Approach 1: Brute Force 
```cpp
// Time: O(n²), Space: O(1)
for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
        if(numbers[i] + numbers[j] == target)
            return {i + 1, j + 1};
    }
}
```
**Why not? ** Too slow, doesn't use sorted property

**Why not?** Uses O(n) space, violates "constant space" requirement

### Approach 2: Binary Search 
```cpp
// Time: O(n log n), Space: O(1)
// For each element, binary search for complement
```
**Why not?** Slower than two pointers (O(n log n) vs O(n))

### Approach 3: Two Pointers  (Current)
**Perfect!** O(n) time, O(1) space, uses sorted property

---

##  Submission Results

- **Status**: Accepted 
- **Runtime**: Beats ~85% of C++ submissions
- **Memory**:  Beats ~90% of C++ submissions (O(1) space!)
- **Date Solved**: 2026-01-01

---

## Tags

`#array` `#twopointers` `#medium` `#sorted-array` `#interview-favorite` `#optimal`

---


**Last Updated**: 2026-01-01  
**Author**: [Chinmay048](https://github.com/Chinmay048)

---

> **Key Takeaway**:  When you see a **sorted array** in a problem, think **Two Pointers** or **Binary Search** first! 