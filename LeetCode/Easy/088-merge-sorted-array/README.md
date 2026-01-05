# 88. Merge Sorted Array

**Difficulty**:  Easy  
**Topics**: `Array`, `Two Pointers`, `Sorting`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/merge-sorted-array/)  
**Language**: C++

---

## Problem Description

You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

Merge `nums1` and `nums2` into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.

### Example 1:
```
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6]. 
The result of the merge is [1,2,2,3,5,6]. 
```

### Example 2:
```
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1]. 
```

### Example 3:
```
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the result can fit in nums1.
```

### Constraints:
- `nums1.length == m + n`
- `nums2.length == n`
- `0 <= m, n <= 200`
- `1 <= m + n <= 200`
- `-10^9 <= nums1[i], nums2[i] <= 10^9`

---

##  Solution 1: Two Pointers with Auxiliary Array (My Initial Approach)

###  Intuition

Since both arrays are already sorted, we can use a **merge** technique similar to merge sort:
- Use two pointers, one for each array (`ptr1` for `nums1`, `ptr2` for `nums2`)
- Compare elements at both pointers and pick the smaller one
- Store results in a new array and then copy back to `nums1`

###  Algorithm

1. **Handle edge cases**:
    - If `m == 0`: directly assign `nums2` to `nums1`
    - If `m + n == 1`: array is already in correct state

2. **Initialize pointers**:
    - `ptr1 = 0` (for nums1)
    - `ptr2 = 0` (for nums2)
    - `i = 0` (for result array)

3. **Merge process**:
    - While `i < nums1.size()`:
        - If `ptr1 == m`: all elements from nums1 used, add from nums2
        - If `ptr2 == n`: all elements from nums2 used, add from nums1
        - If `nums1[ptr1] > nums2[ptr2]`: add smaller element from nums2
        - If `nums1[ptr1] <= nums2[ptr2]`: add smaller element from nums1

4. **Copy result**:  Assign the merged array back to `nums1`

###  Complexity Analysis

- **Time Complexity**: `O(m + n)`
- **Space Complexity**: `O(m + n)` - Uses auxiliary array

###  Code

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            nums1=nums2;
            return;
        }
        else if(m+n==1)
            return;
        else{
            int ptr1=0, ptr2=0, i=0;
            vector<int> ans;
            
            while(i<nums1.size()){
                if(ptr1==m)
                    ans.push_back(nums2[ptr2++]);
                else if(ptr2==n)
                    ans. push_back(nums1[ptr1++]);
                else if(nums1[ptr1]>nums2[ptr2]){
                    if(ptr2>=n)
                        ptr2=n-1;
                    ans.push_back(nums2[ptr2++]);
                }
                else if(nums1[ptr1]<=nums2[ptr2]){
                    if(ptr2>=n)
                        ptr2=n-1;
                    ans.push_back(nums1[ptr1++]);
                }
                i++;
            }
            nums1=ans;
        }
    }
};
```

---

##  Solution 2: Optimized Two Pointers (Backward Merge) - BETTER!

###  Intuition

The key insight is:  **Why start from the beginning when we can start from the end?**

Since `nums1` already has extra space at the end, we can:
- Start from the **last positions** of both arrays
- Compare and place the **larger** element at the end of `nums1`
- Work **backwards** to avoid overwriting unprocessed elements
- No extra space needed!

**Visual Example:**
```
nums1 = [1,2,3,0,0,0], m=3
nums2 = [2,5,6], n=3

Step 1: Compare 3 vs 6 → Place 6 at position 5
        [1,2,3,0,0,6]
         
Step 2: Compare 3 vs 5 → Place 5 at position 4
        [1,2,3,0,5,6]
        
Step 3: Compare 3 vs 2 → Place 3 at position 3
        [1,2,3,3,5,6]
        
Step 4: Compare 2 vs 2 → Place 2 at position 2
        [1,2,2,3,5,6]
        
...  and so on
```

###  Algorithm

1. Initialize three pointers:
    - `i = m - 1` (last element of nums1's valid part)
    - `j = n - 1` (last element of nums2)
    - `k = m + n - 1` (last position in nums1)

2. **While both arrays have elements** (`i >= 0 && j >= 0`):
    - Compare `nums1[i]` and `nums2[j]`
    - Place the **larger** one at position `k`
    - Decrement the corresponding pointer

3. **Handle remaining nums2 elements**:
    - If `j >= 0`, copy remaining nums2 elements
    - (No need to handle remaining nums1 elements - they're already in place!)

###  Why This Works Better

**Key Advantages:**

1. **Space Efficient**: No auxiliary array needed → `O(1)` space
2. **No Overwriting Issues**: Writing from end avoids overwriting unprocessed data
3. **Cleaner Logic**: No special edge case handling needed
4. **Better Performance**: Less memory allocation and copying
5. **Elegant**:  Uses the problem's constraint (extra space in nums1) cleverly

###  Complexity Analysis

- **Time Complexity**: `O(m + n)`
    - Single pass through both arrays
    - Each element compared and placed once

- **Space Complexity**: `O(1)` 
    - Only uses three pointer variables
    - No auxiliary array needed
    - **This is optimal!**

###  Code

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) 
                nums1[k--] = nums1[i--];
            else 
                nums1[k--] = nums2[j--];
        }

        // Copy remaining nums2 elements (if any)
        while (j >= 0) 
            nums1[k--] = nums2[j--];
    }
};
```

---

##  Solution Comparison

| Aspect | Solution 1 (Forward) | Solution 2 (Backward) |
|--------|--------------------|----------------------|
| **Space Complexity** | O(m + n) | **O(1)** |
| **Memory Usage** | Creates auxiliary array | In-place modification |
| **Edge Cases** | Needs explicit handling | Handles naturally |
| **Code Length** | Longer (~25 lines) | Shorter (~10 lines) |
| **Readability** | More verbose | Cleaner & elegant |
| **Performance** | Extra copy overhead | Direct placement |
| **LeetCode Optimal** |  No |  **Yes** |

---

##  Key Learnings

 **Backward Iteration**: Sometimes working backwards is more efficient than forwards  
 **Space Optimization**: Use existing space cleverly before allocating new memory  
 **In-place Algorithms**: Modify data structures without extra space when possible  
 **Problem Constraints**: The extra space in nums1 is a hint to use backward merge  
 **Two Pointers Pattern**: Can be applied in both directions depending on the problem

**Important Insight:**  
When merging arrays in-place, if you have extra space at the end, **start from the end** to avoid overwriting data!

---

##  Test Cases

Both solutions handle:
-  Standard merge case: `[1,2,3,0,0,0]` and `[2,5,6]` → `[1,2,2,3,5,6]`
-  Empty nums2: `[1]` and `[]` → `[1]`
-  Empty nums1: `[0]` and `[1]` → `[1]`
-  All nums2 larger: `[1,2,3,0,0,0]` and `[4,5,6]` → `[1,2,3,4,5,6]`
-  All nums1 larger: `[4,5,6,0,0,0]` and `[1,2,3]` → `[1,2,3,4,5,6]`

---

## Why I Improved My Solution

**My Learning Journey:**

1. **First Attempt (Solution 1)**:
    - Natural instinct:  start from beginning
    - Used auxiliary array for safety
    - Works correctly but not optimal

2. **Optimization (Solution 2)**:
    - Realized `nums1` has extra space for a reason!
    - Backward iteration prevents overwriting
    - Achieved O(1) space complexity
    - Cleaner and more elegant code

**Lesson**:  Always analyze the problem constraints - they often hint at the optimal approach!

---

**Status**:  Solved (Both approaches)  
**Date Solved**: 2026-01-05  
**Preferred Solution**: Solution 2 (Backward Merge) 