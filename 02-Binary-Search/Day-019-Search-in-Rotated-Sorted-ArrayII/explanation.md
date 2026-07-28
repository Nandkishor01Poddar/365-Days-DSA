# LeetCode 81 - Search in Rotated Sorted Array II

## Intuition

This problem is similar to **LeetCode 33**, but the array may contain **duplicate elements**.

In LeetCode 33, we can always determine which half of the array is sorted. However, duplicates can make this impossible.

Example:

```text
nums = [1, 0, 1, 1, 1]

left = 0
mid = 2
right = 4

        L   M     R
nums = [1, 0, 1, 1, 1]
```

Here,

```
nums[left] == nums[mid] == nums[right]
```

Since all three values are equal, we **cannot determine** whether the left half or the right half is sorted.

To remove this ambiguity, we simply shrink the search space by moving both pointers inward.

```cpp
left++;
right--;
```

---

## Algorithm

1. Initialize `left = 0` and `right = n - 1`.

2. While `left <= right`:
   - Compute `mid`.
   - If `nums[mid] == target`, return `true`.

3. If

```cpp
nums[left] == nums[mid] && nums[mid] == nums[right]
```

we cannot determine the sorted half.

Shrink the search space:

```cpp
left++;
right--;
```

4. Otherwise, if the left half is sorted:

```cpp
nums[left] <= nums[mid]
```

Check whether the target lies inside the left half.

If yes:

```cpp
right = mid - 1;
```

Otherwise:

```cpp
left = mid + 1;
```

5. Otherwise, the right half is sorted.

Check whether the target belongs to the right half.

If yes:

```cpp
left = mid + 1;
```

Otherwise:

```cpp
right = mid - 1;
```

6. If the loop finishes, return `false`.

---

## Dry Run

### Example

```text
nums = [2,5,6,0,0,1,2]
target = 0
```

| left | mid | right | nums[mid] | Action |
|------|-----|-------|-----------|--------|
| 0 | 3 | 6 | 0 | Target found → Return true |

---

### Duplicate Case

```text
nums = [1,0,1,1,1]
target = 0
```

### Iteration 1

```
left = 0
mid = 2
right = 4

nums[left] = 1
nums[mid] = 1
nums[right] = 1
```

Cannot determine the sorted half.

```
left++
right--
```

Now

```
left = 1
right = 3
```

---

### Iteration 2

```
left = 1
mid = 2
right = 3
```

Left half is sorted.

Target belongs to the left half.

```
right = mid - 1
```

---

### Iteration 3

```
left = 1
mid = 1
right = 1
```

```
nums[mid] == target
```

Return `true`.

---

## Complexity Analysis

### Time Complexity

- Average Case: **O(log n)**
- Worst Case: **O(n)**

The worst case occurs when the array contains many duplicate values, forcing us to shrink the search space one element at a time.

Example:

```text
[1,1,1,1,1,1,1,1]
```

---

### Space Complexity

```
O(1)
```

No extra space is used.

---

## C++ Code

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return true;

            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return false;
    }
};
```

## Key Takeaways

- Handle duplicates first by checking:
  ```cpp
  nums[left] == nums[mid] && nums[mid] == nums[right]
  ```
- If duplicates prevent identifying the sorted half, shrink both ends:
  ```cpp
  left++;
  right--;
  ```
- Otherwise, use the same binary search logic as LeetCode 33 to determine the sorted half and narrow the search space.