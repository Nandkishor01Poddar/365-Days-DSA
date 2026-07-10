````md
# LeetCode 167 – Two Sum II - Input Array Is Sorted

**Difficulty:** Medium  
**Topics:** Array, Two Pointers, Binary Search

---

## Problem Statement

Given a **1-indexed** array of integers `numbers` that is sorted in **non-decreasing order**, find two numbers such that they add up to a given `target`.

Return the **1-based indices** of the two numbers as an integer array `[index1, index2]`, where:

- `1 <= index1 < index2 <= numbers.length`
- There is **exactly one solution**.
- You **may not use the same element twice**.

---

## Interview Perspective

This is one of the most common **Two Pointer** interview questions.

**Interviewer expects you to:**
- Recognize that the array is **sorted**.
- Avoid using extra space like a hash map.
- Optimize the brute-force `O(n²)` approach to **`O(n)`**.
- Explain why moving the left or right pointer is always the correct choice.

**Common Follow-up Questions**
- How would you solve it if the array was **not sorted**?
  - Use an `unordered_map` for **O(n)** time and **O(n)** space.
- Can this be solved using Binary Search?
  - Yes. For each element, perform Binary Search on the remaining array.
  - Time Complexity: **O(n log n)**.
- Which solution is the most optimal?
  - **Two Pointers** because it achieves **O(n)** time with **O(1)** extra space.

---

## Approach: Two Pointers

Since the array is already **sorted**, we can efficiently solve the problem using the **Two Pointer** technique.

### Algorithm

1. Initialize two pointers:
   - `left = 0`
   - `right = numbers.size() - 1`

2. While `left < right`:
   - Calculate the current sum:
     ```cpp
     sum = numbers[left] + numbers[right];
     ```
   - If `sum == target`, return:
     ```cpp
     {left + 1, right + 1}
     ```
   - If `sum < target`, increment `left`.
   - If `sum > target`, decrement `right`.

3. Return an empty vector if no pair exists.

---

## Dry Run

### Input

```text
numbers = [2, 7, 11, 15]
target = 9
```

| Left | Right | Elements | Sum | Action |
|:----:|:-----:|:--------:|:---:|:------:|
| 0 | 3 | 2 + 15 | 17 | `right--` |
| 0 | 2 | 2 + 11 | 13 | `right--` |
| 0 | 1 | 2 + 7 | 9 | Return `{1, 2}` |

### Output

```text
[1, 2]
```

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## C++ Solution

```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target)
            return {left + 1, right + 1};
        else if (sum < target)
            left++;
        else
            right--;
    }

    return {};
}
```

---

## Why This Approach Works

Because the array is **sorted**:

- If the current sum is **less than** the target, moving the left pointer increases the sum.
- If the current sum is **greater than** the target, moving the right pointer decreases the sum.

This guarantees that each pointer moves at most `n` times, resulting in an **O(n)** solution.

---

## Key Takeaways

- Classic **Two Pointer** interview problem.
- Uses the sorted property of the array.
- Returns **1-based indices**.
- Single-pass solution.
- **Optimal:** `O(n)` time and `O(1)` extra space.
- Frequently asked in coding interviews at product-based companies.

---

> **Note:** This approach works **only for sorted arrays**. If the array is **unsorted**, the preferred approach is to use an **`unordered_map`**, which runs in **O(n)** time with **O(n)** additional space.
````
