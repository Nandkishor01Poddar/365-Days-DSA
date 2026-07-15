# LeetCode 35 - Search Insert Position

**Difficulty:** Easy  
**Pattern:** Binary Search  
**Time Complexity:**  
- Linear Search: **O(n)**
- Binary Search: **O(log n)**

**Space Complexity:**  
- Linear Search: **O(1)**
- Binary Search: **O(1)**

---

# Problem Statement

Given a **sorted array of distinct integers** and a target value, return the index if the target is found.

If the target is **not present**, return the index where it would be inserted while maintaining the sorted order.

---

## Example 1

```text
Input:
nums = [1,3,5,6]
target = 5

Output:
2
```

---

## Example 2

```text
Input:
nums = [1,3,5,6]
target = 2

Output:
1
```

---

## Example 3

```text
Input:
nums = [1,3,5,6]
target = 7

Output:
4
```

---

## Approach 1 : Linear Search (Brute Force)

### Idea

Traverse the array from left to right.

- If an element is greater than or equal to the target, return its index.
- If no such element exists, the target should be inserted at the end of the array.

### Algorithm

1. Traverse the array.
2. Check if `nums[i] >= target`.
3. Return `i`.
4. If traversal completes, return `nums.size()`.

### Dry Run

```text
nums = [1,3,5,6]
target = 2

i = 0 -> 1 < 2
i = 1 -> 3 >= 2

Answer = 1
```

### Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | O(n) |
| Space | O(1) |

### Interview Discussion

**Advantages**

- Very easy to implement.
- No special logic required.

**Disadvantages**

- Doesn't utilize the fact that the array is sorted.
- Inefficient for large arrays.

---

# Approach 2 : Binary Search (Optimal)

### Observation

The array is already sorted.

Instead of checking every element, repeatedly divide the search space into two halves.

### Core Idea

There are only two possibilities:

- Target exists → Return its index.
- Target doesn't exist → Return the position where it should be inserted.

After Binary Search finishes,

```text
start == insertion position
```

Therefore, simply return `start`.

---

## Binary Search Logic

Initialize

```text
start = 0
end = n - 1
```

Repeat while

```text
start <= end
```

Find

```text
mid = start + (end - start) / 2
```

Cases

### Case 1

```text
nums[mid] == target
```

Return `mid`.

---

### Case 2

```text
nums[mid] < target
```

Search in the right half.

```text
start = mid + 1
```

---

### Case 3

```text
nums[mid] > target
```

Search in the left half.

```text
end = mid - 1
```

---

When the loop ends,

```text
start > end
```

At this point,

`start` represents the first position where the target can be inserted.

Return

```text
start
```

---

# Dry Run

```text
nums = [1,3,5,6]
target = 2
```

Initial

```text
start = 0
end = 3
```

Iteration 1

```text
mid = 1

nums[mid] = 3
```

Since

```text
3 > 2
```

Move left

```text
end = 0
```

---

Iteration 2

```text
start = 0
end = 0

mid = 0

nums[mid] = 1
```

Since

```text
1 < 2
```

Move right

```text
start = 1
```

Now

```text
start = 1
end = 0
```

Loop terminates.

Return

```text
start = 1
```

Correct Answer ✅

---

# Why Return `start`?

When Binary Search finishes,

```text
end < start
```

The search space becomes empty.

At this moment,

- All indices before `start` contain values smaller than the target.
- All indices from `start` onward contain values greater than or equal to the target.

Therefore,

```text
start
```

is exactly the insertion position.

---

# Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | O(log n) |
| Space | O(1) |

---

# Interview Follow-Up Questions

### Q1. Why use Binary Search?

Because the array is sorted, allowing us to eliminate half of the search space in each iteration.

---

### Q2. Why return `start` instead of `end`?

When the loop terminates,

```text
start = end + 1
```

`start` points to the correct insertion position.

`end` points to the last element smaller than the target.

---

### Q3. Why calculate mid like this?

```cpp
mid = start + (end - start) / 2;
```

instead of

```cpp
mid = (start + end) / 2;
```

To prevent integer overflow when `start` and `end` are very large.

---

### Q4. Can this be solved without Binary Search?

Yes.

Using Linear Search.

However,

- Time Complexity becomes **O(n)**.
- Binary Search is the preferred interview solution.

---

# Key Takeaways

- Always use Binary Search on sorted arrays.
- Binary Search reduces the search space by half in every iteration.
- Returning `start` gives the correct insertion index when the target is absent.
- This problem is the foundation for advanced Binary Search questions like:
  - First and Last Position of Element
  - Lower Bound
  - Upper Bound
  - Floor and Ceil
  - Search in Rotated Sorted Array