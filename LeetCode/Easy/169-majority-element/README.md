# 169. Majority Element

**Difficulty**: Easy  
**Topics**: `Array`, `Hash Table`, `Divide and Conquer`, `Sorting`, `Counting`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/majority-element/)  
**Language**: C++

---

## Problem Description

Given an array `nums` of size `n`, return the **majority element**.

The majority element is the element that appears **more than ⌊n / 2⌋ times**. You may assume that the majority element always exists in the array.

### Example 1:
```
Input: nums = [3,2,3]
Output:  3
```

### Example 2:
```
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```

### Constraints:
- `n == nums.length`
- `1 <= n <= 5 * 10^4`
- `-10^9 <= nums[i] <= 10^9`

**Follow-up**: Could you solve the problem in linear time and in O(1) space?

---

## Solution 1: My Initial Approach (Count Each Element)

### Intuition

My first thought was straightforward:
- For each element in the array, **count how many times it appears**
- If the count is greater than `n/2`, that's our majority element!
- Use the built-in `count()` function to count occurrences

This approach is simple to understand and implement - just check every element and count its occurrences.

### Algorithm

1. Loop through each element `nums[i]`
2. Count occurrences of `nums[i]` in the entire array using `count()`
3. If count > `nums.size()/2`, return that element
4. If no element found (shouldn't happen per problem statement), return -1

### Code

```cpp
class Solution {
public: 
    int majorityElement(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int n = count(nums.begin(), nums.end(), nums[i]);
            if(n > nums.size()/2)
                return nums[i];
        }
        return -1;
    }
};
```

### Complexity Analysis

- **Time Complexity**: `O(n²)`
    - Outer loop runs `n` times
    - `count()` function scans the entire array → `O(n)`
    - Total: `n × n = O(n²)`

- **Space Complexity**: `O(1)`
    - Only using a few variables
    - No extra data structures

### What Went Wrong?

**Problem:  Inefficiency due to redundant counting**

Let's trace through an example:  `nums = [2,2,1,1,1,2,2]`

```
i=0: nums[0]=2, count entire array for 2 → found 4 times → 4 > 3, return 2 ✓
```

But what if the array was:  `nums = [1,1,1,2,2,2,2]`

```
i=0: nums[0]=1, count entire array for 1 → found 3 times → 3 not > 3
i=1: nums[1]=1, count entire array for 1 → found 3 times → 3 not > 3 (REDUNDANT!)
i=2: nums[2]=1, count entire array for 1 → found 3 times → 3 not > 3 (REDUNDANT!)
i=3: nums[3]=2, count entire array for 2 → found 4 times → 4 > 3, return 2 ✓
```

**Issues:**
1. **Repeated Work**: We count the same element multiple times if it appears more than once
2. **Time Complexity**: O(n²) is too slow for large arrays (n up to 50,000)
3. **Not Optimal**: The problem asks for O(n) time in the follow-up

**Example of inefficiency:**
```
Array: [7,7,7,7,7,7,7,7,7,7]  (10 elements, all 7s)

My approach:
- i=0: Count 7 → scan all 10 elements
- i=1: Count 7 → scan all 10 elements again (WASTE!)
- i=2: Count 7 → scan all 10 elements again (WASTE!)
...  
Total operations: 10 × 10 = 100 operations for a 10-element array! 
```

---

## Solution 2: Sorting Approach (Better)

### Intuition

A clever observation: If an element appears **more than n/2 times**, it **must occupy the middle position** after sorting!

**Why?**
```
Array size = 7, majority element appears at least 4 times

Case 1: [1,1,1,1,2,3,4]  → middle (index 3) = 1 ✓
Case 2: [1,2,3,4,4,4,4]  → middle (index 3) = 4 ✓
Case 3: [1,4,4,4,4,4,5]  → middle (index 3) = 4 ✓

No matter where the majority elements are positioned,
they MUST include the middle index because they're > n/2! 
```

### Algorithm

1. Sort the array
2. Return the element at index `n/2`

### Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
```

### Complexity Analysis

- **Time Complexity**: `O(n log n)`
    - Sorting takes `O(n log n)`
    - Accessing middle element takes `O(1)`

- **Space Complexity**: `O(1)` or `O(log n)`
    - Depends on sorting algorithm used
    - Most in-place sorts use O(log n) for recursion stack

### Why This is Better Than My Approach

- **Much faster**: O(n log n) vs O(n²)
- **No redundant work**: We sort once and directly access the answer
- **Simpler code**: Just 2 lines!

**Performance comparison:**
```
For n = 50,000 elements: 

My approach: 50,000² = 2,500,000,000 operations (2.5 billion!)
Sorting:      50,000 × log(50,000) ≈ 782,000 operations

Sorting is ~3,200 times faster!
```

---

## Solution 3: Boyer-Moore Voting Algorithm (Optimal)

### Intuition - The Voting Concept

Imagine a voting scenario where the majority candidate has **more votes than all other candidates combined**.

**Key Insight**: If we pair up each majority element with a different element and cancel them out, the majority element will still have elements remaining!

**Analogy:**
```
Think of a battle between two armies: 
- Majority army has MORE than 50% soldiers
- All other armies combined have LESS than 50%

Strategy:  Each majority soldier fights one enemy soldier (both eliminated)

Result: Majority army will still have soldiers left! 
```

**Visual Example:**
```
Array: [2, 2, 1, 1, 1, 2, 2]

Think of it as:
2 = Team A (majority)
1 = Team B

Pairing and canceling:
2 vs 1 → cancel
2 vs 1 → cancel  
2 vs 1 → cancel
Remaining: 2, 2 → Team A wins!  ✓
```

### The Algorithm - Step by Step

The algorithm works like a "voting game":

1. **Pick a candidate**: Start with the first element as potential majority
2. **Vote counting**:
    - Same element → vote FOR (count++)
    - Different element → vote AGAINST (count--)
3. **Change candidate**: When count reaches 0, pick a new candidate
4. **Winner**:  The last standing candidate is the majority element

### How It Works

Let's trace through:  `nums = [2, 2, 1, 1, 1, 2, 2]`

```
Initial: count = 0, candidate = undefined

i=0: nums[0]=2
     count=0 → new candidate=2, count=1
     State: candidate=2, count=1

i=1: nums[1]=2
     2==2 → count++
     State: candidate=2, count=2

i=2: nums[2]=1
     1≠2 → count--
     State: candidate=2, count=1

i=3: nums[3]=1
     1≠2 → count--
     State: candidate=2, count=0

i=4: nums[4]=1
     count=0 → new candidate=1, count=1
     State:  candidate=1, count=1

i=5: nums[5]=2
     2≠1 → count--
     State: candidate=1, count=0

i=6: nums[6]=2
     count=0 → new candidate=2, count=1
     State:  candidate=2, count=1

Final Answer: 2 ✓
```

**Why does this work?**

The key insight:  Since the majority element appears MORE than n/2 times, even after all cancellations with different elements, it will survive!

### Code (Most Readable Version)

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int candidate;
        
        for(int i = 0; i < n; i++) {
            // If count is 0, pick new candidate
            if(count == 0) 
                candidate = nums[i];
            
            // Vote for or against current candidate
            if(nums[i] == candidate) 
                count++;  // Vote FOR
            else 
                count--;  // Vote AGAINST
        }
        
        return candidate;
    }
};
```

### Complexity Analysis

- **Time Complexity**: `O(n)`
    - Single pass through the array
    - Each operation is O(1)
    - **This is OPTIMAL! **

- **Space Complexity**:  `O(1)`
    - Only two variables:  `count` and `candidate`
    - **This is OPTIMAL!**

### Why This is THE BEST Solution

**Comparison with all approaches:**

| Approach | Time | Space | Pass Through Array |
|----------|------|-------|-------------------|
| My Approach (Count) | O(n²) | O(1) | Multiple (n times) |
| Sorting | O(n log n) | O(1) | Once + sort |
| **Boyer-Moore** | **O(n)** | **O(1)** | **Once** |

**For n = 50,000:**
```
My approach:   2,500,000,000 operations
Sorting:      ~782,000 operations  
Boyer-Moore:  50,000 operations (ONE pass!)

Boyer-Moore is 50,000x faster than my approach!
Boyer-Moore is 15x faster than sorting!
```

---

## All Three Solutions Comparison


### When to Use Each

**My Approach (Brute Force):**
- When array is very small (< 100 elements)
- When simplicity is more important than performance
- For educational purposes to understand the problem

**Sorting Approach:**
- When you need a quick solution
- When the array will be used sorted later anyway
- When you can't remember Boyer-Moore algorithm

**Boyer-Moore (Optimal):**
- For large arrays
- When performance matters
- In production code
- To impress in interviews!

---

## Key Learnings

**From My Approach:**
- Simple solutions work but may not be efficient
- Counting repeatedly is wasteful
- O(n²) is acceptable for small inputs but fails for large ones

**From Sorting:**
- Mathematical properties can simplify problems
- The middle element trick is elegant
- Sometimes preprocessing (sorting) makes the solution obvious

**From Boyer-Moore:**
- Advanced algorithms can achieve both O(n) time and O(1) space
- The "voting" and "cancellation" concept is powerful
- Understanding WHY it works is crucial

**General Lessons:**
1. **Start Simple**: My brute force was a good starting point
2. **Optimize Step by Step**: Sorting was a good intermediate solution
3. **Learn Patterns**: Boyer-Moore is a classic algorithm worth knowing
4. **Trade-offs**: Sometimes O(n log n) is "good enough"
5. **Problem Guarantees**: The guarantee of majority existing makes Boyer-Moore work

---

## My Learning Journey

**What I Did Right:**
- Solved the problem correctly
- Code was clean and easy to understand
- Used built-in functions effectively

**What I Learned:**
- Need to consider time complexity for large inputs
- Redundant operations (counting same element multiple times) are costly
- Sometimes mathematical properties (like the middle element) provide shortcuts
- Advanced algorithms like Boyer-Moore can achieve optimal complexity

**Next Time:**
- Check constraints (n up to 50,000 means O(n²) might be too slow)
- Think about whether I'm doing redundant work
- Consider if sorting or other preprocessing helps
- Look for classic algorithm patterns (voting, sliding window, two pointers, etc.)

---

## Test Cases

All solutions handle:
- Simple majority:  `[3,2,3]` → `3`
- Clear majority: `[2,2,1,1,1,2,2]` → `2`
- All same: `[1,1,1,1]` → `1`
- Minimum majority: `[1,1,2]` → `1`
- Large arrays: Working efficiently up to 50,000 elements

---

**Status**:  Solved (Multiple Approaches)  
**Date Solved**: 2026-01-05  
**My Initial Approach**:  Brute Force O(n²)  
**Optimal Solution**: Boyer-Moore Voting Algorithm O(n)  
**Key Takeaway**: Always analyze complexity for large inputs! 