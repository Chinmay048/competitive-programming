# 283. Move Zeroes

**Difficulty**:  Easy  
**Topics**: `Array`, `Two Pointers`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/move-zeroes/)  
**Language**: C++

---

## Problem Description

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Note:** You must do this **in-place** without making a copy of the array.

### Example 1:
```
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```

### Example 2:
```
Input: nums = [0]
Output: [0]
```

### Constraints:
- `1 <= nums.length <= 10^4`
- `-2^31 <= nums[i] <= 2^31 - 1`

**Follow-up:** Could you minimize the total number of operations done?

---

## My Approach (Two Pointers with Swap)

### Intuition

The key insight:  **Use two pointers to partition the array! **

Think of it like organizing a bookshelf:
- One pointer (`i`) scans through all books
- Another pointer (`j`) marks the position where the next non-zero book should go
- When we find a non-zero book, we swap it to position `j` and move `j` forward

**Visual Example:**
```
Original: [0, 1, 0, 3, 12]
           i
           j

Step-by-step:
i=0: nums[0]=0 → Skip (don't swap)
     [0, 1, 0, 3, 12]
      j  i

i=1: nums[1]=1 → Swap with j=0, j++
     [1, 0, 0, 3, 12]
         j  i

i=2: nums[2]=0 → Skip
     [1, 0, 0, 3, 12]
         j     i

i=3: nums[3]=3 → Swap with j=1, j++
     [1, 3, 0, 0, 12]
            j     i

i=4: nums[4]=12 → Swap with j=2, j++
     [1, 3, 12, 0, 0]
               j     i

Final: [1, 3, 12, 0, 0] 
```

**Why this works:**
- Pointer `j` always points to where the next non-zero should be placed
- All elements before `j` are non-zero (in original order)
- All elements from `j` to `i-1` are zeros
- Swapping maintains relative order of non-zero elements

### Algorithm

1. Initialize `j = 0` (position for next non-zero element)
2. Loop through array with pointer `i`:
    - If `nums[i] != 0`:
        - Swap `nums[i]` with `nums[j]`
        - Increment `j`
    - If `nums[i] == 0`:
        - Skip (just move `i` forward)
3. Array is modified in-place, no return needed

### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;  // Position for next non-zero element
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
```

### Step-by-Step Trace

Example: `nums = [0,1,0,3,12]`

```
Initial: [0, 1, 0, 3, 12], j=0

i=0: nums[0]=0 → Skip
     [0, 1, 0, 3, 12], j=0

i=1: nums[1]=1 ≠ 0 → swap(nums[1], nums[0]), j=1
     [1, 0, 0, 3, 12], j=1

i=2: nums[2]=0 → Skip
     [1, 0, 0, 3, 12], j=1

i=3: nums[3]=3 ≠ 0 → swap(nums[3], nums[1]), j=2
     [1, 3, 0, 0, 12], j=2

i=4: nums[4]=12 ≠ 0 → swap(nums[4], nums[2]), j=3
     [1, 3, 12, 0, 0], j=3

Final: [1, 3, 12, 0, 0] ✓
```

### Why This Works

**Invariants maintained throughout:**
1. **Before j**:  All non-zero elements in original relative order
2. **From j to i-1**: All zeros
3. **From i onwards**: Not yet processed

**Key Properties:**
- Swapping `nums[i]` with `nums[j]` moves non-zero to correct position
- When `nums[i]` is zero, we don't swap (it stays in the "zero zone")
- When `nums[i]` is non-zero and `i == j`, we swap element with itself (no change)
- Relative order preserved because we process left to right

### Complexity Analysis

- **Time Complexity**: `O(n)`
    - Single pass through the array
    - Each element visited exactly once
    - Swap operation is O(1)

- **Space Complexity**: `O(1)`
    - Only two pointer variables (`i` and `j`)
    - In-place modification
    - No extra arrays or data structures

---

## Alternative Approaches

### Approach 1: Brute Force (Not Optimal)

**Idea:** Count zeros, create new array with non-zeros first, then add zeros.

```cpp
void moveZeroes(vector<int>& nums) {
    vector<int> result;
    int zeroCount = 0;
    
    // Collect non-zeros
    for(int num : nums) {
        if(num != 0)
            result.push_back(num);
        else
            zeroCount++;
    }
    
    // Add zeros at end
    for(int i = 0; i < zeroCount; i++)
        result.push_back(0);
    
    nums = result;
}
```

**Complexity:**
- Time: O(n)
- Space: O(n) - Uses extra array (violates in-place requirement)

---

### Approach 2: Two Pass (Works but not optimal)

**Idea:** First pass moves non-zeros, second pass fills remaining with zeros.

```cpp
void moveZeroes(vector<int>& nums) {
    int j = 0;
    
    // First pass: Move non-zeros forward
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }
    
    // Second pass: Fill remaining with zeros
    for(int i = j; i < nums.size(); i++) {
        nums[i] = 0;
    }
}
```

**Complexity:**
- Time: O(n) but requires two passes
- Space: O(1)

**Why my approach is better:**
- Single pass vs two passes
- Fewer write operations
- More elegant with swap

---

## Solution Comparison

| Approach | Time | Space | Passes | In-Place | Relative Order |
|----------|------|-------|--------|----------|----------------|
| **My Two-Pointer Swap** | O(n) | O(1) | 1 | ✓ | ✓ |
| Brute Force | O(n) | O(n) | 1 | ✗ | ✓ |
| Two Pass | O(n) | O(1) | 2 | ✓ | ✓ |

**Winner:** My approach!  Single pass, O(1) space, in-place, maintains order.

---

## Key Learnings

**Two Pointers Pattern:**
- One pointer for scanning (`i`)
- One pointer for writing/placing (`j`)
- This pattern is powerful for in-place array modifications

**In-Place Algorithms:**
- Swapping is key for in-place modifications
- No need for extra arrays
- Space complexity of O(1) is optimal

**Partitioning:**
- This problem is essentially partitioning:  non-zeros | zeros
- Similar to partition step in QuickSort
- Useful pattern for many array problems

**Efficiency:**
- Single pass is better than multiple passes
- Minimize number of operations (swaps only when needed)
- Understanding when swap with itself is harmless

---

## Edge Cases Handled

The solution correctly handles:

| Input | Output | Explanation |
|-------|--------|-------------|
| `[0,1,0,3,12]` | `[1,3,12,0,0]` | Standard case |
| `[0]` | `[0]` | Single zero |
| `[1]` | `[1]` | Single non-zero |
| `[0,0,0]` | `[0,0,0]` | All zeros |
| `[1,2,3]` | `[1,2,3]` | No zeros |
| `[1,0,2,0,3]` | `[1,2,3,0,0]` | Alternating zeros |
| `[0,0,1]` | `[1,0,0]` | Leading zeros |

---

## Visual Walkthrough

**Example:  [0,1,0,3,12]**

```
State visualization (j marks position, i scans):

Initial: 
[0, 1, 0, 3, 12]
 j
 i

Step 1: i=0, nums[0]=0, skip
[0, 1, 0, 3, 12]
 j
    i

Step 2: i=1, nums[1]=1, swap(1,0), j++
[1, 0, 0, 3, 12]
    j
       i

Step 3: i=2, nums[2]=0, skip
[1, 0, 0, 3, 12]
    j
          i

Step 4: i=3, nums[3]=3, swap(3,0), j++
[1, 3, 0, 0, 12]
       j
             i

Step 5: i=4, nums[4]=12, swap(12,0), j++
[1, 3, 12, 0, 0]
          j
                i (done)

Result: [1, 3, 12, 0, 0] ✓
```

---

## Test Cases

```cpp
// Test Case 1: Standard
Input:   [0,1,0,3,12]
Output: [1,3,12,0,0]

// Test Case 2: Single zero
Input:  [0]
Output: [0]

// Test Case 3: No zeros
Input:  [1,2,3,4,5]
Output: [1,2,3,4,5]

// Test Case 4: All zeros
Input:  [0,0,0,0]
Output: [0,0,0,0]

// Test Case 5: Single non-zero
Input:  [5]
Output: [5]

// Test Case 6: Zeros at end already
Input:  [1,2,3,0,0]
Output: [1,2,3,0,0]
```

---

## Why This Problem is Important

**Pattern Recognition:**
- Two-pointer technique for in-place operations
- Partitioning arrays efficiently
- Understanding invariants

**Interview Value:**
- Common array manipulation question
- Tests understanding of in-place algorithms
- Good for discussing optimization
- Follow-up: minimize operations

**Real-World Applications:**
- Data cleaning (removing null/empty values)
- Memory management (compacting memory)
- Stream processing (filtering and reordering)
- Database operations (null handling)

---

## Problem Insights

**Why swapping works better than shifting:**

Shifting approach (less efficient):
```cpp
// For each zero, shift all elements right
// Requires multiple writes per zero
```

Swapping approach (my solution):
```cpp
// Each non-zero element swapped at most once
// Single pass, minimal operations
```

**Optimization achieved:**
- My solution: At most n swaps
- Shifting approach: Could be n² operations
- Two-pass approach: 2n operations (still more than necessary)

---

**Status**:  Solved  
**Date Solved**: 2026-01-06  
**Approach**: Two Pointers with Swap  
**Complexity**: O(n) time, O(1) space - Optimal!   
**Key Pattern**: Two-pointer in-place partitioning