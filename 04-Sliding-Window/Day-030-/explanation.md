# LeetCode 1343 - Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

## Problem Statement

You are given:

- An integer array `arr`
- An integer `k`
- An integer `threshold`

Find the number of subarrays of size `k` whose average is greater than or equal to `threshold`.

The subarray must contain exactly `k` consecutive elements.

---

# Example

### Input

```text
arr = [2,2,2,2,5,5,5,8]
k = 3
threshold = 4
```

### Output

```text
3
```

---

# Understanding the Condition

We need:

```text
Average >= threshold
```

Average is:

```text
sum / k
```

Therefore:

```text
sum / k >= threshold
```

Multiply both sides by `k`:

```text
sum >= k * threshold
```

So instead of calculating the average, we can simply check:

```text
windowSum >= k * threshold
```

This is an important interview optimization.

---

# Example

```text
k = 3
threshold = 4
```

Required sum:

```text
k * threshold

= 3 * 4

= 12
```

Therefore, every window with:

```text
sum >= 12
```

is valid.

---

# Observation

The subarray size is always:

```text
k
```

The window size never changes.

Therefore:

> This is a **Fixed Size Sliding Window** problem.

---

# Approach 1 : Brute Force

## Idea

For every possible subarray of size `k`:

1. Calculate the complete sum.
2. Check whether the sum is greater than or equal to `k * threshold`.
3. If valid, increase the count.

---

## Example

```text
arr = [2,2,2,2,5,5,5,8]
k = 3
threshold = 4
```

Required sum:

```text
3 * 4 = 12
```

Check every window.

### Window 1

```text
2 2 2
```

Sum:

```text
6
```

```text
6 < 12
```

Not counted.

---

### Window 2

```text
2 2 2
```

Sum:

```text
6
```

Not counted.

---

### Window 3

```text
2 2 5
```

Sum:

```text
9
```

Not counted.

---

### Window 4

```text
2 5 5
```

Sum:

```text
12
```

Count:

```text
1
```

---

### Window 5

```text
5 5 5
```

Sum:

```text
15
```

Count:

```text
2
```

---

### Window 6

```text
5 5 8
```

Sum:

```text
18
```

Count:

```text
3
```

Final answer:

```text
3
```

---

## Brute Force Time Complexity

For every window, we calculate `k` elements.

```text
O(n * k)
```

---

## Brute Force Space Complexity

Only a few variables are required.

```text
O(1)
```

---

# Approach 2 : Sliding Window

## Key Observation

Look at two consecutive windows.

First window:

```text
2 2 2
```

Sum:

```text
6
```

Next window:

```text
2 2 5
```

Instead of calculating:

```text
2 + 2 + 5
```

again, reuse the previous sum.

Remove the outgoing element:

```text
6 - 2
```

Add the incoming element:

```text
6 - 2 + 5
```

New sum:

```text
9
```

This is the Sliding Window technique.

---

# Sliding Window Formula

When the window moves one position:

```text
newSum = oldSum - outgoingElement + incomingElement
```

In code:

```cpp
windowSum -= arr[i - k];
windowSum += arr[i];
```

---

# Sliding Window Steps

## Step 1: Calculate the Target

```text
target = k * threshold
```

For:

```text
k = 3
threshold = 4
```

We get:

```text
target = 12
```

---

## Step 2: Build the First Window

```text
2 2 2
```

Sum:

```text
6
```

Check:

```text
6 >= 12
```

False.

Count:

```text
0
```

---

## Step 3: Slide the Window

Current:

```text
2 2 2
```

Remove:

```text
2
```

Add:

```text
5
```

New window:

```text
2 2 5
```

New sum:

```text
6 - 2 + 5

= 9
```

Check:

```text
9 >= 12
```

False.

---

## Step 4

Current:

```text
2 2 5
```

Remove:

```text
2
```

Add:

```text
5
```

New sum:

```text
9 - 2 + 5

= 12
```

Check:

```text
12 >= 12
```

True.

Count:

```text
1
```

---

## Step 5

Current:

```text
2 5 5
```

Remove:

```text
2
```

Add:

```text
5
```

New sum:

```text
12 - 2 + 5

= 15
```

Valid.

Count:

```text
2
```

---

## Step 6

Current:

```text
5 5 5
```

Remove:

```text
5
```

Add:

```text
8
```

New sum:

```text
15 - 5 + 8

= 18
```

Valid.

Count:

```text
3
```

Final answer:

```text
3
```

---

# Sliding Window Algorithm

```text
target = k * threshold

Build the first window

Calculate its sum

If sum >= target
    count++

Slide the window

Remove the outgoing element

Add the incoming element

If sum >= target
    count++

Return count
```

---

# C++ Solution

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int target = k * threshold;

        int windowSum = 0;
        int count = 0;

        // Build the first window
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        // Check the first window
        if (windowSum >= target) {
            count++;
        }

        // Slide the window
        for (int i = k; i < arr.size(); i++) {

            // Remove outgoing element
            windowSum -= arr[i - k];

            // Add incoming element
            windowSum += arr[i];

            // Check current window
            if (windowSum >= target) {
                count++;
            }
        }

        return count;
    }
};
```

---

# Why Don't We Calculate the Average?

We could write:

```cpp
if (windowSum / k >= threshold)
```

But there is no need.

Instead:

```cpp
if (windowSum >= k * threshold)
```

This is simpler and avoids division.

---

# Brute Force vs Sliding Window

| Brute Force | Sliding Window |
|-------------|----------------|
| Calculates every window sum from scratch | Reuses previous window sum |
| Repeated calculations | Remove + Add |
| Time: **O(n × k)** | Time: **O(n)** |
| Space: **O(1)** | Space: **O(1)** |
| Easy but slower | Optimized and interview preferred |

---

# Why Sliding Window is Better?

Suppose:

```text
Window 1

2 2 2
```

Then:

```text
Window 2

2 2 5
```

Only one element leaves:

```text
2
```

And one element enters:

```text
5
```

So instead of recalculating the entire window:

```text
2 + 2 + 5
```

we do:

```text
oldSum - 2 + 5
```

Each window takes only:

```text
O(1)
```

Therefore, the entire algorithm takes:

```text
O(n)
```

---

# Time Complexity

### First Window

```text
O(k)
```

### Sliding

```text
O(n - k)
```

### Overall

```text
O(n)
```

---

# Space Complexity

Only variables such as:

```text
windowSum
count
target
```

are used.

Therefore:

```text
O(1)
```

---

# Final Complexity

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | **O(n × k)** | **O(1)** |
| Sliding Window | **O(n)** | **O(1)** |

---

# Interview Takeaways

✅ Fixed window size → think **Sliding Window**.

✅ Convert:

```text
average >= threshold
```

into:

```text
sum >= k * threshold
```

✅ Build the first window once.

✅ When sliding:

```text
Remove outgoing element
+
Add incoming element
```

✅ Maintain the window sum instead of recalculating it.

---

# Key Learning

- Fixed Size Sliding Window
- Running Sum
- Average to Sum Transformation
- Threshold Comparison
- Window Update
- Time Complexity Optimization
- O(1) Extra Space

---

# Pattern Summary

The common Fixed Size Sliding Window pattern is:

```text
Build First Window
       ↓
Calculate Information
       ↓
Store / Check Answer
       ↓
Remove Left Element
       ↓
Add Right Element
       ↓
Update Answer
       ↓
Repeat
```

---

# Similar Problems

- LeetCode 643 - Maximum Average Subarray I
- LeetCode 1652 - Defuse the Bomb
- LeetCode 2090 - K Radius Subarray Averages
- LeetCode 2379 - Minimum Recolors to Get K Consecutive Black Blocks
- LeetCode 1456 - Maximum Number of Vowels in a Substring of Given Length
- LeetCode 1343 - Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold