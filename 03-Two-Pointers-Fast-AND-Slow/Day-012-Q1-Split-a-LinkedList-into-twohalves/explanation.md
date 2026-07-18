# Split a Linked List into Two Halves (GFG)

## Problem Statement

Given the head of a **circular singly linked list**, split the list into two **circular linked lists**.

- If the number of nodes is **even**, both lists should contain an equal number of nodes.
- If the number of nodes is **odd**, the **first list should contain one extra node**.

Return the heads of the two newly formed circular linked lists.

---

## Approach (Fast and Slow Pointer)

The most efficient way to solve this problem is by using the **Fast and Slow Pointer** technique.

### Idea

- Use two pointers:
  - **Slow pointer** moves one node at a time.
  - **Fast pointer** moves two nodes at a time.
- When the fast pointer reaches the end of the circular list:
  - The slow pointer will be at the middle.
- Split the list into two halves by modifying the `next` pointers.

---

## Algorithm

1. Handle special cases:
   - If the list is empty, return `{NULL, NULL}`.
   - If only one node exists, return `{head, NULL}`.

2. Initialize:
   - `slow = head`
   - `fast = head`

3. Move pointers until the fast pointer reaches the end.

   ```cpp
   while (fast->next != head && fast->next->next != head)
   {
       slow = slow->next;
       fast = fast->next->next;
   }
   ```

4. If the list contains an even number of nodes, move the fast pointer one more step so it reaches the last node.

   ```cpp
   if (fast->next->next == head)
       fast = fast->next;
   ```

5. Store the starting nodes of both halves.

   ```cpp
   head1 = head;
   head2 = slow->next;
   ```

6. Make the second half circular.

   ```cpp
   fast->next = head2;
   ```

7. Make the first half circular.

   ```cpp
   slow->next = head1;
   ```

8. Return both heads.

---

## Dry Run

### Input

```
1 → 2 → 3 → 4 → 5 → (back to 1)
```

Initially

```
Slow = 1
Fast = 1
```

### Iteration 1

```
Slow = 2
Fast = 3
```

### Iteration 2

```
Slow = 3
Fast = 5
```

Loop stops because `fast->next == head`.

Now,

```
Head1 = 1
Head2 = 4
```

Update pointers

```
5 → 4
3 → 1
```

### Result

First List

```
1 → 2 → 3 → (back to 1)
```

Second List

```
4 → 5 → (back to 4)
```

---

## Correctness

- The slow pointer always reaches the middle because it moves one step while the fast pointer moves two.
- The fast pointer reaches the last node of the circular list.
- Breaking the connection after the slow pointer creates the first half.
- Connecting the last node to the second half makes the second list circular.
- Both resulting lists remain circular and contain all original nodes exactly once.

---

## Complexity Analysis

### Time Complexity

- Traversing the circular linked list once takes **O(n)**.

**Overall:** **O(n)**

### Space Complexity

Only two pointers are used.

**Overall:** **O(1)**

---

## C++ Code

```cpp
pair<Node *, Node *> splitList(Node *head)
{
    if (head == NULL || head->next == head)
    {
        return {head, NULL};
    }

    Node *slow = head;
    Node *fast = head;

    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head)
    {
        fast = fast->next;
    }

    Node *head1 = head;
    Node *head2 = slow->next;

    fast->next = head2;
    slow->next = head1;

    return {head1, head2};
}
```

---

## Key Points

- Use the **Fast and Slow Pointer** technique to locate the middle.
- Handle **odd** and **even** number of nodes separately.
- Modify only the `next` pointers.
- No extra data structures are required.
- Efficient solution with **O(n)** time and **O(1)** auxiliary space.