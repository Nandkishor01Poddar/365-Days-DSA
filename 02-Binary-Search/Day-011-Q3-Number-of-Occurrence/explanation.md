# Number of Occurrence (GFG)

## Problem Statement

Given a **sorted array** `arr[]` and an integer `target`, find the **number of times the target appears** in the array.

If the target is not present, return `0`.

---

## Examples

### Example 1

```
Input:
arr = [1, 2, 2, 2, 3, 4]
target = 2

Output:
3
```

**Explanation**

The element `2` appears at indices `1`, `2`, and `3`.

Hence, the answer is **3**.

---

### Example 2

```
Input:
arr = [1, 2, 3, 4]
target = 5

Output:
0
```

**Explanation**

The target does not exist in the array.

---

### Example 3

```
Input:
arr = [5, 5, 5, 5]

target = 5

Output:
4
```

---

# Approach 1: Brute Force

## Intuition

Traverse the entire array and count every occurrence of the target.

---

## Algorithm

1. Initialize `count = 0`.
2. Traverse the array.
3. If the current element equals the target, increment `count`.
4. Return `count`.

---

## Code (Brute Force)

```cpp
class Solution {
public:
    int countFreq(vector<int>& arr, int target) {

        int count = 0;

        for (int num : arr) {
            if (num == target)
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

Since the array is sorted, all occurrences of the target are placed together.

Instead of checking every element, we can:

1. Find the **first occurrence** of the target.
2. Find the **last occurrence** of the target.

The total number of occurrences is:

```
lastIndex - firstIndex + 1
```

If the target is not found, return `0`.

---

## Algorithm

### Step 1: Find the First Occurrence

- Apply Binary Search.
- Whenever the target is found:
  - Store the index.
  - Continue searching on the **left** to find an earlier occurrence.

---

### Step 2: Find the Last Occurrence

- Apply Binary Search again.
- Whenever the target is found:
  - Store the index.
  - Continue searching on the **right** to find a later occurrence.

---

### Step 3

If the first occurrence is `-1`, return `0`.

Otherwise,

```
Occurrences = lastIndex - firstIndex + 1
```

---

## Dry Run

### Input

```
arr = [1,2,2,2,3,4]
target = 2
```

### Finding First Occurrence

| Start | End | Mid | arr[mid] | Answer | Action |
|------:|----:|----:|----------|-------:|--------|
|0|5|2|2|2|Move Left|
|0|1|0|1|2|Move Right|
|1|1|1|2|1|Move Left|

First occurrence = **1**

---

### Finding Last Occurrence

| Start | End | Mid | arr[mid] | Answer | Action |
|------:|----:|----:|----------|-------:|--------|
|0|5|2|2|2|Move Right|
|3|5|4|3|2|Move Left|
|3|3|3|2|3|Move Right|

Last occurrence = **3**

---

```
Occurrences = 3 - 1 + 1 = 3
```

---

## Code (Binary Search)

```cpp
class Solution {
public:

    int binarySearch(vector<int>& arr, int target, bool findFirst) {

        int start = 0;
        int end = arr.size() - 1;
        int answer = -1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {

                answer = mid;

                if (findFirst)
                    end = mid - 1;
                else
                    start = mid + 1;
            }

            else if (arr[mid] < target) {
                start = mid + 1;
            }

            else {
                end = mid - 1;
            }
        }

        return answer;
    }

    int countFreq(vector<int>& arr, int target) {

        int first = binarySearch(arr, target, true);

        if (first == -1)
            return 0;

        int last = binarySearch(arr, target, false);

        return last - first + 1;
    }
};
```

---

# Why do we perform Binary Search twice?

The first Binary Search gives the **leftmost occurrence**.

The second Binary Search gives the **rightmost occurrence**.

Knowing both indices allows us to calculate the total occurrences in constant time.

```
Occurrences = lastIndex - firstIndex + 1
```

---

# Edge Cases

### Case 1

```
Input:
arr = [1,2,3,4]
target = 5

Output:
0
```

---

### Case 2

```
Input:
arr = [7]

target = 7

Output:
1
```

---

### Case 3

```
Input:
arr = [2,2,2,2,2]

target = 2

Output:
5
```

---

### Case 4

```
Input:
arr = [1,2,3,4]

target = 1

Output:
1
```

---

# Complexity Analysis

### Brute Force

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

### Binary Search

- First Binary Search: `O(log n)`
- Second Binary Search: `O(log n)`

Overall:

- **Time Complexity:** `O(log n)`
- **Space Complexity:** `O(1)`

---

# Key Takeaways

- The array is sorted, making Binary Search applicable.
- Use one Binary Search to find the **first occurrence**.
- Use another Binary Search to find the **last occurrence**.
- Total occurrences = **`lastIndex - firstIndex + 1`**.
- If the target is not found (`first == -1`), return `0`.
- This approach improves the time complexity from **O(n)** to **O(log n)**.