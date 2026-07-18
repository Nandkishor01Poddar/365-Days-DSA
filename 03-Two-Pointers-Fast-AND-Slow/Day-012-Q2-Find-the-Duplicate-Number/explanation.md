# 287. Find the Duplicate Number (LeetCode)

## Optimal Approach (Floyd's Cycle Detection)

### Intuition

The array contains `n + 1` integers where every value lies in the range `[1, n]`. Since there are more elements than unique values, at least one number must be repeated.

We can treat the array as a **linked list**:

- Each **index** acts as a node.
- The **value at that index** represents the next node.

For example,

```text
nums = [1,3,4,2,2]

Index : 0  1  2  3  4
Value : 1  3  4  2  2
```

The links become:

```text
0 → 1 → 3 → 2 → 4
          ↑     |
          └─────┘
```

Notice that the duplicate number creates a **cycle** in the linked list.

To find the duplicate, we use **Floyd's Tortoise and Hare Algorithm**, which is commonly used to detect cycles in linked lists.

---

## Approach

The algorithm works in two phases.

### Phase 1: Detect the Cycle

- Initialize two pointers:
  - `slow` moves one step at a time.
  - `fast` moves two steps at a time.
- Continue moving both pointers until they meet.
- Their meeting confirms that a cycle exists.

```cpp
do
{
    slow = nums[slow];
    fast = nums[nums[fast]];
} while (slow != fast);
```

---

### Phase 2: Find the Entrance of the Cycle

- Place one pointer at the beginning (`0`).
- Keep the other pointer at the meeting point.
- Move both one step at a time.
- The point where they meet again is the duplicate number.

```cpp
int n1 = 0;
int n2 = slow;

while (n1 != n2)
{
    n1 = nums[n1];
    n2 = nums[n2];
}
```

Return `n1`.

---

## Dry Run

### Input

```text
nums = [1,3,4,2,2]
```

### Step 1: Detect the Cycle

| Iteration | Slow | Fast |
|-----------|------|------|
| Start | 0 | 0 |
| 1 | 1 | 3 |
| 2 | 3 | 4 |
| 3 | 2 | 4 |
| 4 | 4 | 4 |

Pointers meet at index `4`.

---

### Step 2: Find the Duplicate

Initialize

```text
n1 = 0
n2 = 4
```

| Step | n1 | n2 |
|------|----|----|
| 1 | 1 | 2 |
| 2 | 3 | 4 |
| 3 | 2 | 2 |

Both pointers meet at **2**.

Therefore,

```text
Duplicate Number = 2
```

---

## C++ Code

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = 0, fast = 0;

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while (slow != fast);

        int n1 = 0;
        int n2 = slow;

        while (n1 != n2)
        {
            n1 = nums[n1];
            n2 = nums[n2];
        }

        return n1;
    }
};
```

---

## Why Does It Work?

- The duplicate value causes multiple indices to point to the same node.
- This creates a cycle in the linked-list representation of the array.
- Floyd's algorithm first detects the cycle.
- The second phase finds the entry point of the cycle, which corresponds to the duplicate number.

---

## Complexity Analysis

### Time Complexity

- Phase 1 takes **O(n)**.
- Phase 2 also takes **O(n)**.

Overall Time Complexity:

```text
O(n)
```

### Space Complexity

Only a few variables are used.

```text
O(1)
```

---

## Key Points

- Treat the array as a linked list.
- Duplicate number forms a cycle.
- Use Floyd's Tortoise and Hare Algorithm.
- No modification of the array is required.
- Uses constant extra space.
- Runs in **O(n)** time and **O(1)** space.