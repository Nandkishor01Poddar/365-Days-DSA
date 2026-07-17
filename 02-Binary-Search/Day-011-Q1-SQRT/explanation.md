# LeetCode 69 - Sqrt(x)

## Problem Statement

Given a non-negative integer `x`, return the **integer square root** of `x`.

The returned integer should be the **floor** of the square root, meaning the greatest integer `y` such that:

```
y * y <= x
```

You must **not** use any built-in exponent function or operator.

### Examples

**Example 1**
```
Input: x = 4
Output: 2
```

**Example 2**
```
Input: x = 8
Output: 2

Explanation:
The square root of 8 is 2.828..., so we return 2.
```

---

# Approach 1: Brute Force

## Idea

Start from `1` and keep checking whether `i * i <= x`.

- If yes, store `i` as the answer.
- Stop when `i * i > x`.

The last valid value of `i` is the integer square root.

---

## Algorithm

1. If `x < 2`, return `x`.
2. Initialize `ans = 0`.
3. Traverse from `1` to `x`.
4. If `i * i <= x`, update `ans = i`.
5. Otherwise, stop the loop.
6. Return `ans`.

---

## Code (Brute Force)

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;

        int ans = 0;

        for (long long i = 1; i <= x; i++) {
            if (i * i <= x)
                ans = i;
            else
                break;
        }

        return ans;
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** `O(√x)`
- **Space Complexity:** `O(1)`

---

# Approach 2: Binary Search (Optimal)

## Intuition

Instead of checking every number one by one, notice that:

- If `mid² == x`, we found the answer.
- If `mid² < x`, the answer lies on the **right side**.
- If `mid² > x`, the answer lies on the **left side**.

Since the search space is sorted, **Binary Search** is the perfect choice.

---

## Algorithm

1. If `x < 2`, return `x`.
2. Initialize:
   - `start = 0`
   - `end = x`
   - `ans = 0`
3. Find the middle element.
4. Compute:

```cpp
long long square = 1LL * mid * mid;
```

Using `1LL` avoids integer overflow.

5. If
   - `square == x`, return `mid`.
   - `square < x`, store `mid` as the current answer and search right.
   - `square > x`, search left.
6. Return `ans`.

---

## Dry Run

Suppose:

```
x = 20
```

| Start | End | Mid | Mid² | Answer | Next Step |
|------:|----:|----:|-----:|-------:|-----------|
| 0 | 20 | 10 | 100 | 0 | Move Left |
| 0 | 9 | 4 | 16 | 4 | Move Right |
| 5 | 9 | 7 | 49 | 4 | Move Left |
| 5 | 6 | 5 | 25 | 4 | Move Left |

Loop ends.

```
Answer = 4
```

---

## Code (Binary Search)

```cpp
class Solution {
public:
    int mySqrt(int x) {

        if (x < 2)
            return x;

        int start = 0;
        int end = x;
        int ans = 0;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            long long square = 1LL * mid * mid;

            if (square == x)
                return mid;

            else if (square < x) {
                ans = mid;
                start = mid + 1;
            }

            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};
```

---

# Why use `1LL * mid * mid`?

Suppose:

```
mid = 50000
```

Then,

```
mid * mid = 2,500,000,000
```

But an `int` can only store up to

```
2,147,483,647
```

So the multiplication overflows and produces an incorrect result.

Writing

```cpp
1LL * mid * mid
```

forces the multiplication to happen using the `long long` data type, preventing overflow.

---

# Complexity Analysis

- **Time Complexity:** `O(log x)`
- **Space Complexity:** `O(1)`

---

# Key Takeaways

- Brute Force checks every possible answer one by one.
- Binary Search halves the search space every iteration.
- Always use `1LL * mid * mid` to avoid integer overflow.
- Binary Search reduces the time complexity from **O(√x)** to **O(log x)**.