# 66. Plus One

**Difficulty**: Easy  
**Topics**: `Array`, `Math`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/plus-one/)  
**Language**: C++

---

## Problem Description

You are given a **large integer** represented as an integer array `digits`, where each `digits[i]` is the `ith` digit of the integer. The digits are ordered from most significant to least significant in left-to-right order.  The large integer does not contain any leading `0`'s.

Increment the large integer by one and return the resulting array of digits.

### Example 1:
```
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4]. 
```

### Example 2:
```
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation:  The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
```

### Example 3:
```
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
```

### Constraints:
- `1 <= digits.length <= 100`
- `0 <= digits[i] <= 9`
- `digits` does not contain any leading `0`'s

---

## My Approach (Reverse Iteration with Carry Handling)

### Intuition

This problem simulates adding 1 to a number represented as an array of digits, just like doing addition by hand!

The key insight is to work **from right to left** (least significant to most significant digit):
1. Add 1 to the last digit
2. Handle carry propagation (when digit becomes 10)
3. Special case: if the first digit becomes 10, we need an extra digit at the front

**Visual Example:**
```
digits = [9,9,9]

Step 1: Start from rightmost digit (9)
        9 + 1 = 10 → Set to 0, carry 1
        [9,9,0]

Step 2: Move to next digit (9)
        9 + 1 (carry) = 10 → Set to 0, carry 1
        [9,0,0]

Step 3: Move to first digit (9)
        9 + 1 (carry) = 10 → Set to 0, need new digit
        [1,0,0,0]

Result: [1,0,0,0] = 1000
```

### Algorithm

1. **Iterate from right to left** (`i = size-1` to `i = 0`):

2. **For the last digit** (`i == size-1`):
    - Add 1: `digits[i]++`

3. **Handle carry**:
    - If `digits[i] == 10`:
        - Set current digit to 0: `digits[i] = 0`
        - If **not** the first digit: Carry to previous:  `digits[i-1]++`
        - If **is** the first digit:
            - Add new digit at the end: `digits.push_back(0)`
            - Set first digit to 1: `digits[0] = 1`

4. **Return modified array**

### Why This Works

- **Right to Left**: Mimics natural addition process
- **Carry Propagation**:  When a digit becomes 10, it carries over to the next significant digit
- **Edge Case (999...9)**: When all digits are 9, we need an extra digit at the front
- **Early Termination**: If no carry, we can stop (loop naturally handles this)

---

## Complexity Analysis

- **Time Complexity**: `O(n)`
    - We iterate through the array once from right to left
    - In the worst case (all 9's), we process every digit
    - Where `n = digits.length`

- **Space Complexity**: `O(1)`
    - We modify the array in-place
    - Only one extra digit added in worst case (which is part of output)
    - No auxiliary data structures used

---

## Current Solution

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1; i >= 0; i--){
            // Add 1 to the last digit
            if(i == digits.size()-1)
                digits[i]++;
            
            // Handle carry
            if(digits[i] == 10){
                digits[i] = 0;
                
                if(i != 0)
                    // Carry to previous digit
                    digits[i-1]++;
                else{
                    // Need extra digit at front
                    digits. push_back(0);
                    digits[i] = 1;
                }
            }
        }
        return digits;
    }
};
```

**See `solution.cpp` for complete code with test cases.**

---

## Edge Cases Handled

| Input | Output | Explanation |
|-------|--------|-------------|
| `[1,2,3]` | `[1,2,4]` | Simple case: no carry |
| `[1,9,9]` | `[2,0,0]` | Carry propagates through multiple digits |
| `[9]` | `[1,0]` | Single digit overflow |
| `[9,9,9]` | `[1,0,0,0]` | All 9's - need extra digit |
| `[0]` | `[1]` | Edge case: zero |

---


## Test Cases

The solution handles:
- No carry: `[1,2,3]` → `[1,2,4]`
- Single carry: `[1,2,9]` → `[1,3,0]`
- Multiple carries: `[1,9,9]` → `[2,0,0]`
- All nines: `[9,9,9]` → `[1,0,0,0]`
- Single digit: `[9]` → `[1,0]`
- Large array: `[4,3,2,1]` → `[4,3,2,2]`

---

## Problem Insights

**Why not convert to integer? **
- The problem uses an array because the number might be **too large** for standard integer types
- In languages like Java/C++, even `long long` has limits
- Array representation allows arbitrary precision (like Python's big integers)

**Real-world application:**
- This is how arbitrary precision arithmetic libraries work
- Used in cryptography, scientific computing, and financial calculations
- Foundation for understanding big number operations

---

**Status**:  Solved  
**Date Solved**:  2026-01-05  
**Difficulty**: Easy - Good practice for array manipulation and carry logic!  