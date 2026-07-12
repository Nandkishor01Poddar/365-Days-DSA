# LeetCode 2486 - Append Characters to String to Make Subsequence

## Problem Statement

You are given two strings:

- `s`
- `t`

Your task is to determine the **minimum number of characters** that need to be appended **at the end of string `s`** so that `t` becomes a **subsequence** of `s`.

A **subsequence** is a sequence that can be obtained by deleting some (or no) characters from a string without changing the order of the remaining characters.

Return the minimum number of characters that need to be appended.

---

# Examples

## Example 1

```text
Input:
s = "coaching"
t = "coding"

Output:
4
```

Explanation

```text
Matched characters

c
o
...

Remaining characters

ding

Need to append:
ding

Answer = 4
```

---

## Example 2

```text
Input:
s = "abcde"
t = "a"

Output:
0
```

Explanation

```text
"a" already exists as a subsequence.

Nothing needs to be appended.
```

---

## Example 3

```text
Input:
s = "z"
t = "abcde"

Output:
5
```

Explanation

```text
No character matches.

Entire string "abcde"
must be appended.

Answer = 5
```

---

# Observation

We only need to know:

> **How many characters of `t` already appear in order inside `s`.**

The remaining characters are the answer.

---

# Brute Force Approach

## Idea

Start matching `t` from its first character.

For every character of `t`:

- Search the remaining part of `s`.
- If found, continue.
- Otherwise, stop.

The remaining characters of `t` must be appended.

Since for every character of `t` we may scan almost the entire remaining part of `s`, this approach is slower.

---

## Algorithm

1. Start from the first character of `t`.
2. Search it in `s`.
3. If found

   - move to the next character of `t`
   - continue searching after that position in `s`

4. If not found

   - stop searching

5. Remaining characters of `t` are the answer.

---

## Brute Force Code

```cpp
class Solution {
public:
    int appendCharacters(string s, string t) {

        int start = 0;

        for(int j = 0; j < t.size(); j++){

            bool found = false;

            for(int i = start; i < s.size(); i++){

                if(s[i] == t[j]){
                    found = true;
                    start = i + 1;
                    break;
                }

            }

            if(!found)
                return t.size() - j;
        }

        return 0;
    }
};
```

---

## Dry Run (Brute Force)

```text
s = coaching
t = coding
```

Search

```text
c ✔
o ✔
d ✖
```

Remaining

```text
ding
```

Answer

```text
4
```

---

## Complexity

Time Complexity

```text
O(n × m)
```

Space Complexity

```text
O(1)
```

---

# Optimized Approach (Two Pointers)

## Idea

Instead of repeatedly searching from the beginning,

use **two pointers**.

One pointer traverses `s`.

Another pointer traverses `t`.

Whenever both characters match,

move both pointers.

Otherwise,

only move the pointer of `s`.

At the end,

the pointer of `t` tells us how many characters have already matched.

---

## Algorithm

1. Create two pointers

```text
i = 0
j = 0
```

2. Traverse while both pointers are valid.

3. If

```text
s[i] == t[j]
```

move both pointers.

Otherwise,

move only `i`.

4. After traversal,

remaining characters are

```text
t.size() - j
```

---

## Code

```cpp
class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int i = 0;
        int j = 0;

        while (i < s.size() && j < t.size())
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }

        return t.size() - j;
    }
};
```

---

# Dry Run

Input

```text
s = coaching
t = coding
```

Initial

```text
i
↓

c o a c h i n g

j
↓

c o d i n g
```

---

### Step 1

```text
c == c

Move both pointers
```

---

### Step 2

```text
o == o

Move both pointers
```

---

### Step 3

```text
a != d

Move only i
```

---

### Step 4

```text
c != d

Move i
```

---

### Step 5

```text
h != d

Move i
```

---

### Step 6

```text
i != d

Move i
```

---

### Step 7

```text
n != d

Move i
```

---

### Step 8

```text
g != d

Move i
```

End of string.

Matched characters

```text
co
```

Remaining

```text
ding
```

Answer

```text
4
```

---

# Why Two Pointers?

We never need to restart searching.

Each character of `s`

is visited only once.

Each character of `t`

is also visited only once.

Therefore,

the solution is much faster.

---

# Complexity Analysis

## Brute Force

Time

```text
O(n × m)
```

Space

```text
O(1)
```

---

## Optimized

Time

```text
O(n + m)
```

Space

```text
O(1)
```

---

# Key Takeaways

- We only care about how much of `t` is already a subsequence.
- Two pointers efficiently compare both strings.
- No extra array or hash map is required.
- Every character is visited at most once.

---

# Interview Tip

Whenever two strings need to be compared **in order**, think about using **Two Pointers**.

Common problems using this pattern:

- Is Subsequence
- Append Characters to String to Make Subsequence
- Merge Strings Alternately
- Backspace String Compare
- Valid Palindrome
- Reverse String

Pattern

```text
String 1

i ----->

String 2

j ----->
```

Move pointers according to the condition and avoid unnecessary rescanning.