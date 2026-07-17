# LeetCode 142 - Linked List Cycle II

## Problem Statement

Given the head of a linked list, return the node where the cycle begins.

If there is no cycle, return `nullptr`.

You are **not allowed to modify** the linked list.

---

# Brute Force Approach (Hashing)

## Idea

Store every visited node in a hash set.

While traversing:

- If the current node is already present in the hash set, that node is the starting point of the cycle.
- Otherwise, insert it into the set and continue.

---

## Algorithm

1. Create an empty `unordered_set<ListNode*>`.
2. Traverse the linked list.
3. If current node already exists in the set:
   - Return that node.
4. Otherwise insert it.
5. If traversal reaches `nullptr`, return `nullptr`.

---

## Code

```cpp
ListNode* detectCycle(ListNode* head) {
    unordered_set<ListNode*> visited;

    while (head != nullptr) {
        if (visited.count(head))
            return head;

        visited.insert(head);
        head = head->next;
    }

    return nullptr;
}
```

---

## Complexity

**Time Complexity:** O(n)

**Space Complexity:** O(n)

---

## Better Approach (Floyd's Cycle Detection Algorithm)

### Idea

Use two pointers:

- Slow → moves one step
- Fast → moves two steps

If they meet, a cycle exists.

After they meet:

- Move one pointer to the head.
- Keep the other at the meeting point.
- Move both one step at a time.
- The node where they meet again is the starting node of the cycle.

---

## Why does this work?

Let

- `x` = distance from head to cycle start
- `y` = distance from cycle start to meeting point
- `L` = cycle length

When slow and fast meet:

```
2(x + y) = x + y + kL
```

Simplifying,

```
x + y = kL
```

Therefore,

```
x = kL - y
```

This means:

- One pointer starting from the head travels `x` steps.
- The other pointer starting from the meeting point also travels `kL - y` steps, which lands exactly at the cycle start.

Hence both pointers meet at the first node of the cycle.

---

## Algorithm

1. Initialize slow and fast at head.
2. Move:
   - slow by one step
   - fast by two steps
3. If they never meet, return `nullptr`.
4. If they meet:
   - Set one pointer to `head`.
   - Keep the other at the meeting point.
5. Move both one step at a time.
6. The meeting node is the answer.

---

## Code

```cpp
ListNode* detectCycle(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast == nullptr || fast->next == nullptr)
        return nullptr;

    ListNode* n1 = head;
    ListNode* n2 = slow;

    while (n1 != n2) {
        n1 = n1->next;
        n2 = n2->next;
    }

    return n1;
}
```

---

## Complexity

**Time Complexity:** O(n)

**Space Complexity:** O(1)

---

# Interview Discussion

### Brute Force

✔ Easy to understand

✔ Finds the answer in one traversal

❌ Uses extra memory O(n)

---

### Floyd's Algorithm

✔ No extra space

✔ O(n) time

✔ O(1) space

✔ Most expected solution in coding interviews

---

# Comparison

| Approach | Time | Space |
|----------|------|-------|
| Hashing | O(n) | O(n) |
| Floyd's Cycle Detection | O(n) | O(1) |

---

# Interview Tip

For LeetCode **142**, begin by explaining the hashing solution. Then optimize it using Floyd's Tortoise and Hare algorithm. Mention that the interviewer usually expects the **O(1) space** solution because it satisfies the follow-up requirement.