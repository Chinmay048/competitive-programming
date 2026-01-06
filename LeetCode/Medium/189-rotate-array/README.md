# 189. Rotate Array

**Difficulty**:  Medium  
**Topics**: `Array`, `Math`, `Two Pointers`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/rotate-array/)  
**Language**: C++

---

## Problem Description

Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

### Example 1:
```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation: 
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

### Example 2:
```
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:  
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

### Constraints:
- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`
- `0 <= k <= 10^5`

**Follow-up:**
- Try to come up with as many solutions as you can.  There are at least **three** different ways to solve this problem.
- Could you do it in-place with O(1) extra space?

---

## My Approach (Reversal Algorithm - Optimal!)

### Intuition

This is one of the most elegant solutions!  The key insight is:

**"Three reversals can achieve rotation!"**

Think about what rotation does:
- Takes last `k` elements and moves them to the front
- Remaining elements shift to the right

**The Magic Formula:**
1. Reverse the entire array
2. Reverse the first `k` elements
3. Reverse the remaining elements

**Visual Example:**
```
Original: [1, 2, 3, 4, 5, 6, 7], k = 3

Goal: Move last 3 elements [5,6,7] to front → [5,6,7,1,2,3,4]

Step 1: Reverse entire array
[1,2,3,4,5,6,7] → [7,6,5,4,3,2,1]

Step 2: Reverse first k=3 elements
[7,6,5,4,3,2,1] → [5,6,7,4,3,2,1]
 ^^^^^

Step 3: Reverse remaining n-k elements
[5,6,7,4,3,2,1] → [5,6,7,1,2,3,4] 
       ^^^^^^^

Result: [5,6,7,1,2,3,4] - Perfect!
```

**Why does this work?**

Let's break down the logic:
```
Original array: [A A A A | B B B]
                 ^^^^^^^   ^^^^^
                 n-k       k elements
                 elements

After full reverse: [B B B | A A A] (reversed)
                     ^^^^^   ^^^^^^^

After reversing first k:  [B B B | A A A]
                          ^^^^^
                          (un-reversed)

After reversing last n-k: [B B B | A A A]
                                    ^^^^^^^
                                    (un-reversed)

Final:  Elements in correct positions! 
```

### Algorithm

1. **Handle k > n**: Use `k = k % nums.size()` to handle cases where k exceeds array length
2. **Reverse entire array**: `reverse(nums.begin(), nums.end())`
3. **Reverse first k elements**: `reverse(nums.begin(), nums.begin() + k)`
4. **Reverse remaining n-k elements**: `reverse(nums.begin() + k, nums.end())`

### Code

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Handle k larger than array size
        k = k % nums. size();
        
        // Step 1: Reverse entire array
        reverse(nums.begin(), nums.end());
        
        // Step 2: Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Step 3: Reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};
```

### Step-by-Step Trace

Example:  `nums = [1,2,3,4,5,6,7], k = 3`

```
Initial: [1, 2, 3, 4, 5, 6, 7]

k = 3 % 7 = 3 (no change)

Step 1: Reverse entire array
reverse(begin, end)
[1,2,3,4,5,6,7] → [7,6,5,4,3,2,1]

Step 2: Reverse first k=3 elements
reverse(begin, begin+3)
[7,6,5,4,3,2,1] → [5,6,7,4,3,2,1]
 ^^^^^             ^^^^^

Step 3: Reverse remaining n-k=4 elements
reverse(begin+3, end)
[5,6,7,4,3,2,1] → [5,6,7,1,2,3,4]
       ^^^^^^^           ^^^^^^^

Final: [5,6,7,1,2,3,4] ✓
```

### Why `k % nums.size()` is Important

```
Example: nums = [1,2,3,4,5], k = 12

Without modulo: 
- Rotating 12 times = rotating 5 times + 5 times + 2 times
- After 5 rotations: back to original
- After 10 rotations: back to original
- So 12 rotations = 2 rotations

With modulo:
k = 12 % 5 = 2
- Directly rotate 2 positions
- Same result, much more efficient! 

Edge case: k = 0 or k = n
- Array remains unchanged (reversals cancel out)
```

### Complexity Analysis

- **Time Complexity**: `O(n)`
    - Three reverse operations
    - Each reverse is O(n/2) + O(k/2) + O((n-k)/2) ≈ O(n)
    - Total: O(n)

- **Space Complexity**: `O(1)`
    - In-place reversal
    - Only using iterators, no extra arrays
    - **This is optimal!**

---

## Alternative Approaches

### Approach 1: Using Extra Array (Brute Force)

**Idea:** Copy last k elements to a new array, then shift remaining elements.

```cpp
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    vector<int> temp(n);
    
    // Copy rotated positions
    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = nums[i];
    }
    
    nums = temp;
}
```

**Complexity:**
- Time: O(n)
- Space: O(n) ❌ - Uses extra array

---

### Approach 2: One by One Rotation (Naive)

**Idea:** Rotate array one position at a time, k times.

```cpp
void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    
    for(int i = 0; i < k; i++) {
        // Rotate once
        int last = nums[nums.size() - 1];
        for(int j = nums.size() - 1; j > 0; j--) {
            nums[j] = nums[j-1];
        }
        nums[0] = last;
    }
}
```

**Complexity:**
- Time: O(n × k) - Very slow for large k
- Space: O(1)

---

### Approach 3:  Cyclic Replacements (Advanced)

**Idea:** Place each element directly in its final position.

```cpp
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    int count = 0;
    
    for(int start = 0; count < n; start++) {
        int current = start;
        int prev = nums[start];
        
        do {
            int next = (current + k) % n;
            int temp = nums[next];
            nums[next] = prev;
            prev = temp;
            current = next;
            count++;
        } while(start != current);
    }
}
```

**Complexity:**
- Time: O(n)
- Space: O(1)
- More complex to understand

---

## Solution Comparison

| Approach | Time | Space | In-Place | Simplicity |
|----------|------|-------|----------|------------|
| **My Reversal Algorithm** | O(n) | O(1) | ✓ | ⭐⭐⭐⭐⭐ |
| Extra Array | O(n) | O(n) | ✗ | ⭐⭐⭐⭐⭐ |
| One by One | O(n×k) | O(1) | ✓ | ⭐⭐⭐⭐ |
| Cyclic Replacements | O(n) | O(1) | ✓ | ⭐⭐ |

**Winner:** My reversal algorithm!   Optimal time and space, plus it's elegant and easy to understand.

---

## Key Learnings

**Reversal Technique:**
- Reversing subarrays can achieve complex rearrangements
- Three reversals = rotation (mathematical property)
- This pattern appears in many array problems

**Modulo Arithmetic:**
- `k % n` handles k larger than array size
- Optimization: don't rotate more than necessary
- Edge cases: k = 0, k = n (array unchanged)

**In-Place Algorithms:**
- O(1) space is achievable even for complex operations
- Reversal is a powerful in-place operation
- No need for extra arrays if we're clever

**Problem-Solving Insight:**
- Sometimes the "trick" makes the problem trivial
- Multiple approaches exist - pick the best one
- Elegance and efficiency can go together

---

## Edge Cases Handled

| Input | k | Output | Explanation |
|-------|---|--------|-------------|
| `[1,2,3,4,5,6,7]` | 3 | `[5,6,7,1,2,3,4]` | Standard rotation |
| `[-1,-100,3,99]` | 2 | `[3,99,-1,-100]` | Negative numbers |
| `[1,2,3]` | 0 | `[1,2,3]` | k = 0, no rotation |
| `[1,2,3]` | 3 | `[1,2,3]` | k = n, full rotation |
| `[1,2,3]` | 4 | `[3,1,2]` | k > n, same as k=1 |
| `[1]` | 5 | `[1]` | Single element |
| `[1,2]` | 1 | `[2,1]` | Two elements |

---

## Visual Walkthrough

**Example:  [1,2,3,4,5,6,7], k = 3**

```
Initial State: 
Indices:   0  1  2  3  4  5  6
Array:   [1, 2, 3, 4, 5, 6, 7]

Goal: Last 3 elements move to front
      [5, 6, 7, 1, 2, 3, 4]

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Step 1: Reverse ENTIRE array
Before: [1, 2, 3, 4, 5, 6, 7]
         ↕  ↕  ↕  ↕  ↕  ↕  ↕
After:  [7, 6, 5, 4, 3, 2, 1]

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Step 2: Reverse FIRST k=3 elements
Before: [7, 6, 5 | 4, 3, 2, 1]
         ↕  ↕  ↕
After:  [5, 6, 7 | 4, 3, 2, 1]

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Step 3: Reverse REMAINING n-k=4 elements
Before: [5, 6, 7 | 4, 3, 2, 1]
                   ↕  ↕  ↕  ↕
After:  [5, 6, 7 | 1, 2, 3, 4]

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Final:  [5, 6, 7, 1, 2, 3, 4] ✓
```

---

## Mathematical Proof

**Why does this work?**

Let's denote the array as two parts:
- Part A: First n-k elements
- Part B:  Last k elements

```
Original: [A₁ A₂ A₃ ...  Aₙ₋ₖ | B₁ B₂ ...  Bₖ]

After step 1 (reverse all):
[Bₖ ...  B₂ B₁ | Aₙ₋ₖ ... A₂ A₁]

After step 2 (reverse first k):
[B₁ B₂ ... Bₖ | Aₙ₋ₖ ... A₂ A₁]

After step 3 (reverse last n-k):
[B₁ B₂ ...  Bₖ | A₁ A₂ ...  Aₙ₋ₖ]

This is exactly the rotated array!
```

---

## Test Cases

```cpp
// Test Case 1: Standard rotation
Input:   nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

// Test Case 2: With negative numbers
Input:  nums = [-1,-100,3,99], k = 2
Output:  [3,99,-1,-100]

// Test Case 3: k = 0
Input:  nums = [1,2,3], k = 0
Output:  [1,2,3]

// Test Case 4: k = n (full rotation)
Input:  nums = [1,2,3,4], k = 4
Output: [1,2,3,4]

// Test Case 5: k > n
Input:  nums = [1,2,3], k = 5
Output: [2,3,1] (same as k=2)

// Test Case 6: Single element
Input:  nums = [1], k = 3
Output: [1]

// Test Case 7: Rotate by 1
Input:  nums = [1,2,3,4,5], k = 1
Output: [5,1,2,3,4]
```

---

## Why This Problem is Important

**Algorithm Pattern:**
- Reversal technique is a classic array manipulation
- Appears in string rotation, array partition problems
- Foundation for understanding in-place algorithms

**Interview Value:**
- Very common in coding interviews (Google, Amazon, Microsoft)
- Tests multiple approaches and optimization thinking
- Good for discussing trade-offs (time vs space)
- Follow-up questions about edge cases

**Real-World Applications:**
- Circular buffers in operating systems
- Image rotation algorithms
- Shift operations in cryptography
- Time series data manipulation

---

## Problem Insights

**Why reversal works better than shifting:**

```
Shifting approach (one by one):
- For k rotations: O(n × k) time
- Example: k=1000, n=1000 → 1,000,000 operations

Reversal approach:
- Always O(n) regardless of k
- Example: k=1000, n=1000 → ~3000 operations (3 reversals)

```

**The "Aha!" Moment:**
> "Instead of moving elements one by one, reverse sections to rearrange the entire array in O(n) time!"

---

**Status**: Solved  
**Date Solved**: 2026-01-06  
**Approach**: Reversal Algorithm (Three Reversals)  
**Complexity**: O(n) time, O(1) space - Optimal!  
**Key Pattern**: Array reversal for in-place rotation  
**Difficulty Rating**: Medium - but elegant solution makes it feel easy! 