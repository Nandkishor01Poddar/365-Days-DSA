# Count the Zeros (GFG)

## Problem Statement

You are given a **sorted binary array** consisting of only `1`s and `0`s.

The array is sorted such that **all the `1`s appear first**, followed by **all the `0`s**.

Your task is to count the total number of `0`s in the array.

---

## Examples

### Example 1

```
Input:
arr = [1, 1, 1, 0, 0]

Output:
2
```

**Explanation**

There are **2 zeros** in the array.

---

### Example 2

```
Input:
arr = [1, 1, 1, 1]

Output:
0
```

**Explanation**

There are no zeros.

---

### Example 3

```
Input:
arr = [0, 0, 0, 0]

Output:
4
```

**Explanation**

Every element is zero.

---

# Approach 1: Brute Force

## Intuition

Traverse the entire array and count every occurrence of `0`.

---

## Algorithm

1. Initialize `count = 0`.
2. Traverse the array.
3. If the current element is `0`, increment `count`.
4. Return `count`.

---

## Code (Brute Force)

```cpp
class Solution {
public:
    int countZeroes(vector<int>& arr) {

        int count = 0;

        for (int num : arr) {
            if (num == 0)
                count++;
        }

        return count;
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

# Approach 2: Binary Search (Optimal)

## Intuition

Since the array is sorted:

```
1 1 1 1 0 0 0
```

All the `1`s are on the left and all the `0`s are on the right.

Instead of checking every element, we can find the **first occurrence of `0`** using Binary Search.

Once we know the index of the first `0`, the number of zeros is simply:

```
Number of zeros = n - firstZeroIndex
```

---

## Algorithm

1. Initialize:
   - `start = 0`
   - `end = n - 1`
   - `firstZero = n`
2. Perform Binary Search.
3. If `arr[mid] == 1`
   - Search in the right half.
4. Otherwise (`arr[mid] == 0`)
   - Store the current index.
   - Continue searching on the left to find the first `0`.
5. Return:

```
n - firstZero
```

---

## Dry Run

### Input

```
arr = [1,1,1,0,0,0]
```

| Start | End | Mid | arr[mid] | firstZero | Action |
|------:|----:|----:|----------|----------:|--------|
|0|5|2|1|6|Move Right|
|3|5|4|0|4|Move Left|
|3|3|3|0|3|Move Left|

Loop ends.

```
firstZero = 3

Answer = 6 - 3 = 3
```

---

## Code (Binary Search)

```cpp
class Solution {
public:
    int countZeroes(vector<int>& arr) {

        int n = arr.size();

        int start = 0;
        int end = n - 1;
        int firstZero = n;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (arr[mid] == 1) {
                start = mid + 1;
            }
            else {
                firstZero = mid;
                end = mid - 1;
            }
        }

        return n - firstZero;
    }
};
```

---

# Why initialize `firstZero = n`?

Suppose the array is:

```
1 1 1 1
```

No zero exists.

If we initialize

```cpp
firstZero = 0;
```

then

```
Answer = n - 0 = n
```

which is incorrect.

Instead, initialize

```cpp
firstZero = n;
```

If no zero is found,

```
Answer = n - n = 0
```

which is correct.

---

# Edge Cases

### Case 1

```
Input:
[1,1,1,1]

Output:
0
```

---

### Case 2

```
Input:
[0,0,0,0]

Output:
4
```

---

### Case 3

```
Input:
[1,1,0,0]

Output:
2
```

---

# Complexity Analysis

### Brute Force

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

### Binary Search

- **Time Complexity:** `O(log n)`
- **Space Complexity:** `O(1)`

---

# Key Takeaways

- The array is sorted (`1`s first, then `0`s), making Binary Search applicable.
- Find the **first occurrence of `0`** instead of counting each zero.
- Number of zeros = **`n - firstZeroIndex`**.
- Initialize `firstZero` with `n` to correctly handle arrays containing no zeros.
- Binary Search improves the time complexity from **O(n)** to **O(log n)**.