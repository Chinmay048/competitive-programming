# 278. First Bad Version

**Difficulty**: Easy  
**Topics**: `Binary Search`, `Interactive`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/first-bad-version/)  
**Language**: C++

---

## Problem Description

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have `n` versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API `bool isBadVersion(version)` which returns whether `version` is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

### Example 1:

```

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.

```

### Example 2:

```

Input: n = 1, bad = 1
Output: 1

```

### Constraints:
- `1 <= bad <= n <= 2^31 - 1`

---

## My Approach (Binary Search - Minimize Index)

### Intuition

The versions are ordered in a specific way:
`[Good, Good, Good, ..., Bad, Bad, Bad]`

This is a **monotonic** property (sorted sequence of False then True). We are looking for the **boundary** where the status flips from Good to Bad. Since we want to find a specific element in a sorted range, Binary Search is the optimal choice.

**Key Insight:**
- If `mid` is **Bad**: The first bad version could be `mid` itself, or something to the left. So, we record `mid` as a potential answer and try looking left (`right = mid - 1`).
- If `mid` is **Good**: The bad version must be further to the right. We discard the left side (`left = mid + 1`).

**Visual Example:**

```

Versions: [1, 2, 3, 4, 5], First Bad = 4
Status:   [G, G, G, B, B]

Range [1, 5]:
Mid = 3 (Good).
We need to go Right. New Range [4, 5].

Range [4, 5]:
Mid = 4 (Bad).
Found a bad one! Store result = 4.
Try to see if there is an earlier one? Go Left. New Range [4, 3].

Range Invalid. Return result (4).

```

### Algorithm

1.  Initialize `left = 1`, `right = n`.
2.  Maintain a variable `result` to store the earliest bad version found so far.
3.  Loop while `left <= right`:
    * Calculate `mid`.
    * **If `isBadVersion(mid)` is True**:
        * This is a candidate for the *first* bad version.
        * Update `result = mid`.
        * Shrink the search space to the left (`right = mid - 1`) to check if an earlier bad version exists.
    * **If `isBadVersion(mid)` is False**:
        * We are still in the "Good" zone. The bad versions are to the right.
        * Move `left = mid + 1`.
4.  Return `result`.

### Code

```cpp
class Solution {
public:
    int firstBadVersion(int n) {
        // Use long long for left/right to prevent overflow during addition
        // though mid calc method below handles int range fine.
        int left = 1;
        int right = n;
        int result = n; // Default to n (or 0), guaranteed to find one.

        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(isBadVersion(mid)){
                // mid is Bad. Could be the first one, or there's one earlier.
                result = mid;
                right = mid - 1; // Try to find a smaller index
            }
            else {
                // mid is Good. First bad is to the right.
                left = mid + 1;
            }
        }
        return result;  
    }
};

```

### Step-by-Step Trace

**Example:** `n = 5`, `bad = 4` (Sequence: G, G, G, B, B)

**Iteration 1:**

* `left = 1`, `right = 5`
* `mid = 3`
* `isBadVersion(3)` is **False** (Good).
* Update: `left = mid + 1 = 4`.

**Iteration 2:**

* `left = 4`, `right = 5`
* `mid = 4`
* `isBadVersion(4)` is **True** (Bad).
* Update: `result = 4`.
* Update: `right = mid - 1 = 3`.

**Iteration 3:**

* `left = 4`, `right = 3`
* Loop terminates (`left > right`).
* Return `result` (4).

### Why This Works

We are effectively narrowing down the search space. By always storing the `mid` when it is "Bad" and then moving left, we ensure that if a smaller index is also "Bad", we will find it and overwrite `result`. If we move left and find "Good", we know the previous `result` was indeed the first bad one.

### Complexity Analysis

* **Time Complexity**: `O(log n)`
* We cut the search space in half with every API call.


* **Space Complexity**: `O(1)`
* Only a few integer variables are used.



---

## Alternative Approaches

### Approach 1: Linear Scan (Brute Force)

**Idea:** Check version 1, then 2, then 3... until `isBadVersion` returns true.

```cpp
for (int i = 1; i <= n; i++) {
    if (isBadVersion(i)) return i;
}
return n;

```

**Drawback:** Time complexity is `O(n)`. If `n` is large (e.g., 2 billion) and the bad version is at the end, this will Time Limit Exceed (TLE).

---

## Solution Comparison

| Approach | Time | Space | Readability | Optimality |
| --- | --- | --- | --- | --- |
| **My Binary Search** | O(log n) | O(1) | High | ✓ Optimal |
| Linear Scan | O(n) | O(1) | Very High | ✗ (Too slow) |

---

## Key Learnings

**Binary Search Template II:**

* This problem is a variation of "Find Lower Bound".
* Unlike finding an exact number, we are finding the *first* index that satisfies a condition.
* The pattern `if (condition) { result = mid; right = mid - 1; }` is a standard pattern for finding the **first occurrence**.

**API Minimization:**

* The problem specifically asks to minimize calls. `O(log n)` makes ~30 calls for `n = 10^9`, whereas `O(n)` would make 1 billion calls.

---

## Edge Cases Handled

| Input | Output | Explanation |
| --- | --- | --- |
| `n=1, bad=1` | 1 | Single version, immediately bad |
| `n=5, bad=1` | 1 | First version is bad (result updates many times) |
| `n=5, bad=5` | 5 | Last version is bad (left keeps moving right) |
| `n=MAX_INT` | ... | Handled by safe `mid` calculation |

---

## Test Cases (Driver Code)

Since `isBadVersion` is an API provided by LeetCode, we need to mock it to run this locally.

```cpp
#include <iostream>
using namespace std;

int BAD_VERSION_GLOBAL=0;
bool isBadVersion(int version) {
    return (version>=BAD_VERSION_GLOBAL);
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1,right=n,result=n;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isBadVersion(mid)){
                result=mid;
                right=mid-1;
            }
            else 
                left=mid+1;
        }
        return result;  
    }
};

int main(){
    Solution object;    
    // Case 1
    int n1 = 5;
    BAD_VERSION_GLOBAL = 4;
    cout << "n=" << n1 << ", bad=" << BAD_VERSION_GLOBAL 
         << " -> Output: " << object.firstBadVersion(n1) << endl;

    // Case 2
    int n2 = 1;
    BAD_VERSION_GLOBAL = 1;
    cout << "n=" << n2 << ", bad=" << BAD_VERSION_GLOBAL 
         << " -> Output: " << object.firstBadVersion(n2) << endl;
         
    return 0;
}

```

---

## Problem Insights

**Pattern recognition:**

* Whenever you see "First X that satisfies Y" in a sorted domain, it is Binary Search.
* The "Bad Version" logic is identical to `lower_bound` in C++.

**Status**: ✓ Solved

**Date Solved**: 2026-01-06

**Approach**: Binary Search (Left Boundary)

**Complexity**: O(log n) time

**Key Pattern**: `right = mid - 1` to find first occurrence

**Difficulty**: Easy

