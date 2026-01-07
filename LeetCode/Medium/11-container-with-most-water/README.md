# 11. Container With Most Water

**Difficulty**:  Medium  
**Topics**: `Array`, `Two Pointers`, `Greedy`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/container-with-most-water/)  
**Language**: C++

---

## Problem Description

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `ith` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

**Note:** You may not slant the container.

### Example 1:

![Container With Most Water](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.
```

### Example 2:
```
Input: height = [1,1]
Output: 1
```

### Constraints:
- `n == height.length`
- `2 <= n <= 10^5`
- `0 <= height[i] <= 10^4`

---

## My Approach (Two Pointers - Greedy)

### Intuition

This problem is about finding the maximum area formed by two vertical lines.

**Key Formula:**
```
Area = width × height
     = (right - left) × min(height[left], height[right])
```

**Why min()?** Water can only be as high as the shorter line (it would overflow otherwise!)

**Visual Example:**
```
height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
Index:    0  1  2  3  4  5  6  7  8

If we pick lines at index 1 and 8:
Height at 1: 8
Height at 8: 7
Width: 8 - 1 = 7
Water height: min(8, 7) = 7
Area = 7 × 7 = 49 ✓
```

**The Strategy - Two Pointers:**

Start with the **widest container** (leftmost and rightmost lines):
- This gives us maximum width
- Now we need to find maximum height

Move the pointer pointing to the **shorter line** inward:
- Why? Because the shorter line limits the height
- Moving the taller line won't help (height is still limited by shorter line)
- Moving the shorter line might find a taller line → better area

**Visual Walkthrough:**
```
height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
          L                       R

Step 1: left=0, right=8
Area = (8-0) × min(1,7) = 8 × 1 = 8
height[0]=1 < height[8]=7 → move left++

Step 2: left=1, right=8
Area = (8-1) × min(8,7) = 7 × 7 = 49 ✓ (BEST!)
height[1]=8 > height[8]=7 → move right--

Step 3: left=1, right=7
Area = (7-1) × min(8,3) = 6 × 3 = 18
height[1]=8 > height[7]=3 → move right--

...  and so on

Maximum area found: 49
```

### Algorithm

1. Initialize two pointers:  `left = 0`, `right = n-1`
2. Initialize `result = 0` to track maximum area
3. While `left < right`:
    - Calculate current area: `(right - left) × min(height[left], height[right])`
    - Update `result` if current area is larger
    - Move the pointer pointing to shorter height:
        - If `height[left] <= height[right]`: move `left++`
        - Else: move `right--`
4. Return `result`

### Code

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, result = 0;
        
        for(int i = 0; i < height. size() && left != right; i++){
            // Calculate current area
            int temp = (right - left) * ((height[left] <= height[right]) ? height[left] : height[right]);
            
            // Update maximum area
            if(result < temp)
                result = temp;
            
            // Move pointer pointing to shorter line
            if(height[left] <= height[right])
                left++;
            else
                right--;
        }
        
        return result;
    }
};
```

### Cleaner Version (Optional)

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;
        
        while(left < right) {
            // Calculate current area
            int width = right - left;
            int h = min(height[left], height[right]);
            int area = width * h;
            
            // Update maximum
            maxArea = max(maxArea, area);
            
            // Move pointer with shorter height
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        
        return maxArea;
    }
};
```

### Step-by-Step Trace

Example: `height = [1,8,6,2,5,4,8,3,7]`

```
Initial: left=0, right=8, result=0

Iteration 1:
left=0, right=8
width = 8-0 = 8
h = min(1,7) = 1
area = 8 × 1 = 8
result = max(0,8) = 8
height[0]=1 < height[8]=7 → left++

Iteration 2:
left=1, right=8
width = 8-1 = 7
h = min(8,7) = 7
area = 7 × 7 = 49
result = max(8,49) = 49
height[1]=8 > height[8]=7 → right--

Iteration 3:
left=1, right=7
width = 7-1 = 6
h = min(8,3) = 3
area = 6 × 3 = 18
result = max(49,18) = 49
height[1]=8 > height[7]=3 → right--

Iteration 4:
left=1, right=6
width = 6-1 = 5
h = min(8,8) = 8
area = 5 × 8 = 40
result = max(49,40) = 49
height[1]=8 = height[6]=8 → right--

Iteration 5:
left=1, right=5
width = 5-1 = 4
h = min(8,4) = 4
area = 4 × 4 = 16
result = max(49,16) = 49
height[1]=8 > height[5]=4 → right--

Iteration 6:
left=1, right=4
width = 4-1 = 3
h = min(8,5) = 5
area = 3 × 5 = 15
result = max(49,15) = 49
height[1]=8 > height[4]=5 → right--

Iteration 7:
left=1, right=3
width = 3-1 = 2
h = min(8,2) = 2
area = 2 × 2 = 4
result = max(49,4) = 49
height[1]=8 > height[3]=2 → right--

Iteration 8:
left=1, right=2
width = 2-1 = 1
h = min(8,6) = 6
area = 1 × 6 = 6
result = max(49,6) = 49
height[1]=8 > height[2]=6 → right--

left=1, right=1 → Stop (left == right)

Final result: 49 ✓
```

### Why This Works - The Greedy Proof

**Question:** Why is it safe to move the shorter pointer?  Won't we miss some solutions?

**Answer:** No! Here's why:

```
Suppose we have: 
height[left] < height[right]

Current area = width × height[left]

If we move right pointer inward:
- Width decreases
- Height is still limited by height[left] (the shorter one)
- Area = (smaller width) × height[left] = WORSE

If we move left pointer inward:
- Width decreases
- BUT we might find height[new_left] > height[left]
- Area might improve! 

Therefore, moving the shorter pointer is the only chance to improve! 
```

**Mathematical Insight:**
- We start with maximum width
- As we move inward, width always decreases
- The only way to compensate is to increase height
- Moving the taller pointer won't increase height (limited by shorter side)
- Moving the shorter pointer might find a taller line

### Complexity Analysis

- **Time Complexity**:  `O(n)`
    - Single pass through the array
    - Two pointers meet in the middle
    - Each element considered at most once

- **Space Complexity**: `O(1)`
    - Only using a few variables (left, right, result)
    - No extra data structures

---

## Alternative Approaches

### Approach 1: Brute Force (Not Optimal)

**Idea:** Try every possible pair of lines.

```cpp
int maxArea(vector<int>& height) {
    int maxArea = 0;
    
    for(int i = 0; i < height.size(); i++) {
        for(int j = i + 1; j < height.size(); j++) {
            int width = j - i;
            int h = min(height[i], height[j]);
            int area = width * h;
            maxArea = max(maxArea, area);
        }
    }
    
    return maxArea;
}
```

**Complexity:**
- Time: O(n²)  - Too slow for large inputs
- Space: O(1)

**Why it's worse:**
- Checks all n(n-1)/2 pairs
- For n=10,000: 50 million operations!
- My approach: only 10,000 operations

---

## Solution Comparison

| Approach | Time | Space | Optimality | Passes All Cases |
|----------|------|-------|------------|------------------|
| **My Two-Pointer** | O(n) | O(1) | ✓ Optimal | ✓ |
| Brute Force | O(n²) | O(1) | ✗ | ✓ |

**Performance comparison for n = 10,000:**
```
Brute Force:    ~50,000,000 operations
Two Pointers:   ~10,000 operations

Two pointers is 5,000x faster!
```

---

## Key Learnings

**Two Pointers Pattern:**
- Start from extremes (widest container)
- Move pointers based on greedy choice
- One pass achieves optimal solution

**Greedy Strategy:**
- Move the pointer that limits the height
- This is the only way to potentially improve
- Proof: moving the other pointer can only make it worse

**Area Calculation:**
- Width × Height
- Height limited by shorter line (water would overflow)
- Trade-off: width vs height

**Problem-Solving Insight:**
- Start with maximum width, then optimize height
- Greedy choice at each step leads to global optimum
- Two pointers eliminate need to check all pairs

---

## Edge Cases Handled

| Input | Output | Explanation |
|-------|--------|-------------|
| `[1,8,6,2,5,4,8,3,7]` | 49 | Standard case |
| `[1,1]` | 1 | Minimum input |
| `[4,3,2,1,4]` | 16 | Best at extremes |
| `[1,2,1]` | 2 | Symmetric |
| `[2,3,4,5,18,17,6]` | 17 | High line at end |

---




## Test Cases

```cpp
// Test Case 1: Example from problem
Input:   height = [1,8,6,2,5,4,8,3,7]
Output:  49
Trace:  Lines at index 1 (height 8) and 8 (height 7)
        Area = 7 × 7 = 49

// Test Case 2: Minimum input
Input:  height = [1,1]
Output: 1
Trace:  Only one pair possible
        Area = 1 × 1 = 1

// Test Case 3: Increasing heights
Input:  height = [1,2,3,4,5]
Output: 6
Trace:  Lines at index 0 and 4
        Area = 4 × 1 = 4...  but better is 1 and 3
        Actually:  indices 1 and 4:  3 × 2 = 6

// Test Case 4: Same heights
Input:  height = [5,5,5,5]
Output: 15
Trace:  Lines at index 0 and 3
        Area = 3 × 5 = 15

// Test Case 5: One tall line
Input:  height = [1,8,1]
Output: 2
Trace:  Lines at index 0 and 2
        Area = 2 × 1 = 2
```

---

> "Don't check all pairs. Start wide and move the limiting factor inward!"


---

**Status**:  ✓ Solved  
**Date Solved**: 2026-01-06  
**Approach**: Two Pointers with Greedy Strategy  
**Complexity**: O(n) time, O(1) space - Optimal!   
**Key Pattern**: Greedy two-pointer optimization  
**Difficulty**: Medium - elegant solution once you see the insight! 