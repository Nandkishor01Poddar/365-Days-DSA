# LeetCode 680 – Valid Palindrome II

## Problem Statement

Given a string `s`, return `true` if the string can be a palindrome after deleting **at most one** character.

Otherwise, return `false`.

---

# Method 1: Two Pointer + Helper Function (Optimal)

## Idea

A palindrome reads the same from both left and right.

Use two pointers:

* `left` starts from the beginning.
* `right` starts from the end.

Move both pointers toward the center while the characters are equal.

If a mismatch occurs, we have only **one chance** to delete a character.

There are two possibilities:

* Skip the left character and check whether the remaining substring is a palindrome.
* Skip the right character and check whether the remaining substring is a palindrome.

If either substring is a palindrome, return `true`; otherwise, return `false`.

---

## Algorithm

1. Initialize two pointers:

   * `left = 0`
   * `right = n - 1`
2. Compare characters at both pointers.
3. If they are equal:

   * Move both pointers inward.
4. If they are different:

   * Check whether `s[left + 1 ... right]` is a palindrome.
   * Check whether `s[left ... right - 1]` is a palindrome.
   * If either is a palindrome, return `true`.
5. If the loop finishes without problems, return `true`.

---

## Time Complexity

**O(n)**

The main traversal is **O(n)**.

At most one additional palindrome check is performed, which is also **O(n)**.

Overall complexity remains **O(n)**.

---

## Space Complexity

**O(1)**

Only a few pointer variables are used.

---

## Advantages

* Optimal linear-time solution.
* Uses constant extra space.
* Does not modify the original string.
* Efficient and interview-friendly.
* Demonstrates the Two Pointer technique.

---

# Method 2: Brute Force (Delete Every Character)

## Idea

Try deleting each character one by one.

After every deletion:

* Create a new string.
* Check whether it is a palindrome.

If any modified string is a palindrome, return `true`.

Otherwise, return `false`.

---

## Algorithm

1. If the original string is already a palindrome, return `true`.
2. For every index:

   * Remove that character.
   * Check whether the new string is a palindrome.
3. If any check returns `true`, return `true`.
4. Otherwise return `false`.

---

## Time Complexity

**O(n²)**

* There are **n** possible deletions.
* Each palindrome check takes **O(n)**.

Overall complexity:

**O(n²)**

---

## Space Complexity

**O(n)**

A new string is created for each deletion attempt.

---

## Advantages

* Very easy to understand.
* Straightforward implementation.
* Useful for beginners.

---

# Comparison

| Feature                       | Method 1 | Method 2 |
| ----------------------------- | -------- | -------- |
| Time Complexity               | O(n)     | O(n²)    |
| Space Complexity              | O(1)     | O(n)     |
| Uses Two Pointers             | ✅        | ❌        |
| Deletes Character Efficiently | ✅        | ❌        |
| Interview Preferred           | ✅        | ❌        |
| Easy to Understand            | Moderate | ✅        |

---

# Best Choice for Interviews

✅ **Method 1 (Two Pointer + Helper Function)** is the preferred interview solution because:

* Achieves **O(n)** time complexity.
* Uses **O(1)** extra space.
* Avoids creating unnecessary strings.
* Efficiently handles the "delete at most one character" condition.
* Commonly expected by interviewers.

---

# Helper Function

### `palindromeHelper(left, right, s)`

Checks whether the substring `s[left...right]` is a palindrome.

Example:

```cpp id="ccjlwm"
bool palindromeHelper(int left, int right, string s)
{
    while (left < right)
    {
        if (s[left] != s[right])
            return false;

        left++;
        right--;
    }

    return true;
}
```

---

# Example

### Input

```text id="q6xlyl"
"abca"
```

### Output

```text id="kegqzg"
true
```

---

# Dry Run

Initial String

```text id="v6h6h0"
a  b  c  a
↑        ↑
L        R
```

Characters match:

```text id="b6ylc9"
b  c
↑  ↑
L  R
```

Mismatch occurs:

```text id="pxeiyl"
b != c
```

Try two possibilities:

1. Skip `'b'`

```text id="i2szgq"
aca
```

Palindrome ✅

2. Skip `'c'`

```text id="jlwmv0"
aba
```

Palindrome ✅

Since one valid palindrome exists after deleting a single character:

```text id="s0kruy"
Return true
```

---

# Key Learning

This problem teaches:

* Two Pointer technique
* Greedy decision making
* Palindrome checking
* Helper functions
* Time and Space Complexity analysis

---

# Final Recommendation

For **LeetCode 680 – Valid Palindrome II**:

* ✅ **Method 1 (Two Pointer + Helper Function)** → Best for interviews and the optimal solution with **O(n)** time complexity.
* ✅ **Method 2 (Brute Force)** → Easier to understand but significantly slower because it checks every possible deletion.

Whenever possible, prefer the **Two Pointer** approach because it minimizes both time and space complexity while efficiently solving the problem.
