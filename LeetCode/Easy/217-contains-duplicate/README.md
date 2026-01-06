# 217. Contains Duplicate

**Difficulty**:  Easy  
**Topics**: `Array`, `Hash Table`, `Sorting`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/contains-duplicate/)  
**Language**: C++

---

## Problem Description

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.

### Example 1:
```
Input: nums = [1,2,3,1]
Output: true
```

### Example 2:
```
Input: nums = [1,2,3,4]
Output: false
```

### Example 3:
```
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
```

### Constraints:
- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

---

## My Approach (Sorting)


**Current Status:** I'm using the sorting approach because I haven't learned hash maps yet. Once I learn hash maps/hash sets, I'll update this solution with the optimal O(n) time complexity approach!

This solution works correctly and is a good starting point, but there's room for optimization in the future.

---

### Intuition

The key insight:  **If there are duplicates, they will be adjacent after sorting! **

When we sort an array, all identical elements are placed next to each other. So instead of comparing every element with every other element, we just need to:
1. Sort the array
2. Check if any adjacent elements are equal

**Visual Example:**
```
Original: [1, 3, 2, 1]

After sorting: [1, 1, 2, 3]
                 ↑  ↑
            Adjacent duplicates found!

Compare neighbors: 
- nums[0] vs nums[1] → 1 == 1 → Found duplicate!  Return true ✓
```

**Another example:**
```
Original: [1, 2, 3, 4]

After sorting: [1, 2, 3, 4]

Compare neighbors:
- nums[0] vs nums[1] → 1 != 2
- nums[1] vs nums[2] → 2 != 3
- nums[2] vs nums[3] → 3 != 4

No duplicates found → Return false ✓
```

### Algorithm

1. **Sort the array** using `sort()`
2. **Loop through the array** from index 0 to size-2
3. **Compare adjacent elements**:  If `nums[i] == nums[i+1]`, we found a duplicate
4. If duplicate found, return `true`
5. If loop completes without finding duplicates, return `false`

### Code

```cpp
class Solution {
public: 
    bool containsDuplicate(vector<int>& nums) {
        // Sort the array so duplicates are adjacent
        sort(nums.begin(), nums.end());
        
        // Check each adjacent pair
        for(int i = 0; i < nums.size() - 1; i++)
            if(nums[i] == nums[i+1])
                return true;  // Found duplicate
        
        return false;  // No duplicates
    }
};
```

### Step-by-Step Trace

Example: `nums = [1,1,1,3,3,4,3,2,4,2]`

```
Step 1: Sort the array
Before: [1,1,1,3,3,4,3,2,4,2]
After:  [1,1,1,2,2,3,3,3,4,4]

Step 2: Check adjacent elements
i=0: nums[0]=1, nums[1]=1 → 1 == 1 → Duplicate found! 
Return true ✓

(No need to check further)
```

### Why This Works

**Key Principle:**
- Sorting groups identical elements together
- If duplicates exist, they MUST be adjacent after sorting
- We only need to check neighbors, not all pairs

**Correctness:**
- If `nums[i] == nums[i+1]`, definitely a duplicate
- If no adjacent pairs match, all elements are unique
- Sorting doesn't lose any information, just reorders

### Complexity Analysis

- **Time Complexity**: `O(n log n)`
    - Sorting takes `O(n log n)`
    - Loop through array takes `O(n)`
    - Total: `O(n log n)` (sorting dominates)

- **Space Complexity**:  `O(1)` or `O(log n)`
    - Depends on the sorting algorithm implementation
    - Most sorting algorithms use `O(log n)` space for recursion
    - We don't use any extra arrays

### Advantages of This Approach

**Pros:**
- Simple to understand and implement
- No need for additional data structures
- Works with the tools I currently know
- Space efficient (no extra arrays)
- Easy to code in an interview setting

**Cons:**
- Not the most optimal time complexity
- Modifies the original array (sorting changes order)
- Can be improved with hash maps

---

## Future Optimization:  Hash Set Approach

### Why Hash Maps/Sets are Better

Once I learn hash maps, I can optimize this to O(n) time!

**The Idea:**
- Use a hash set to track elements we've seen
- For each element, check if it's already in the set
- If yes → duplicate found
- If no → add it to the set


**Why it's better:**
- Time: O(n) - single pass through array
- Space: O(n) - need to store elements in set
- Doesn't modify original array
- Faster for large arrays

**Complexity Comparison:**

| Approach | Time | Space | Learning Status |
|----------|------|-------|-----------------|
| **My Current (Sorting)** | O(n log n) | O(1) | ✓ Implemented   |
| Hash Set | O(n) | O(n) | To Learn        |

---

## Key Learnings

**Current Understanding:**
- Sorting can simplify comparison problems
- Adjacent element checking is powerful after sorting
- O(n log n) is acceptable for many practical cases
- Understanding trade-offs between time and space complexity

**Future Learning Goals:**
- Learn hash maps and hash sets
- Understand O(1) lookup time
- Practice hash-based problems
- Update this solution with optimal approach

**Problem-Solving Insight:**
- Start with what you know (sorting is a valid approach!)
- Recognize when there's room for optimization
- Build solutions incrementally as you learn new concepts
- Don't let "not optimal" stop you from solving the problem

---

## Edge Cases Handled

The solution correctly handles:
- Small arrays:  `[1,2,3,1]` → `true`
- No duplicates: `[1,2,3,4]` → `false`
- All duplicates: `[1,1,1,1]` → `true`
- Single element: `[1]` → `false`
- Two elements: `[1,1]` → `true`, `[1,2]` → `false`
- Large arrays: Works correctly (though not most efficient)
- Negative numbers: `[-1,-1,0]` → `true`
- Mixed values: `[1,1,1,3,3,4,3,2,4,2]` → `true`

---

## Test Cases

```cpp
// Test Case 1: Duplicate exists
nums = [1,2,3,1]
After sort: [1,1,2,3]
Output:  true ✓

// Test Case 2: All unique
nums = [1,2,3,4]
After sort: [1,2,3,4]
Output: false ✓

// Test Case 3: Multiple duplicates
nums = [1,1,1,3,3,4,3,2,4,2]
After sort: [1,1,1,2,2,3,3,3,4,4]
Output:  true ✓

// Test Case 4: Single element
nums = [1]
Output: false ✓

// Test Case 5: All same
nums = [5,5,5,5]
After sort: [5,5,5,5]
Output: true ✓
```

---

## Why This Problem is Important

**Fundamental Concepts:**
- Introduction to duplicate detection
- Understanding sorting applications
- Learning about hash table use cases
- Comparing different algorithmic approaches

**Interview Value:**
- Common warm-up question
- Tests basic problem-solving skills
- Good for discussing optimization
- Multiple valid approaches exist

**Real-World Applications:**
- Data validation (checking for unique IDs)
- Duplicate detection in databases
- Email/username uniqueness checking
- Fraud detection systems

---

## My Learning Journey

**Current Stage:**
-  Understand the problem
-  Solve using sorting
-  Recognize time complexity
-  Identify room for improvement

**Next Steps:**
-  Learn hash maps/hash sets
-  Implement O(n) solution
-  Compare performance practically
-  Update this README with optimal approach

**Philosophy:**
> "The best solution is one that works. The optimal solution comes with more learning.  Both are valuable!"

---

**Status**:  Solved (Sorting Approach)  
**Date Solved**: 2026-01-06  
**Current Approach**: Sorting with O(n log n) time  
**Future Optimization**: Hash Set with O(n) time - TO BE UPDATED  
**Learning Note**: This is my current best solution with the tools I know.  Will improve as I learn more!  