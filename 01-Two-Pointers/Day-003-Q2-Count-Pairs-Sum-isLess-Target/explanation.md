# LeetCode 2824 – Count pairs Whose Sum is Less than Target

## Problem Statement

You are given two sorted integer arrays `nums1` and `nums2` along with two integers `m` and `n`.

- The first `m` elements of `nums1` are valid.
- `nums1` has enough extra space (`n` positions) to store all elements of `nums2`.

Merge `nums2` into `nums1` so that `nums1` becomes one sorted array.

The merge must be performed **in-place** without using any extra array.

---

# Method: Three Pointers (Optimal)

## Intuition

Since both arrays are already sorted, we can merge them efficiently by starting from the **end** of both arrays.

We use three pointers:

- `i` → Last valid element of `nums1`
- `j` → Last element of `nums2`
- `k` → Last index of `nums1`

At each step:

- Compare `nums1[i]` and `nums2[j]`.
- Place the larger element at `nums1[k]`.
- Move the corresponding pointer backward.
- Continue until one array is exhausted.

If any elements remain in `nums2`, copy them into `nums1`.

There is no need to copy the remaining elements of `nums1` because they are already in their correct positions.

---

## Algorithm

1. Initialize:
   - `i = m - 1`
   - `j = n - 1`
   - `k = m + n - 1`
2. Compare `nums1[i]` and `nums2[j]`.
3. Place the larger element at `nums1[k]`.
4. Move the corresponding pointer backward.
5. Repeat until one array is exhausted.
6. Copy any remaining elements from `nums2`.

---

## Example 1

### Input

```text
nums1 = [1,2,3,0,0,0]
m = 3

nums2 = [2,5,6]
n = 3
```

### Output

```text
[1,2,2,3,5,6]
```

---

## Dry Run

```text
nums1 : 1 2 3 0 0 0
              ↑     ↑
              i     k

nums2 : 2 5 6
            ↑
            j
```

- Compare `3` and `6` → Place `6`
- Compare `3` and `5` → Place `5`
- Compare `3` and `2` → Place `3`
- Compare `2` and `2` → Place `2`

Final array:

```text
[1,2,2,3,5,6]
```

---

## Example 2

### Input

```text
nums1 = [2,0]
m = 1

nums2 = [1]
n = 1
```

### Output

```text
[1,2]
```

---

## Time Complexity

- Traversing both arrays once: **O(m + n)**

---

## Space Complexity

- Only three pointer variables are used.

**O(1)**

---

## Advantages

- Optimal solution.
- In-place merging.
- Constant extra space.
- Linear time complexity.
- Interview-friendly.

---

## Key Concepts Learned

- Three Pointer Technique
- In-place Array Manipulation
- Merging Two Sorted Arrays
- Time and Space Complexity Optimization

---

## Final Recommendation

The **Three Pointer** approach is the optimal solution for merging two sorted arrays.

- ✅ **Time Complexity:** `O(m + n)`
- ✅ **Space Complexity:** `O(1)`

It is the standard interview solution because it efficiently merges both arrays without using any extra memory.