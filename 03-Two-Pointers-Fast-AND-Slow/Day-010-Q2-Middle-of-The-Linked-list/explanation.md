# LeetCode 876 -- Find Middle of Linked List

# Problem

Given the head of a singly linked list, return the **middle node**.

If the linked list has an even number of nodes, return the **second
middle node**.

------------------------------------------------------------------------

# Example 1

Input

    1 -> 2 -> 3 -> 4 -> 5

Output

    3

------------------------------------------------------------------------

# Example 2

Input

    1 -> 2 -> 3 -> 4 -> 5 -> 6

Output

    4

------------------------------------------------------------------------

# Brute Force Approach

## Idea

1.  Count the total number of nodes.
2.  Traverse the list again.
3.  Move `count / 2` steps from the head.
4.  Return that node.

## Algorithm

1.  Initialize `count = 0`.
2.  Traverse the linked list and count nodes.
3.  Reset the pointer to the head.
4.  Move `count / 2` steps.
5.  Return the current node.

## Time Complexity

-   Counting nodes: **O(N)**
-   Moving to middle: **O(N/2)**

Overall:

**O(N)**

## Space Complexity

**O(1)**

------------------------------------------------------------------------

# Optimal Approach (Slow and Fast Pointer)

## Idea

Use two pointers.

-   Slow pointer moves **one node**.
-   Fast pointer moves **two nodes**.

When the fast pointer reaches the end, the slow pointer will be at the
middle.

## Algorithm

1.  Initialize `slow = head` and `fast = head`.
2.  While `fast != nullptr` and `fast->next != nullptr`:
    -   Move slow by one step.
    -   Move fast by two steps.
3.  Return the slow pointer.

## Time Complexity

**O(N)**

## Space Complexity

**O(1)**

------------------------------------------------------------------------

# Dry Run

For:

    1 -> 2 -> 3 -> 4 -> 5

  Iteration   Slow   Fast
  ----------- ------ ------
  Start       1      1
  1           2      3
  2           3      5

Answer:

    3

------------------------------------------------------------------------

For:

    1 -> 2 -> 3 -> 4 -> 5 -> 6

  Iteration   Slow   Fast
  ----------- ------ ------
  Start       1      1
  1           2      3
  2           3      5
  3           4      NULL

Answer:

    4

------------------------------------------------------------------------

# Why Does Slow Pointer Reach the Middle?

The fast pointer moves twice as fast as the slow pointer.

When the fast pointer has traveled the entire list, the slow pointer has
traveled exactly half the distance, so it points to the middle node.

------------------------------------------------------------------------

# Interview Questions

## Q1. Why do we use the slow and fast pointer technique?

It finds the middle node in a **single traversal**, making it more
efficient than traversing the list twice.

------------------------------------------------------------------------

## Q2. Why is the second middle returned for even-length lists?

The loop condition:

``` cpp
while (fast != nullptr && fast->next != nullptr)
```

allows the slow pointer to move one extra step before the fast pointer
reaches the end.

------------------------------------------------------------------------

## Q3. Which approach is better?

-   Brute Force: Easy to understand.
-   Optimal: Preferred in interviews because it requires only one
    traversal and constant extra space.

------------------------------------------------------------------------

## Q4. Where is this technique used?

-   Find middle of linked list
-   Detect a cycle (Floyd's Algorithm)
-   Find the start of a cycle
-   Check if a linked list is a palindrome
-   Merge sort on linked lists
-   Find the nth node from the end

------------------------------------------------------------------------

# Common Mistakes

Incorrect loop:

``` cpp
while (fast->next != nullptr)
```

This may dereference a null pointer.

Correct loop:

``` cpp
while (fast != nullptr && fast->next != nullptr)
```

------------------------------------------------------------------------

# Key Takeaways

-   Brute Force uses two traversals.
-   Slow/Fast Pointer uses one traversal.
-   Both have **O(1)** extra space.
-   The optimal solution is the standard interview approach.
