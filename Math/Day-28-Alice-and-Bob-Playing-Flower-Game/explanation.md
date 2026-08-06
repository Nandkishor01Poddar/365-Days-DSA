# LeetCode -- 3021. Alice and Bob Playing Flower Game

## Intuition
Alice wins only when the total number of flowers picked is **odd**.

A sum is odd only when:
- One number is **odd**
- The other number is **even**

So, we only need to count all possible `(odd, even)` and `(even, odd)` pairs.

---

## Approach

1. Count the number of odd and even integers from `1` to `n`.
   - Odd numbers = `(n + 1) / 2`
   - Even numbers = `n / 2`

2. Count the number of odd and even integers from `1` to `m`.
   - Odd numbers = `(m + 1) / 2`
   - Even numbers = `m / 2`

3. Calculate the total winning pairs:
   - `oddN × evenM`
   - `evenN × oddM`

4. Return their sum.

---

## Dry Run

### Example

**Input:**
```
n = 3, m = 2
```

Odd numbers in `1..3` = 2 → {1, 3}

Even numbers in `1..3` = 1 → {2}

Odd numbers in `1..2` = 1 → {1}

Even numbers in `1..2` = 1 → {2}

Winning pairs:

```
(odd, even) = 2 × 1 = 2
(even, odd) = 1 × 1 = 1
```

Total:

```
2 + 1 = 3
```

**Output:**
```
3
```

---

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

Since we only perform a few arithmetic operations, the solution runs in constant time and uses constant extra space.