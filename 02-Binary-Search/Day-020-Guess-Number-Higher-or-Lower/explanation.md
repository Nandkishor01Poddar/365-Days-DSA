# 374. Guess Number Higher or Lower

## Intuition
The numbers are in sorted order from `1` to `n`. Since the `guess()` API tells us whether our guess is too high, too low, or correct, we can eliminate half of the remaining search space after every guess. This makes **Binary Search** the optimal approach.

---

## Approach
1. Initialize two pointers:
   - `low = 1`
   - `high = n`
2. While `low <= high`:
   - Compute the middle value:
     ```cpp
     mid = low + (high - low) / 2;
     ```
     This avoids integer overflow.
   - Call `guess(mid)`:
     - If it returns `0`, `mid` is the answer.
     - If it returns `-1`, our guess is too high, so search the left half:
       ```cpp
       high = mid - 1;
       ```
     - If it returns `1`, our guess is too low, so search the right half:
       ```cpp
       low = mid + 1;
       ```
3. Return the correct number.

---

## Code

```cpp
class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);

            if (res == 0)
                return mid;
            else if (res == -1)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
    }
};
```

---

## Dry Run

### Input
```
n = 10
pick = 6
```

| low | high | mid | guess(mid) | Action |
|-----|------|-----|------------|--------|
| 1 | 10 | 5 | 1 | low = 6 |
| 6 | 10 | 8 | -1 | high = 7 |
| 6 | 7 | 6 | 0 | Return 6 |

**Output:** `6`

---

## Complexity Analysis

- **Time Complexity:** `O(log n)`
- **Space Complexity:** `O(1)`

---

## Key Points
- Use Binary Search because the search space is sorted.
- Use:
  ```cpp
  mid = low + (high - low) / 2;
  ```
  to prevent integer overflow.
- The loop condition should be:
  ```cpp
  while (low <= high)
  ```
  so that the last remaining candidate is also checked.