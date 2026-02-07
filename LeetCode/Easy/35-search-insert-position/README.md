# 35. Search Insert Position

**Difficulty**: 🟢 Easy  
**Topics**: `Array`, `Binary Search`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/search-insert-position/)  
**Language**: C++

---

## Problem Description

Given a sorted array of distinct integers `nums` and a target value `target`, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

### Example 1:
```
Input: nums = [1,3,5,6], target = 5
Output: 2
```

### Example 2:
```
Input: nums = [1,3,5,6], target = 2
Output: 1
```

### Example 3:
```
Input: nums = [1,3,5,6], target = 7
Output: 4
```

### Constraints:
- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` contains **distinct** values sorted in **ascending** order
- `-10^4 <= target <= 10^4`

---

## My Approach (Binary Search)

### Intuition

This is a classic **Binary Search** problem with a twist! Instead of just finding whether the target exists, we need to handle the case where it doesn't exist by returning the correct insertion position.

**Key Insight:**  When binary search ends without finding the target, the `left` pointer will be positioned exactly where the target should be inserted!

Think of it like organizing books on a shelf:
1. Open the book in the middle to check if it matches your target book
2. If your target book should come before the middle book, search the left half
3. If it should come after, search the right half
4. When you can't divide anymore, the gap where you're standing is exactly where the target belongs

**Visual Example:**
```
nums = [1, 3, 5, 6], target = 2

Iteration 1:
[1, 3, 5, 6]
L     M     R
Mid = 3. 
3 > 2 → Target is smaller. Search left half.

Iteration 2:
[1, 3]
L  M
Mid = 1.
1 < 2 → Target is larger. Search right half.

Now: left = 1 (position after 1)
This is exactly where 2 should be inserted!
Return left = 1 ✓
```

**Another Example:**
```
nums = [1, 3, 5, 6], target = 5

Iteration 1:
[1, 3, 5, 6]
L     M     R
Mid = 3.
3 < 5 → Target is larger. Search right half.

Iteration 2:
[5, 6]
L  M
Mid = 5.
5 == 5 → Found! Return mid = 2 ✓
```

### Algorithm

1. Initialize two pointers: `left = 0`, `right = nums.size() - 1`
2. While `left <= right`:
    * Calculate `mid` using safe formula: `mid = left + (right - left) / 2`
    * **Match:** If `nums[mid] == target`, return `mid`
    * **Too big:** If `nums[mid] > target`, discard right half (`right = mid - 1`)
    * **Too small:** If `nums[mid] < target`, discard left half (`left = mid + 1`)
3. When loop exits, `left` is the insertion position. Return `left`

### Why This Works

**Understanding the `left` pointer after binary search ends:**

When the while loop condition `left <= right` becomes false, it means `left > right`. At this point:
- All elements to the **left of** `left` are smaller than target
- All elements to the **right of** `right` are larger than target
- `left` is positioned exactly between them → **The insertion position!**

**Example trace:**
```
nums = [1, 3, 5, 6], target = 2

left = 0, right = 3
mid = 1, nums[1] = 3
3 > 2, so right = 0

left = 0, right = 0
mid = 0, nums[0] = 1
1 < 2, so left = 1

left = 1, right = 0
Loop exits! (1 > 0)

At this point:
- nums[0] = 1 (smaller than 2)
- nums[1] = 3 (larger than 2)
- left = 1 is the perfect insertion position!
```

---

## Complexity Analysis

- **Time Complexity**: `O(log n)`
    - Binary search eliminates half of the remaining elements in each iteration
    - Maximum iterations = log₂(n)
    - Example: Array of 1,000,000 elements → at most ~20 iterations

- **Space Complexity**: `O(1)`
    - Only using a few variables (left, right, mid)
    - No extra data structures

---

## Solution Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while(left <= right) {
        // Calculate mid safely to prevent integer overflow
        int mid = left + (right - left) / 2;
        
        if(nums[mid] == target)
            return mid;  // Target found
        else if(nums[mid] > target)
            right = mid - 1;  // Search left half
        else
            left = mid + 1;  // Search right half
    }
    
    return left;  // Insertion position when target not found
}

int main() {
    // Case 1: Target found in array
    vector<int> nums1 = {1, 3, 5, 6};
    cout << "Input: nums = [1,3,5,6], target = 5" << endl;
    cout << "Output: " << searchInsert(nums1, 5) << endl;
    cout << "Explanation: 5 is found at index 2" << endl << endl;

    // Case 2: Target not found - insert in middle
    vector<int> nums2 = {1, 3, 5, 6};
    cout << "Input: nums = [1,3,5,6], target = 2" << endl;
    cout << "Output: " << searchInsert(nums2, 2) << endl;
    cout << "Explanation: 2 should be inserted at index 1" << endl << endl;

    // Case 3: Target not found - insert at end
    vector<int> nums3 = {1, 3, 5, 6};
    cout << "Input: nums = [1,3,5,6], target = 7" << endl;
    cout << "Output: " << searchInsert(nums3, 7) << endl;
    cout << "Explanation: 7 should be inserted at index 4 (end of array)" << endl;

    return 0;
}
```

**Output:**
```
Input: nums = [1,3,5,6], target = 5
Output: 2
Explanation: 5 is found at index 2

Input: nums = [1,3,5,6], target = 2
Output: 1
Explanation: 2 should be inserted at index 1

Input: nums = [1,3,5,6], target = 7
Output: 4
Explanation: 7 should be inserted at index 4 (end of array)
```

---

## Key Learnings

**Binary Search Mastery:**
- Binary search works on **any sorted array**
- The key insight: after binary search ends, pointers tell you useful information
- `left` pointer = insertion position when target not found
- `right` pointer = position of largest element smaller than target

 **Safe Mid Calculation:**
- Always use `mid = left + (right - left) / 2` to avoid integer overflow
- Never use `mid = (left + right) / 2` with large array indices

**Why This Beats Linear Search:**
- Linear search: O(n) time → checking every element
- Binary search: O(log n) time → eliminating half each iteration
- For 1,000,000 elements: Linear = 1M checks, Binary = ~20 checks!

---