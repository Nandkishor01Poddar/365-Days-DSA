# Cube Root (GFG)

## Problem Statement

Given a non-negative integer `x`, find its **integer cube root**.

The integer cube root is the **greatest integer** `y` such that:

```
y³ ≤ x
```

If `x` is a perfect cube, return its exact cube root. Otherwise, return the floor of the cube root.

---

## Examples

### Example 1

```
Input:
x = 27

Output:
3
```

**Explanation**

```
3³ = 27
```

Hence, the cube root is **3**.

---

### Example 2

```
Input:
x = 20

Output:
2
```

**Explanation**

```
2³ = 8
3³ = 27
```

Since

```
8 ≤ 20 < 27
```

the integer cube root is **2**.

---

### Example 3

```
Input:
x = 64

Output:
4
```

---

# Approach 1: Brute Force

## Intuition

Start checking numbers from `0` onwards.

For each number `i`, compute:

```
i³
```

- If `i³ ≤ x`, update the answer.
- Stop when `i³ > x`.

The last valid value of `i` is the integer cube root.

---

## Algorithm

1. If `x < 2`, return `x`.
2. Initialize `answer = 0`.
3. Traverse from `0` to `x`.
4. If `i³ ≤ x`, update the answer.
5. Otherwise, stop.
6. Return the answer.

---

## Code (Brute Force)

```cpp
class Solution {
public:
    int cubeRoot(int x) {

        if (x < 2)
            return x;

        int answer = 0;

        for (long long i = 0; i <= x; i++) {

            if (i * i * i <= x)
                answer = i;
            else
                break;
        }

        return answer;
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** `O(∛x)`
- **Space Complexity:** `O(1)`

---

# Approach 2: Binary Search (Optimal)

## Intuition

The cube values are increasing:

```
0³ = 0
1³ = 1
2³ = 8
3³ = 27
4³ = 64
...
```

Since cube values are sorted, we can use **Binary Search**.

For every middle element:

- If `mid³ == x`, we found the answer.
- If `mid³ < x`, search in the right half.
- If `mid³ > x`, search in the left half.

---

## Algorithm

1. If `x < 2`, return `x`.
2. Initialize:
   - `start = 0`
   - `end = x`
   - `answer = 0`
3. Find the middle element.
4. Compute

```cpp
long long cube = 1LL * mid * mid * mid;
```

Using `1LL` prevents integer overflow.

5. If
   - `cube == x`, return `mid`.
   - `cube < x`, store `mid` as the current answer and search right.
   - `cube > x`, search left.
6. Return `answer`.

---

## Dry Run

### Input

```
x = 20
```

| Start | End | Mid | Mid³ | Answer | Action |
|------:|----:|----:|------:|-------:|--------|
|0|20|10|1000|0|Move Left|
|0|9|4|64|0|Move Left|
|0|3|1|1|1|Move Right|
|2|3|2|8|2|Move Right|
|3|3|3|27|2|Move Left|

Loop ends.

```
Answer = 2
```

---

## Code (Binary Search)

```cpp
class Solution {
public:
    int cubeRoot(int x) {

        if (x < 2)
            return x;

        int start = 0;
        int end = x;
        int answer = 0;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            long long cube = 1LL * mid * mid * mid;

            if (cube == x) {
                return mid;
            }
            else if (cube < x) {
                answer = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return answer;
    }
};
```

---

# Why use `1LL * mid * mid * mid`?

Suppose:

```
mid = 2000
```

Then,

```
2000³ = 8,000,000,000
```

But an `int` can only store up to:

```
2,147,483,647
```

So,

```cpp
mid * mid * mid
```

may overflow and produce an incorrect result.

Using

```cpp
1LL * mid * mid * mid
```

forces the multiplication to be performed using the `long long` data type, preventing overflow.

---

# Edge Cases

### Case 1

```
Input:
0

Output:
0
```

---

### Case 2

```
Input:
1

Output:
1
```

---

### Case 3

```
Input:
7

Output:
1
```

---

### Case 4

```
Input:
8

Output:
2
```

---

### Case 5

```
Input:
28

Output:
3
```

---

# Complexity Analysis

### Brute Force

- **Time Complexity:** `O(∛x)`
- **Space Complexity:** `O(1)`

### Binary Search

- **Time Complexity:** `O(log x)`
- **Space Complexity:** `O(1)`

---

# Key Takeaways

- Brute Force checks every possible cube root one by one.
- Since cube values are sorted, Binary Search is a more efficient solution.
- Use `1LL * mid * mid * mid` to avoid integer overflow.
- Store the latest valid `mid` as the answer whenever `mid³ ≤ x`.
- Binary Search improves the time complexity from **O(∛x)** to **O(log x)**.