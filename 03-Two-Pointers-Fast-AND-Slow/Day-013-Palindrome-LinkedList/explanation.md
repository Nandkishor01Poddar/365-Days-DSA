# 234. Palindrome Linked List

## Problem

Given the head of a singly linked list, return `true` if it is a
palindrome, otherwise return `false`.

------------------------------------------------------------------------

## Pattern

**Fast & Slow Pointer + Reverse Linked List**

This is a classic interview problem because it combines two common
linked list techniques: 1. Find the middle of the list. 2. Reverse the
second half. 3. Compare both halves.

------------------------------------------------------------------------

## Intuition

A palindrome reads the same from left to right and right to left.

Example:

    1 -> 2 -> 2 -> 1

The first half:

    1 -> 2

The second half:

    2 -> 1

If we reverse the second half, it becomes:

    1 -> 2

Now both halves are identical.

------------------------------------------------------------------------

## Step 1: Find the Middle

Use two pointers:

-   `slow` moves one step.
-   `fast` moves two steps.

``` cpp
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
```

When the loop ends:

-   Even length: `slow` points to the beginning of the second half.
-   Odd length: `slow` points to the middle node.

------------------------------------------------------------------------

## Step 2: Reverse the Second Half

Reverse the list starting from `slow`.

``` cpp
ListNode* prev = nullptr;

while (slow) {
    ListNode* nextNode = slow->next;
    slow->next = prev;
    prev = slow;
    slow = nextNode;
}
```

After reversing, `prev` is the head of the reversed second half.

------------------------------------------------------------------------

## Step 3: Compare Both Halves

``` cpp
ListNode* first = head;
ListNode* second = prev;

while (second) {
    if (first->val != second->val)
        return false;

    first = first->next;
    second = second->next;
}

return true;
```

We only iterate until `second` becomes `nullptr` because the reversed
second half is never longer than the first.

------------------------------------------------------------------------

## Dry Run

Input:

    1 -> 2 -> 2 -> 1

### Find Middle

    slow = second 2

### Reverse Second Half

    2 -> 1

    becomes

    1 -> 2

### Compare

    1 == 1 ✔
    2 == 2 ✔

Return `true`.

------------------------------------------------------------------------

## Complete Solution

``` cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        while (slow) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            if (first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};
```

------------------------------------------------------------------------

## Complexity

-   **Time:** `O(n)`
-   **Space:** `O(1)`

------------------------------------------------------------------------

## Key Interview Takeaways

-   Use **Fast & Slow pointers** to find the middle.
-   Reverse only the **second half** of the list.
-   Compare the two halves node by node.
-   Each node is visited only a constant number of times, giving
    **O(n)** time and **O(1)** extra space.
