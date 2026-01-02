# Halloumi Boxes

**Problem Code**:  1903A  
**Difficulty**:  800 Rating  
**Contest**: CodeForces (Div. 2/3)  
**Link**: [CodeForces Problem 1903A](https://codeforces.com/problemset/problem/1903/A)  
**Language**: C++  
**Topic**:  Greedy, Sorting, Implementation

---

## Problem Statement

You have n boxes of halloumi cheese arranged in a line. Each box has a tastiness value a_i.

You want to arrange the boxes so that the tastiness values are in non-decreasing order (sorted).

You can perform operations where you select k consecutive boxes and reverse their order any number of times.

Determine if it's possible to sort the array with these operations.

### Input Format

- First line: t (number of test cases)
- For each test case:
    - First line: n (number of boxes), k (size of operation window)
    - Second line: n integers a_1, a_2, ..., a_n (tastiness values)

### Output Format

For each test case, print "YES" if the array can be sorted, otherwise print "NO".

### Constraints

- 1 <= t <= 10^4
- 2 <= k <= n <= 50
- 1 <= a_i <= 10^9
- Sum of n over all test cases <= 2 × 10^5

### Example

**Input:**
```
4
3 2
4 2 1
4 1
2 4 3 1
5 3
5 4 3 2 1
6 4
1 2 3 4 5 6
```

**Output:**
```
YES
NO
YES
YES
```

### Explanation

**Test 1:** n=3, k=2, array=[4,2,1]
- We can select boxes 1-2, reverse:  [2,4,1]
- Select boxes 2-3, reverse: [2,1,4]
- Select boxes 1-2, reverse: [1,2,4]
- Result:  Sorted! → YES

**Test 2:** n=4, k=1, array=[2,4,3,1]
- Can only "reverse" single boxes (no change)
- Array not sorted → NO

**Test 3:** n=5, k=3, array=[5,4,3,2,1]
- With k=3, we can perform enough operations to sort → YES

**Test 4:** n=6, k=4, array=[1,2,3,4,5,6]
- Already sorted → YES

---

## Solution Approach

### Key Insight

The critical observation is based on the value of k:

**Case 1: k >= 2**
- We can select and reverse any 2 consecutive elements
- This allows us to perform bubble sort operations
- We can swap any adjacent elements
- Therefore, we can ALWAYS sort the array
- Answer: YES

**Case 2: k == 1**
- We can only "reverse" a single box (which does nothing)
- No swaps are possible
- We can only succeed if the array is ALREADY sorted
- Answer: YES if sorted, NO otherwise

### Algorithm

1. Read n and k
2. Read array a of size n
3. If k >= 2:
    - Print "YES" (always sortable)
4.  Else (k == 1):
- Check if array is already sorted
- Print "YES" if sorted, "NO" otherwise

### Why This Works

When k >= 2, we can reverse any 2 consecutive elements:
- Reverse [a, b] → [b, a] (this is a swap!)
- Using adjacent swaps, we can implement bubble sort
- Bubble sort can sort any array
- Therefore, answer is always YES

When k == 1:
- Reversing a single element doesn't change anything
- No operations can modify the array
- Only possible if already sorted

---

## Complexity Analysis

**Time Complexity**:  O(t × n)
- t test cases
- For each test case: O(n) to check if sorted
- is_sorted() function traverses array once:  O(n)
- Total: O(t × n)

**Space Complexity**: O(n)
- Storing array of size n
- No extra data structures
- O(1) auxiliary space

---

## Implementation Details

### Using Fast I/O

```cpp
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```

Essential for competitive programming to avoid TLE on large inputs.

### Using STL is_sorted()

```cpp
bool sorted = is_sorted(a.begin(), a.end());
```

Cleaner than manual loop, checks if array is sorted in O(n).

### Output Optimization

Using `\n` instead of `endl` to avoid buffer flushing (faster).

---

## Code Walkthrough

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);  // Fast I/O
    cin. tie(NULL);
    
    int t;
    cin >> t;  // Number of test cases
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        // k >= 2: Can swap adjacent elements -> always sortable
        if(k >= 2)
            cout << "YES\n";
        else{
            // k == 1: No swaps possible, check if already sorted
            bool sorted = is_sorted(a.begin(), a.end());
            cout << (sorted ? "YES" : "NO") << "\n";
        }
    }
    
    return 0;
}
```

---

## Test Cases

### Test Case 1: k >= 2 (Always YES)
```
Input:
1
3 2
4 2 1

Output:  YES

Explanation:  k=2, so we can swap adjacent elements and sort
```

### Test Case 2: k == 1, Already Sorted (YES)
```
Input:
1
4 1
1 2 3 4

Output: YES

Explanation: k=1 but array already sorted
```

### Test Case 3: k == 1, Not Sorted (NO)
```
Input:
1
4 1
2 4 3 1

Output: NO

Explanation:  k=1 and array not sorted, cannot fix
```

### Test Case 4: All Same Elements
```
Input:
1
5 1
5 5 5 5 5

Output: YES

Explanation: All elements same = sorted
```

### Edge Cases
- Minimum n=2, k=2
- Already sorted array
- Reverse sorted array
- All elements identical
- Single element differs

---

## Key Learnings

1. **Problem Simplification**:  Recognize when a problem has a simple mathematical solution
2. **Operation Analysis**: Understanding what operations allow (k>=2 enables any swap)
3. **Edge Case Recognition**: k==1 is special case
4. **STL Usage**: Using is_sorted() for cleaner code
5. **Fast I/O**: Essential for CodeForces problems with large inputs

---

## Common Mistakes to Avoid

1. **Overthinking**: No need to simulate the reversals
2. **Missing k==1 case**: Special handling needed
3. **Slow I/O**: Not using fast I/O can cause TLE
4. **Using endl**: Slower than \n
5. **Not checking already sorted**: When k==1, must verify
---
## Tags

greedy, sorting, implementation, math, easy, 800-rating, codeforces

---

## Submission Statistics

- **Status**: Accepted
- **Verdict**: Correct
- **Time**: ~15ms
- **Memory**: ~1MB
- **Rating**: 800
- **Date Solved**: 2026-01-02

---

**Last Updated**: 2026-01-02  
**Author**: [Chinmay048](https://github.com/Chinmay048)

---

## Notes

This is a classic "observation" problem where the solution comes from understanding the problem constraints rather than implementing complex algorithms. The key insight is recognizing that k>=2 gives us the power to perform any adjacent swaps, which is sufficient to sort any array.