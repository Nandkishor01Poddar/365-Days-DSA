# LeetCode 3 - Longest Substring Without Repeating Characters

## Problem Statement

Given a string `s`, find the length of the **longest substring without repeating characters**.

A substring must contain **continuous characters**.

---

# Example

### Input

```text
s = "abcabcbb"
```

### Output

```text
3
```

### Explanation

The longest substrings without repeating characters are:

```text
"abc"
"bca"
"cab"
```

Their length is:

```text
3
```

Therefore:

```text
Answer = 3
```

---

# Important Observation

Unlike Fixed Size Sliding Window problems, here the window size is **not fixed**.

For example:

```text
"a"
"ab"
"abc"
```

The window expands.

When a duplicate appears:

```text
"abca"
```

The window becomes invalid.

We need to move `left`.

Therefore, this is:

> **Variable Size Sliding Window**

---

# Sliding Window

We maintain two pointers:

```text
left
right
```

The current window is:

```text
s[left ... right]
```

### `right`

Expands the window.

### `left`

Shrinks the window when a duplicate is found.

---

# Approach 1 : Brute Force

## Idea

Generate every possible substring and check whether it contains duplicate characters.

For every starting position:

```text
Start from i

Keep adding characters

Check for duplicate
```

This requires checking many substrings repeatedly.

---

## Time Complexity

Depending on implementation, brute force can take approximately:

```text
O(n²)
```

or worse if every substring is checked using another data structure.

---

## Space Complexity

```text
O(n)
```

depending on the duplicate-checking method.

---

# Approach 2 : Sliding Window + Set

## Idea

Maintain a set containing characters currently inside the window.

Example:

```text
s = "abcabcbb"
```

Window:

```text
a b c
```

Set:

```text
{a,b,c}
```

When another `a` appears:

```text
a b c a
```

`a` already exists.

So we remove characters from the left until the duplicate disappears.

---

## Code Logic

```cpp
while (seen.count(s[right])) {

    seen.erase(s[left]);

    left++;
}
```

Then:

```cpp
seen.insert(s[right]);
```

---

## Complexity

```text
Time  : O(n)
Space : O(n)
```

Although there is a `while` loop inside the `for` loop, the overall complexity remains `O(n)` because each character is inserted and removed at most once.

---

# Approach 3 : Optimized Last Index ⭐

Instead of storing only whether a character exists, store the **last index where each character appeared**.

For example:

```text
s = "abcabcbb"
```

After processing:

```text
a → 0
b → 1
c → 2
```

When we encounter `a` again at index `3`:

```text
a was last seen at index 0
```

Instead of moving `left` one position at a time, we can directly jump:

```text
left = 0 + 1

left = 1
```

This makes the window valid immediately.

---

# Why Direct Jump Works

Suppose:

```text
s = "abcdaef"
```

Current window:

```text
a b c d
```

Now we encounter:

```text
a
```

The previous `a` was at index `0`.

Instead of:

```text
left++
```

multiple times, directly move:

```text
left = previousIndex + 1
```

Therefore:

```text
left = 1
```

New valid window:

```text
b c d a
```

---

# Important Condition

We should only move `left` if the previous occurrence is **inside the current window**.

Therefore:

```cpp
if (lastIndex.count(s[right]) &&
    lastIndex[s[right]] >= left)
```

Why?

Consider:

```text
s = "abba"
```

After processing the second `b`:

```text
left = 2
```

Later we encounter `a`.

Previous `a` was at index `0`.

But:

```text
0 < left
```

So that `a` is already outside the current window.

We should NOT move `left` backward.

Therefore we check:

```cpp
lastIndex[s[right]] >= left
```

---

# Optimized Algorithm

```text
Initialize left = 0

Create a map storing the last index of each character

For every right:

    If current character was seen
    AND its previous position is inside the window:

        Move left directly after its previous position

    Update current character's last index

    Calculate current window length

    Update maximum answer
```

---

# Dry Run

```text
s = "abcabcbb"
```

### Step 1

```text
right = 0
character = a
```

Store:

```text
a → 0
```

Window:

```text
a
```

Length:

```text
1
```

Answer:

```text
1
```

---

### Step 2

```text
right = 1
character = b
```

Store:

```text
b → 1
```

Window:

```text
ab
```

Length:

```text
2
```

Answer:

```text
2
```

---

### Step 3

```text
right = 2
character = c
```

Store:

```text
c → 2
```

Window:

```text
abc
```

Length:

```text
3
```

Answer:

```text
3
```

---

### Step 4

```text
right = 3
character = a
```

Previous `a`:

```text
index = 0
```

Current:

```text
left = 0
```

Since:

```text
0 >= 0
```

Move:

```text
left = 0 + 1

left = 1
```

Update:

```text
a → 3
```

Current window:

```text
b c a
```

Length:

```text
3
```

Answer:

```text
3
```

---

### Step 5

```text
right = 4
character = b
```

Previous `b`:

```text
index = 1
```

Current:

```text
left = 1
```

Duplicate is inside the window.

Move:

```text
left = 1 + 1

left = 2
```

Current window:

```text
c a b
```

Length:

```text
3
```

Answer:

```text
3
```

---

# Optimized C++ Code

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Store the last index of every character
        unordered_map<char, int> lastIndex;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            // If the character appeared before and
            // its previous occurrence is inside the window
            if (lastIndex.count(s[right]) &&
                lastIndex[s[right]] >= left) {

                // Jump left directly after the duplicate
                left = lastIndex[s[right]] + 1;
            }

            // Update the last index of current character
            lastIndex[s[right]] = right;

            // Calculate current window length
            int windowLength = right - left + 1;

            // Update maximum length
            ans = max(ans, windowLength);
        }

        return ans;
    }
};
```

---

# VS Code Dynamic Input

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    // Store the last index of every character
    unordered_map<char, int> lastIndex;

    int left = 0;
    int ans = 0;

    for (int right = 0; right < s.length(); right++)
    {
        // Check whether the character appeared
        // inside the current window
        if (lastIndex.count(s[right]) &&
            lastIndex[s[right]] >= left)
        {
            // Jump left directly
            left = lastIndex[s[right]] + 1;
        }

        // Store the latest index
        lastIndex[s[right]] = right;

        // Calculate current window length
        int windowLength = right - left + 1;

        // Update maximum answer
        ans = max(ans, windowLength);
    }

    return ans;
}

int main()
{
    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Longest substring length: "
         << lengthOfLongestSubstring(s)
         << endl;

    return 0;
}
```

---

# VS Code Example

### Input

```text
abcabcbb
```

### Output

```text
Longest substring length: 3
```

---

# Approach Comparison

| Approach | Time | Space | Main Idea |
|---|---:|---:|---|
| Brute Force | `O(n²)` or worse | `O(n)` | Generate/check substrings |
| Sliding Window + Set | **O(n)** | `O(n)` | Remove duplicates one by one |
| Sliding Window + Last Index | **O(n)** | `O(n)` | Jump `left` directly |

---

# Why Last Index is Better?

### Set Approach

When duplicate is found:

```text
Duplicate
   ↓
Remove from left
   ↓
Remove again
   ↓
Remove again
   ↓
Valid window
```

### Last Index Approach

```text
Duplicate
   ↓
Find previous index
   ↓
Jump left directly
   ↓
Valid window
```

The second approach is cleaner and avoids repeatedly deleting characters.

---

# Even More Optimized Version

Because this problem deals with characters, we can use an array instead of `unordered_map`.

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> lastIndex(256, -1);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            if (lastIndex[s[right]] >= left) {
                left = lastIndex[s[right]] + 1;
            }

            lastIndex[s[right]] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```

This gives constant-time array lookup and is a very clean implementation for an interview.

---

# Complexity of Optimized Array Version

```text
Time  : O(n)
Space : O(1)
```

The array has a fixed size of `256`.

---

# Interview Takeaways

✅ This is a **Variable Size Sliding Window** problem.

✅ `right` expands the window.

✅ `left` shrinks or jumps when the window becomes invalid.

✅ Store the **last index** instead of repeatedly removing characters.

✅ Important condition:

```cpp
lastIndex[s[right]] >= left
```

This prevents `left` from moving backward.

✅ Current window length:

```cpp
right - left + 1
```

---

# Core Variable Sliding Window Pattern

```cpp
int left = 0;

for (int right = 0; right < n; right++)
{
    // Expand window

    while (window is invalid)
    {
        // Shrink window
        left++;
    }

    // Update answer
}
```

For LC 3, we optimize the shrinking step:

```cpp
left = lastIndex[s[right]] + 1;
```

---

# Key Learning

- Variable Size Sliding Window
- Two Pointers
- Hash Map
- Last Seen Index
- Direct Pointer Jump
- Duplicate Detection
- Maximum Window Length
- `O(n)` Optimization

---

# Similar Problems

- LeetCode 209 - Minimum Size Subarray Sum
- LeetCode 1004 - Max Consecutive Ones III
- LeetCode 904 - Fruit Into Baskets
- LeetCode 424 - Longest Repeating Character Replacement
- LeetCode 567 - Permutation in String
- LeetCode 438 - Find All Anagrams in a String
- LeetCode 76 - Minimum Window Substring