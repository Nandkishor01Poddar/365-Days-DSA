# LeetCode 2379 - Minimum Recolors to Get K Consecutive Black Blocks

## Problem Statement

You are given:

- A string `blocks` consisting of:
  - `'B'` → Black Block
  - `'W'` → White Block
- An integer `k`

You need to obtain **k consecutive black blocks**.

In one operation, you can **recolor one white block (`W`) into a black block (`B`)**.

Return the **minimum number of recolors** needed.

---

# Example

### Input

```text
blocks = "WBBWWBBWBW"
k = 7
```

### Output

```text
3
```

### Explanation

Possible windows of size **7**

```
Window 1

W B B W W B B

White Blocks = 3
```

```
Window 2

B B W W B B W

White Blocks = 3
```

```
Window 3

B W W B B W B

White Blocks = 3
```

```
Window 4

W W B B W B W

White Blocks = 4
```

Minimum White Blocks

```
min(3,3,3,4)

=

3
```

Therefore,

```
Minimum Recolors = 3
```

---

# Observation

Every white block requires exactly **one recolor**.

So the problem becomes

> Find the window of size **k** having the **minimum number of white blocks**.

This is much easier than thinking about recoloring.

---

# Why Sliding Window?

Notice

Window 1

```
W B B W W B B
```

↓

Window 2

```
B B W W B B W
```

Instead of counting all **7** blocks again,

only two characters change.

Outgoing

```
W
```

Incoming

```
W
```

Everything else remains the same.

Therefore,

Instead of recalculating,

we update the count in **O(1)** time.

---

# Approach 1 : Brute Force

## Idea

For every possible window of size `k`

- Count the number of white blocks.
- Update the minimum answer.

Repeat for every window.

---

## Algorithm

```
For every window

Count white blocks

Update minimum answer
```

---

## Dry Run

```
blocks

W B B W W B B W B W
```

Window 1

```
W B B W W B B

White = 3
```

Window 2

```
B B W W B B W

White = 3
```

Window 3

```
B W W B B W B

White = 3
```

Window 4

```
W W B B W B W

White = 4
```

Answer

```
3
```

---

## Time Complexity

```
O(n × k)
```

Each window counts all `k` characters.

---

## Space Complexity

```
O(1)
```

---

# Approach 2 : Sliding Window (Optimal)

## Observation

Current Window

```
W B B W W B B

White = 3
```

Move one step.

New Window

```
B B W W B B W
```

Instead of counting again,

Remove outgoing character

```
W

White Count--

3 → 2
```

Add incoming character

```
W

White Count++

2 → 3
```

Window updated in

```
O(1)
```

---

# Sliding Window Steps

## Step 1

Build the first window.

```
W B B W W B B
```

White Count

```
3
```

Initialize answer

```
answer = 3
```

---

## Step 2

Slide the window.

Outgoing Character

```
If W

whiteCount--
```

Incoming Character

```
If W

whiteCount++
```

Update

```
answer

=

min(answer, whiteCount)
```

Repeat until the end.

---

# Sliding Window Algorithm

```
Count white blocks in first window

Store answer

Slide window

Remove outgoing white block

Add incoming white block

Update minimum answer
```

---

# Dry Run

### Window 1

```
W B B W W B B

White = 3

Answer = 3
```

---

### Window 2

Remove

```
W
```

White

```
3 → 2
```

Add

```
W
```

White

```
2 → 3
```

Answer

```
3
```

---

### Window 3

Remove

```
B
```

White

```
3
```

Add

```
B
```

White

```
3
```

Answer

```
3
```

---

### Window 4

Remove

```
B
```

White

```
3
```

Add

```
W
```

White

```
4
```

Answer remains

```
3
```

---

# Time Complexity

Building first window

```
O(k)
```

Sliding window

```
O(n-k)
```

Overall

```
O(n)
```

---

# Space Complexity

```
O(1)
```

Only a few variables are used.

---

# Brute Force vs Sliding Window

| Brute Force | Sliding Window |
|-------------|----------------|
| Count every window from scratch | Reuse previous window count |
| Repeated calculations | Remove one character and add one character |
| Time Complexity = **O(n × k)** | Time Complexity = **O(n)** |
| Easy to understand | Faster and optimized |
| Not suitable for large inputs | Interview preferred |

---

# Why Sliding Window is Better?

Instead of

```
Window 1

W B B W W B B
```

↓

Calculating again

```
Window 2

B B W W B B W
```

We simply

```
Remove outgoing character

+

Add incoming character
```

Each slide takes only

```
O(1)
```

So overall complexity becomes

```
O(n)
```

---

# Interview Takeaways

✅ Window size is fixed (`k`).

✅ Think in terms of **white blocks**, not recolors.

✅ Every white block requires exactly one recolor.

✅ Maintain the white count while sliding.

✅ Remove the outgoing character and add the incoming character.

---

# Key Learning

- Fixed Size Sliding Window
- Character Counting
- Running Count
- Window Update
- Time Complexity Optimization
- Minimum in Every Window

---

# Final Complexity

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | **O(n × k)** | **O(1)** |
| Sliding Window | **O(n)** | **O(1)** |

---

# Similar Problems

- LeetCode 643 - Maximum Average Subarray I
- LeetCode 1652 - Defuse the Bomb
- LeetCode 2090 - K Radius Subarray Averages
- LeetCode 2379 - Minimum Recolors to Get K Consecutive Black Blocks
- LeetCode 1456 - Maximum Number of Vowels in a Substring of Given Length
- LeetCode 1343 - Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
```