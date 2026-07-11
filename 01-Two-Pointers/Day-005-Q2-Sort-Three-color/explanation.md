# LeetCode 75 – Sort Colors

# Sort Three Colors (Dutch National Flag Algorithm)

## Problem Statement

Given an array containing only **0**, **1**, and **2**, sort the array in-place so that:

- All `0`s come first
- Then all `1`s
- Then all `2`s

Example:

```
Input : 2 0 2 1 1 0
Output: 0 0 1 1 2 2
```

---

# Approach 1: Brute Force

## Method 1: Use a Sorting Algorithm

Simply sort the array using a standard sorting algorithm.

```cpp
sort(nums.begin(), nums.end());
```

### Complexity

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(1)` (ignoring recursion/implementation details)

---

## Method 2: Counting

Count the number of `0`s, `1`s, and `2`s.

Then overwrite the array.

```cpp
count0 = ...
count1 = ...
count2 = ...
```

Fill:

- First `count0` positions → `0`
- Next `count1` positions → `1`
- Remaining positions → `2`

### Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

# Best Approach: Dutch National Flag Algorithm

This is the most common interview solution.

## Idea

Use three pointers.

```
i  -> next position for 0
j  -> current element
k  -> next position for 2
```

Initially

```
i = 0
j = 0
k = n-1
```

The array is divided into four regions.

```
0 .... i-1      -> all 0
i .... j-1      -> all 1
j .... k        -> unknown
k+1 .... n-1    -> all 2
```

---

## Algorithm

- If `nums[j] == 0`
  - Swap `nums[i]` and `nums[j]`
  - `i++`
  - `j++`

- If `nums[j] == 1`
  - `j++`

- If `nums[j] == 2`
  - Swap `nums[j]` and `nums[k]`
  - `k--`
  - Do **not** increment `j`

---

## Code

```cpp
void sortThreeColor(vector<int> &nums){
    int i = 0;
    int j = 0;
    int k = nums.size() - 1;

    while(j <= k){
        if(nums[j] == 0){
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
        else if(nums[j] == 1){
            j++;
        }
        else{
            swap(nums[j], nums[k]);
            k--;
        }
    }
}
```

---

## Dry Run

Input

```
2 0 2 1 1 0
```

| Step | Array | i | j | k | Action |
|------|-------|---|---|---|--------|
|1|2 0 2 1 1 0|0|0|5|Swap j,k|
|2|0 0 2 1 1 2|0|0|4|Swap i,j|
|3|0 0 2 1 1 2|1|1|4|Swap i,j|
|4|0 0 2 1 1 2|2|2|4|Swap j,k|
|5|0 0 1 1 2 2|2|2|3|j++|
|6|0 0 1 1 2 2|2|3|3|j++|

Final Output

```
0 0 1 1 2 2
```

---

## Why don't we increment `j` after swapping with `k`?

The element that comes from index `k` has **not been processed yet**.

Example:

```
2 1 0
```

Swap first and last:

```
0 1 2
```

The new value at index `j` must be checked again.

Therefore:

- After swapping with `k`, only `k--`
- Do **not** do `j++`

---

# Complexity

| Approach | Time | Space |
|----------|------|-------|
| sort() | O(n log n) | O(1) |
| Counting | O(n) | O(1) |
| Dutch National Flag | **O(n)** | **O(1)** |

---

# Interview Preparation

## Which approach should you explain first?

1. Brute Force (`sort()`).
2. Better approach (Counting).
3. Best approach (Dutch National Flag).

This demonstrates that you can optimize your solution.

## Best Choice

For coding interviews, the **Dutch National Flag Algorithm** is the preferred solution because:

- Single traversal
- In-place sorting
- Constant extra space
- Frequently asked by interviewers

---

# Key Takeaways

- `i` tracks the next position for `0`.
- `j` scans the array.
- `k` tracks the next position for `2`.
- Increment `j` only when the current element is confirmed as `0` or `1`.
- Do **not** increment `j` after swapping with `k`.
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`
