# LeetCode 143 - Reorder List

## Problem Statement

You are given the head of a singly linked list.

Reorder the list in the following pattern:

```
L0 → L1 → L2 → ... → Ln
```

into

```
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...
```

You **cannot change the node values**. Only the links between nodes can be modified.

---

# Approach

The solution consists of **three steps**:

1. Find the middle of the linked list.
2. Reverse the second half.
3. Merge the two halves alternately.

This gives an **O(n)** time solution with **O(1)** extra space.

---

# Step 1: Find the Middle

Use the **Slow and Fast Pointer** technique.

- Slow pointer moves one node at a time.
- Fast pointer moves two nodes at a time.
- When the fast pointer reaches the end, the slow pointer will be at the middle.

### Example

Input

```
1 → 2 → 3 → 4 → 5
```

Movement

```
Slow = 3
Fast = End
```

Split the list

```
First Half

1 → 2 → 3

Second Half

4 → 5
```

---

# Step 2: Reverse the Second Half

Reverse the second half using the standard linked list reversal algorithm.

Before

```
4 → 5
```

After

```
5 → 4
```

Now we have

```
First Half

1 → 2 → 3

Second Half

5 → 4
```

---

# Step 3: Merge Both Lists

Merge one node from the first half and one node from the reversed second half.

Process

```
1 → 2 → 3

5 → 4
```

Iteration 1

```
1 → 5 → 2 → 3
```

Iteration 2

```
1 → 5 → 2 → 4 → 3
```

Final Output

```
1 → 5 → 2 → 4 → 3
```

---

# Dry Run

### Input

```
1 → 2 → 3 → 4 → 5
```

### Find Middle

```
First Half

1 → 2 → 3

Second Half

4 → 5
```

### Reverse Second Half

```
5 → 4
```

### Merge

```
1 → 5

1 → 5 → 2

1 → 5 → 2 → 4

1 → 5 → 2 → 4 → 3
```

Final Answer

```
1 → 5 → 2 → 4 → 3
```

---

# Algorithm

1. If the list has 0 or 1 node, return.
2. Find the middle using slow and fast pointers.
3. Split the linked list into two halves.
4. Reverse the second half.
5. Merge the first half and reversed second half alternately.
6. Return the reordered list.

---

# Complexity Analysis

### Time Complexity

- Finding the middle → **O(n)**
- Reversing the second half → **O(n)**
- Merging both halves → **O(n)**

Overall Time Complexity

```
O(n)
```

---

### Space Complexity

Only a few pointers are used.

```
O(1)
```

---

# Key Concepts Used

- Slow & Fast Pointer
- Linked List Reversal
- In-place Merge
- Constant Extra Space

---

# C++ Code

```cpp
// (Paste your VS Code solution here)
```

---

# Summary

This problem is solved efficiently by combining three classic linked list techniques:

- Find the middle using slow and fast pointers.
- Reverse the second half of the list.
- Merge the two halves alternately.

This approach runs in **O(n)** time and uses **O(1)** extra space, making it the optimal solution.