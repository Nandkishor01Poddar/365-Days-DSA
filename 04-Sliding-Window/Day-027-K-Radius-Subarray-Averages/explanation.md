# LeetCode 2090 - K Radius Subarray Averages

## Problem Statement

You are given:

- An integer array `nums`
- An integer `k`

For every index `i`, find the average of the subarray centered at `i` having radius `k`.

The window contains:

- `k` elements on the left
- Current element
- `k` elements on the right

If there are not enough elements on either side, the answer for that index is `-1`.

The average is calculated using **integer division**.

---

# Example

### Input

```text
nums = [7,4,3,9,1,8,5,2,6]
k = 3
```

### Output

```text
[-1,-1,-1,5,4,4,-1,-1,-1]
```

### Explanation

Window Size

```
2*k + 1

= 2*3 + 1

= 7
```

For index **3**

```
7 4 3 9 1 8 5

Sum = 37

Average = 37 / 7 = 5
```

For index **4**

```
4 3 9 1 8 5 2

Sum = 32

Average = 32 / 7 = 4
```

For index **5**

```
3 9 1 8 5 2 6

Sum = 34

Average = 34 / 7 = 4
```

All remaining indices do not have enough elements on both sides.

---

# Observation

The window size is always

```
2*k + 1
```

The window size never changes.

Whenever the window size is fixed,

👉 Think **Fixed Size Sliding Window**.

---

# Approach 1 : Brute Force

## Idea

For every index

- Move `k` positions left.
- Move `k` positions right.
- Calculate the sum.
- Compute the average.

Repeat this for every index.

---

## Algorithm

```
For every index

    Check if k elements exist on both sides

    If not

        answer = -1

    Else

        Calculate sum

        Store average
```

---

## Dry Run

```
nums

7 4 3 9 1 8 5 2 6

Index = 3

Take

7 4 3 9 1 8 5

Average = 37/7 = 5
```

Next

```
Index = 4

Take

4 3 9 1 8 5 2

Average = 32/7 = 4
```

Again calculate everything from scratch.

---

## Time Complexity

```
O(n × (2k + 1))

≈ O(n × k)
```

---

## Space Complexity

```
O(n)
```

Answer array.

---

# Approach 2 : Sliding Window (Optimal)

## Observation

Look at two consecutive windows.

Window 1

```
7 4 3 9 1 8 5

Sum = 37
```

Window 2

```
4 3 9 1 8 5 2
```

Instead of calculating again,

```
Remove

7

Add

2
```

New Sum

```
37 - 7 + 2

= 32
```

No need to calculate the entire window again.

---

# Sliding Window Steps

## Step 1

Find window size

```
window = 2*k + 1
```

---

## Step 2

Build the first window.

```
7 4 3 9 1 8 5

Sum = 37
```

---

## Step 3

Store first average.

```
Center index = k

ans[k]

=

37 / 7

=

5
```

---

## Step 4

Slide the window.

Old Window

```
7 4 3 9 1 8 5
```

↓

Remove

```
7
```

↓

Add

```
2
```

↓

New Window

```
4 3 9 1 8 5 2

Sum

=

32
```

Store

```
ans[4]=32/7=4
```

Repeat until the end.

---

# Sliding Window Algorithm

```
Find window size

Build first window

Find its sum

Store first average

Slide window

Remove left element

Add right element

Store average
```

---

# Why Use long long?

The sum of the window may exceed the range of `int`.

Example

```
nums

100000
100000
100000
100000
100000
```

Window Sum

```
500000
```

For larger constraints, the sum can become much larger.

Using

```cpp
long long sum;
```

prevents integer overflow.

---

# Time Complexity

Building first window

```
O(window)

≈ O(k)
```

Sliding window

```
O(n)
```

Overall

```
O(n)
```

---

# Space Complexity

```
O(n)
```

Answer array.

---

# Brute Force vs Sliding Window

| Brute Force | Sliding Window |
|-------------|----------------|
| Calculates every window from scratch | Reuses previous window sum |
| Repeated calculations | Only remove one element and add one element |
| Time Complexity = **O(n × k)** | Time Complexity = **O(n)** |
| Easy to implement | Faster and optimized |
| Not efficient for large input | Interview preferred |

---

# Why Sliding Window is Better?

Instead of

```
Window 1

7 4 3 9 1 8 5
```

↓

Calculating again

```
Window 2

4 3 9 1 8 5 2
```

We simply

```
Remove

7

Add

2
```

Every slide takes only

```
O(1)
```

Therefore

```
Total

O(n)
```

---

# Edge Cases

## Case 1

```
k = 0
```

Every element is its own average.

Return the original array.

---

## Case 2

```
Window Size > Array Size
```

Example

```
n = 4

k = 3

Window

7
```

Impossible.

Return

```
[-1,-1,-1,-1]
```

---

# Interview Takeaways

✅ Identify the window size.

✅ If the window size is constant, think **Fixed Size Sliding Window**.

✅ Instead of recalculating every window, reuse the previous sum.

✅ Remove the outgoing element and add the incoming element.

✅ Use `long long` whenever the window sum can overflow an `int`.

---

# Key Learning

- Fixed Size Sliding Window
- Running Sum
- Window Size = `2*k+1`
- Integer Division
- Overflow Handling using `long long`
- Time Complexity Optimization

---

# Final Complexity

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | **O(n × k)** | **O(n)** |
| Sliding Window | **O(n)** | **O(n)** |

---

# Similar Problems

- LeetCode 643 - Maximum Average Subarray I ✅
- LeetCode 1652 - Defuse the Bomb       ✅
- LeetCode 2090 - K Radius Subarray Averages. ✅
- LeetCode 2379 - Minimum Recolors to Get K Consecutive Black Blocks
- LeetCode 1456 - Maximum Number of Vowels in a Substring of Given Length
- LeetCode 1343 - Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold