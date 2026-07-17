# LeetCode 141 - Linked List Cycle

## Problem Statement

Given the `head` of a linked list, determine whether the linked list contains a cycle.

A cycle exists if some node in the list can be reached again by continuously following the `next` pointer.

Return:

- `true` → if there is a cycle.
- `false` → otherwise.

---

# Approach 1: Brute Force (Hashing)

## Idea

While traversing the linked list, keep track of every visited node.

- If a node is visited again, a cycle exists.
- Otherwise, continue until `nullptr` is reached.

### Algorithm

1. Create an empty `unordered_set<ListNode*>`.
2. Traverse the linked list.
3. For each node:
   - If it already exists in the set, return `true`.
   - Otherwise insert it into the set.
4. If traversal reaches `nullptr`, return `false`.

---

## Dry Run

Example:

```
1 → 2 → 3 → 4
     ↑       ↓
     ← ← ← ←
```

Visited nodes:

| Current Node | Visited Set | Cycle? |
|--------------|------------|---------|
| 1 | {1} | No |
| 2 | {1,2} | No |
| 3 | {1,2,3} | No |
| 4 | {1,2,3,4} | No |
| 2 | Already Exists | Yes |

Return **true**.

---

## Code

```cpp
bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> visited;

    while(head != nullptr) {
        if(visited.count(head))
            return true;

        visited.insert(head);
        head = head->next;
    }

    return false;
}
```

---

## Complexity

- **Time:** O(n)
- **Space:** O(n)

---

## Why isn't this the best solution?

Although the time complexity is optimal, it requires **extra memory** to store every visited node.

Interviewers usually ask if we can solve it **without extra space**.

---

# Approach 2: Floyd's Cycle Detection Algorithm (Tortoise & Hare)

## Idea

Use two pointers:

- **Slow Pointer** → moves one step.
- **Fast Pointer** → moves two steps.

### Observation

- If there is **no cycle**, the fast pointer reaches `nullptr`.
- If there **is a cycle**, the fast pointer eventually catches the slow pointer.

This works because the fast pointer moves faster inside the cycle and must eventually meet the slow pointer.

---

## Algorithm

1. Initialize:
   - `slow = head`
   - `fast = head`
2. While `fast` and `fast->next` are not `nullptr`:
   - Move slow by one step.
   - Move fast by two steps.
3. If both pointers become equal, return `true`.
4. If loop ends, return `false`.

---

## Dry Run

Example:

```
1 → 2 → 3 → 4
     ↑       ↓
     ← ← ← ←
```

| Step | Slow | Fast |
|------|------|------|
| 0 | 1 | 1 |
| 1 | 2 | 3 |
| 2 | 3 | 2 |
| 3 | 4 | 4 |

Both pointers meet.

Return **true**.

---

## Code

```cpp
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }

    return false;
}
```

---

## Complexity

- **Time:** O(n)
- **Space:** O(1)

---

# Why Floyd's Algorithm Works

Suppose:

- Slow moves **1 step**
- Fast moves **2 steps**

Inside the cycle:

- Fast gains **1 node** over slow in every iteration.
- Eventually, the distance between them becomes zero.
- Therefore, they must meet.

---

# Interview Discussion

### If the interviewer asks:

> How would you solve this?

Start with the hashing approach because it's intuitive.

Then say:

> "We can optimize the space complexity from O(n) to O(1) using Floyd's Cycle Detection Algorithm."

This demonstrates problem-solving ability and optimization skills.

---

# Comparison

| Approach | Time | Space | Interview Preference |
|----------|------|-------|----------------------|
| Hashing | O(n) | O(n) | Good starting solution |
| Floyd's Cycle Detection | O(n) | O(1) | ⭐ Best solution |

---

# Key Interview Takeaways

- Always mention the hashing solution first.
- Then optimize to Floyd's Tortoise and Hare algorithm.
- Floyd's algorithm is expected in most coding interviews because it achieves:
  - **O(n)** time
  - **O(1)** extra space

This is the standard and most efficient solution for **LeetCode 141 – Linked List Cycle**.