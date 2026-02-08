# 344. Reverse String

**Difficulty**: Easy  
**Topics**: `String`, `Two Pointers`, `Recursion`  
**Link**: [LeetCode Problem](https://leetcode.com/problems/reverse-string/)  
**Language**: C++

---

## Problem Description

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this **by modifying the input array in-place** with `O(1)` extra memory.

### Example 1:
```
Input: s = ['h','e','l','l','o']
Output: ['o','l','l','e','h']
```

### Example 2:
```
Input: s = ['H','a','n','n','a','h']
Output: ['h','a','n','n','a','H']
```

### Constraints:
- `1 <= s.length <= 10^5`
- `s[i]` is a printable ascii character.

**Follow-up:** Do not allocate extra space for another array. You must do this **by modifying the input array in-place** and without using extra space.

---

## My Approach (Two Pointers Swap)

### Intuition

This is a classic **two-pointer approach** problem! The key insight is simple:
- Start with one pointer at the beginning and one at the end
- Swap the characters at these positions
- Move the pointers towards each other
- Continue until they meet in the middle

Think of it like reversing a book by standing at both ends and walking towards the middle, swapping letters as you go!

**Visual Example:**
```
s = ['h', 'e', 'l', 'l', 'o']
     left                    right

Step 1: Swap s[0]='h' with s[4]='o'
        ['o', 'e', 'l', 'l', 'h']
         left            right

Step 2: Swap s[1]='e' with s[3]='l'
        ['o', 'l', 'l', 'e', 'h']
             left    right

Step 3: left=2, right=2 (middle reached)
        ['o', 'l', 'l', 'e', 'h'] - Done!
```

**Why This Works:**
- Swapping pairs from outside to inside gradually reverses the entire string
- When pointers meet or cross, all characters have been reversed
- The middle character (in odd-length strings) stays in place, which is correct!

### Algorithm

1. Initialize two pointers: `left = 0`, `right = s.size() - 1`
2. While `left < right`:
    * Swap `s[left]` with `s[right]`
    * Increment `left`
    * Decrement `right`
3. Array is reversed in-place, no return needed

### Code Explanation

```cpp
int left = 0, right = s.size() - 1;
while(left < right) {
    // Create temporary variable to hold one value
    char temp = s[left];
    
    // Move right value to left position
    s[left] = s[right];
    
    // Move temp value to right position
    s[right] = temp;
    
    // Move pointers closer
    left++;
    right--;
}
```

**Combined increment/decrement syntax:**
```cpp
char temp = s[left];
s[left++] = s[right];  // Swap AND increment left
s[right--] = temp;     // Swap AND decrement right
```

### Why This Works

**Understanding Two Pointers:**
- `left` pointer starts at position 0 (first character)
- `right` pointer starts at position n-1 (last character)
- Each iteration swaps these two positions
- Pointers move towards each other until they meet

**Visual Step-by-Step:**
```
s = ['h', 'e', 'l', 'l', 'o']
     0    1    2    3    4

Initial: left=0, right=4
Step 1: Swap s[0] and s[4]
        ['o', 'e', 'l', 'l', 'h']
        left=1, right=3

Step 2: Swap s[1] and s[3]
        ['o', 'l', 'l', 'e', 'h']
        left=2, right=2

Step 3: left is not < right anymore, stop!
Result: ['o', 'l', 'l', 'e', 'h']
```

**For even-length string:**
```
s = ['H', 'a', 'n', 'n', 'a', 'h']
     0    1    2    3    4    5

Initial: left=0, right=5
Step 1: Swap s[0] and s[5] -> ['h', 'a', 'n', 'n', 'a', 'H']
Step 2: Swap s[1] and s[4] -> ['h', 'h', 'n', 'n', 'a', 'a']
Step 3: Swap s[2] and s[3] -> ['h', 'h', 'n', 'n', 'a', 'a']
                                         (s[2] = s[3] = 'n', swapping identical values is fine!)

Result: ['h', 'a', 'n', 'n', 'a', 'H']
```

---

## Complexity Analysis

- **Time Complexity**: `O(n)`
    - We visit each character exactly once
    - `n` is the length of the string
    - Example: String of length 1,000,000 -> 500,000 swaps = O(n)

- **Space Complexity**: `O(1)`
    - Only using a constant amount of extra space (variables: `left`, `right`, `temp`)
    - Modifying the input array in-place
    - No additional data structures

---

## Solution Code

```cpp
#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;
    
    while(left < right) {
        // Swap using temporary variable
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
}

int main() {
    // Case 1: Reverse "hello"
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    cout << "Input: ['h','e','l','l','o']" << endl;
    cout << "Before reverse: ";
    for(int i = 0; i < s1.size(); i++)
        cout << s1[i];
    cout << endl;
    
    reverseString(s1);
    
    cout << "Output: ";
    for(int i = 0; i < s1.size(); i++)
        cout << s1[i];
    cout << endl;
    cout << "Explanation: Reversed string is 'olleh'" << endl << endl;

    // Case 2: Reverse "Hannah"
    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    cout << "Input: ['H','a','n','n','a','h']" << endl;
    cout << "Before reverse: ";
    for(int i = 0; i < s2.size(); i++)
        cout << s2[i];
    cout << endl;
    
    reverseString(s2);
    
    cout << "Output: ";
    for(int i = 0; i < s2.size(); i++)
        cout << s2[i];
    cout << endl;
    cout << "Explanation: Reversed string is 'hannaH'" << endl;

    return 0;
}
```

**Output:**
```
Input: ['h','e','l','l','o']
Before reverse: hello
Output: olleh
Explanation: Reversed string is 'olleh'

Input: ['H','a','n','n','a','h']
Before reverse: Hannah
Output: hannaH
Explanation: Reversed string is 'hannaH'
```

---

## Submission Results

- **Status**: Accepted
- **Runtime**: Beats 95-100% of C++ submissions
- **Memory**: Beats 90-95% of C++ submissions (O(1) space!)
- **Date Solved**: 2026-02-08

---

## Key Learnings

Two Pointers Technique:
- One of the most important techniques in coding interviews
- Works great for: reversing strings/arrays, finding pairs, removing elements
- Always: one pointer at start, one at end, move towards middle
- Usually: O(n) time, O(1) space!

In-place Modification:
- Modifying the input directly saves memory (important for large inputs)
- Swapping is the key operation for in-place reversals
- Using a temp variable makes swapping safe and clear

Why Two Pointers Works Here:
- Array is processed from both ends simultaneously
- Each iteration handles two positions -> O(n) becomes O(n/2) iterations
- Perfect for symmetric operations like reversal

Increment/Decrement Shorthand:
- `left++` increments after using the current value
- `s[left++] = x` means: use current left, then increment
- This is valid because we're using the index before incrementing

---

## Alternative Approaches

**Approach 2: Using Recursion**
```cpp
void reverseStringRecursive(vector<char>& s, int left, int right) {
    if(left >= right) return;
    
    // Swap
    swap(s[left], s[right]);
    
    // Recursive call
    reverseStringRecursive(s, left + 1, right - 1);
}
```
- Time: O(n) for n recursive calls
- Space: O(n) for recursion stack

**Approach 3: Built-in Reverse Function**
```cpp
void reverseString(vector<char>& s) {
    reverse(s.begin(), s.end());
}
```
- Time: O(n)
- Space: O(1)
- But: Using built-in defeats the purpose of learning two pointers!

---
## Tags

array, two-pointers, easy, in-place, sorted-array, interview-favorite, optimal

---

**Last Updated**: 2026-02-08  
**Author**: [Chinmay048](https://github.com/Chinmay048)