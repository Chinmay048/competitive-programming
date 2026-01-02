# 26. Remove Duplicates from Sorted Array

**Difficulty**:  Easy  
**Topics**: Array, Two Pointers  
**Link**: [LeetCode Problem](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)  
**Language**: C++

---

## Problem Description

Given an integer array `nums` sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.  Then return the number of unique elements in `nums`.

Consider the number of unique elements of `nums` to be `k`, to get accepted, you need to do the following things:

- Change the array `nums` such that the first `k` elements of `nums` contain the unique elements in the order they were present in `nums` initially. The remaining elements of `nums` are not important as well as the size of `nums`.
- Return `k`.

### Custom Judge:

The judge will test your solution with the following code:

```cpp
int[] nums = [... ]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums. length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

If all assertions pass, then your solution will be accepted.

### Example 1:
```
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

### Example 2:
```
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

### Constraints:
- `1 <= nums.length <= 3 * 10^4`
- `-100 <= nums[i] <= 100`
- `nums` is sorted in non-decreasing order

---

## My Approach (Two Pointers)

### Intuition

Since the array is already sorted, all duplicate elements are adjacent to each other. We can use two pointers:
- **Pointer i**: Tracks the position of the last unique element
- **Pointer j**: Scans through the array to find the next unique element

When we find a new unique element (nums[j] != nums[i]), we move it to position i+1 and increment i.

### Algorithm

1. Initialize pointer `i = 0` (position of last unique element)
2. Start pointer `j` from index 1 and iterate through array
3. For each element at `j`:
    - If `nums[j] != nums[i]` (found a new unique element):
        - Increment `i`
        - Copy `nums[j]` to `nums[i]`
4. Return `i + 1` (number of unique elements)

### Why This Works

- Array is sorted, so duplicates are consecutive
- Pointer `i` always points to the last unique element placed
- Pointer `j` scans ahead to find next unique element
- We overwrite duplicates in-place with unique elements
- Only need to keep track of first `k` elements

### Visual Example

For `nums = [0,0,1,1,1,2,2,3,3,4]`:

```
Initial: i=0, j=1
[0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
 i  j

j=1: nums[i]=0, nums[j]=0 → same, skip

j=2: nums[i]=0, nums[j]=1 → different! 
     i++, nums[i]=nums[j]
[0, 1, 1, 1, 1, 2, 2, 3, 3, 4]
    i     j

j=3: nums[i]=1, nums[j]=1 → same, skip
j=4: nums[i]=1, nums[j]=1 → same, skip

j=5: nums[i]=1, nums[j]=2 → different!
     i++, nums[i]=nums[j]
[0, 1, 2, 1, 1, 2, 2, 3, 3, 4]
       i           j

...  continue until j reaches end

Final: i=4
[0, 1, 2, 3, 4, _, _, _, _, _]
             i
Return i+1 = 5
```

---

## Complexity Analysis

**Time Complexity**: O(n)
- Single pass through the array with pointer j
- Each element is visited exactly once
- All operations inside loop are O(1)

**Space Complexity**: O(1)
- Only using two pointer variables (i and j)
- Modifying array in-place
- No extra data structures needed
- This is optimal!

---

## Solution Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++)
            if (nums[i] != nums[j])
                nums[++i] = nums[j];
        return i + 1;
    }
};
```

**See `solution.cpp` for complete implementation with test cases.**

---

## Test Cases Analysis

### Test Case 1: [1,1,2]
```
Initial: [1, 1, 2]
         i  j

j=1: nums[0]=1, nums[1]=1 → skip
j=2: nums[0]=1, nums[2]=2 → different
     i becomes 1, nums[1]=2

Result: [1, 2, _]
Return:  2
```

### Test Case 2: [0,0,1,1,1,2,2,3,3,4]
```
Initial: [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]

After processing:
[0, 1, 2, 3, 4, _, _, _, _, _]

Return: 5
```

### Edge Cases:
- Single element [1] → Return 1
- All same [5,5,5,5] → Return 1
- All unique [1,2,3,4] → Return 4
- Two elements same [1,1] → Return 1
- Two elements different [1,2] → Return 2
---

## Pattern Recognition

This problem demonstrates the **Slow-Fast Pointer** pattern:

**When to use:**
- Array/string in-place modification
- Removing elements based on condition
- Finding unique elements
- Moving elements around

**Structure:**
```cpp
int slow = 0;
for (int fast = 0; fast < arr.size(); fast++) {
    if (condition) {
        // Process and move slow pointer
        arr[slow++] = arr[fast];
    }
}
return slow;
```

---

## Submission Results

- **Status**: Accepted
- **Runtime**:  Beats 95-100% of C++ submissions
- **Memory**: Beats 90-95% of C++ submissions (O(1) space!)
- **Date Solved**: 2026-01-01

---

## Tags

array, two-pointers, easy, in-place, sorted-array, interview-favorite, optimal

---

**Last Updated**: 2026-01-01  
**Author**: [Chinmay048](https://github.com/Chinmay048)

---

## Notes

This is a classic two-pointers problem and frequently asked in interviews. The key insight is recognizing that since the array is sorted, we can use the slow-fast pointer technique to remove duplicates in a single pass with O(1) extra space.  This pattern appears in many array manipulation problems.