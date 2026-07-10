````md
# LeetCode 15 – 3Sum


**Difficulty:** Medium  
**Topics:** Array, Two Pointers, Sorting

---

## Problem Statement

Given an integer array `nums`, return **all the unique triplets** `[nums[i], nums[j], nums[k]]` such that:

- `i != j`
- `i != k`
- `j != k`
- `nums[i] + nums[j] + nums[k] == 0`

The solution set **must not contain duplicate triplets**.

---

## Interview Perspective

This is one of the most frequently asked **Two Pointer** interview questions.

### Interviewer expects you to:

- Recognize that **sorting** simplifies the problem.
- Reduce the brute-force `O(n³)` solution to **O(n²)**.
- Handle duplicate triplets correctly.
- Explain why the two-pointer technique works after sorting.

### Common Follow-up Questions

- Why do we sort the array first?
- Why do we skip duplicate elements?
- Can this problem be solved without sorting?
- What is the optimal time complexity?

---

## Brute Force Approach

Generate every possible triplet using three nested loops.

### Algorithm

- Iterate over every possible combination of three elements.
- Check whether their sum equals `0`.
- Store only unique triplets.

### Complexity

- **Time Complexity:** `O(n³)`
- **Space Complexity:** `O(1)` (excluding the result)

This approach is inefficient for large inputs.

---

## Optimal Approach: Sorting + Two Pointers

### Idea

1. Sort the array.
2. Fix one element.
3. Use two pointers to find the remaining two elements whose sum makes the total equal to `0`.
4. Skip duplicate values to avoid repeated triplets.

---

## Algorithm

1. Sort the array.
2. Iterate through each element as the first element of the triplet.
3. If the current element is the same as the previous one, skip it.
4. Initialize:
   - `left = i + 1`
   - `right = n - 1`
5. While `left < right`:
   - Calculate the sum.
   - If the sum is:
     - **0** → store the triplet and move both pointers.
     - **Less than 0** → move `left`.
     - **Greater than 0** → move `right`.
6. Skip duplicate values for both pointers.

---

## Dry Run

### Input

```text
nums = [-1, 0, 1, 2, -1, -4]
```

### After Sorting

```text
[-4, -1, -1, 0, 1, 2]
```

### Iteration

#### First Element = -4

| Left | Right | Sum | Action |
|:---:|:----:|:---:|:------:|
| -1 | 2 | -3 | Move Left |
| -1 | 2 | -3 | Move Left |
| 0 | 2 | -2 | Move Left |
| 1 | 2 | -1 | Move Left |

No triplet found.

---

#### First Element = -1

| Left | Right | Sum | Action |
|:---:|:----:|:---:|:------:|
| -1 | 2 | 0 | Store `[-1,-1,2]` |
| 0 | 1 | 0 | Store `[-1,0,1]` |

Skip duplicate `-1`.

---

### Output

```text
[
  [-1, -1, 2],
  [-1, 0, 1]
]
```

---

## Why Sorting Helps

Sorting arranges numbers in increasing order.

If the current sum is:

- **Too small**, move the left pointer to increase the sum.
- **Too large**, move the right pointer to decrease the sum.

This eliminates the need to check every combination.

---

## Why Skip Duplicates?

Consider:

```text
[-1, -1, 0, 1, 2]
```

Without skipping duplicates, the same triplet could be generated multiple times.

Skipping duplicates ensures every triplet appears **exactly once**.

---

## Complexity Analysis

### Time Complexity

- Sorting → `O(n log n)`
- Outer loop → `O(n)`
- Two pointers → `O(n)`

Overall:

```text
O(n²)
```

---

### Space Complexity

```text
O(log n)
```

Used by the sorting algorithm's recursion stack (implementation-dependent).

---

## C++ Solution

```cpp
void twoSumHelper(int f, vector<vector<int>>& res, const vector<int>& nums) {
    int left = f + 1;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[f] + nums[left] + nums[right];

        if (sum > 0)
            right--;
        else if (sum < 0)
            left++;
        else {
            res.push_back({nums[f], nums[left], nums[right]});

            left++;
            right--;

            while (left < right && nums[left] == nums[left - 1])
                left++;

            while (left < right && nums[right] == nums[right + 1])
                right--;
        }
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;

    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] > 0)
            break;

        if (i == 0 || nums[i] != nums[i - 1])
            twoSumHelper(i, res, nums);
    }

    return res;
}
```

---

## Key Takeaways

- Sort the array first.
- Fix one element and solve the remaining problem using Two Pointers.
- Skip duplicates for:
  - The fixed element.
  - The left pointer.
  - The right pointer.
- Time Complexity: **O(n²)**
- Space Complexity: **O(log n)**
- This is the **optimal and interview-preferred solution**.

---

> **Interview Tip:** Whenever a problem asks for unique pairs or triplets in an array, first think about **sorting** followed by the **Two Pointer** technique. This combination is a common optimization pattern that frequently appears in coding interviews.
````
