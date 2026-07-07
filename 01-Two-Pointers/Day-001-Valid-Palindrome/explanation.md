# LeetCode 125 – Valid Palindrome

## Problem Statement

Given a string `s`, determine whether it is a palindrome after:

* Converting all uppercase letters to lowercase.
* Removing all non-alphanumeric characters.

Return `true` if it is a palindrome; otherwise, return `false`.

---

# Method 1: Two Pointer (Optimal)

## Idea

Use two pointers:

* `st` starts from the beginning.
* `end` starts from the end.

Move both pointers toward the center.

Before comparing characters:

* Skip all non-alphanumeric characters using `isalnum()`.
* Convert characters to lowercase using `tolower()`.

If any pair of characters is different, return `false`.

If all characters match, return `true`.

---

## Algorithm

1. Initialize two pointers:

   * `st = 0`
   * `end = n - 1`
2. Skip invalid characters from the left.
3. Skip invalid characters from the right.
4. Compare characters ignoring case.
5. If different → return `false`.
6. Move both pointers inward.
7. Continue until `st >= end`.
8. Return `true`.

---

## Time Complexity

**O(n)**

Each character is visited at most once.

---

## Space Complexity

**O(1)**

Only two integer variables are used.

---

## Advantages

* No preprocessing required.
* Does not modify the original string.
* Constant extra space.
* Fast and memory efficient.
* Standard two-pointer approach.

---

# Method 2: Preprocessing + Palindrome Check

## Idea

First clean the string.

Steps:

1. Remove all non-alphanumeric characters using `remove_if()`.
2. Convert the remaining characters to lowercase.
3. Perform a normal palindrome check using two pointers.

---

## Algorithm

1. Remove unwanted characters.
2. Convert every character to lowercase.
3. Initialize two pointers.
4. Compare characters from both ends.
5. If mismatch occurs, return `false`.
6. Otherwise continue until pointers meet.
7. Return `true`.

---

## Time Complexity

**O(n)**

* Removing invalid characters → O(n)
* Lowercase conversion → O(n)
* Palindrome check → O(n)

Overall complexity remains **O(n)**.

---

## Space Complexity

**O(n)**

Although the string is modified in place, this preprocessing approach is commonly considered to require additional work proportional to the input size compared with the optimal two-pointer solution.

---

## Advantages

* Easy to understand.
* Cleaner palindrome checking logic.
* Good for beginners.

---

# Comparison

| Feature             | Method 1 | Method 2        |
| ------------------- | -------- | --------------- |
| Time Complexity     | O(n)     | O(n)            |
| Space Complexity    | O(1)     | O(n)            |
| Modifies String     | No       | Yes             |
| Faster              | ✅        | Slightly slower |
| Interview Preferred | ✅        | Sometimes       |
| Easy to Read        | Moderate | Yes             |

---

# Best Choice for Interviews

✅ **Method 1 (Two Pointer)** is the preferred interview solution because:

* Uses **O(1)** extra space.
* Avoids unnecessary preprocessing.
* Demonstrates knowledge of the two-pointer technique.
* Is the standard optimal solution expected by interviewers.

---

# STL Functions Used

### `isalnum(c)`

Checks whether a character is:

* Alphabet (`A-Z`, `a-z`)
* Digit (`0-9`)

Example:

```cpp
isalnum('A');   // true
isalnum('5');   // true
isalnum('@');   // false
```

---

### `tolower(c)`

Converts an uppercase letter to lowercase.

Example:

```cpp
tolower('A');   // 'a'
tolower('B');   // 'b'
```

---

### `remove_if()`

Removes characters satisfying a condition.

Used here to remove all non-alphanumeric characters.

```cpp
s.erase(remove_if(s.begin(), s.end(),
                  [](unsigned char c) {
                      return !isalnum(c);
                  }),
        s.end());
```

---

# Key Learning

This problem teaches:

* Two Pointer technique
* Character handling using `<cctype>`
* String preprocessing
* STL algorithms (`remove_if`)
* Time and Space Complexity analysis

---

# Final Recommendation

For **LeetCode 125 – Valid Palindrome**:

* ✅ **Method 1 (Two Pointer)** → Best for interviews and optimal solution.
* ✅ **Method 2 (Preprocessing)** → Easier to understand but uses more memory and modifies the string.

Whenever possible, prefer **Method 1** in coding interviews.
