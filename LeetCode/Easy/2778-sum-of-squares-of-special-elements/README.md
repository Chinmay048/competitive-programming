# 2778. Sum of Squares of Special Elements

**Difficulty**: Easy  
**Topics**: `Array`, `Math`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/sum-of-squares-of-special-elements/)  
**Language**: C++

---

## Problem Description

You are given a **1-indexed** integer array `nums` of length `n`.

An element `nums[i]` of `nums` is called **special** if `i` divides `n`, i.e.  `n % i == 0`.

Return the **sum of the squares** of all **special** elements of `nums`.

### Example 1:
```
Input: nums = [1,2,3,4]
Output: 21
Explanation: There are exactly 3 special elements in nums: nums[1] since 1 divides 4, 
nums[2] since 2 divides 4, and nums[4] since 4 divides 4.
Hence, the sum of the squares of all special elements of nums is 
nums[1] * nums[1] + nums[2] * nums[2] + nums[4] * nums[4] = 1 * 1 + 2 * 2 + 4 * 4 = 21.
```

### Example 2:
```
Input: nums = [2,7,1,19,18,3]
Output: 63
Explanation: There are exactly 4 special elements in nums: nums[1] since 1 divides 6, 
nums[2] since 2 divides 6, nums[3] since 3 divides 6, and nums[6] since 6 divides 6.
Hence, the sum of the squares of all special elements of nums is 
nums[1] * nums[1] + nums[2] * nums[2] + nums[3] * nums[3] + nums[6] * nums[6] = 
2 * 2 + 7 * 7 + 1 * 1 + 3 * 3 = 63.
```

### Constraints:
- `1 <= nums.length == n <= 50`
- `1 <= nums[i] <= 50`

---

## My Approach (Direct Iteration with Divisibility Check)

### Intuition

This problem has a straightforward approach!

**Key Understanding:**
- The array is **1-indexed** in the problem description
- But in code, arrays are **0-indexed**
- So position `i` in 0-indexed corresponds to position `i+1` in 1-indexed

**What makes an element "special"?**
- An element at 1-indexed position `p` is special if `p` divides `n`
- In 0-indexed:  element at position `i` is special if `(i+1)` divides `n`
- Check:  `n % (i+1) == 0`

**Visual Example:**
```
nums = [1, 2, 3, 4]  (0-indexed:  indices 0,1,2,3)
n = 4

1-indexed positions:  1, 2, 3, 4

Check divisibility:
Position 1: 4 % 1 = 0 ✓ → nums[0]=1 is special → square = 1
Position 2: 4 % 2 = 0 ✓ → nums[1]=2 is special → square = 4
Position 3: 4 % 3 = 1 ✗ → nums[2]=3 is NOT special
Position 4: 4 % 4 = 0 ✓ → nums[3]=4 is special → square = 16

Sum = 1 + 4 + 16 = 21 ✓
```

**Strategy:**
1. Iterate through array (0-indexed from 0 to n-1)
2. For each position `i`, check if `(i+1)` divides `n`
3. If yes, add `nums[i]² ` to the sum
4. Return total sum

### Algorithm

1. Get array length `n = nums.size()`
2. Initialize `sum = 0`
3. Loop through array with index `i` from 0 to n-1:
    - Check if `n % (i+1) == 0` (i+1 because of 1-indexing)
    - If true:  add `nums[i] * nums[i]` to sum
4. Return sum

### Code

```cpp
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        
        for(int i = 0; i < nums.size(); i++)
            if(n % (i + 1) == 0)  // Check if (i+1) divides n
                sum += nums[i] * nums[i];  // Add square
        
        return sum;
    }
};
```

### Alternative Cleaner Version

```cpp
class Solution {
public: 
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        // Check each 1-indexed position
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) {
                sum += nums[i-1] * nums[i-1];  // i-1 for 0-indexed array
            }
        }
        
        return sum;
    }
};
```

### Step-by-Step Trace

**Example 1:** `nums = [1,2,3,4]`

```
n = 4
sum = 0

i=0: (i+1)=1
     n % 1 = 4 % 1 = 0 ✓
     nums[0] = 1
     sum = 0 + 1*1 = 1

i=1: (i+1)=2
     n % 2 = 4 % 2 = 0 ✓
     nums[1] = 2
     sum = 1 + 2*2 = 5

i=2: (i+1)=3
     n % 3 = 4 % 3 = 1 ✗
     Skip

i=3: (i+1)=4
     n % 4 = 4 % 4 = 0 ✓
     nums[3] = 4
     sum = 5 + 4*4 = 21

Return 21 ✓
```

**Example 2:** `nums = [2,7,1,19,18,3]`

```
n = 6
sum = 0

i=0: (i+1)=1
     6 % 1 = 0 ✓
     sum = 0 + 2*2 = 4

i=1: (i+1)=2
     6 % 2 = 0 ✓
     sum = 4 + 7*7 = 53

i=2: (i+1)=3
     6 % 3 = 0 ✓
     sum = 53 + 1*1 = 54

i=3: (i+1)=4
     6 % 4 = 2 ✗
     Skip

i=4: (i+1)=5
     6 % 5 = 1 ✗
     Skip

i=5: (i+1)=6
     6 % 6 = 0 ✓
     sum = 54 + 3*3 = 63

Return 63 ✓
```

### Why This Works

**Divisibility Property:**
- Divisors of n are exactly the positions that make elements "special"
- For n=6, divisors are:  1, 2, 3, 6
- These correspond to 0-indexed positions: 0, 1, 2, 5
- For n=4, divisors are: 1, 2, 4
- These correspond to 0-indexed positions: 0, 1, 3

**Index Conversion:**
- Problem uses 1-indexed:  positions start at 1
- Array uses 0-indexed: positions start at 0
- Conversion:  `1-indexed position = 0-indexed position + 1`
- So we check: `n % (i+1) == 0`

### Complexity Analysis

- **Time Complexity**:  `O(n)`
    - Single loop through array
    - Each iteration: O(1) operations (modulo, multiplication, addition)
    - Total: O(n)

- **Space Complexity**: `O(1)`
    - Only using two variables:  `n` and `sum`
    - No extra data structures

---

## Understanding Divisors

**What are divisors?**

For a number n, a divisor is a number d where `n % d == 0`

**Examples:**
```
n = 4
Divisors: 1, 2, 4
Special positions (1-indexed): 1, 2, 4

n = 6
Divisors:  1, 2, 3, 6
Special positions (1-indexed): 1, 2, 3, 6

n = 12
Divisors: 1, 2, 3, 4, 6, 12
Special positions (1-indexed): 1, 2, 3, 4, 6, 12

n = 7 (prime)
Divisors: 1, 7
Special positions (1-indexed): 1, 7
```

**Number of divisors:**
- Always includes 1 and n
- Prime numbers have exactly 2 divisors
- Perfect squares have odd number of divisors
- Most numbers:  between 2 and O(√n) divisors

---

## Edge Cases Handled

| Input | n | Divisors | Output | Explanation |
|-------|---|----------|--------|-------------|
| `[1,2,3,4]` | 4 | 1,2,4 | 21 | 1² + 2² + 4² = 21 |
| `[2,7,1,19,18,3]` | 6 | 1,2,3,6 | 63 | 2² + 7² + 1² + 3² = 63 |
| `[1]` | 1 | 1 | 1 | Only position 1 |
| `[5,10]` | 2 | 1,2 | 125 | 5² + 10² = 125 |
| `[3,5,7]` | 3 | 1,3 | 58 | 3² + 7² = 58 |
| `[2,3,5,7,11]` | 5 | 1,5 | 125 | 2² + 11² = 125 |

---

## Key Learnings

**Index Conversion:**
- Problem uses 1-indexed (mathematical convention)
- Code uses 0-indexed (programming convention)
- Always convert properly:  `1-indexed = 0-indexed + 1`

**Divisibility:**
- Modulo operator `%` checks divisibility
- `n % d == 0` means d divides n evenly
- Understanding divisors is fundamental in math problems

**Problem-Solving Pattern:**
- Read problem carefully for indexing convention
- Identify mathematical property (divisibility here)
- Simple iteration with conditional check

**Squaring:**
- `nums[i] * nums[i]` computes square
- Can also use `pow(nums[i], 2)` but multiplication is faster
- No need to import math library

---

## Test Cases

```cpp
// Test Case 1: Example from problem
Input:    nums = [1,2,3,4]
Output:  21
Trace:  Positions 1,2,4 divide 4
        1² + 2² + 4² = 1 + 4 + 16 = 21

// Test Case 2: Example from problem
Input:  nums = [2,7,1,19,18,3]
Output:   63
Trace:  Positions 1,2,3,6 divide 6
        2² + 7² + 1² + 3² = 4 + 49 + 1 + 9 = 63

// Test Case 3: Single element
Input:  nums = [5]
Output:  25
Trace:  Position 1 divides 1
        5² = 25

// Test Case 4: Two elements
Input:  nums = [3,7]
Output: 58
Trace:  Positions 1,2 divide 2
        3² + 7² = 9 + 49 = 58

// Test Case 5: Prime length
Input:  nums = [2,3,5,7,11]
Output: 125
Trace:  Positions 1,5 divide 5 (prime)
        2² + 11² = 4 + 121 = 125

// Test Case 6: Perfect square length
Input:  nums = [1,2,3,4,5,6,7,8,9]
Output: 207
Trace:  Positions 1,3,9 divide 9
        1² + 3² + 9² = 1 + 9 + 81 = 91
        Wait, also check all divisors:  1,3,9
        1² + 3² + 9² = 91
```

---

## Problem Insights

**Common Pitfalls:**
1. **Forgetting the +1**: Using `n % i` instead of `n % (i+1)`
2. **Off-by-one errors**: Confusing 0-indexed with 1-indexed
3. **Loop bounds**: Make sure to check all positions

**Why 1-indexed in problem?**
- Mathematical convention (positions start at 1)
- Makes divisibility check more intuitive
- Common in math-related problems

**Optimization note:**
- This problem requires checking all positions:  O(n)
- Cannot optimize further without changing problem
- Already optimal for this problem type

---

**Status**: ✓ Solved  
**Date Solved**: 2026-01-06  
**Approach**: Direct iteration with divisibility check  
**Complexity**: O(n) time, O(1) space - Optimal!   
**Key Concept**: 1-indexed to 0-indexed conversion  
**Difficulty**: Easy - straightforward once you handle indexing!  