# Leetcode 33 - Search in Rotated Sorted Array

## Problem Statement

Given a sorted array that has been rotated and a target value, return
the index of the target. If the target is not present, return -1.

Example:

``` text
Array  : 4 5 6 7 0 1 2
Target : 0
Output : 4
```

------------------------------------------------------------------------

# Method 1: Brute Force (Linear Search)

## Idea

Traverse every element until the target is found.

## Algorithm

``` text
For each element
    If element == target
        return index
Return -1
```

## Complexity

-   Time: O(n)
-   Space: O(1)

------------------------------------------------------------------------

# Method 2: Binary Search

## Observation

A rotated sorted array always has one sorted half.

Example:

``` text
4 5 6 7 | 0 1 2
```

At each iteration:

-   If nums\[mid\] \>= nums\[st\], the left half is sorted.
-   Otherwise, the right half is sorted.

### Left Half Sorted

Condition:

``` cpp
nums[mid] >= nums[st]
```

If:

``` cpp
target >= nums[st] && target < nums[mid]
```

Search left:

``` cpp
end = mid - 1;
```

Otherwise:

``` cpp
st = mid + 1;
```

### Right Half Sorted

If:

``` cpp
target > nums[mid] && target <= nums[end]
```

Search right:

``` cpp
st = mid + 1;
```

Otherwise:

``` cpp
end = mid - 1;
```

------------------------------------------------------------------------

# Dry Run

Input:

``` text
Array : 4 5 6 7 0 1 2
Target: 0
```

    st   end   mid   nums\[mid\] Action
  ---- ----- ----- ------------- -----------------------------------------
     0     6     3             7 Left sorted, move right (st=4)
     4     6     5             1 Left sorted, target in left part, end=4
     4     4     4             0 Target found

Answer:

``` text
Index = 4
```

------------------------------------------------------------------------

# Complexity Comparison

  Method          Time       Space
  --------------- ---------- -------
  Brute Force     O(n)       O(1)
  Binary Search   O(log n)   O(1)

------------------------------------------------------------------------

# Key Points

-   One half of the array is always sorted.
-   Identify the sorted half.
-   Check if the target belongs to that half.
-   Discard the other half.
-   Repeat until the target is found or the search space becomes empty.
