# LeetCode 344 – Reverse String

## Problem Statement

Write a function that reverses an array of characters **in-place**.

The input is given as an array of characters `s`.

You must modify the input array directly using **O(1)** extra memory.

---

# Method 1: Two Pointer (Optimal)

## Idea

Use two pointers:

* `left` starts from the beginning of the array.
* `right` starts from the end of the array.

Swap the characters at both pointers, then move the pointers toward the center.

Continue until both pointers meet or cross each other.

---

## Algorithm

1. Initialize two pointers:

   * `left = 0`
   * `right = s.size() - 1`
2. While `left < right`:

   * Swap `s[left]` and `s[right]`.
   * Increment `left`.
   * Decrement `right`.
3. The array is now reversed.

---

## Time Complexity

**O(n)**

Each character is swapped at most once.

---

## Space Complexity

**O(1)**

The reversal is performed in-place using only two pointers.

---

## Advantages

* Simple and easy to implement.
* Uses constant extra space.
* No additional array or string is required.
* Optimal solution expected in coding interviews.
* Works efficiently for arrays of any size.

---

# Method 2: Using STL `reverse()`

## Idea

The C++ Standard Library provides the `reverse()` function in the `<algorithm>` header.

It automatically reverses the elements within the given range.

---

## Algorithm

1. Include the `<algorithm>` header.
2. Call:

   ```cpp
   reverse(s.begin(), s.end());
   ```
3. The array is reversed in-place.

---

## Time Complexity

**O(n)**

The STL function visits each element approximately once.

---

## Space Complexity

**O(1)**

`reverse()` performs the operation in-place.

---

## Advantages

* Very concise.
* Easy to read.
* Less code to write.
* Suitable when STL usage is allowed.

---

# Comparison

| Feature               | Method 1 | Method 2  |
| --------------------- | -------- | --------- |
| Time Complexity       | O(n)     | O(n)      |
| Space Complexity      | O(1)     | O(1)      |
| Uses STL              | ❌        | ✅         |
| Easy to Understand    | ✅        | ✅         |
| Interview Preferred   | ✅        | Sometimes |
| Manual Implementation | ✅        | ❌         |

---

# Best Choice for Interviews

✅ **Method 1 (Two Pointer)** is the preferred interview solution because:

* Demonstrates understanding of the two-pointer technique.
* Uses constant extra space.
* Does not rely on library functions.
* Clearly shows the reversal logic.
* Commonly expected by interviewers.

---

# STL Function Used

### `swap(a, b)`

Exchanges the values of two variables.

Example:

```cpp
char a = 'h';
char b = 'o';

swap(a, b);

// a = 'o'
// b = 'h'
```

---

### `reverse(first, last)`

Reverses the elements within the specified range.

Example:

```cpp
#include <algorithm>

reverse(s.begin(), s.end());
```

---

# Example

### Input

```text
["h","e","l","l","o"]
```

### Output

```text
["o","l","l","e","h"]
```

---

# Dry Run

Initial Array

```text
h  e  l  l  o
↑           ↑
L           R
```

Swap `h` and `o`

```text
o  e  l  l  h
   ↑     ↑
   L     R
```

Swap `e` and `l`

```text
o  l  l  e  h
      ↑
    L = R
```

Pointers meet, so the array is completely reversed.

---

# Key Learning

This problem teaches:

* Two Pointer technique
* In-place array manipulation
* Swapping elements
* STL `swap()`
* STL `reverse()`
* Time and Space Complexity analysis

---

# Final Recommendation

For **LeetCode 344 – Reverse String**:

* ✅ **Method 1 (Two Pointer)** → Best for interviews and demonstrates problem-solving skills.
* ✅ **Method 2 (STL `reverse()`)** → Best for concise and production-ready code when library functions are allowed.

Whenever possible, implement the **Two Pointer** solution first in coding interviews to showcase your understanding of fundamental algorithms.
