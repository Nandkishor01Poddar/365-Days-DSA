# LeetCode 2130 - Maximum Twin Sum of a Linked List

## Approach 1: Vector + Two Pointers

### Idea

Since a singly linked list cannot be accessed from both ends, we first copy all node values into a vector.

After that, we use two pointers:

- `left` starts from index `0`
- `right` starts from index `n - 1`

For every pair:

```
Twin Sum = values[left] + values[right]
```

Update the maximum twin sum and move both pointers toward the center.

---

### Algorithm

1. Traverse the linked list.
2. Store every node value in a vector.
3. Initialize:
   - `left = 0`
   - `right = n - 1`
4. While `left < right`
   - Calculate twin sum.
   - Update maximum.
   - Move both pointers.
5. Return the maximum twin sum.

---

### Dry Run

Linked List

```
5 -> 4 -> 2 -> 1
```

Vector

```
[5, 4, 2, 1]
```

| left | right | Twin Sum | Maximum |
|------|-------|----------|---------|
|0|3|5+1 = 6|6|
|1|2|4+2 = 6|6|

Answer = **6**

---

### Complexity

**Time Complexity**

```
O(n)
```

- Traversing list = O(n)
- Two pointer traversal = O(n)

Overall:

```
O(n)
```

**Space Complexity**

```
O(n)
```

because an additional vector is used.

---

# Approach 2: Slow/Fast Pointer + Reverse (Optimal)

## Idea

Instead of storing values in a vector, split the linked list into two halves.

Steps:

1. Find the middle using Slow and Fast pointers.
2. Reverse the second half.
3. Traverse both halves together.
4. Calculate twin sums.
5. Return the maximum.

This uses **constant extra space**.

---

## Step 1: Find Middle

Use two pointers.

- Slow moves **1 step**
- Fast moves **2 steps**

```cpp
while(fast != nullptr && fast->next != nullptr)
{
    slow = slow->next;
    fast = fast->next->next;
}
```

### Example (Even Length)

```
5 -> 4 -> 2 -> 1

S
F
```

Iteration 1

```
5 -> 4 -> 2 -> 1
     S
          F
```

Iteration 2

```
5 -> 4 -> 2 -> 1
          S
               F(NULL)
```

Now,

```
slow = 2
```

Second half starts from **2**.

---

### Example (6 Nodes)

```
1 -> 2 -> 3 -> 4 -> 5 -> 6

S
F
```

Iteration 1

```
1 -> 2 -> 3 -> 4 -> 5 -> 6
     S
          F
```

Iteration 2

```
1 -> 2 -> 3 -> 4 -> 5 -> 6
          S
                    F
```

Iteration 3

```
1 -> 2 -> 3 -> 4 -> 5 -> 6
               S
                         F(NULL)
```

Middle becomes

```
4
```

Second half starts from **4**.

---

## Step 2: Reverse Second Half

Original

```
2 -> 1
```

After reversing

```
1 -> 2
```

Reverse function

```cpp
ListNode* reverse(ListNode* head)
{
    ListNode* prev = nullptr;

    while(head != nullptr)
    {
        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }

    return prev;
}
```

---

## Step 3: Calculate Twin Sum

Now

First Half

```
5 -> 4
```

Reversed Second Half

```
1 -> 2
```

Compare both simultaneously.

|First|Second|Twin Sum|
|------|------|--------|
|5|1|6|
|4|2|6|

Maximum = **6**

---

## Why Reverse?

A singly linked list only moves forward.

Without reversing, we cannot access the last node while starting from the head.

Reversing the second half allows us to compare:

```
Head  <--> Last

Second <--> Second Last
```

using only forward traversal.

---

## Complexity

### Finding Middle

```
O(n)
```

### Reversing

```
O(n/2)
```

### Calculating Twin Sum

```
O(n/2)
```

Overall

```
O(n)
```

### Space Complexity

```
O(1)
```

No extra array or vector is used.

---

# What if the list has Odd Length?

LeetCode 2130 guarantees that the linked list has an **even** number of nodes.

However, for a general linked list, use:

```cpp
while(fast != nullptr && fast->next != nullptr)
{
    slow = slow->next;
    fast = fast->next->next;
}

if(fast != nullptr)
{
    // Odd length
    // Skip the middle node
    slow = slow->next;
}
```

Example

```
1 -> 2 -> 3 -> 4 -> 5
```

Here,

```
fast != nullptr
```

which means the list length is odd.

The middle node (**3**) has no twin, so we skip it before reversing.

---

# Comparison

| Approach | Time | Space |
|----------|------|-------|
| Vector + Two Pointers | O(n) | O(n) |
| Slow/Fast + Reverse | O(n) | O(1) |

The **Slow/Fast + Reverse** approach is the optimal solution because it achieves **O(n)** time with **O(1)** extra space.