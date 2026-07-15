# LeetCode 704 – Binary Search
 

## Problem Statement

Given a **sorted array** and a target element, find the index of the target using Binary Search.
If the target is not present, return `-1`.

---

## Brute Force Approach (Linear Search)

### Algorithm

1. Start from the first element.
2. Compare every element with the target.
3. If the target is found, return its index.
4. If the loop ends without finding the target, return `-1`.

### Code

```cpp
int linearSearch(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}
```

### Time Complexity

- **Best Case:** O(1)
- **Average Case:** O(n)
- **Worst Case:** O(n)

### Space Complexity

- **O(1)**

### Drawback

Since every element may need to be checked, Linear Search is slow for large arrays.

---

# Optimal Approach (Binary Search)

## Idea

Binary Search works only on **sorted arrays**.

Instead of checking every element, Binary Search repeatedly divides the search space into two halves.

- Find the middle element.
- If middle equals target → return index.
- If target is smaller → search left half.
- If target is greater → search right half.
- Continue until the element is found or the search space becomes empty.

---

## Algorithm

1. Initialize:
   - `start = 0`
   - `end = n - 1`
2. Find middle:
   ```cpp
   mid = start + (end - start) / 2;
   ```
3. Compare:
   - If `nums[mid] == target` → return `mid`
   - If `nums[mid] > target` → move left (`end = mid - 1`)
   - Else → move right (`start = mid + 1`)
4. Repeat until `start > end`.
5. Return `-1` if not found.

---

## Dry Run

### Input

```text
Array = [2, 4, 6, 8, 10, 12]
Target = 8
```

### Iteration 1

```
start = 0
end = 5

mid = 2

nums[mid] = 6
```

Since `8 > 6`, search the right half.

```
start = 3
end = 5
```

---

### Iteration 2

```
start = 3
end = 5

mid = 4

nums[mid] = 10
```

Since `8 < 10`, search the left half.

```
start = 3
end = 3
```

---

### Iteration 3

```
start = 3
end = 3

mid = 3

nums[mid] = 8
```

Target found.

Return **3**.

---

## Binary Search Code

```cpp
int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}
```

---

## Time Complexity

| Case | Complexity |
|------|------------|
| Best Case | O(1) |
| Average Case | O(log n) |
| Worst Case | O(log n) |

---

## Space Complexity

**O(1)**

---

# Why Binary Search is Faster?

Linear Search removes **one element** from consideration each step.

Binary Search removes **half of the remaining elements** each step.

Example:

For an array of **1,000,000 elements**

- Linear Search → up to **1,000,000 comparisons**
- Binary Search → about **20 comparisons**

This makes Binary Search much more efficient for searching in sorted arrays.

---

## Conditions

Binary Search works only when:

- The array is **sorted**.
- Random access to elements is available (like arrays or vectors).

---

## Summary

| Approach | Time | Space |
|----------|------|-------|
| Linear Search | O(n) | O(1) |
| Binary Search | O(log n) | O(1) |

**Binary Search is the preferred approach for searching in sorted arrays because it significantly reduces the search space in every iteration.**