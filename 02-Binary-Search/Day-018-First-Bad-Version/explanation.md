# 278. First Bad Version

## Problem Statement

You are given `n` versions numbered from `1` to `n`.

There exists a **first bad version**, and every version after it is also bad.

You are given the API:

```cpp
bool isBadVersion(int version);
```

Your task is to find the **first bad version** using the minimum number of API calls.

---

## Approach

Since the versions are sorted like this:

```
Good Good Good Bad Bad Bad Bad
```

there is a transition point where the versions change from **Good** to **Bad**.

This is a perfect use case for **Binary Search**.

### Logic

- If `mid` is **bad**, then the first bad version could be `mid` or somewhere before it.
  - Move `high = mid`.
- If `mid` is **good**, then the first bad version must be after `mid`.
  - Move `low = mid + 1`.

Continue until `low == high`.

That index is the first bad version.

---

## Algorithm

1. Initialize:
   - `low = 1`
   - `high = n`
2. While `low < high`
   - Calculate `mid`.
   - If `isBadVersion(mid)` is true
     - `high = mid`
   - Else
     - `low = mid + 1`
3. Return `low`.

---

## Dry Run

### Input

```
n = 8
firstBad = 5
```

Versions:

```
Version : 1 2 3 4 5 6 7 8
Status  : G G G G B B B B
```

### Iteration 1

```
low = 1
high = 8

mid = 4

isBadVersion(4) = false

low = mid + 1 = 5
```

### Iteration 2

```
low = 5
high = 8

mid = 6

isBadVersion(6) = true

high = mid = 6
```

### Iteration 3

```
low = 5
high = 6

mid = 5

isBadVersion(5) = true

high = mid = 5
```

Now,

```
low = 5
high = 5
```

Answer:

```
First Bad Version = 5
```

---

## C++ Code

```cpp
#include <iostream>
using namespace std;

int firstBad;

// Simulated API
bool isBadVersion(int version) {
    return version >= firstBad;
}

int firstBadVersion(int n) {
    int low = 1, high = n;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (isBadVersion(mid))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    int n;

    cout << "Enter total versions: ";
    cin >> n;

    cout << "Enter first bad version: ";
    cin >> firstBad;

    cout << "First Bad Version = " << firstBadVersion(n);

    return 0;
}
```

---

## Complexity Analysis

### Time Complexity

```
O(log n)
```

Binary Search halves the search space in every iteration.

### Space Complexity

```
O(1)
```

Only constant extra space is used.

---

## Key Takeaways

- Binary Search works because versions are sorted (Good → Bad).
- If `mid` is bad, search the left half.
- If `mid` is good, search the right half.
- Always calculate:

```cpp
mid = low + (high - low) / 2;
```

to avoid integer overflow.

---

## Pattern Learned

This problem follows the **First True Binary Search** pattern.

```cpp
while (low < high) {
    int mid = low + (high - low) / 2;

    if (condition(mid))
        high = mid;
    else
        low = mid + 1;
}

return low;
```

This same pattern is used in many LeetCode problems such as:

- 34. Find First and Last Position of Element in Sorted Array
- 875. Koko Eating Bananas
- 1011. Capacity To Ship Packages Within D Days
- 1482. Minimum Number of Days to Make m Bouquets