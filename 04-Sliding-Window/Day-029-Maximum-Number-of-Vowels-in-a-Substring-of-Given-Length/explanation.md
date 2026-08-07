# LeetCode 1456 - Maximum Number of Vowels in a Substring of Given Length

## Problem Statement

You are given:

- A string `s`
- An integer `k`

Return the **maximum number of vowels** in **any substring of length `k`**.

The vowels are:

```text
a, e, i, o, u
```

---

# Example

### Input

```text
s = "abciiidef"
k = 3
```

### Output

```text
3
```

### Explanation

Possible substrings of length **3**

```text
abc → Vowels = 1

bci → Vowels = 1

cii → Vowels = 2

iii → Vowels = 3

iid → Vowels = 2

ide → Vowels = 2

def → Vowels = 1
```

Maximum vowels

```text
3
```

---

# Observation

Every substring has the same length.

```
Window Size = k
```

The window size never changes.

Whenever the window size is fixed,

👉 Think **Fixed Size Sliding Window**.

---

# Approach 1 : Brute Force

## Idea

For every substring of length `k`

- Count the vowels.
- Update the maximum answer.

Repeat for every possible substring.

---

## Algorithm

```
For every window

Count vowels

Update maximum answer
```

---

## Dry Run

```
s

abciiidef

k = 3
```

Window 1

```text
abc

Vowels = 1
```

Window 2

```text
bci

Vowels = 1
```

Window 3

```text
cii

Vowels = 2
```

Window 4

```text
iii

Vowels = 3
```

Window 5

```text
iid

Vowels = 2
```

Window 6

```text
ide

Vowels = 2
```

Window 7

```text
def

Vowels = 1
```

Maximum

```text
3
```

---

## Time Complexity

```text
O(n × k)
```

Every window counts all `k` characters.

---

## Space Complexity

```text
O(1)
```

---

# Approach 2 : Sliding Window (Optimal)

## Observation

Current Window

```text
abc

Vowels = 1
```

Move one step.

New Window

```text
bci
```

Instead of counting all characters again,

Remove outgoing character

```text
a

Vowel Count--

1 → 0
```

Add incoming character

```text
i

Vowel Count++

0 → 1
```

Window updated in

```text
O(1)
```

---

# Sliding Window Steps

## Step 1

Build the first window.

```text
abc
```

Vowel Count

```text
1
```

Initialize answer

```text
answer = 1
```

---

## Step 2

Slide the window.

Outgoing Character

```text
If vowel

vowelCount--
```

Incoming Character

```text
If vowel

vowelCount++
```

Update

```text
answer

=

max(answer, vowelCount)
```

Repeat until the end.

---

# Sliding Window Algorithm

```text
Count vowels in first window

Store answer

Slide window

Remove outgoing vowel

Add incoming vowel

Update maximum answer
```

---

# Dry Run

### Window 1

```text
abc

Vowels = 1

Answer = 1
```

---

### Window 2

Remove

```text
a
```

Vowel Count

```text
1 → 0
```

Add

```text
i
```

Vowel Count

```text
0 → 1
```

Answer

```text
1
```

---

### Window 3

Remove

```text
b
```

Vowel Count

```text
1
```

Add

```text
i
```

Vowel Count

```text
2
```

Answer

```text
2
```

---

### Window 4

Remove

```text
c
```

Vowel Count

```text
2
```

Add

```text
i
```

Vowel Count

```text
3
```

Answer

```text
3
```

---

### Window 5

Remove

```text
i
```

Vowel Count

```text
3 → 2
```

Add

```text
d
```

Vowel Count

```text
2
```

Answer

```text
3
```

---

### Window 6

Remove

```text
i
```

Vowel Count

```text
2 → 1
```

Add

```text
e
```

Vowel Count

```text
2
```

Answer

```text
3
```

---

### Window 7

Remove

```text
i
```

Vowel Count

```text
2 → 1
```

Add

```text
f
```

Vowel Count

```text
1
```

Answer

```text
3
```

---

# Time Complexity

Building first window

```text
O(k)
```

Sliding window

```text
O(n-k)
```

Overall

```text
O(n)
```

---

# Space Complexity

```text
O(1)
```

Only a few variables are used.

---

# Brute Force vs Sliding Window

| Brute Force | Sliding Window |
|-------------|----------------|
| Counts vowels in every window from scratch | Reuses previous vowel count |
| Repeated calculations | Remove one character and add one character |
| Time Complexity = **O(n × k)** | Time Complexity = **O(n)** |
| Easy to understand | Faster and optimized |
| Not suitable for large inputs | Interview preferred |

---

# Why Sliding Window is Better?

Instead of

```text
Window 1

abc
```

↓

Calculating again

```text
Window 2

bci
```

We simply

```text
Remove outgoing character

+

Add incoming character
```

Each slide takes only

```text
O(1)
```

Therefore,

```text
Total

O(n)
```

---

# Interview Takeaways

✅ Window size is fixed (`k`).

✅ Count vowels only once for the first window.

✅ Maintain the vowel count while sliding.

✅ Remove the outgoing character and add the incoming character.

✅ Update the maximum vowel count after every slide.

---

# Key Learning

- Fixed Size Sliding Window
- Character Counting
- Running Count
- Window Update
- Time Complexity Optimization
- Maximum in Every Window

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