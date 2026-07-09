# LeetCode 1 – Two Sum

## Problem Statement

You are given an integer array `nums` and an integer `target`.

Return the **indices** of the two numbers such that they add up to `target`.

You may assume that each input has **exactly one solution**, and you cannot use the same element twice.

You can return the answer in any order.

---

# Method: Hash Map (Optimal)

## Intuition

A brute-force solution checks every possible pair, which takes **O(n²)** time.

A better approach is to use a **Hash Map** (`unordered_map`) to store numbers we have already visited along with their indices.

For every element:

- Compute the value needed to reach the target.
- Check whether that value already exists in the hash map.
- If it exists, we have found our answer.
- Otherwise, store the current number and its index in the hash map.

Since hash map lookup takes **O(1)** on average, the overall solution becomes linear.

---

## Algorithm

1. Create an empty hash map.
2. Traverse the array.
3. For each element:
   - Calculate `target - nums[i]`.
   - If the value exists in the hash map, return both indices.
   - Otherwise, store the current number and its index.
4. Return the answer.

---

## Example

### Input

```text
nums = [2,7,11,15]
target = 9
```

### Dry Run

Initially

```text
Map = {}
```

**Step 1**

```text
Current = 2
Looking For = 7
```

Not found.

Store

```text
Map = {2 : 0}
```

---

**Step 2**

```text
Current = 7
Looking For = 2
```

Found in the map.

Return indices

```text
[0,1]
```

---

### Output

```text
[0,1]
```

---

## Time Complexity

- Traverse the array once: **O(n)**
- Hash map lookup: **O(1)** (average)

Overall Time Complexity:

**O(n)**

---

## Space Complexity

The hash map stores at most `n` elements.

**O(n)**

---

## Advantages

- Optimal linear-time solution.
- Uses only one traversal.
- Fast hash map lookup.
- Common interview approach.

---

## Key Concepts Learned

- Hash Map (`unordered_map`)
- One-pass traversal
- Complement technique
- Time and Space Complexity Optimization

---

## Final Recommendation

The **Hash Map** approach is the optimal solution for the Two Sum problem.

- ✅ **Time Complexity:** `O(n)`
- ✅ **Space Complexity:** `O(n)`

It is the standard solution expected in coding interviews because it efficiently finds the required pair in a single pass.