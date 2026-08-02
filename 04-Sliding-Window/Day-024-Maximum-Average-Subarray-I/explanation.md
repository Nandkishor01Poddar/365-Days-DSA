# 643. Maximum Average Subarray I

## Problem Statement

Given an integer array `nums` consisting of `n` elements and an integer `k`, find the contiguous subarray of length `k` that has the maximum average value and return that average.

---

## Example

Input:

```text
nums = [1,12,-5,-6,50,3]
k = 4
```

Output:

```text
12.75
```

Explanation:

```text
Window 1 = [1,12,-5,-6]    Sum = 2    Average = 0.5
Window 2 = [12,-5,-6,50]   Sum = 51   Average = 12.75
Window 3 = [-5,-6,50,3]    Sum = 42   Average = 10.5

Maximum Average = 12.75
```

---

# Approach 1 : Brute Force

## Idea

Generate every possible subarray of size `k`.

For each window,

- Calculate its sum.
- Calculate its average.
- Keep track of the maximum average.

---

## Algorithm

1. Traverse every possible starting index.
2. Compute the sum of the next `k` elements.
3. Find the average.
4. Update maximum average.

---

## Code

```cpp
double findMaxAverage(vector<int>& nums, int k) {

    double maxAvg = INT_MIN;

    for(int i=0;i<=nums.size()-k;i++){

        double sum = 0;

        for(int j=i;j<i+k;j++){
            sum += nums[j];
        }

        maxAvg = max(maxAvg, sum/k);
    }

    return maxAvg;
}
```

---

## Dry Run

```text
nums = [1,12,-5,-6,50,3]
k = 4
```

Window 1

```text
1 + 12 + (-5) + (-6)

Sum = 2

Average = 0.5
```

Window 2

```text
12 + (-5) + (-6) + 50

Sum = 51

Average = 12.75
```

Window 3

```text
-5 + (-6) + 50 + 3

Sum = 42

Average = 10.5
```

Answer

```text
12.75
```

---

## Complexity

Time Complexity

```text
O((n-k+1) × k)

≈ O(nk)
```

Space Complexity

```text
O(1)
```

---

# Why Brute Force is Slow?

Notice that while moving from one window to another,

```text
Window 1

[1 12 -5 -6]

Sum = 2
```

Next window

```text
[12 -5 -6 50]
```

Again we calculate

```text
12 + (-5) + (-6) + 50
```

Although

```text
12
-5
-6
```

were already calculated before.

We repeat unnecessary work.

---

# Optimized Approach : Sliding Window

## Observation

When the window moves one step,

Only

- One new element enters.
- One old element leaves.

Instead of calculating the entire sum again,

Update the previous sum.

Formula

```cpp
windowSum += nums[i];      // Add new element

windowSum -= nums[i-k];    // Remove old element
```

This makes each window update in **O(1)** time.

---

# Algorithm

### Step 1

Calculate the sum of the first window.

```text
First k elements
```

### Step 2

Store it as maximum sum.

### Step 3

Slide the window.

For every new position

```text
Add incoming element.

Remove outgoing element.

Update maximum sum.
```

### Step 4

Return

```text
maxSum / k
```

---

# Code

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double windowSum = 0;

        // First window
        for(int i=0;i<k;i++)
            windowSum += nums[i];

        double maxSum = windowSum;

        // Sliding window
        for(int i=k;i<nums.size();i++){

            windowSum += nums[i];

            windowSum -= nums[i-k];

            maxSum = max(maxSum, windowSum);
        }

        return maxSum/k;
    }
};
```

---

# Dry Run

Input

```text
nums = [1,12,-5,-6,50,3]

k = 4
```

### First Window

```text
[1 12 -5 -6]

Sum = 2

maxSum = 2
```

---

### Slide 1

Incoming

```text
50
```

Outgoing

```text
1
```

Update

```text
windowSum

= 2 + 50

= 52

windowSum

= 52 - 1

= 51
```

Window

```text
[12 -5 -6 50]
```

Update

```text
maxSum = max(2,51)

= 51
```

---

### Slide 2

Incoming

```text
3
```

Outgoing

```text
12
```

Update

```text
windowSum

= 51 + 3

= 54

windowSum

= 54 - 12

= 42
```

Window

```text
[-5 -6 50 3]
```

Update

```text
maxSum

= max(51,42)

= 51
```

Loop Ends.

Answer

```text
51 / 4

= 12.75
```

---

# Why Sliding Window Works

Suppose

```text
Current Window

[1 12 -5 -6]

Sum = 2
```

Next Window

```text
[12 -5 -6 50]
```

Instead of

```text
12-5-6+50
```

calculate

```text
Previous Sum

+

Incoming Element

-

Outgoing Element
```

which is

```text
2 + 50 - 1

= 51
```

Only **2 operations** instead of **k operations**.

---

# Complexity Analysis

## Brute Force

Time

```text
O(nk)
```

Space

```text
O(1)
```

---

## Sliding Window

Time

```text
O(n)
```

Space

```text
O(1)
```

---

# Comparison

| Feature | Brute Force | Sliding Window |
|----------|-------------|----------------|
| Recalculate every window | ✅ Yes | ❌ No |
| Uses previous window sum | ❌ No | ✅ Yes |
| Time Complexity | O(nk) | O(n) |
| Space Complexity | O(1) | O(1) |
| Interview Preferred | ❌ | ✅ |

---

# Interview Points

### Q1. Why Sliding Window?

Because the window size is fixed.

Instead of recalculating every window,

reuse the previous window's sum.

---

### Q2. Why not calculate average every time?

Average

```text
Average = Sum / k
```

Since `k` is constant,

comparing sums is enough.

Compute the average only once at the end.

---

### Q3. Why subtract `nums[i-k]`?

It is the element leaving the current window.

Example

```text
Current

[1 12 -5 -6]

Next

[12 -5 -6 50]
```

`1` leaves,

so subtract it.

---

### Q4. Why use `max(maxSum, windowSum)`?

It keeps the maximum window sum seen so far.

Equivalent to

```cpp
if(windowSum > maxSum)
    maxSum = windowSum;
```

---

# Key Takeaway

Whenever you encounter:

- Fixed-size subarray
- Fixed-size substring
- Maximum/Minimum sum
- Average
- Count

Always think of the **Sliding Window** technique first.