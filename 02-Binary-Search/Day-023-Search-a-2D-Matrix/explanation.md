# LeetCode 74 - Search a 2D Matrix

## Problem Statement
You are given an `m x n` integer matrix with the following properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer `target`, return `true` if the target exists in the matrix, otherwise return `false`.

---

## Approach
Since the matrix satisfies the given conditions, we can consider it as a single sorted 1D array.

Instead of searching row by row, we perform **Binary Search** on the entire matrix.

To access an element during binary search:

- `row = mid / n`
- `col = mid % n`

where `n` is the number of columns.

This allows us to find the target in logarithmic time.

---

## Algorithm
1. Find the number of rows (`m`) and columns (`n`).
2. Initialize:
   - `left = 0`
   - `right = m * n - 1`
3. While `left <= right`:
   - Calculate `mid`.
   - Convert the 1D index into a 2D index:
     - `row = mid / n`
     - `col = mid % n`
   - Compare `matrix[row][col]` with the target.
     - If equal, return `true`.
     - If smaller, search the right half.
     - Otherwise, search the left half.
4. If the loop ends, return `false`.

---

## Dry Run

### Input

```
Matrix:
1   3   5   7
10 11 16 20
23 30 34 60

Target = 16
```

### Binary Search Steps

| Left | Right | Mid | Value | Action |
|------|-------|-----|-------|--------|
| 0 | 11 | 5 | 11 | Search Right |
| 6 | 11 | 8 | 23 | Search Left |
| 6 | 7 | 6 | 16 | Found |

Output:

```
true
```

---

## C++ Code

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};
```

---

## Complexity Analysis

### Time Complexity
- Binary search is performed on `m × n` elements.
- **Time Complexity:** **O(log(m × n))**

### Space Complexity
- No extra space is used.
- **Space Complexity:** **O(1)**

---

## Key Idea
Treat the 2D matrix as a sorted 1D array and use binary search. Convert each 1D index into its corresponding row and column using:

- `row = index / number_of_columns`
- `col = index % number_of_columns`

This provides an efficient solution with logarithmic time complexity.