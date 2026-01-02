# 27. Remove Element

**Difficulty**:  Easy  
**Topics**: Array, Two Pointers  
**Link**: [LeetCode Problem](https://leetcode.com/problems/remove-element/)  
**Language**: C++

---

## Problem Description

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in `nums` in-place. The order of the elements may be changed. Then return the number of elements in `nums` which are not equal to `val`.

Consider the number of elements in `nums` which are not equal to `val` be `k`, to get accepted, you need to do the following things:

- Change the array `nums` such that the first `k` elements of `nums` contain the elements which are not equal to `val`. The remaining elements of `nums` are not important as well as the size of `nums`.
- Return `k`.

### Custom Judge:

The judge will test your solution with the following code:

```cpp
int[] nums = [... ]; // Input array
int val = .. .; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums. length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
```

If all assertions pass, then your solution will be accepted.

### Example 1:
```
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

### Example 2:
```
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

### Constraints:
- `0 <= nums.length <= 100`
- `0 <= nums[i] <= 50`
- `0 <= val <= 100`

---

## My Approach (Two Pointers with Swap)

### Intuition

Instead of shifting elements when we find `val`, we can use a clever approach:
- Use two pointers: one from the start (left) and one from the end (right)
- When we find `val` at the left pointer, swap it with the element at the right pointer
- Then remove the last element (which now contains `val`)
- This way, we move all instances of `val` to the end and shrink the array

The key insight is that we don't care about the order of elements, so swapping with the end is perfectly valid.

### Algorithm

1. Initialize two pointers: `left = 0`, `right = nums.size() - 1`
2. While `left <= right`:
    - If `nums[left] != val`: move left pointer forward (keep this element)
    - If `nums[left] == val`:
        - Swap `nums[left]` with `nums[right]` (without using extra variable)
        - Remove the last element using `pop_back()`
        - Move right pointer backward
3. Return `left` (which represents the count of valid elements)

### Swap Without Extra Variable

The swap logic uses arithmetic operations:
```cpp
nums[left] = nums[left] + nums[right];   // left now holds sum
nums[right] = nums[left] - nums[right];  // right now has original left value
nums[left] = nums[left] - nums[right];   // left now has original right value
```

### Why This Works

- Elements equal to `val` are moved to the end
- We don't care about their final position (beyond index k)
- The left pointer naturally counts non-val elements
- Order doesn't matter, so swapping is fine
- Using `pop_back()` actually removes elements from the vector

### Visual Example

For `nums = [3,2,2,3], val = 3`:

```
Initial: left=0, right=3
[3, 2, 2, 3]
 L        R

left=0: nums[0]=3, equals val
  Swap with right:  [3, 2, 2, 3] -> after arithmetic swap
  Pop back: [3, 2, 2]
  right=2

[3, 2, 2]
 L     R

left=0: nums[0]=3, equals val  
  Swap with right: [2, 2, 3]
  Pop back: [2, 2]
  right=1

[2, 2]
 L  R

left=0: nums[0]=2, not equal to val
  left=1

[2, 2]
    LR

left=1: nums[1]=2, not equal to val
  left=2

left > right, loop ends
Return left=2

Final: [2, 2]
```

---

## Complexity Analysis

**Time Complexity**: O(n)
- We traverse the array at most once
- Each element is processed exactly once
- Left and right pointers together cover all elements
- pop_back() is O(1) operation

**Space Complexity**: O(1)
- Only using two pointer variables
- No extra data structures
- Modifying array in-place
- Swap done without extra variable

---

## Solution Code

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size() - 1;
        
        while(left <= right) {
            if(val != nums[left])
                left++;
            else {
                // Swap without using extra variable
                nums[left] = nums[left] + nums[right];
                nums[right] = nums[left] - nums[right];
                nums[left] = nums[left] - nums[right];
                
                nums.pop_back();
                right--;
            }
        }
        
        return left;
    }
};
```

**See `solution.cpp` for complete implementation with test cases.**

---

## Key Learnings

1. **Two Pointers from Both Ends**:  Effective when order doesn't matter
2. **Swap Without Extra Variable**: Using arithmetic operations (a=a+b, b=a-b, a=a-b)
3. **In-Place Modification**: Using pop_back() to actually remove elements
4. **Order Independence**: When order doesn't matter, we have more flexibility
5. **Pointer Movement Strategy**: Move left when good element, move right when removing

---

## Test Cases Analysis

### Test Case 1: nums = [3,2,2,3], val = 3
```
Process: 
- Start: [3,2,2,3]
- Swap and remove first 3: [3,2,2] -> [2,2]  (swapped 3 with last 3)
- Swap and remove another 3: [2,2]
- Both 2s don't match val, left moves forward

Result: k = 2, nums = [2,2]
```

### Test Case 2: nums = [0,1,2,2,3,0,4,2], val = 2
```
Process:
- Start: [0,1,2,2,3,0,4,2]
- Keep 0, 1
- Find 2, swap with last element, remove
- Continue process...

Result: k = 5, nums = [0,1,4,0,3,_,_,_]
(Order may vary, but 5 non-2 elements remain)
```

### Edge Cases:
- Empty array [] with val=1 → Return 0
- All elements match val [2,2,2] with val=2 → Return 0
- No elements match val [1,2,3] with val=5 → Return 3
- Single element [1] with val=1 → Return 0
- Single element [1] with val=2 → Return 1

---

## Alternative Approaches

### Approach 1: Two Pointers (Copy Forward)
```cpp
// Time: O(n), Space: O(1)
int k = 0;
for(int i = 0; i < nums.size(); i++) {
    if(nums[i] != val) {
        nums[k++] = nums[i];
    }
}
return k;
```
**Simpler approach**, overwrites elements in place

### Approach 2: Current Solution (Swap from End)
```cpp
// Time: O(n), Space: O(1)
// Two pointers from both ends with swap
```
**Creative approach**, actually removes elements with pop_back()

### Approach 3: Using STL remove()
```cpp
// Time: O(n), Space: O(1)
auto it = remove(nums.begin(), nums.end(), val);
nums.erase(it, nums.end());
return nums.size();
```
**STL approach**, but you should implement yourself in interviews

### Approach 4: Create New Array
```cpp
// Time: O(n), Space: O(n)
vector<int> result;
for(int num : nums) {
    if(num != val) result.push_back(num);
}
```
**Not optimal** due to extra space

---
## Pattern Recognition

This problem demonstrates the **Two Pointers from Both Ends** pattern:

**When to use:**
- Order doesn't need to be preserved
- Need to remove/move elements
- Can swap elements from beginning with end

**Structure:**
```cpp
int left = 0, right = size - 1;
while(left <= right) {
    if(condition) {
        // Process left
        left++;
    } else {
        // Swap and shrink from right
        swap(arr[left], arr[right]);
        right--;
    }
}
```

---

## Submission Results

- **Status**: Accepted
- **Runtime**:  Beats 100% of C++ submissions
- **Memory**:  Beats 85-90% of C++ submissions
- **Date Solved**: 2026-01-02

---
## Tags

array, two-pointers, easy, in-place, swap-technique, creative-solution

---

**Last Updated**: 2026-01-02  
**Author**: [Chinmay048](https://github.com/Chinmay048)

---

## Notes

This problem is similar to problem 26 (Remove Duplicates) but with a twist - we're removing specific values, not duplicates. The key insight is recognizing that order doesn't matter, which allows us to use the two-pointer approach from both ends.  Your solution demonstrates a creative use of arithmetic swapping and vector operations, though the simpler "copy forward" approach is more commonly seen in interviews.