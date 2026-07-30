# 367. Valid Perfect Square

## Approach
We use **Binary Search** to determine whether a given number is a perfect square without using any built-in square root function.

Since the square root of a number `num` lies between `1` and `num / 2` (for `num > 1`), we perform binary search within this range.

At each step:
- Calculate the middle value `mid`.
- Instead of checking `mid * mid` (which may overflow), compare `mid` with `num / mid`.
- If `mid == num / mid` **and** `num % mid == 0`, then `mid × mid = num`, so `num` is a perfect square.
- If `mid > num / mid`, search the left half.
- Otherwise, search the right half.

If no such value is found, return `false`.

---

## Algorithm
1. If `num < 2`, return `true`.
2. Initialize:
   - `left = 1`
   - `right = num / 2`
3. While `left <= right`:
   - Compute `mid`.
   - If `mid == num / mid` and `num % mid == 0`, return `true`.
   - If `mid > num / mid`, move to the left half.
   - Otherwise, move to the right half.
4. Return `false` if no perfect square is found.

---

## Dry Run

### Input
```
num = 16
```

| Left | Right | Mid | Comparison | Action |
|------|-------|-----|------------|--------|
| 1 | 8 | 4 | 4 == 16/4 and 16 % 4 == 0 | Return true |

Output:
```
true
```

---

### Input
```
num = 14
```

| Left | Right | Mid | Comparison | Action |
|------|-------|-----|------------|--------|
| 1 | 7 | 4 | 4 > 14/4 | right = 3 |
| 1 | 3 | 2 | 2 < 14/2 | left = 3 |
| 3 | 3 | 3 | 3 > 14/3 | right = 2 |

Loop ends.

Output:
```
false
```

---

## C++ Code

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;

        int left = 1, right = num / 2;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (mid == num / mid && num % mid == 0)
                return true;
            else if (mid > num / mid)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return false;
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** `O(log n)`
  - Binary search halves the search space in every iteration.

- **Space Complexity:** `O(1)`
  - Only a few variables are used.

---

## Key Takeaways
- Binary Search works because the square function is monotonic.
- Avoid `mid * mid` to prevent integer overflow.
- The condition `mid == num / mid` alone is **not enough** because of integer division.
- Always verify divisibility using `num % mid == 0`.