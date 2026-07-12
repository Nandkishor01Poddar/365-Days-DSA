# LeetCode 246 - Strobogrammatic Number

## Problem Statement

A number is called **Strobogrammatic** if it appears the same after rotating it **180°** (turning it upside down).

You are given a string `num` representing a number.

Return:

- `true` if it is a strobogrammatic number.
- `false` otherwise.

---

## Examples

### Example 1

```text
Input:
num = "69"

Output:
true

Explanation:
6 becomes 9
9 becomes 6

After rotation:
69 -> 69
```

### Example 2

```text
Input:
num = "88"

Output:
true

Explanation:
8 remains 8 after rotation.
```

### Example 3

```text
Input:
num = "962"

Output:
false

Explanation:
9 -> 6
6 -> 9
2 cannot be rotated.

Hence, it is not a strobogrammatic number.
```

---

# Observation

Only **five digits** remain valid after a 180° rotation.

| Digit | Rotates To |
|-------:|:----------:|
| 0 | 0 |
| 1 | 1 |
| 8 | 8 |
| 6 | 9 |
| 9 | 6 |

The following digits are **invalid** because they do not form any valid digit after rotation.

```text
2
3
4
5
7
```

---

# Brute Force Approach

## Idea

Create another string that represents the rotated version of the original number.

### Steps

1. Traverse the string from right to left.
2. Rotate every digit using the mapping.
3. If an invalid digit appears, return `false`.
4. Store the rotated digit in a new string.
5. Compare the rotated string with the original string.

If both are equal, return `true`.

Otherwise return `false`.

---

## Dry Run

Input

```text
69
```

Traverse from right to left

```text
9 -> 6
6 -> 9
```

New string becomes

```text
69
```

Original

```text
69
```

Both are equal.

Answer = **true**

---

## Brute Force Code

```cpp
bool isStrobogrammatic(string num) {

    map<char,char> mp = {
        {'0','0'},
        {'1','1'},
        {'8','8'},
        {'6','9'},
        {'9','6'}
    };

    string rotated = "";

    for(int i = num.size()-1; i >= 0; i--){

        if(mp.find(num[i]) == mp.end())
            return false;

        rotated += mp[num[i]];
    }

    return rotated == num;
}
```

---

## Complexity

Time Complexity

```text
O(n)
```

Space Complexity

```text
O(n)
```

Because we create another string.

---

# Optimized Approach (Two Pointers)

## Idea

Instead of creating another string, compare the digits directly using two pointers.

One pointer starts from the beginning.

Another pointer starts from the end.

If every pair satisfies the rotation rule, then the number is strobogrammatic.

---

## Algorithm

1. Create a map containing valid rotations.
2. Initialize

```text
i = 0
j = n - 1
```

3. While `i <= j`

- Check whether the left digit exists in the map.
- If not, return `false`.
- Compare

```text
Map[leftDigit]
```

with

```text
rightDigit
```

- If they are different, return `false`.
- Otherwise move both pointers.

4. If the loop finishes successfully, return `true`.

---

## Dry Run

Input

```text
619
```

Initial

```text
i                j
↓                ↓

6      1      9
```

### First Iteration

```text
left = 6
right = 9

Map[6] = 9

9 == 9

Move both pointers.
```

Now

```text
      i,j
       ↓

6      1      9
```

### Second Iteration

```text
left = 1
right = 1

Map[1] = 1

1 == 1

Move pointers.
```

Loop ends.

Answer

```text
true
```

---

## Dry Run 2

Input

```text
962
```

```text
left = 9
right = 2

Map[9] = 6

6 != 2
```

Return

```text
false
```

---

# Why Two Pointers?

Notice that every digit only needs to match the digit at the opposite end after rotation.

So instead of building another string, we compare both ends directly.

This saves extra memory.

---

## Complexity

Time Complexity

```text
O(n)
```

Space Complexity

```text
O(1)
```

The map always contains only **5 elements**, so it is considered constant extra space.

---

# Key Takeaways

- Only digits **0, 1, 6, 8, 9** are valid.
- Digits **2, 3, 4, 5, 7** immediately make the answer false.
- Brute Force builds a rotated string.
- Two Pointer approach compares both ends directly.
- Two Pointer solution is more space-efficient and is the preferred interview solution.

---

# Interview Tip

Whenever you need to compare the **left side** of a string with the **right side**, think about using the **Two Pointer** technique.

Examples include:

- Valid Palindrome
- Reverse String
- Strobogrammatic Number
- Two Sum II
- Container With Most Water

The pattern remains the same:

```text
Left Pointer  ---> <--- Right Pointer
```