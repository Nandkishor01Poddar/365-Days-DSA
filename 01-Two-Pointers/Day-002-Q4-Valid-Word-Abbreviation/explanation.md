# Valid Word Abbreviation

> **Source:** NeetCode 250 – Two Pointers

---

# Problem Statement

Given two strings:

* `word` – the original word.
* `abbr` – an abbreviation of the word.

Determine whether `abbr` is a **valid abbreviation** of `word`.

### Rules

* Letters in `abbr` must exactly match the corresponding letters in `word`.
* Numbers represent the number of characters to skip in `word`.
* Numbers **cannot** have leading zeros.
* Return `true` if the abbreviation is valid; otherwise, return `false`.

---

# Example

### Input

```text
word = "internationalization"
abbr = "i12iz4n"
```

### Output

```text
true
```

### Explanation

* `i` matches `i`
* `12` skips the next 12 characters
* `i` matches
* `z` matches
* `4` skips the next 4 characters
* `n` matches

Both strings are completely processed, so the abbreviation is valid.

---

# Intuition

Instead of expanding the abbreviation, we process both strings simultaneously.

* Use one pointer for the original word.
* Use another pointer for the abbreviation.
* If the current character is a letter, compare it directly.
* If it is a number, read the entire number and skip that many characters in the original word.

Since each pointer only moves forward, the solution is highly efficient.

---

# Approach (Two Pointers)

Use two pointers:

* `i` → points to the original word.
* `j` → points to the abbreviation.

### If `abbr[j]` is a letter

* Compare it with `word[i]`.
* If they are different, return `false`.
* Otherwise move both pointers.

### If `abbr[j]` is a digit

* Leading zero is invalid.
* Read the complete number.
* Skip that many characters in the original word.
* Continue comparing.

Finally, both pointers should reach the end of their respective strings.

---

# Algorithm

1. Initialize two pointers:

   * `i = 0`
   * `j = 0`
2. Traverse both strings.
3. If the current abbreviation character is a letter:

   * Compare with the current character in `word`.
   * If they don't match, return `false`.
4. If the current abbreviation character is a digit:

   * Reject leading zero.
   * Read the entire number.
   * Move `i` forward by that number.
5. Continue until one string ends.
6. Return `true` only if both pointers reach the end.

---

# Dry Run

### Input

```text
word = "internationalization"
abbr = "i12iz4n"
```

| Word Pointer (`i`) | Abbreviation Pointer (`j`) | Action             |
| -----------------: | -------------------------: | ------------------ |
|                  i |                          i | Characters match   |
|                  n |                          1 | Read number `12`   |
| Skip 12 characters |                            | Move `i` forward   |
|                  i |                          i | Characters match   |
|                  z |                          z | Characters match   |
|                  a |                          4 | Read number `4`    |
|  Skip 4 characters |                            | Move `i` forward   |
|                  n |                          n | Characters match   |
|                End |                        End | Valid abbreviation |

---

# Edge Cases

### Leading Zero

```text
word = "apple"
abbr = "a01e"
```

Output

```text
false
```

Reason:

Numbers with leading zeros are invalid.

---

### Character Mismatch

```text
word = "apple"
abbr = "a2e"
```

Output

```text
false
```

Reason:

After skipping two characters, the next expected character does not match.

---

### Complete Skip

```text
word = "apple"
abbr = "5"
```

Output

```text
true
```

All five characters are skipped.

---

# Complexity Analysis

## Time Complexity

**O(n + m)**

* `n` = length of `word`
* `m` = length of `abbr`

Each pointer moves only forward.

---

## Space Complexity

**O(1)**

Only a few integer variables are used.

---

# Why This Approach Works

The abbreviation is processed exactly once.

Whenever a number appears, it tells us how many characters to skip in the original word. Instead of creating another string or modifying the original word, we simply move the pointer forward.

Because both pointers only move in one direction, every character is processed at most once, resulting in a linear-time solution.

---

# STL Functions Used

### `isdigit()`

Checks whether a character is a digit.

```cpp
isdigit('7');   // true
isdigit('A');   // false
```

---

# Key Takeaways

* Two Pointer technique
* Parsing multi-digit numbers
* String traversal
* Handling edge cases like leading zeros
* Constant extra space
* Linear-time solution

---

# Final Recommendation

✅ The **Two Pointer** approach is the optimal solution for this problem.

It is:

* **Time Efficient:** `O(n + m)`
* **Space Efficient:** `O(1)`
* Easy to implement
* Commonly expected in coding interviews
* The standard solution used in the NeetCode 250 roadmap
