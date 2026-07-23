# LeetCode 19: Remove Nth Node From End of List

## Problem Statement
Given the head of a singly linked list and an integer `n`, remove the **nth node from the end** of the list and return the head of the modified linked list.

---

## Approach: Two Pointer (Fast & Slow)

We use two pointers (`fast` and `slow`) along with a **dummy node**.

### Algorithm
1. Create a dummy node and connect it before the head.
2. Initialize both `fast` and `slow` to the dummy node.
3. Move the `fast` pointer **(n + 1)** steps ahead.
4. Move both `fast` and `slow` one step at a time until `fast` reaches `NULL`.
5. Now, `slow` points to the node just before the node that needs to be deleted.
6. Update the links to remove the target node.
7. Return `dummy->next` as the new head.

---

## Dry Run

### Input
```
Head = 1 -> 2 -> 3 -> 4 -> 5
n = 2
```

### Step 1
```
Dummy -> 1 -> 2 -> 3 -> 4 -> 5
```

Move `fast` **3** steps ahead.

```
slow = Dummy
fast = Node 3
```

### Step 2

Move both pointers together.

| Fast | Slow |
|------|------|
| 4 | 1 |
| 5 | 2 |
| NULL | 3 |

Now `slow` is just before the node to delete.

### Step 3

Delete node `4`.

```
3 -> 5
```

### Output
```
1 -> 2 -> 3 -> 5
```

---

## Why Dummy Node?

A dummy node simplifies the code by handling the case where the **first node** needs to be removed.

Example:
```
Head = 1
n = 1
```

After deletion:
```
NULL
```

Without a dummy node, extra conditions would be required.

---

## Time Complexity

- **O(N)** – Single traversal of the linked list.

## Space Complexity

- **O(1)** – Only a few extra pointers are used.

---

## Key Idea

Maintain a gap of **(n + 1)** nodes between the `fast` and `slow` pointers.

When `fast` reaches the end of the list, `slow` will be exactly one node before the node that needs to be removed.

---

## C++ Logic

```cpp
ListNode* dummy = new ListNode(0);
dummy->next = head;

ListNode* fast = dummy;
ListNode* slow = dummy;

// Move fast pointer n+1 steps ahead
for (int i = 0; i <= n; i++) {
    fast = fast->next;
}

// Move both pointers together
while (fast != NULL) {
    fast = fast->next;
    slow = slow->next;
}

// Delete the target node
ListNode* temp = slow->next;
slow->next = slow->next->next;
delete temp;

return dummy->next;
```

---

## Summary

- ✅ Use a dummy node.
- ✅ Move `fast` pointer `n + 1` steps ahead.
- ✅ Move both pointers together.
- ✅ Delete `slow->next`.
- ✅ Return `dummy->next`.

This is the **optimal solution** with **O(N)** time complexity and **O(1)** auxiliary space.