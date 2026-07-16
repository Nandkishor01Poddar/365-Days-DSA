# LeetCode 202 -- Happy Number
# Problem

A number is called a **Happy Number** if repeatedly replacing it with
the **sum of the squares of its digits** eventually becomes **1**.

If the process enters a cycle that never reaches `1`, the number is
**not** a happy number.

------------------------------------------------------------------------

# Example

### Input

    19

### Process

    19
    ↓
    1² + 9² = 82

    82
    ↓
    8² + 2² = 68

    68
    ↓
    6² + 8² = 100

    100
    ↓
    1² + 0² + 0² = 1

Output:

    Happy Number

------------------------------------------------------------------------

# Brute Force Approach (Hash Set)

## Idea

Store every generated number in a hash set.

-   If we reach `1`, return `true`.
-   If a number repeats, a cycle exists.
-   Therefore, return `false`.

## Algorithm

1.  Create an empty `unordered_set`.
2.  Calculate the sum of the squares of the digits.
3.  If the number is `1`, return `true`.
4.  If it already exists in the set, return `false`.
5.  Otherwise, insert it and continue.

## Time Complexity

**O(log n)**

## Space Complexity

**O(log n)**

------------------------------------------------------------------------

# Optimal Approach (Floyd's Cycle Detection)

## Idea

Treat the generated sequence like a linked list.

Use two pointers:

-   **Slow Pointer** → Moves one step.
-   **Fast Pointer** → Moves two steps.

If:

-   Fast reaches `1` → Happy Number.
-   Slow and Fast meet → Cycle detected → Not Happy Number.

This is the same technique used in **Linked List Cycle Detection**.

## Algorithm

1.  Initialize both pointers with `n`.
2.  Move slow by one transformation.
3.  Move fast by two transformations.
4.  If fast becomes `1`, return `true`.
5.  If slow equals fast, return `false`.

## Time Complexity

**O(log n)**

## Space Complexity

**O(1)**

------------------------------------------------------------------------

# Why Floyd's Algorithm Works

A non-happy number eventually repeats the same values, forming a cycle.

Example:

    2
    ↓
    4
    ↓
    16
    ↓
    37
    ↓
    58
    ↓
    89
    ↓
    145
    ↓
    42
    ↓
    20
    ↓
    4
    ...

Since a cycle exists, the slow and fast pointers must eventually meet.

------------------------------------------------------------------------

# Interview Questions

## Q1. Why use Floyd's Cycle Detection?

Because the sequence can form a cycle. Floyd detects cycles in constant
space.

------------------------------------------------------------------------

## Q2. Why not use recursion?

Recursion adds extra stack space and offers no advantage here.

------------------------------------------------------------------------

## Q3. Which approach is better?

-   Brute Force: Easy to understand and implement.
-   Floyd's Algorithm: Better because it uses **O(1)** extra space.

------------------------------------------------------------------------

## Q4. Why does the algorithm terminate?

Every transformation quickly reduces the number into a small range, so
the sequence either reaches `1` or enters a cycle.

------------------------------------------------------------------------

## Q5. Can there be multiple cycles?

No. For this transformation, every sequence either reaches `1` or falls
into the known non-happy cycle.

------------------------------------------------------------------------

# Common Mistake

Incorrect initialization:

``` cpp
int fast, slow = n;
```

Only `slow` is initialized.

Correct:

``` cpp
int slow = n;
int fast = n;
```

------------------------------------------------------------------------

# Key Takeaways

-   Learn **sum of squares of digits**.
-   Detect repeated states using a hash set (Brute Force).
-   Optimize space using Floyd's Cycle Detection.
-   Recognize the connection to Linked List cycle detection.
-   Mention both approaches and their complexities during interviews.
