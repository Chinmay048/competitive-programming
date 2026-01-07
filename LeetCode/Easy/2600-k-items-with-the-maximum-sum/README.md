# 2600.  K Items With the Maximum Sum

**Difficulty**: Easy  
**Topics**: `Math`, `Greedy`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/k-items-with-the-maximum-sum/)  
**Language**: C++

---

## Problem Description

There is a bag that consists of items, each item has a number `1`, `0`, or `-1` written on it.

You are given four **non-negative** integers `numOnes`, `numZeros`, `numNegOnes`, and `k`.

The bag initially contains:
- `numOnes` items with `1` written on them
- `numZeros` items with `0` written on them
- `numNegOnes` items with `-1` written on them

We want to pick exactly `k` items among the available items.  Return the **maximum** possible sum of numbers written on the items.

### Example 1:
```
Input: numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2
Output: 2
Explanation: We have a bag of items with numbers written on them {1, 1, 1, 0, 0}. 
We take 2 items with 1 written on them and get a sum in a total of 2.
It can be proven that 2 is the maximum possible sum. 
```

### Example 2:
```
Input: numOnes = 3, numZeros = 2, numNegOnes = 0, k = 4
Output: 3
Explanation: We have a bag of items with numbers written on them {1, 1, 1, 0, 0}. 
We take 3 items with 1 written on them, and 1 item with 0 written on it, 
and get a sum in a total of 3.
It can be proven that 3 is the maximum possible sum.
```

### Example 3:
```
Input: numOnes = 5, numZeros = 4, numNegOnes = 2, k = 6
Output:  5
Explanation: We have a bag of items with numbers written on them {1, 1, 1, 1, 1, 0, 0, 0, 0, -1, -1}. 
We take 5 items with 1 written on them, and 1 item with 0 written on it,
and get a sum in a total of 5.
It can be proven that 5 is the maximum possible sum.
```

### Constraints:
- `0 <= numOnes, numZeros, numNegOnes <= 50`
- `0 <= k <= numOnes + numZeros + numNegOnes`

---

## My Approach (Greedy with Cases)

### Intuition

To maximize the sum, we should pick items **greedily** in this order:
1. **First**, take all the `1`s (they add positively to sum)
2. **Then**, take `0`s (they don't hurt the sum)
3. **Finally**, take `-1`s (only if we must to reach k items)

**Key Insight:** Since we want maximum sum, we follow this greedy strategy:
- Take `1`s as much as possible
- Take `0`s if we still need more items (they don't change the sum)
- Take `-1`s only when forced (they reduce the sum)

**Visual Example:**
```
numOnes = 3, numZeros = 2, numNegOnes = 1, k = 5

Bag: [1, 1, 1, 0, 0, -1]

Greedy picking:
Step 1: Take all 3 ones → sum = 3, items picked = 3
Step 2: Need 2 more, take 2 zeros → sum = 3, items picked = 5
Result: 3 ✓

Another example with k = 6:
Step 1: Take all 3 ones → sum = 3, items picked = 3
Step 2: Take all 2 zeros → sum = 3, items picked = 5
Step 3: Need 1 more, take 1 negative → sum = 3-1 = 2, items picked = 6
Result: 2 ✓
```

### Algorithm - Case Analysis

We handle **four cases** based on the value of k:

**Case 1: `k <= numOnes`**
- We can pick k ones
- Sum = k
- Example: k=2, numOnes=3 → pick 2 ones → sum = 2

**Case 2: `numOnes < k <= numOnes + numZeros`**
- Pick all ones, fill remaining with zeros
- Sum = numOnes (zeros don't add anything)
- Example: k=4, numOnes=3, numZeros=2 → pick 3 ones + 1 zero → sum = 3

**Case 3: `k > numOnes + numZeros`**
- Pick all ones, all zeros, and forced to pick some negatives
- Number of negatives = k - (numOnes + numZeros)
- Sum = numOnes - (number of negatives)
- Example: k=6, numOnes=3, numZeros=2 → pick 3 ones + 2 zeros + 1 negative → sum = 3-1 = 2

**Case 4 (Edge):** This is covered by Case 2 when k equals numOnes + numZeros

### Code

```cpp
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        // Case 1: Can pick only ones
        if(k <= numOnes)
            return k;
        
        // Case 2: Pick all ones and some/all zeros
        else if(k <= numOnes + numZeros)
            return numOnes;
        
        // Case 3: Must pick some negatives
        else if(k > numOnes + numZeros){
            int temp = k - (numOnes + numZeros);  // Number of -1s to pick
            return numOnes - temp;
        }
        
        // Default (shouldn't reach here based on logic)
        else 
            return numOnes;
    }
};
```

### Cleaner Version (Optional)

```cpp
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        // Take as many 1s as possible (up to k)
        int onesUsed = min(k, numOnes);
        k -= onesUsed;
        
        // If still need items, take 0s (doesn't affect sum)
        int zerosUsed = min(k, numZeros);
        k -= zerosUsed;
        
        // If still need items, must take -1s
        int negOnesUsed = k;  // Remaining k
        
        return onesUsed - negOnesUsed;
    }
};
```

### Step-by-Step Trace

**Example 1:** `numOnes=3, numZeros=2, numNegOnes=0, k=2`

```
Bag: [1, 1, 1, 0, 0]

Check conditions:
k = 2
numOnes = 3

k < numOnes?  → 2 < 3 → YES

Return k = 2 ✓
```

**Example 2:** `numOnes=3, numZeros=2, numNegOnes=0, k=4`

```
Bag: [1, 1, 1, 0, 0]

Check conditions:
k = 4
numOnes = 3
numOnes + numZeros = 3 + 2 = 5

k <= numOnes? → 4 <= 3 → NO
k <= numOnes + numZeros? → 4 <= 5 → YES

Return numOnes = 3 ✓
```

**Example 3:** `numOnes=5, numZeros=4, numNegOnes=2, k=6`

```
Bag: [1, 1, 1, 1, 1, 0, 0, 0, 0, -1, -1]

Check conditions:
k = 6
numOnes = 5
numOnes + numZeros = 5 + 4 = 9

k <= numOnes? → 6 <= 5 → NO
k <= numOnes + numZeros? → 6 <= 9 → YES

Return numOnes = 5 ✓
```

**Example 4 (with negatives):** `numOnes=3, numZeros=2, numNegOnes=3, k=7`

```
Bag: [1, 1, 1, 0, 0, -1, -1, -1]

Check conditions:
k = 7
numOnes = 3
numOnes + numZeros = 3 + 2 = 5

k <= numOnes? → 7 <= 3 → NO
k <= numOnes + numZeros? → 7 <= 5 → NO
k > numOnes + numZeros? → 7 > 5 → YES

temp = k - (numOnes + numZeros) = 7 - 5 = 2
Return numOnes - temp = 3 - 2 = 1 ✓

Verification: Pick 3 ones + 2 zeros + 2 negatives
             = 3 + 0 + (-2) = 1 ✓
```

### Why This Works

**Greedy Strategy Correctness:**

To maximize sum, we should:
1. Prioritize items with highest value (1s)
2. Then items with neutral value (0s)
3. Only take negative items when forced

**Mathematical Proof:**
```
Let's say we pick: 
- x ones (contributes +x to sum)
- y zeros (contributes 0 to sum)
- z negative ones (contributes -z to sum)

Total sum = x - z

To maximize:  maximize x, minimize z
Subject to: x + y + z = k

Greedy approach:
- Set x = min(k, numOnes)
- Set y = min(k-x, numZeros)
- Set z = k - x - y

This gives maximum possible sum! 
```

### Complexity Analysis

- **Time Complexity**:  `O(1)`
    - Only performing comparisons and arithmetic
    - No loops or iterations
    - Constant time operations

- **Space Complexity**: `O(1)`
    - Only using a few variables
    - No extra data structures

---

## Alternative Approaches

### Approach 1: Simulation (Less Efficient)

**Idea:** Actually build the array and pick k largest elements.

```cpp
int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    vector<int> items;
    
    // Build array
    for(int i = 0; i < numOnes; i++) items.push_back(1);
    for(int i = 0; i < numZeros; i++) items.push_back(0);
    for(int i = 0; i < numNegOnes; i++) items.push_back(-1);
    
    // Already sorted in descending order, pick first k
    int sum = 0;
    for(int i = 0; i < k; i++) {
        sum += items[i];
    }
    
    return sum;
}
```

**Complexity:**
- Time: O(n) where n = numOnes + numZeros + numNegOnes
- Space: O(n) - creates array

**Why my approach is better:**
- O(1) time vs O(n) time
- O(1) space vs O(n) space
- Direct calculation without building array

---

### Approach 2: Formula-Based (Similar to Mine)

```cpp
int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    return min(k, numOnes) - max(0, k - numOnes - numZeros);
}
```

**Explanation:**
- `min(k, numOnes)`: Number of 1s we can take
- `max(0, k - numOnes - numZeros)`: Number of -1s we're forced to take
- Difference gives the sum

**This is equivalent to my approach but more compact! **

---

## Solution Comparison

| Approach | Time | Space | Readability | Optimality |
|----------|------|-------|-------------|------------|
| **My Case Analysis** | O(1) | O(1) | Clear logic | ✓ Optimal |
| Simulation | O(n) | O(n) | Very clear | ✗ |
| Formula (compact) | O(1) | O(1) | Less clear | ✓ Optimal |

---

## Key Learnings

**Greedy Strategy:**
- Pick highest value items first
- Simple greedy works when values are sorted
- No need to consider all possibilities

**Case Analysis:**
- Breaking problem into cases simplifies logic
- Each case has a simple formula
- Covers all possible scenarios

**Math vs Simulation:**
- Direct calculation beats simulation
- O(1) is always better than O(n) when possible
- Understanding the pattern eliminates need for actual array

**Problem-Solving Insight:**
- Recognize when greedy is optimal
- Use math to avoid unnecessary computation
- Case-by-case thinking clarifies logic

---

## Edge Cases Handled

| Input | Output | Explanation |
|-------|--------|-------------|
| `numOnes=3, k=2` | 2 | Pick 2 ones |
| `numOnes=3, k=4, numZeros=2` | 3 | All ones + 1 zero |
| `numOnes=3, k=6, numZeros=2, numNegOnes=2` | 2 | All ones + all zeros + 1 negative |
| `numOnes=0, k=2, numZeros=5` | 0 | Only zeros available |
| `k=0` | 0 | Pick nothing |
| `numOnes=5, k=5` | 5 | Exactly all ones |

---

## Test Cases

```cpp
// Test Case 1: Pick only ones
Input:   numOnes=3, numZeros=2, numNegOnes=0, k=2
Output: 2
Trace:   k < numOnes → return k = 2

// Test Case 2: Pick all ones + some zeros
Input:  numOnes=3, numZeros=2, numNegOnes=0, k=4
Output:  3
Trace:  k <= numOnes+numZeros → return numOnes = 3

// Test Case 3: Pick all ones + all zeros + some negatives
Input:  numOnes=5, numZeros=4, numNegOnes=2, k=10
Output: 4
Trace:  temp = 10-(5+4) = 1, return 5-1 = 4

// Test Case 4: k = 0
Input:  numOnes=5, numZeros=3, numNegOnes=2, k=0
Output: 0
Trace:  k < numOnes → return 0

// Test Case 5: All negatives
Input:  numOnes=0, numZeros=0, numNegOnes=5, k=3
Output: -3
Trace:  temp = 3-(0+0) = 3, return 0-3 = -3

// Test Case 6: Exactly all ones and zeros
Input:  numOnes=3, numZeros=2, numNegOnes=5, k=5
Output: 3
Trace:  k = numOnes+numZeros → return numOnes = 3
```

---
## Problem Insights

**Why greedy works here:**
- Items have clear ordering:  1 > 0 > -1
- No dependencies between items
- Optimal strategy is straightforward:  take best first

---

**Status**: ✓ Solved  
**Date Solved**: 2026-01-06  
**Approach**: Greedy with Case Analysis  
**Complexity**: O(1) time, O(1) space - Optimal!  
**Key Pattern**: Greedy selection with mathematical formula  
**Difficulty**: Easy - straightforward greedy strategy! 