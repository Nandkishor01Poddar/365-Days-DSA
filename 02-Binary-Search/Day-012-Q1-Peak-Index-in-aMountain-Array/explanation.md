# LeetCode 852 - Peak Element
## Problem Statement

Given an array, find the index of **any peak element**.

A **peak element** is an element that is **greater than its adjacent
elements**.

-   The first element only has a right neighbor.
-   The last element only has a left neighbor.

**Example:**

``` text
Array: [1, 3, 20, 4, 1, 0]

Peak Element = 20
Peak Index = 2
```

------------------------------------------------------------------------

# Method 1: Linear Search

## Idea

Check every element one by one.

1.  Check if the first element is a peak.
2.  Check every middle element.
3.  Check the last element.

If any element is greater than both of its neighbors, return its index.

## Algorithm

``` text
If array has only one element
    return 0

If first element > second element
    return 0

For every middle element
    If current > left AND current > right
        return current index

If last element > second last
    return last index
```

## Time Complexity

-   **Time:** O(n)
-   **Space:** O(1)

------------------------------------------------------------------------

# Method 2: Binary Search

## Idea

Instead of checking every element, observe the **slope** of the array.

### Case 1

If

``` text
arr[mid] > arr[mid + 1]
```

then we are on the **descending slope**.

Example:

``` text
1 3 7 5 2
    ^
   mid
```

A peak exists at `mid` or somewhere on the **left**.

Move:

``` cpp
end = mid;
```

------------------------------------------------------------------------

### Case 2

If

``` text
arr[mid] < arr[mid + 1]
```

then we are on the **ascending slope**.

Example:

``` text
1 3 5 7 6
    ^
   mid
```

A peak exists on the **right**.

Move:

``` cpp
st = mid + 1;
```

------------------------------------------------------------------------

## Why does Binary Search work?

A peak always exists.

-   Ascending slope → move right.
-   Descending slope → move left.

Eventually `st == end`, which points to a peak.

------------------------------------------------------------------------

## Binary Search Dry Run

Input

``` text
1 3 20 4 1 0
```

  st   end   mid   arr\[mid\]   arr\[mid+1\]   Decision
  ---- ----- ----- ------------ -------------- ------------
  0    5     2     20           4              end = 2
  0    2     1     3            20             st = 2
  2    2     \-    \-           \-             Peak Found

Result

``` text
Peak Index = 2
Peak Element = 20
```

------------------------------------------------------------------------

# Complexity Comparison

  Method          Time       Space
  --------------- ---------- -------
  Linear Search   O(n)       O(1)
  Binary Search   O(log n)   O(1)

------------------------------------------------------------------------

# Conclusion

-   Use **Linear Search** for understanding the basic concept.
-   Use **Binary Search** in interviews and coding platforms because it
    is much faster (`O(log n)`).
