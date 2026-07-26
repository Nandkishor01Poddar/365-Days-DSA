# LeetCode 457 – Circular Array Loop (Fast & Slow Pointer)

## Intuition

This problem is an application of **Floyd's Cycle Detection Algorithm** (Fast & Slow Pointer).

We treat each **array index as a node** and the value at that index tells us where to move next.

- Positive value → Move forward.
- Negative value → Move backward.
- The array is circular, so we wrap around using modulo.

Our goal is to determine whether there exists a **valid cycle**.

---

## Conditions for a Valid Cycle

A cycle is valid only if:

1. Every move is in the **same direction**.
   - Either all positive.
   - Or all negative.

2. The cycle length must be **greater than 1**.

If any condition fails, the cycle is invalid.

---

## Example

Input

```text
nums = [2, -1, 1, 2, 2]
```

Index mapping

```text
Index : 0   1   2   3   4
Value : 2  -1   1   2   2
```

Movement

```text
0 → 2 → 3 → 0
```

This forms a valid cycle because

- All values are positive.
- Cycle length is 3.

Answer = **true**

---

# Step 1: Next Index Function

Since the array is circular, after moving beyond the last index we return to the beginning.

Similarly, moving before index 0 wraps to the end.

```cpp
int nextIndex(vector<int>& nums, int i) {
    int n = nums.size();
    return ((i + nums[i]) % n + n) % n;
}
```

Why `+ n`?

Because C++ returns a negative remainder for negative numbers.

Example

```text
(-1) % 5 = -1
```

Adding `n` makes it positive.

```text
((-1 % 5) + 5) % 5 = 4
```

---

# Step 2: Try Every Starting Index

A cycle may start from any index.

```cpp
for(int i = 0; i < n; i++)
```

Skip already visited nodes.

```cpp
if(nums[i] == 0)
    continue;
```

---

# Step 3: Decide the Direction

The direction must remain the same throughout the traversal.

```cpp
bool forward = nums[i] > 0;
```

If

```text
forward = true
```

then every visited element must be positive.

If

```text
forward = false
```

then every visited element must be negative.

---

# Step 4: Initialize Fast and Slow Pointer

Both start from the same index.

```cpp
int slow = i;
int fast = i;
```

---

# Step 5: Move Slow and Fast

Slow moves one step.

```cpp
nextSlow = nextIndex(nums, slow);
```

Fast moves two steps.

```cpp
nextFast = nextIndex(nums, fast);
nextFast = nextIndex(nums, nextFast);
```

---

# Step 6: Direction Check

Suppose

```text
2 → -3
```

Direction changed.

This is **not allowed**.

Therefore

```cpp
if ((nums[nextSlow] > 0) != forward)
    break;
```

Same check is performed for fast pointer.

---

# Step 7: Detect Cycle

If

```cpp
slow == fast
```

then a cycle exists.

Example

```text
Step 1
Slow = 2
Fast = 3

Step 2
Slow = 3
Fast = 2

Step 3
Slow = 0
Fast = 0
```

Both meet.

---

# Step 8: Ignore Self Loop

Suppose

```text
nums = [3]
```

Movement

```text
0 → 0
```

The pointer immediately comes back to itself.

Cycle length = 1.

The problem states that cycle length must be greater than one.

Hence

```cpp
if (slow == nextIndex(nums, slow))
    break;
```

---

# Step 9: Mark Visited Nodes

If no valid cycle is found from this starting point, mark all visited nodes.

```cpp
nums[curr] = 0;
```

Now future iterations skip them.

```cpp
if(nums[i] == 0)
    continue;
```

This prevents revisiting the same path repeatedly.

---

# Dry Run

Input

```text
nums = [2, -1, 1, 2, 2]
```

### Initial

```text
Slow = 0
Fast = 0
```

### First Move

```text
Slow = 2
Fast = 3
```

### Second Move

```text
Slow = 3
Fast = 2
```

### Third Move

```text
Slow = 0
Fast = 0
```

Pointers meet.

Self-loop?

```text
0 → 2

No
```

Therefore

```text
Return True
```

---

# Visualization

```text
      0
     / \
    /   \
   2 --> 3
    ^     |
    |_____|
```

Fast Pointer

```text
0 → 3 → 0
```

Slow Pointer

```text
0 → 2 → 3 → 0
```

Eventually both meet.

---

# Complexity Analysis

### Time Complexity

- Every index is visited at most once.

**O(n)**

### Space Complexity

No extra data structure is used.

**O(1)**

---

# Key Points

- Treat every index as a node.
- Positive means move forward.
- Negative means move backward.
- Use Floyd's Fast & Slow Pointer algorithm.
- Reject cycles if direction changes.
- Reject cycles of length 1.
- Mark visited nodes as `0` to avoid repeated work.
- Overall complexity is **O(n)** time and **O(1)** space.