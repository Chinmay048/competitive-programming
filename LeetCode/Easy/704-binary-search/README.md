# 704. Binary Search

**Difficulty**: Easy  
**Topics**: `Array`, `Binary Search`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/binary-search/)  
**Language**: C++

---

## Problem Description

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.

### Example 1:

```

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

```

### Example 2:

```

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

```

### Constraints:
- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i], target <= 10^4`
- All the integers in `nums` are **unique**.
- `nums` is sorted in ascending order.

---

## My Approach (Iterative Binary Search)

### Intuition

Since the input array is **sorted**, checking every element (Linear Search) is inefficient. Instead, we can eliminate half of the remaining elements at each step.

Think of it like looking up a name in a physical phonebook:
1. Open the book in the middle.
2. If the name is alphabetically before the current page, ignore the right half.
3. If the name is after, ignore the left half.
4. Repeat until found.

**Key Insight:**
- If `nums[mid] < target`, the target *must* be in the right half.
- If `nums[mid] > target`, the target *must* be in the left half.

**Visual Example:**

```

nums = [-1, 0, 3, 5, 9, 12], target = 9

Iteration 1:
[-1, 0, 3, 5, 9, 12]
L        M        R
Mid val = 3.
3 < 9 → Target is to the right. Move Left to M+1.

Iteration 2:
[-1, 0, 3, 5, 9, 12]
L  M   R
Mid val = 9.
9 == 9 → Found! Return index.

```

### Algorithm

1.  Initialize two pointers: `left` at index `0`, and `right` at index `n-1`.
2.  Loop while `left <= right`:
    * Calculate `mid`.
    * **Match:** If `nums[mid] == target`, return `mid`.
    * **Too small:** If `nums[mid] < target`, discard left half (`left = mid + 1`).
    * **Too big:** If `nums[mid] > target`, discard right half (`right = mid - 1`).
3.  If loop finishes, return `-1`.

### Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            // Calculate mid safely to prevent integer overflow
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};

```

### Step-by-Step Trace

**Example:** `nums = [-1, 0, 3, 5, 9, 12]`, `target = 2`

**Iteration 1:**

* `left = 0`, `right = 5`
* `mid = 2` (value = 3)
* `3 > 2` → Target is smaller.
* Update: `right = mid - 1 = 1`

**Iteration 2:**

* `left = 0`, `right = 1`
* `mid = 0` (value = -1)
* `-1 < 2` → Target is larger.
* Update: `left = mid + 1 = 1`

**Iteration 3:**

* `left = 1`, `right = 1`
* `mid = 1` (value = 0)
* `0 < 2` → Target is larger.
* Update: `left = mid + 1 = 2`

**End:**

* `left (2) > right (1)`. Loop terminates.
* Return `-1`.

### Why This Works

**Invariant:**
If the target exists, it is guaranteed to be within `[left, right]`. By shrinking this range, we either find the element or the range becomes invalid (`left > right`), proving the element doesn't exist.

**Overflow Protection:**
Using `mid = left + (right - left) / 2` instead of `(left + right) / 2` prevents integer overflow when `left` and `right` are large numbers close to `INT_MAX`.

### Complexity Analysis

* **Time Complexity**: `O(log n)`
* The search space is divided by 2 in every iteration.


* **Space Complexity**: `O(1)`
* Uses constant extra space (pointers only).



---

## Alternative Approaches

### Approach 1: Recursive Binary Search

**Idea:** Call the function recursively for the new ranges.

```cpp
int helper(vector<int>& nums, int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;
    if (nums[mid] > target) return helper(nums, left, mid - 1, target);
    return helper(nums, mid + 1, right, target);
}

```

**Drawback:** Uses `O(log n)` stack space. My iterative approach is `O(1)` space, making it superior.

### Approach 2: Linear Search

**Idea:** Iterate through the array one by one.

```cpp
for(int i=0; i<nums.size(); i++) if(nums[i]==target) return i;

```

**Drawback:** `O(n)` time complexity. Too slow for large datasets.

---

## Solution Comparison

| Approach | Time | Space | Readability | Optimality |
| --- | --- | --- | --- | --- |
| **My Iterative BS** | O(log n) | O(1) | Standard | ✓ Optimal |
| Recursive BS | O(log n) | O(log n) | Clean | ✗ (Stack overhead) |
| Linear Search | O(n) | O(1) | Simple | ✗ (Too slow) |

---

## Key Learnings

**Integer Overflow:**

* Always calculate mid using offset logic: `left + (right - left) / 2`.

**Loop Condition:**

* `left <= right` ensures we process the case when `left` and `right` point to the same single element.

**Boundary Updates:**

* Always use `mid - 1` or `mid + 1`. Using just `mid` can lead to infinite loops.

---

## Edge Cases Handled

| Input | Output | Explanation |
| --- | --- | --- |
| `nums=[5], target=5` | 0 | Single element match |
| `nums=[5], target=1` | -1 | Single element mismatch |
| `nums=[1, 3], target=3` | 1 | Target at end |
| `nums=[1, 3], target=1` | 0 | Target at start |
| `nums=[], target=5` | -1 | Empty array |

---

## Test Cases

```cpp
int main(){
    Solution object;
    
    // Case 1: Target is in the upper half
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    cout << "Output: " << object.search(nums1, 9) << endl; 
    // Expected: 4

    // Case 2: Target does not exist
    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    cout << "Output: " << object.search(nums2, 2) << endl;
    // Expected: -1
    
    return 0;
}

```

---

## Problem Insights

**When to use Binary Search:**

* Whenever the input array is **sorted**.
* When the problem asks for `O(log n)` time complexity.

**Status**: ✓ Solved

**Date Solved**: 2026-01-06

**Approach**: Iterative Binary Search

**Complexity**: O(log n) time, O(1) space

**Key Pattern**: Divide and Conquer

**Difficulty**: Easy
