# LeetCode 153 - Find Minimum in Rotated Sorted Array

## Problem Statement

Given a **sorted array that has been rotated**, find the **minimum
element**.

Example:

``` text
Original: 1 2 3 4 5 6 7
Rotated : 4 5 6 7 1 2 3

Minimum = 1
```

------------------------------------------------------------------------

# Method 1: Brute Force (Linear Search)

## Idea

Traverse the entire array and keep track of the smallest element.

## Algorithm

``` text
Initialize minimum = first element

For every element:
    If current element < minimum
        Update minimum

Return minimum
```

## Dry Run

Array:

``` text
4 5 6 7 0 1 2
```

  Current   Minimum
  --------- ---------
  4         4
  5         4
  6         4
  7         4
  0         0
  1         0
  2         0

Answer:

``` text
0
```

## Complexity

-   Time: **O(n)**
-   Space: **O(1)**

------------------------------------------------------------------------

# Method 2: Binary Search

## Observation

A rotated sorted array has **two sorted parts**.

Example:

``` text
4 5 6 7 | 0 1 2
```

The minimum element is the **first element of the second sorted part**.

------------------------------------------------------------------------

## Binary Search Logic

Maintain:

-   `st` = start index
-   `end` = end index
-   `ans` = current minimum candidate

Find:

``` text
mid = st + (end - st) / 2
```

### Case 1

If

``` text
nums[mid] >= nums[0]
```

Example:

``` text
4 5 6 7 0 1 2
    ^
   mid
```

`mid` is in the **left sorted portion**.

The minimum must be on the **right**.

Move:

``` cpp
st = mid + 1;
```

------------------------------------------------------------------------

### Case 2

If

``` text
nums[mid] < nums[0]
```

Example:

``` text
4 5 6 7 0 1 2
          ^
         mid
```

`mid` is in the **right sorted portion**.

It can be the minimum.

Store it:

``` cpp
ans = nums[mid];
```

Continue searching left:

``` cpp
end = mid - 1;
```

------------------------------------------------------------------------

# Dry Run

Input

``` text
4 5 6 7 0 1 2
```

  st   end   mid   nums\[mid\]   Action             ans
  ---- ----- ----- ------------- ------------------ -----
  0    6     3     7             st = 4             4
  4    6     5     1             ans = 1, end = 4   1
  4    4     4     0             ans = 0, end = 3   0

Loop ends.

Answer:

``` text
Minimum = 0
```

------------------------------------------------------------------------

# Complexity Comparison

  Method          Time       Space
  --------------- ---------- -------
  Brute Force     O(n)       O(1)
  Binary Search   O(log n)   O(1)

------------------------------------------------------------------------

# Key Points

-   Brute force checks every element.
-   Binary search uses the sorted property to eliminate half the search
    space.
-   The binary search approach assumes:
    -   Array is sorted in ascending order.
    -   Array is rotated.
    -   No duplicate elements.
