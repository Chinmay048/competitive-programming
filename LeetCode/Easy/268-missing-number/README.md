# 268. Missing Number

**Difficulty**:  Easy  
**Topics**: `Array`, `Math`, `Bit Manipulation`, `Sorting`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/missing-number/)  
**Language**: C++

---

## Problem Description

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

### Example 1:
```
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 
2 is the missing number in the range since it does not appear in nums. 
```

### Example 2:
```
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 
2 is the missing number in the range since it does not appear in nums.
```

### Example 3:
```
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 
8 is the missing number in the range since it does not appear in nums. 
```

### Constraints:
- `n == nums.length`
- `1 <= n <= 10^4`
- `0 <= nums[i] <= n`
- All the numbers of `nums` are **unique**

**Follow-up**: Could you implement a solution using only `O(1)` extra space complexity and `O(n)` runtime complexity?

---

## My Approach (Mathematical Sum Formula)

### Intuition

This is a beautiful math-based solution!

The key insight:   We know **exactly** what numbers SHOULD be in the array:  `[0, 1, 2, 3, .. ., n]`

**Strategy:**
1. Calculate what the sum SHOULD be if all numbers were present
2. Calculate the ACTUAL sum of numbers in the array
3. The difference is the missing number!

**Visual Example:**
```
nums = [3, 0, 1]
n = 3 (array has 3 elements)

Expected range: [0, 1, 2, 3]
Expected sum:   0 + 1 + 2 + 3 = 6

Actual array:  [3, 0, 1]
Actual sum:  3 + 0 + 1 = 4

Missing number = 6 - 4 = 2 ✓
```

### The Math Behind It

**Sum of first n natural numbers formula:**
```
Sum = n × (n + 1) / 2

Examples:
0 + 1 + 2 + 3 = 3 × 4 / 2 = 6
0 + 1 + 2 + 3 + 4 = 4 × 5 / 2 = 10
0 + 1 + 2 + ...  + n = n × (n + 1) / 2
```

**Why this formula works:**

Imagine pairing numbers from opposite ends:
```
0 + 1 + 2 + 3 + 4 + 5

Pair them: 
(0 + 5) = 5
(1 + 4) = 5
(2 + 3) = 5

Three pairs of 5 = 15
Or using formula: 5 × 6 / 2 = 15 ✓
```

### Algorithm

1. Initialize `sum = 0`
2. Loop through the array and calculate actual sum
3. Calculate expected sum using formula:  `n × (n + 1) / 2`
4. Return the difference:  `expected_sum - actual_sum`

### Code

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        
        // Calculate actual sum
        for(int i = 0; i < nums. size(); i++)
            sum += nums[i];
        
        // Expected sum - Actual sum = Missing number
        return ((nums.size() * (nums.size() + 1)) / 2) - sum;
    }
};
```

### Step-by-Step Trace

Example: `nums = [9,6,4,2,3,5,7,0,1]`

```
Step 1: Calculate actual sum
sum = 9 + 6 + 4 + 2 + 3 + 5 + 7 + 0 + 1 = 37

Step 2: Calculate expected sum
n = 9 (array size)
expected_sum = 9 × (9 + 1) / 2 = 9 × 10 / 2 = 45

Step 3: Find missing number
missing = 45 - 37 = 8 ✓
```

### Complexity Analysis

- **Time Complexity**: `O(n)`
    - Single loop through the array to calculate sum
    - Formula calculation is O(1)

- **Space Complexity**: `O(1)`
    - Only using one variable `sum`
    - No extra data structures

### Why This Approach is Great

**Advantages:**
- Clean and elegant mathematical solution
- O(n) time with single pass
- O(1) space - no extra arrays needed
- Easy to understand once you know the formula
- No sorting or complex logic required

**Key Insight:**
- Uses mathematical property instead of brute force
- Leverages the constraint that numbers are in range [0, n]

---

## Alternative Solutions

### Solution 2: XOR Bit Manipulation (Also Optimal)

**Intuition:**  
XOR has a special property: `a ⊕ a = 0` and `a ⊕ 0 = a`

If we XOR all numbers from [0 to n] with all numbers in the array, pairs cancel out, leaving only the missing number!

**Visual Example:**
```
nums = [3, 0, 1]
n = 3

XOR all indices (0 to n):  0 ⊕ 1 ⊕ 2 ⊕ 3
XOR all array elements:    3 ⊕ 0 ⊕ 1

Combined:  0 ⊕ 1 ⊕ 2 ⊕ 3 ⊕ 3 ⊕ 0 ⊕ 1
         = 0 ⊕ 0 ⊕ 1 ⊕ 1 ⊕ 3 ⊕ 3 ⊕ 2
         = 0 ⊕ 0 ⊕ 0 ⊕ 2  (pairs cancel)
         = 2 ✓
```

**Code:**
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_result = nums. size();  // Start with n
        
        for(int i = 0; i < nums. size(); i++) {
            xor_result ^= i;           // XOR with index
            xor_result ^= nums[i];     // XOR with element
        }
        
        return xor_result;
    }
};
```

**Complexity:**
- Time: O(n)
- Space: O(1)

**Advantage over sum method:**
- No risk of integer overflow for very large arrays
- XOR operations are typically faster than addition

---

### Solution 3: Sorting (Less Optimal)

**Intuition:**
Sort the array and find the first index where `nums[i] != i`

**Code:**
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums. begin(), nums.end());
        
        // Check each position
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i)
                return i;
        }
        
        // If all match, missing number is n
        return nums.size();
    }
};
```

**Complexity:**
- Time: O(n log n) - due to sorting
- Space: O(1) or O(log n) - depending on sort implementation

**Disadvantage:**
- Slower due to sorting
- Modifies the original array

---

## Solution Comparison

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| **Math Sum** | O(n) | O(1) | Simple, elegant | Potential overflow |
| **XOR** | O(n) | O(1) | No overflow risk | Less intuitive |
| **Sorting** | O(n log n) | O(1) | Easy to understand | Slower, modifies array |

---

## Key Learnings

**Mathematical Insights:**
- Sum formula: `n × (n + 1) / 2` for consecutive numbers starting from 0
- This formula is derived from arithmetic progression
- Using math can simplify array problems significantly

**Problem-Solving Patterns:**
- When dealing with consecutive numbers, think about sum formulas
- Expected vs Actual comparison is a powerful technique
- Sometimes math is simpler than complex logic

**Optimization Techniques:**
- Mathematical formulas can achieve O(1) space
- Single pass through array is optimal for time
- XOR is useful for finding unique elements

**Edge Cases to Consider:**
- Missing number is 0: `[1,2,3]` → 0
- Missing number is n:  `[0,1,2]` → 3
- Single element: `[0]` → 1 or `[1]` → 0

---

## Test Cases

The solution handles:
- Small array: `[3,0,1]` → `2`
- Missing is 0: `[1,2,3]` → `0`
- Missing is n: `[0,1,2]` → `3`
- Large array: `[9,6,4,2,3,5,7,0,1]` → `8`
- Single element: `[0]` → `1`
- Two elements: `[0,1]` → `2`

---

## Why This Problem is Important

**Concept Practice:**
- Understanding arithmetic progressions
- Using mathematical formulas to optimize
- Thinking beyond brute force

**Interview Value:**
- Common coding interview question
- Tests mathematical thinking
- Multiple optimal solutions exist
- Good for follow-up questions (XOR approach)

**Real-World Application:**
- Data validation (checking for missing records)
- Sequence verification in databases
- Network packet loss detection
- File chunk verification in downloads

---

**Status**:  Solved  
**Date Solved**: 2026-01-05  
**Approach**: Mathematical Sum Formula  
**Complexity**: O(n) time, O(1) space - Optimal! 