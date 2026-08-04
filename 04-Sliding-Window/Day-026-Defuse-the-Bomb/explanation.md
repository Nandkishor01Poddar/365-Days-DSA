# LeetCode 1652 - Defuse the Bomb

## Problem Statement

You are given a circular integer array `code` and an integer `k`.

For every index:

- If `k > 0`, replace the element with the sum of the **next `k` elements**.
- If `k < 0`, replace the element with the sum of the **previous `|k|` elements**.
- If `k == 0`, replace every element with `0`.

Since the array is **circular**, after the last element, the first element comes again.

---

# Example

### Input

```text
code = [5,7,1,4]
k = 3
```

### Output

```text
[12,10,16,13]
```

### Explanation

```
Index 0 -> 7 + 1 + 4 = 12

Index 1 -> 1 + 4 + 5 = 10

Index 2 -> 4 + 5 + 7 = 16

Index 3 -> 5 + 7 + 1 = 13
```

---

# Approach 1 : Brute Force

## Idea

For every element,

- Visit the next `k` elements (or previous `|k|` elements if `k < 0`)
- Calculate their sum.
- Store the result.

Since we calculate the sum separately for every index, many elements are added repeatedly.

---

## Algorithm

For every index

```
sum = 0

Visit next/previous k elements

Add them into sum

Store answer
```

---

## Code Logic

```cpp
for every index
{
    sum = 0;

    for(k elements)
        sum += value;

    ans[index] = sum;
}
```

---

## Time Complexity

```
O(n × |k|)
```

Every element calculates another `k` elements.

---

## Space Complexity

```
O(n)
```

For the answer array.

---

# Approach 2 : Sliding Window (Optimal)

## Observation

Notice two consecutive windows.

For index 0

```
7 1 4

Sum = 12
```

For index 1

```
1 4 5

Sum = 10
```

Instead of calculating

```
1 + 4 + 5
```

again,

we already know

```
7 + 1 + 4 = 12
```

Simply

```
Remove 7

Add 5
```

New Sum

```
12 - 7 + 5 = 10
```

Only **one element leaves** and **one element enters** the window.

This is the Sliding Window technique.

---

# Sliding Window Steps

### Step 1

Build the first window.

```
code = [5,7,1,4]

Window

7 1 4

Sum = 12
```

---

### Step 2

Store

```
ans[0] = 12
```

---

### Step 3

Slide Window

Current

```
7 1 4
```

Remove

```
7
```

Add

```
5
```

New Window

```
1 4 5

Sum = 10
```

Store

```
ans[1] = 10
```

Repeat until every index is processed.

---

# Why Modulo (%)?

The array is circular.

```
Index

0 1 2 3

After 3

comes

0
```

Instead of writing special conditions,

we use

```cpp
(index % n)
```

Example

```
Index = 4

4 % 4 = 0
```

So

```
code[4 % 4]

=

code[0]
```

This automatically wraps around.

---

# Sliding Window Algorithm

```
Build first window

Calculate its sum

For every index

Store answer

Remove leftmost element

Add next element

Move window forward
```

---

# Time Complexity

```
O(n)
```

Each element enters the window once and leaves once.

---

# Space Complexity

```
O(n)
```

For the answer array.

---

# Brute Force vs Sliding Window

| Brute Force | Sliding Window |
|-------------|----------------|
| Recalculates every window from scratch | Reuses previous window sum |
| Same elements are added many times | Each element is added and removed once |
| Time Complexity: **O(n × |k|)** | Time Complexity: **O(n)** |
| Easy to understand | More optimized |
| Slower for large inputs | Faster and interview preferred |

---

# Why Sliding Window is Better?

Instead of computing every window again,

```
Window 1

7 1 4
```

↓

```
Window 2

1 4 5
```

We simply

```
Remove 7

Add 5
```

So every movement costs **O(1)**.

Overall complexity becomes

```
O(n)
```

instead of

```
O(n × |k|)
```

---

# Interview Takeaways

✅ Identify whether the window size is **fixed** or **variable**.

✅ If consecutive windows overlap, think about Sliding Window.

✅ Instead of recalculating the entire window, remove the outgoing element and add the incoming element.

✅ For circular arrays, use modulo (`%`) to wrap indices.

---

# Key Learning

- Circular Array
- Fixed Size Sliding Window
- Running Sum
- Modulo Arithmetic
- Time Complexity Optimization
- Window Expansion and Shift
- Interview Pattern Recognition

---

# Final Complexity

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | **O(n × |k|)** | **O(n)** |
| Sliding Window | **O(n)** | **O(n)** |

---

## Similar Sliding Window Problems

- LeetCode 643 - Maximum Average Subarray I
- LeetCode 2090 - K Radius Subarray Averages
- LeetCode 219 - Contains Duplicate II
- LeetCode 2379 - Minimum Recolors to Get K Consecutive Black Blocks
- LeetCode 209 - Minimum Size Subarray Sum
- LeetCode 438 - Find All Anagrams in a String
- LeetCode 567 - Permutation in String