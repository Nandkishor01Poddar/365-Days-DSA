# LeetCode 209 - Minimum Size Subarray Sum

## Problem Statement

You are given:

- An integer `target`
- An array of **positive integers** `nums`

Find the **minimum length** of a contiguous subarray whose sum is greater than or equal to `target`.

If no such subarray exists, return:

```text
0
```

---

# Example

### Input

```text
target = 7
nums = [2,3,1,2,4,3]
```

### Output

```text
2
```

### Explanation

The valid subarrays include:

```text
[2,3,1,2] = 8
```

Length:

```text
4
```

```text
[3,1,2,4] = 10
```

Length:

```text
4
```

```text
[1,2,4] = 7
```

Length:

```text
3
```

```text
[2,4,3] = 9
```

Length:

```text
3
```

The smallest valid subarray is:

```text
[4,3]
```

Sum:

```text
4 + 3 = 7
```

Length:

```text
2
```

Therefore:

```text
Answer = 2
```

---

# Important Observation

There is no fixed window size.

We need to find the **smallest** window whose sum is at least `target`.

Therefore, this is a:

> **Variable Size Sliding Window**

---

# Why Can We Use Sliding Window?

The array contains **positive integers**.

Therefore:

When we expand the window:

```text
sum increases
```

When we shrink the window:

```text
sum decreases
```

This predictable behavior allows us to efficiently find the minimum valid window.

---

# Two Pointers

We use two pointers:

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

Shrinks the window.

---

# Core Idea

The main pattern is:

```text
Expand
   ↓
sum >= target
   ↓
Shrink
   ↓
Find smallest valid window
```

Unlike some sliding-window problems, we shrink the window **while it is valid**.

---

# Approach 1 : Brute Force

## Idea

Generate every possible subarray.

For each starting index:

```text
Start a subarray

Keep adding elements

Check whether sum >= target

If valid:
    update minimum length
```

---

## Example

```text
target = 7

nums = [2,3,1,2,4,3]
```

Possible valid windows:

```text
[2,3,1,2] = 8
Length = 4
```

```text
[3,1,2,4] = 10
Length = 4
```

```text
[1,2,4] = 7
Length = 3
```

```text
[2,4,3] = 9
Length = 3
```

```text
[4,3] = 7
Length = 2
```

Minimum:

```text
2
```

---

## Brute Force Time Complexity

If we calculate each subarray sum from scratch:

```text
O(n²)
```

---

## Brute Force Space Complexity

```text
O(1)
```

---

# Approach 2 : Variable Sliding Window

## Step 1: Initialize

```cpp
int left = 0;
int sum = 0;
int ans = INT_MAX;
```

---

## Step 2: Expand the Window

Move `right` through the array.

```cpp
sum += nums[right];
```

---

## Step 3: Check the Condition

When:

```text
sum >= target
```

the current window is valid.

Now we want to make it smaller.

---

## Step 4: Shrink the Window

While the window is still valid:

```cpp
while (sum >= target)
```

Update the answer:

```cpp
ans = min(ans, right - left + 1);
```

Then remove the left element:

```cpp
sum -= nums[left];
left++;
```

---

# Dry Run

```text
target = 7

nums = [2,3,1,2,4,3]
```

---

## Step 1

```text
right = 0

Window:

[2]

sum = 2
```

```text
2 < 7
```

Not valid.

Expand.

---

## Step 2

```text
right = 1

Window:

[2,3]

sum = 5
```

```text
5 < 7
```

Not valid.

Expand.

---

## Step 3

```text
right = 2

Window:

[2,3,1]

sum = 6
```

```text
6 < 7
```

Not valid.

Expand.

---

## Step 4

```text
right = 3

Window:

[2,3,1,2]

sum = 8
```

Now:

```text
8 >= 7
```

Valid.

Length:

```text
4
```

Update:

```text
ans = 4
```

---

### Shrink

Remove `2`:

```text
[3,1,2]

sum = 6
```

Now:

```text
6 < 7
```

Stop shrinking.

---

## Step 5

Add `4`:

```text
[3,1,2,4]

sum = 10
```

Valid.

Length:

```text
4
```

Answer remains:

```text
4
```

---

### Shrink

Remove `3`:

```text
[1,2,4]

sum = 7
```

Still valid.

Length:

```text
3
```

Update:

```text
ans = 3
```

---

### Shrink Again

Remove `1`:

```text
[2,4]

sum = 6
```

Invalid.

Stop.

---

## Step 6

Add `3`:

```text
[2,4,3]

sum = 9
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

### Shrink

Remove `2`:

```text
[4,3]

sum = 7
```

Still valid.

Length:

```text
2
```

Update:

```text
ans = 2
```

---

### Shrink Again

Remove `4`:

```text
[3]

sum = 3
```

Invalid.

Stop.

Final answer:

```text
2
```

---

# Sliding Window Algorithm

```text
left = 0
sum = 0
answer = infinity

For every right:

    Add nums[right] to sum

    While sum >= target:

        Update minimum answer

        Remove nums[left]

        Move left forward

If no valid window exists:

    return 0

Otherwise:

    return answer
```

---

# C++ Solution

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0;
        int sum = 0;

        int ans = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {

            // Expand the window
            sum += nums[right];

            // Shrink while the window is valid
            while (sum >= target) {

                // Update minimum window length
                ans = min(ans, right - left + 1);

                // Remove the leftmost element
                sum -= nums[left];

                // Move left pointer
                left++;
            }
        }

        // Return 0 if no valid subarray exists
        if (ans == INT_MAX)
            return 0;

        return ans;
    }
};
```

---

# VS Code Dynamic Input

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
    int left = 0;
    int sum = 0;

    int ans = INT_MAX;

    for (int right = 0; right < nums.size(); right++)
    {
        // Expand the window
        sum += nums[right];

        // Shrink while the window is valid
        while (sum >= target)
        {
            // Update minimum length
            ans = min(ans, right - left + 1);

            // Remove left element
            sum -= nums[left];

            // Move left forward
            left++;
        }
    }

    // No valid subarray found
    if (ans == INT_MAX)
        return 0;

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

    int target;

    cout << "Enter target: ";
    cin >> target;

    cout << "Minimum Subarray Length: "
         << minSubArrayLen(target, nums)
         << endl;

    return 0;
}
```

---

# VS Code Example

### Input

```text
6
2 3 1 2 4 3
7
```

### Output

```text
Minimum Subarray Length: 2
```

---

# Brute Force vs Sliding Window

| Brute Force | Sliding Window |
|-------------|----------------|
| Checks many subarrays | Maintains one moving window |
| Recalculates sums | Reuses current sum |
| Time: **O(n²)** | Time: **O(n)** |
| Space: **O(1)** | Space: **O(1)** |
| Simple but slow | Optimized and interview preferred |

---

# Why Sliding Window is Better?

Suppose:

```text
[2,3,1,2]
```

Sum:

```text
8
```

The window is valid.

Instead of starting over, remove the left element:

```text
8 - 2 = 6
```

Now add the next element:

```text
6 + 4 = 10
```

The window changes efficiently without recalculating everything.

---

# Important Difference From LC 3

### LC 3 - Longest Substring Without Repeating Characters

We shrink when the window becomes:

```text
INVALID
```

Pattern:

```text
Expand

while invalid:
    shrink

update answer
```

---

### LC 209 - Minimum Size Subarray Sum

We shrink when the window is:

```text
VALID
```

because we want to make it as small as possible.

Pattern:

```text
Expand

while valid:
    update answer
    shrink
```

This distinction is extremely important.

---

# Interview Pattern

For **minimum valid window** problems:

```cpp
for (right...)
{
    // Expand

    while (condition is valid)
    {
        // Update minimum

        // Shrink
    }
}
```

For LC 209:

```cpp
while (sum >= target)
```

because the condition for a valid window is:

```text
sum >= target
```

---

# Why Positive Integers Matter

This solution depends on the fact that all numbers are positive.

When we add an element:

```text
sum increases
```

When we remove an element:

```text
sum decreases
```

This allows us to safely shrink the window.

If negative numbers were allowed, this predictable behavior would no longer hold, and this simple sliding-window approach would not work in general.

---

# Time Complexity

### Expand

Every element is added once:

```text
O(n)
```

### Shrink

Every element is removed at most once:

```text
O(n)
```

Therefore:

```text
Total = O(n)
```

---

# Space Complexity

Only a few variables are used:

```text
left
right
sum
ans
```

Therefore:

```text
O(1)
```

---

# Final Complexity

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | **O(n²)** | **O(1)** |
| Sliding Window | **O(n)** | **O(1)** |

---

# Interview Takeaways

✅ No fixed `k` → Variable Size Sliding Window.

✅ `right` expands the window.

✅ When `sum >= target`, the window is valid.

✅ Because we need the **minimum**, shrink while the window remains valid.

✅ Update the answer **before** removing the left element.

✅ All numbers being positive is important.

---

# Key Learning

- Variable Size Sliding Window
- Two Pointers
- Running Sum
- Minimum Valid Window
- Expand and Shrink
- Positive Integer Constraint
- `O(n)` Optimization

---

# Core Pattern

```text
              right
                ↓
[  window elements  ]

Expand
   ↓
Condition becomes valid
   ↓
Update answer
   ↓
Shrink from left
   ↓
Condition becomes invalid
   ↓
Expand again
```

---

# Similar Problems

- LeetCode 3 - Longest Substring Without Repeating Characters
- LeetCode 1004 - Max Consecutive Ones III
- LeetCode 904 - Fruit Into Baskets
- LeetCode 424 - Longest Repeating Character Replacement
- LeetCode 567 - Permutation in String
- LeetCode 438 - Find All Anagrams in a String
- LeetCode 76 - Minimum Window Substring