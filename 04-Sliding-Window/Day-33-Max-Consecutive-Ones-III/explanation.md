# LeetCode 1004 - Max Consecutive Ones III

## Problem Statement

You are given a binary array `nums` containing only:

```text
0 and 1
```

You are also given an integer `k`.

You can flip at most `k` zeros into ones.

Find the **maximum number of consecutive 1s** that can be obtained.

---

# Example

### Input

```text
nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2
```

### Output

```text
6
```

### Explanation

We can choose:

```text
[0,0,1,1,1,1]
```

There are:

```text
2 zeros
```

Since:

```text
k = 2
```

we can flip both zeros:

```text
[1,1,1,1,1,1]
```

Length:

```text
6
```

Therefore:

```text
Answer = 6
```

---

# Important Observation

We do **not** actually need to flip the zeros.

Instead, think:

> Find the longest subarray containing **at most `k` zeros**.

Why?

If a window contains:

```text
zeros <= k
```

we can flip all those zeros into ones.

Therefore, that entire window can become consecutive ones.

---

# Example

```text
nums = [1,1,1,0,0,1,1]
k = 2
```

Consider:

```text
1 1 1 0 0 1 1
```

Number of zeros:

```text
2
```

Since:

```text
2 <= k
```

we can flip both zeros:

```text
1 1 1 1 1 1 1
```

So the window length is:

```text
7
```

---

# Pattern Recognition

There is no fixed window size.

The window grows and shrinks depending on the number of zeros.

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
nums[left ... right]
```

### `right`

Expands the window.

### `left`

Shrinks the window when the number of zeros becomes greater than `k`.

---

# Valid and Invalid Window

A window is valid when:

```text
zeroCount <= k
```

A window is invalid when:

```text
zeroCount > k
```

Therefore:

```text
Expand
   ↓
zeroCount > k
   ↓
Shrink
   ↓
zeroCount <= k
   ↓
Update maximum
```

---

# Approach 1 : Brute Force

## Idea

Check every possible subarray.

For each subarray:

1. Count the number of zeros.
2. If zeros are `<= k`, the window is valid.
3. Update the maximum length.

---

## Example

```text
nums = [1,1,0,0,1]
k = 1
```

Check:

```text
[1,1] → 0 zeros → valid → length 2
```

```text
[1,1,0] → 1 zero → valid → length 3
```

```text
[1,1,0,0] → 2 zeros → invalid
```

Continue for every possible subarray.

---

## Time Complexity

```text
O(n²)
```

Because we check many subarrays.

---

## Space Complexity

```text
O(1)
```

Only a few variables are needed.

---

# Approach 2 : Variable Sliding Window

## Main Idea

Maintain a window with:

```text
zeroCount <= k
```

Expand the window using `right`.

When we encounter a zero:

```cpp
zeroCount++;
```

If:

```text
zeroCount > k
```

the window becomes invalid.

Shrink it using `left`.

---

# Sliding Window Algorithm

```text
left = 0
zeroCount = 0
answer = 0

For every right:

    If nums[right] == 0:
        zeroCount++

    While zeroCount > k:

        If nums[left] == 0:
            zeroCount--

        left++

    Update maximum length
```

---

# Dry Run

```text
nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2
```

---

## Step 1

```text
Window:

1
```

Zeros:

```text
0
```

Valid:

```text
0 <= 2
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

## Step 2

```text
Window:

1 1
```

Zeros:

```text
0
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

## Step 3

```text
Window:

1 1 1
```

Zeros:

```text
0
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

## Step 4

Add `0`.

```text
1 1 1 0
```

Zeros:

```text
1
```

Valid:

```text
1 <= 2
```

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

Add another `0`.

```text
1 1 1 0 0
```

Zeros:

```text
2
```

Valid:

```text
2 <= 2
```

Length:

```text
5
```

Answer:

```text
5
```

---

## Step 6

Add another `0`.

```text
1 1 1 0 0 0
```

Zeros:

```text
3
```

Now:

```text
3 > 2
```

Window is invalid.

---

# Shrink the Window

Remove from the left.

Remove:

```text
1
```

Zeros remain:

```text
3
```

Still invalid.

Remove:

```text
1
```

Zeros:

```text
3
```

Still invalid.

Remove:

```text
1
```

Zeros:

```text
3
```

Still invalid.

Remove:

```text
0
```

Zeros:

```text
2
```

Now:

```text
2 <= 2
```

Window is valid again.

---

# Why Don't We Actually Flip Zeros?

This is an important problem-solving trick.

Suppose:

```text
window = [1,0,1,0,1]
k = 2
```

We could actually flip:

```text
0 → 1
0 → 1
```

and get:

```text
[1,1,1,1,1]
```

But performing the flip is unnecessary.

We only need to know:

```text
How many zeros are inside the window?
```

If:

```text
zeroCount <= k
```

then we know the entire window can become ones.

This makes the solution much simpler.

---

# C++ LeetCode Solution

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;
        int zeroCount = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Add current element to the window
            if (nums[right] == 0) {
                zeroCount++;
            }

            // Shrink while more than k zeros exist
            while (zeroCount > k) {

                // Remove the leftmost element
                if (nums[left] == 0) {
                    zeroCount--;
                }

                left++;
            }

            // Current window is valid
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
using namespace std;

int longestOnes(vector<int>& nums, int k)
{
    int left = 0;
    int zeroCount = 0;
    int ans = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        // Add current element
        if (nums[right] == 0)
        {
            zeroCount++;
        }

        // Shrink while zeros exceed k
        while (zeroCount > k)
        {
            // Remove left element
            if (nums[left] == 0)
            {
                zeroCount--;
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

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k;

    cout << "Enter k: ";
    cin >> k;

    cout << "Maximum Consecutive Ones: "
         << longestOnes(nums, k)
         << endl;

    return 0;
}
```

---

# VS Code Example

### Input

```text
11
1 1 1 0 0 0 1 1 1 1 0
2
```

### Output

```text
Maximum Consecutive Ones: 6
```

---

# Brute Force vs Sliding Window

| Brute Force | Sliding Window |
|-------------|----------------|
| Checks every possible subarray | Maintains one moving window |
| Counts zeros repeatedly | Maintains `zeroCount` |
| Time: **O(n²)** | Time: **O(n)** |
| Space: **O(1)** | Space: **O(1)** |
| Simple but slow | Optimized and interview preferred |

---

# Why Sliding Window is Better?

Suppose:

```text
1 1 0 0 1
```

Instead of checking every subarray from scratch, we maintain:

```text
zeroCount
```

When a new element enters:

```text
0 → zeroCount++
```

When an element leaves:

```text
0 → zeroCount--
```

Therefore, we always know whether the current window is valid.

---

# Complexity

## Time Complexity

```text
O(n)
```

Every element:

- Enters the window once.
- Leaves the window at most once.

Therefore, total work is linear.

---

## Space Complexity

```text
O(1)
```

Only:

```text
left
right
zeroCount
ans
```

are used.

---

# Important Difference: LC 3 vs LC 209 vs LC 1004

## LC 3 - Longest Substring Without Repeating Characters

Goal:

```text
Longest valid window
```

Invalid condition:

```text
Duplicate character
```

Pattern:

```text
Expand

while invalid:
    shrink

update maximum
```

---

## LC 209 - Minimum Size Subarray Sum

Goal:

```text
Minimum valid window
```

Valid condition:

```text
sum >= target
```

Pattern:

```text
Expand

while valid:
    update minimum
    shrink
```

---

## LC 1004 - Max Consecutive Ones III

Goal:

```text
Longest valid window
```

Valid condition:

```text
zeroCount <= k
```

Invalid condition:

```text
zeroCount > k
```

Pattern:

```text
Expand

while invalid:
    shrink

update maximum
```

---

# Interview Intuition

When you see:

> "You can flip at most `k` zeros."

Do not think about actually flipping them.

Think:

```text
How many zeros are inside my current window?
```

Then:

```text
zeroCount <= k
```

means:

```text
The window can be converted completely into 1s.
```

Therefore:

> **Find the longest window containing at most `k` zeros.**

---

# Interview Pattern

```text
Expand with right
       ↓
Add element to window
       ↓
Update zeroCount
       ↓
Is zeroCount > k?
       ↓
YES
       ↓
Shrink with left
       ↓
zeroCount <= k
       ↓
Update maximum
```

---

# Key Learning

- Variable Size Sliding Window
- Two Pointers
- At Most `K` Constraint
- Counting Zeros
- Longest Valid Window
- Expand and Shrink
- Running Count
- `O(n)` Optimization

---

# Final Complexity

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | **O(n²)** | **O(1)** |
| Sliding Window | **O(n)** | **O(1)** |

---

# Similar Problems

- LeetCode 3 - Longest Substring Without Repeating Characters
- LeetCode 209 - Minimum Size Subarray Sum
- LeetCode 904 - Fruit Into Baskets
- LeetCode 424 - Longest Repeating Character Replacement
- LeetCode 567 - Permutation in String
- LeetCode 438 - Find All Anagrams in a String
- LeetCode 76 - Minimum Window Substring