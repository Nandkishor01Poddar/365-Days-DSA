# LeetCode 151 --- Reverse Words in a String

# Problem

Given a string `s`, reverse the order of the words.

A **word** is a sequence of non-space characters.

The returned string should:

-   Remove leading spaces.
-   Remove trailing spaces.
-   Reduce multiple spaces between words to **one** space.

------------------------------------------------------------------------

## Example

**Input**

``` text
"  the   sky   is  blue  "
```

**Output**

``` text
"blue is sky the"
```

------------------------------------------------------------------------

# Method 1 --- `trim()` + `stringstream` + `vector`

## Idea

1.  Remove leading and trailing spaces using `trim()`.
2.  Use `stringstream` to split the sentence into words.
3.  Store words in a `vector`.
4.  Reverse the vector.
5.  Join the words using a single space.

### Algorithm

``` text
Input
↓
trim()

↓

stringstream

↓

vector<string>

↓

reverse(vector)

↓

join with one space
```

### Time Complexity

-   Trimming → O(n)
-   Splitting → O(n)
-   Reversing → O(n)
-   Joining → O(n)

**Overall:** O(n)

### Space Complexity

O(n)

because we store every word inside a vector.

### Advantages

-   Easy to understand.
-   Good for beginners.
-   Demonstrates `string_view` and `trim()`.

### Disadvantages

-   Extra memory (`vector`).

------------------------------------------------------------------------

# Method 2 --- `stringstream` Only

## Idea

`stringstream >> word` automatically:

-   ignores leading spaces
-   ignores trailing spaces
-   treats multiple spaces as one separator

Therefore `trim()` is unnecessary.

### Algorithm

``` text
Input

↓

stringstream

↓

vector<string>

↓

reverse(vector)

↓

join
```

### Time Complexity

O(n)

### Space Complexity

O(n)

### Advantages

-   Shortest solution.
-   Clean and readable.
-   Most common interview solution.

### Disadvantages

Still needs a vector.

------------------------------------------------------------------------

# Method 3 --- Two Pointer / In-place (Optimal)

## Idea

Do everything directly on the string.

### Step 1

Trim leading and trailing spaces.

``` text
"   the   sky   "

↓

"the   sky"
```

------------------------------------------------------------------------

### Step 2

Remove multiple spaces.

Use two pointers.

-   `read` → reads characters.
-   `write` → writes characters back.

``` text
the_____sky______is

↓

the sky is
```

------------------------------------------------------------------------

### Step 3

Reverse the whole string.

``` text
the sky is blue

↓

eulb si yks eht
```

------------------------------------------------------------------------

### Step 4

Reverse every word.

``` text
eulb

↓

blue
```

``` text
si

↓

is
```

``` text
yks

↓

sky
```

``` text
eht

↓

the
```

Final answer

``` text
blue is sky the
```

### Time Complexity

Every character is visited a constant number of times.

**Overall:** O(n)

### Space Complexity

**O(1)** extra space (when implemented fully in-place).

### Advantages

-   Optimal solution.
-   No vector.
-   No stringstream.
-   Excellent interview solution.

### Disadvantages

-   Harder to write.
-   More pointer manipulation.

------------------------------------------------------------------------

# Comparison

  Method     Time   Extra Space   Difficulty
  ---------- ------ ------------- ------------
  Method 1   O(n)   O(n)          Easy
  Method 2   O(n)   O(n)          Very Easy
  Method 3   O(n)   O(1)          Medium

------------------------------------------------------------------------

# Which Method Should You Use?

## Beginner

Use **Method 1**.

You will learn:

-   `string_view`
-   `trim()`
-   `stringstream`
-   `vector`

------------------------------------------------------------------------

## Coding Interviews

Use **Method 2** if the interviewer only asks for a working solution.

It is short, readable, and commonly accepted.

------------------------------------------------------------------------

## Best Interview / FAANG / Competitive Programming

Use **Method 3**.

Why?

-   Optimal space complexity.
-   Shows understanding of two pointers.
-   Demonstrates in-place string manipulation.
-   No unnecessary containers.

Many interviewers appreciate candidates who can explain Method 2 first
and then optimize to Method 3 when asked about reducing extra space.

------------------------------------------------------------------------

# Interview Strategy

A strong interview flow is:

1.  Explain the straightforward solution using `stringstream` (Method
    2).
2.  Analyze it:
    -   Time = O(n)
    -   Space = O(n)
3.  Ask: \> "Would you like me to optimize the extra space?"
4.  Implement Method 3.

This demonstrates both problem-solving and optimization skills.

------------------------------------------------------------------------

# Key Takeaways

-   `stringstream >> word` automatically ignores multiple spaces.
-   `trim()` is useful to learn but not required with `stringstream`.
-   Method 2 is the cleanest practical solution.
-   Method 3 is the optimal solution and the best choice when
    interviewers ask for **O(1) extra space**.
