# LeetCode 88 – Merge Sorted Array

## Problem Statement

You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of valid elements in each array.

- `nums1` has a size of `m + n`.
- The first `m` elements of `nums1` are valid, while the last `n` elements are placeholders (`0`) to accommodate elements from `nums2`.

Merge `nums2` into `nums1` so that `nums1` becomes a single sorted array.

The merge must be performed **in-place**, meaning no extra array should be used.

---

# Method 1: Three Pointers (Optimal)

## Intuition

Since both arrays are already sorted, we can merge them efficiently without using any additional space.

If we start merging from the beginning of `nums1`, we may overwrite elements that have not yet been compared.

To avoid this, we start filling the array **from the end**.

We use three pointers:

- `i` → Points to the last valid element in `nums1`.
- `j` → Points to the last element in `nums2`.
- `k` → Points to the last index of `nums1`.

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

2. While both arrays contain elements:
   - Compare `nums1[i]` and `nums2[j]`.
   - Place the larger element at `nums1[k]`.
   - Move the corresponding pointer backward.
   - Decrement `k`.

3. Copy any remaining elements from `nums2`.

4. The merged array is stored in `nums1`.

---

## Dry Run

### Input

```text
nums1 = [1,2,3,0,0,0]
m = 3

nums2 = [2,5,6]
n = 3
```

### Initial State

```text
nums1 : 1 2 3 0 0 0
            ↑     ↑
            i     k

nums2 : 2 5 6
            ↑
            j
```

---

### Step 1

Compare:

```text
3 and 6
```

Place `6` at index `k`.

```text
nums1 = [1,2,3,0,0,6]
```

Move pointers:

```text
i = 2
j = 1
k = 4
```

---

### Step 2

Compare:

```text
3 and 5
```

Place `5`.

```text
nums1 = [1,2,3,0,5,6]
```

Move pointers.

---

### Step 3

Compare:

```text
3 and 2
```

Place `3`.

```text
nums1 = [1,2,3,3,5,6]
```

Move pointers.

---

### Step 4

Compare:

```text
2 and 2
```

Place either value.

```text
nums1 = [1,2,2,3,5,6]
```

Now `j = -1`, so the merge is complete.

---

### Output

```text
[1,2,2,3,5,6]
```

---

## Why Start From the End?

If we merge from the beginning, elements in `nums1` may get overwritten before they are compared.

Starting from the end ensures that every original element remains available until it has been processed.

This allows us to perform the merge **in-place** without using extra memory.

---

## Time Complexity

Each element from both arrays is processed at most once.

- Traversing `nums1` → **O(m)**
- Traversing `nums2` → **O(n)**

Overall Time Complexity:

**O(m + n)**

---

## Space Complexity

Only three pointer variables are used.

No additional array is created.

**Space Complexity: O(1)**

---

## Advantages

- Optimal linear-time solution.
- Uses constant extra space.
- Performs merging in-place.
- Avoids unnecessary copying.
- Interview-friendly approach.

---

# Method 2: Extra Array (Brute Force)

## Intuition

Create a new array and merge both arrays into it just like the Merge step of Merge Sort.

After merging, copy all elements back to `nums1`.

Although this approach is simple, it requires additional memory.

---

## Algorithm

1. Create an empty array.
2. Use two pointers to merge both sorted arrays.
3. Append any remaining elements.
4. Copy the merged array back into `nums1`.

---

## Time Complexity

Merging both arrays takes:

**O(m + n)**

Copying elements back also takes:

**O(m + n)**

Overall:

**O(m + n)**

---

## Space Complexity

A new array of size `m + n` is created.

**O(m + n)**

---

## Comparison

| Feature | Method 1 | Method 2 |
|----------|----------|----------|
| Time Complexity | **O(m + n)** | **O(m + n)** |
| Space Complexity | **O(1)** | **O(m + n)** |
| In-place Merge | ✅ | ❌ |
| Uses Extra Array | ❌ | ✅ |
| Interview Preferred | ✅ | ❌ |
| Easy to Understand | Moderate | ✅ |

---

# Key Concepts Learned

This problem teaches several important concepts:

- Three Pointer Technique
- In-place Array Manipulation
- Merging Two Sorted Arrays
- Greedy Element Placement
- Time and Space Complexity Optimization

---

# Final Recommendation

The **Three Pointer** approach is the optimal solution for this problem.

It efficiently merges two sorted arrays by filling `nums1` from the end, preventing overwriting of existing elements.

### Complexity

- ✅ **Time Complexity:** `O(m + n)`
- ✅ **Space Complexity:** `O(1)`

This is the standard solution expected in coding interviews and is the most efficient approach for merging two sorted arrays in-place.