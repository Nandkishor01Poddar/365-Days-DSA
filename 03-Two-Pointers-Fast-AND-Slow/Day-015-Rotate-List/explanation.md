# LeetCode 61: Rotate List

# Approach

To rotate the linked list to the right by `k` positions, we first determine the length of the list and locate its last node (tail). If the list is empty, contains only one node, or `k` is `0`, no rotation is required.

Since rotating the list by its length results in the same list, we reduce unnecessary rotations by computing `k %= length`. If `k` becomes `0`, we simply return the original head.

Next, we connect the tail to the head, converting the linked list into a circular linked list. Instead of physically moving nodes, we only need to determine the new tail. The new tail is located at the `(length - k - 1)`th node from the beginning, and the node immediately after it becomes the new head.

Finally, we break the circular link after the new tail and return the new head.

---

# Algorithm

1. If the list is empty, has only one node, or `k == 0`, return the head.
2. Traverse the list to determine its length and locate the tail node.
3. Compute `k = k % length`.
4. If `k == 0`, return the original head.
5. Connect the tail to the head to form a circular linked list.
6. Move `(length - k - 1)` steps from the head to reach the new tail.
7. The node after the new tail becomes the new head.
8. Break the circular link by setting the new tail's `next` pointer to `nullptr`.
9. Return the new head.

---

# Dry Run

### Example

**Input**

```
head = [1,2,3,4,5], k = 2
```

### Step 1: Find the length

Traverse the list.

```
1 -> 2 -> 3 -> 4 -> 5
```

- Length = **5**
- Tail = **5**

---

### Step 2: Reduce unnecessary rotations

```
k = k % length
  = 2 % 5
  = 2
```

Since `k != 0`, we continue.

---

### Step 3: Form a circular linked list

Connect the tail to the head.

```
1 -> 2 -> 3 -> 4 -> 5
^                   |
|___________________|
```

---

### Step 4: Find the new tail

The new tail is at

```
length - k - 1
= 5 - 2 - 1
= 2
```

Move **2 steps** from the head.

```
Step 0 : 1
Step 1 : 2
Step 2 : 3  ← New Tail
```

---

### Step 5: Find the new head

The node after the new tail becomes the new head.

```
New Head = 4
```

---

### Step 6: Break the circle

Set

```
3 -> next = NULL
```

Final list:

```
4 -> 5 -> 1 -> 2 -> 3
```

**Output**

```
[4,5,1,2,3]
```

---

# Complexity Analysis

- **Time Complexity:** **O(n)**
  - One traversal to calculate the length.
  - One traversal to locate the new tail.
  - Overall complexity remains linear.

- **Space Complexity:** **O(1)**
  - Only a constant amount of extra space is used.

---

# Code

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int len = 1;
        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            len++;
        }

        k %= len;
        if (k == 0)
            return head;

        tail->next = head;

        int steps = len - k - 1;
        ListNode* newTail = head;

        while (steps--) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
```