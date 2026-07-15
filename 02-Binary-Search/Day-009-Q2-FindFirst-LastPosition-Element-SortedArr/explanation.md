# LeetCode 34 - Find First and Last Position of Element in Sorted Array

**Difficulty:** Medium  
**Pattern:** Binary Search

---

# Problem Statement

Given a sorted array of integers `nums` in non-decreasing order, find the **starting** and **ending** position of a given target value.

If the target is not found in the array, return `[-1, -1]`.

You must write an algorithm with **O(log n)** runtime complexity.

---

# Example 1

```text
Input:
nums = [5,7,7,8,8,10]
target = 8

Output:
[3,4]
```

---

# Example 2

```text
Input:
nums = [5,7,7,8,8,10]
target = 6

Output:
[-1,-1]
```

---

# Example 3

```text
Input:
nums = []
target = 0

Output:
[-1,-1]
```

---

# Approach 1 : Brute Force

## Idea

Traverse the entire array.

- Store the index of the first occurrence.
- Keep updating the last occurrence whenever the target is found.

After the traversal,

- Return `{first, last}`.

---

## Algorithm

1. Initialize

```text
first = -1
last = -1
```

2. Traverse the array.

3. If `nums[i] == target`

- If `first == -1`
  - Store `i` as the first occurrence.
- Always update `last = i`.

4. Return `{first, last}`.

---

## Dry Run

```text
nums = [5,7,7,8,8,10]
target = 8
```

Traversal

```text
i = 0 -> 5
i = 1 -> 7
i = 2 -> 7
i = 3 -> 8

first = 3
last = 3

i = 4 -> 8

last = 4

i = 5 -> 10
```

Answer

```text
[3,4]
```

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | O(n) |
| Space | O(1) |

---

## Interview Discussion

### Advantages

- Very easy to understand.
- Simple implementation.

### Disadvantages

- Doesn't utilize the sorted property of the array.
- Fails the required O(log n) complexity.

---

# Approach 2 : Binary Search (Optimal)

## Observation

Since the array is sorted,

Binary Search can efficiently locate

- the **first occurrence**
- the **last occurrence**

using two separate searches.

---

## Core Idea

Perform Binary Search twice.

### First Binary Search

Find the **leftmost occurrence**.

Whenever

```text
nums[mid] == target
```

Store the answer and continue searching on the **left side**.

```text
end = mid - 1
```

---

### Second Binary Search

Find the **rightmost occurrence**.

Whenever

```text
nums[mid] == target
```

Store the answer and continue searching on the **right side**.

```text
start = mid + 1
```

---

# Binary Search Logic

Initialize

```text
start = 0
end = n - 1
answer = -1
```

While

```text
start <= end
```

Compute

```cpp
mid = start + (end - start) / 2;
```

### Case 1

```text
nums[mid] == target
```

Store

```text
answer = mid
```

If searching for

First Occurrence

```text
end = mid - 1
```

Else

```text
start = mid + 1
```

---

### Case 2

```text
nums[mid] < target
```

Search right.

```text
start = mid + 1
```

---

### Case 3

```text
nums[mid] > target
```

Search left.

```text
end = mid - 1
```

---

# Dry Run

```text
nums = [5,7,7,8,8,10]
target = 8
```

### First Occurrence

```text
start = 0
end = 5

mid = 2

7 < 8

start = 3
```

```text
mid = 4

nums[4] = 8

answer = 4

Move Left

end = 3
```

```text
mid = 3

nums[3] = 8

answer = 3

Move Left

end = 2
```

Loop Ends

First = 3

---

### Last Occurrence

```text
start = 0
end = 5
```

```text
mid = 2

7 < 8

start = 3
```

```text
mid = 4

8 found

answer = 4

Move Right

start = 5
```

Loop Ends

Last = 4

Final Answer

```text
[3,4]
```

---

# Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | O(log n) |
| Space | O(1) |

---

# Interview Follow-Up Questions

## Q1. Why perform Binary Search twice?

Because

- one search finds the leftmost occurrence.
- the other search finds the rightmost occurrence.

Each search still takes O(log n).

---

## Q2. Why not stop after finding the target?

Because another occurrence may exist.

We continue searching

- Left for the first occurrence.
- Right for the last occurrence.

---

## Q3. Why initialize answer as -1?

If the target doesn't exist,

the answer remains `-1`.

---

## Q4. Why use

```cpp
mid = start + (end - start) / 2;
```

instead of

```cpp
(start + end) / 2
```

To avoid integer overflow.

---

# Comparison

| Feature | Brute Force | Binary Search |
|----------|-------------|---------------|
| Time Complexity | O(n) | O(log n) |
| Space Complexity | O(1) | O(1) |
| Uses Sorted Property | ❌ No | ✅ Yes |
| Interview Preferred | ❌ No | ✅ Yes |

---

# Key Takeaways

- Always use Binary Search when the array is sorted.
- To find the **first occurrence**, continue searching on the **left** after finding the target.
- To find the **last occurrence**, continue searching on the **right** after finding the target.
- This problem introduces an important Binary Search pattern that is reused in:
  - Lower Bound
  - Upper Bound
  - Count Occurrences
  - Search Insert Position
  - Floor and Ceil
  - Rotated Sorted Array