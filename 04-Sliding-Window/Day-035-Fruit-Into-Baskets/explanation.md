# LeetCode 904 - Fruit Into Baskets

## Problem Statement

You are given an integer array `fruits`.

Each element represents a type of fruit.

You have exactly **2 baskets**.

Each basket can contain only **one type of fruit**, but it can contain any number of fruits of that type.

You want to collect the **maximum number of consecutive fruits**.

---

# Example

### Input

```text
fruits = [1,2,1,2,3,2,2]
```

### Output

```text
4
```

### Explanation

We can collect:

```text
[1,2,1,2]
```

There are only two fruit types:

```text
1
2
```

So both baskets can be used.

Length:

```text
4
```

If we include `3`:

```text
[1,2,1,2,3]
```

There are three fruit types:

```text
1
2
3
```

But we only have two baskets.

Therefore, the maximum is:

```text
4
```

---

# Important Observation

The problem can be converted into:

> Find the **longest contiguous subarray containing at most 2 distinct values**.

Why?

Each basket can store only one fruit type.

Therefore:

```text
Number of distinct fruit types <= 2
```

is a valid window.

---

# Pattern Recognition

There is no fixed window size.

The window grows and shrinks depending on the number of distinct fruit types.

Therefore:

> **Variable Size Sliding Window**

---

# Two Pointers

We use:

```text
left
right
```

The current window is:

```text
fruits[left ... right]
```

### `right`

Expands the window.

### `left`

Shrinks the window when there are more than 2 distinct fruit types.

---

# Frequency Map

We need to know:

```text
How many times does each fruit type occur in the current window?
```

Use:

```cpp
unordered_map<int, int> freq;
```

Example:

```text
Window:

[1,2,1,2]
```

Frequency map:

```text
1 → 2
2 → 2
```

Number of distinct types:

```text
freq.size() = 2
```

The window is valid.

---

# Valid and Invalid Window

### Valid

```text
freq.size() <= 2
```

### Invalid

```text
freq.size() > 2
```

When the window becomes invalid, shrink it from the left.

---

# Approach 1 : Brute Force

## Idea

Check every possible subarray.

For each subarray:

1. Store its distinct fruit types.
2. If there are at most 2 types, calculate its length.
3. Update the maximum length.

---

## Example

```text
fruits = [1,2,1,2,3]
```

Possible valid windows include:

```text
[1]
[1,2]
[1,2,1]
[1,2,1,2]
```

The longest valid window is:

```text
[1,2,1,2]
```

Length:

```text
4
```

---

## Brute Force Time Complexity

```text
O(n²)
```

We examine many possible subarrays.

---

## Brute Force Space Complexity

```text
O(n)
```

A set/map may be required to track distinct values.

---

# Approach 2 : Variable Sliding Window

## Main Idea

Maintain a window containing:

```text
at most 2 distinct fruit types
```

Expand using `right`.

If:

```text
freq.size() > 2
```

the window is invalid.

Shrink using `left` until:

```text
freq.size() <= 2
```

Then update the maximum window length.

---

# Sliding Window Algorithm

```text
left = 0
answer = 0

Create frequency map

For every right:

    Add fruits[right] to frequency map

    While distinct types > 2:

        Decrease frequency of fruits[left]

        If frequency becomes 0:
            Remove that fruit from map

        Move left forward

    Update maximum window length
```

---

# Dry Run

```text
fruits = [1,2,1,2,3,2,2]
```

---

## Step 1

Add:

```text
1
```

Window:

```text
[1]
```

Map:

```text
1 → 1
```

Distinct:

```text
1
```

Valid.

Length:

```text
1
```

Answer:

```text
1
```

---

## Step 2

Add:

```text
2
```

Window:

```text
[1,2]
```

Map:

```text
1 → 1
2 → 1
```

Distinct:

```text
2
```

Valid.

Length:

```text
2
```

Answer:

```text
2
```

---

## Step 3

Add:

```text
1
```

Window:

```text
[1,2,1]
```

Map:

```text
1 → 2
2 → 1
```

Distinct:

```text
2
```

Valid.

Length:

```text
3
```

Answer:

```text
3
```

---

## Step 4

Add:

```text
2
```

Window:

```text
[1,2,1,2]
```

Map:

```text
1 → 2
2 → 2
```

Distinct:

```text
2
```

Valid.

Length:

```text
4
```

Answer:

```text
4
```

---

## Step 5

Add:

```text
3
```

Window:

```text
[1,2,1,2,3]
```

Map:

```text
1 → 2
2 → 2
3 → 1
```

Distinct:

```text
3
```

Invalid:

```text
3 > 2
```

---

# Shrink the Window

Remove from the left.

Remove:

```text
1
```

Map:

```text
1 → 1
2 → 2
3 → 1
```

Still 3 types.

Remove:

```text
2
```

Map:

```text
1 → 1
2 → 1
3 → 1
```

Still 3 types.

Remove:

```text
1
```

Now:

```text
1 → 0
```

Remove `1` from the map.

Map:

```text
2 → 1
3 → 1
```

Distinct:

```text
2
```

Window is valid again.

Current window:

```text
[2,3]
```

Length:

```text
2
```

Answer remains:

```text
4
```

---

# Why Do We Erase From the Map?

Suppose:

```text
freq[1] = 0
```

That means fruit type `1` no longer exists inside the current window.

Therefore, we must remove it:

```cpp
freq.erase(1);
```

Otherwise:

```cpp
freq.size()
```

would incorrectly count `1` as a distinct fruit type.

---

# C++ LeetCode Solution

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < fruits.size(); right++) {

            // Add current fruit to the window
            freq[fruits[right]]++;

            // Shrink while there are more than 2 fruit types
            while (freq.size() > 2) {

                // Remove the leftmost fruit
                freq[fruits[left]]--;

                // Remove fruit type if it no longer exists
                if (freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }

                left++;
            }

            // Current window has at most 2 fruit types
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```

---

# VS Code Dynamic Input

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int totalFruit(vector<int>& fruits)
{
    unordered_map<int, int> freq;

    int left = 0;
    int ans = 0;

    for (int right = 0; right < fruits.size(); right++)
    {
        // Add current fruit
        freq[fruits[right]]++;

        // Shrink while there are more than 2 types
        while (freq.size() > 2)
        {
            // Remove leftmost fruit
            freq[fruits[left]]--;

            // Remove fruit type if frequency becomes zero
            if (freq[fruits[left]] == 0)
            {
                freq.erase(fruits[left]);
            }

            left++;
        }

        // Update maximum window length
        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> fruits(n);

    cout << "Enter fruit types: ";

    for (int i = 0; i < n; i++)
    {
        cin >> fruits[i];
    }

    cout << "Maximum fruits collected: "
         << totalFruit(fruits)
         << endl;

    return 0;
}
```

---

# VS Code Example

### Input

```text
7
1 2 1 2 3 2 2
```

### Output

```text
Maximum fruits collected: 4
```

---

# Brute Force vs Sliding Window

| Brute Force | Sliding Window |
|-------------|----------------|
| Checks every possible subarray | Maintains one moving window |
| Finds distinct types repeatedly | Maintains a frequency map |
| Time: **O(n²)** | Time: **O(n)** |
| Space: **O(n)** | Space: **O(n)** |
| Simple but slow | Optimized and interview preferred |

---

# Why Sliding Window is Better?

Suppose the current window is:

```text
[1,2,1,2]
```

Frequency:

```text
1 → 2
2 → 2
```

Now `3` enters:

```text
[1,2,1,2,3]
```

There are 3 types.

Instead of starting over, we remove elements from the left until one fruit type disappears completely.

This allows us to maintain the window efficiently.

---

# Complexity

## Time Complexity

```text
O(n)
```

Every element:

- Enters the window once.
- Leaves the window at most once.

Map operations are expected `O(1)`.

---

## Space Complexity

```text
O(n)
```

In the worst case, the frequency map can contain many distinct values, although in this particular algorithm we shrink as soon as it exceeds 2.

Because the window is maintained at at most 2 distinct values, the practical auxiliary map size is at most **3 temporarily**, so it can also be considered:

```text
O(1)
```

for the algorithm's maintained state.

---

# Important Difference: LC 1004 vs LC 904

## LC 1004

Problem:

```text
Longest window with at most k zeros
```

Track:

```text
zeroCount
```

Condition:

```text
zeroCount <= k
```

---

## LC 904

Problem:

```text
Longest window with at most 2 distinct values
```

Track:

```text
frequency map
```

Condition:

```text
freq.size() <= 2
```

The underlying pattern is the same:

```text
Expand
   ↓
Constraint violated
   ↓
Shrink
   ↓
Constraint satisfied
   ↓
Update maximum
```

---

# General Pattern: At Most K Distinct

LC 904 is a special case of:

```text
Longest subarray with at most K distinct values
```

For LC 904:

```text
K = 2
```

General pattern:

```cpp
while (freq.size() > K)
{
    freq[arr[left]]--;

    if (freq[arr[left]] == 0)
        freq.erase(arr[left]);

    left++;
}
```

This pattern is extremely useful in interviews.

---

# Interview Intuition

When you see:

> "You have 2 baskets"

Translate it immediately to:

```text
At most 2 distinct values
```

Then think:

```text
Variable Sliding Window
+
Frequency Map
```

The key transformation is:

```text
2 baskets
    ↓
2 fruit types
    ↓
At most 2 distinct values
    ↓
Longest valid window
```

---

# Core Variable Sliding Window Pattern

```text
Expand with right
       ↓
Add element to frequency map
       ↓
Too many distinct values?
       ↓
YES
       ↓
Shrink from left
       ↓
Remove zero-frequency values
       ↓
Window becomes valid
       ↓
Update maximum
```

---

# Key Learning

- Variable Size Sliding Window
- Two Pointers
- Frequency Map
- At Most K Distinct Values
- Hash Map
- Longest Valid Window
- Window Shrinking
- Frequency Management
- `O(n)` Optimization

---

# Final Complexity

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | **O(n²)** | **O(n)** |
| Sliding Window | **O(n)** | **O(1)*** |

`*` The maintained frequency map contains at most 2 active fruit types (and at most 3 briefly before shrinking).

---

# Similar Problems

- LeetCode 3 - Longest Substring Without Repeating Characters
- LeetCode 209 - Minimum Size Subarray Sum
- LeetCode 1004 - Max Consecutive Ones III
- LeetCode 424 - Longest Repeating Character Replacement
- LeetCode 567 - Permutation in String
- LeetCode 438 - Find All Anagrams in a String
- LeetCode 76 - Minimum Window Substring

---

# Pattern Progress

```text
LC 3
Longest window
without duplicates
        ↓
LC 209
Minimum window
with sum >= target
        ↓
LC 1004
Longest window
with at most K zeros
        ↓
LC 904
Longest window
with at most K distinct values
```

The important pattern to remember:

```text
right → expand

while constraint is violated:
    left → shrink

update answer
```