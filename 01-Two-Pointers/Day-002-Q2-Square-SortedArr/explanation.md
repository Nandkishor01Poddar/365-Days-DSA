# LeetCode 977 – Squares of a Sorted Array

## Problem Statement

Given an integer array `nums` sorted in **non-decreasing order**, return an array of the squares of each number, also sorted in **non-decreasing order**.

---

# Method 1: Two Pointer (Optimal)

## Idea

Although the array is already sorted, squaring negative numbers can change their order.

For example:

```text
[-7, -3, 2, 3, 11]
```

After squaring:

```text
[49, 9, 4, 9, 121]
```

The squared values are **not** sorted.

To solve this efficiently:

* Place one pointer (`left`) at the beginning.
* Place another pointer (`right`) at the end.
* Compare the absolute values of both elements.
* The larger absolute value will produce the larger square.
* Place that square at the end of the result array.
* Move the corresponding pointer inward.
* Repeat until all elements are processed.

This avoids sorting after squaring.

---

## Algorithm

1. Create a result array of the same size.
2. Initialize:

   * `left = 0`
   * `right = n - 1`
   * `index = n - 1`
3. While `left <= right`:

   * Compare `abs(nums[left])` and `abs(nums[right])`.
   * Place the larger square at `result[index]`.
   * Move the corresponding pointer.
   * Decrement `index`.
4. Return the result array.

---

## Time Complexity

**O(n)**

Each element is visited exactly once.

---

## Space Complexity

**O(n)**

An additional array of size `n` is used to store the sorted squares.

---

## Advantages

* Linear time solution.
* No extra sorting required.
* Efficient for large inputs.
* Standard interview approach.
* Makes good use of the sorted property of the input array.

---

# Method 2: Square Then Sort

## Idea

A straightforward approach is:

1. Square every element.
2. Sort the resulting array.

Although simple, sorting increases the overall time complexity.

---

## Algorithm

1. Traverse the array.
2. Replace every element with its square.
3. Sort the array.
4. Return the sorted array.

---

## Time Complexity

**O(n log n)**

* Squaring all elements → **O(n)**
* Sorting the array → **O(n log n)**

Overall complexity:

**O(n log n)**

---

## Space Complexity

**O(1)** *(Ignoring the space used internally by the sorting algorithm.)*

If a separate result array is created, the space complexity becomes **O(n)**.

---

## Advantages

* Very easy to understand.
* Requires minimal logic.
* Good for beginners.

---

# Comparison

| Feature             | Method 1 | Method 2    |
| ------------------- | -------- | ----------- |
| Time Complexity     | O(n)     | O(n log n)  |
| Space Complexity    | O(n)     | O(1) / O(n) |
| Uses Sorting        | ❌        | ✅           |
| Interview Preferred | ✅        | ❌           |
| Uses Two Pointers   | ✅        | ❌           |
| Easy to Implement   | Moderate | ✅           |

---

# Best Choice for Interviews

✅ **Method 1 (Two Pointer)** is the preferred interview solution because:

* Achieves **O(n)** time complexity.
* Efficiently utilizes the sorted nature of the input array.
* Avoids unnecessary sorting.
* Demonstrates understanding of the Two Pointer technique.
* Commonly expected by interviewers.

---

# STL Functions Used

### `abs(x)`

Returns the absolute value of a number.

Example:

```cpp
abs(-7);   // 7
abs(5);    // 5
```

---

### `sort(begin, end)`

Sorts the elements in ascending order.

Example:

```cpp
sort(nums.begin(), nums.end());
```

---

# Example

### Input

```text
[-4, -1, 0, 3, 10]
```

### Output

```text
[0, 1, 9, 16, 100]
```

---

# Dry Run

Initial Array

```text
[-4, -1, 0, 3, 10]

L                    R
```

Compare:

* `|-4| = 4`
* `|10| = 10`

Since `10` is larger:

```text
Result:

[_, _, _, _, 100]
```

Move `right`.

Now compare:

* `|-4| = 4`
* `|3| = 3`

```text
Result:

[_, _, _, 16, 100]
```

Move `left`.

Continue:

```text
Result:

[_, _, 9, 16, 100]
```

```text
Result:

[_, 1, 9, 16, 100]
```

```text
Result:

[0, 1, 9, 16, 100]
```

Final Answer:

```text
[0, 1, 9, 16, 100]
```

---

# Key Learning

This problem teaches:

* Two Pointer technique
* Working with sorted arrays
* Absolute value comparison
* Greedy placement strategy
* Time and Space Complexity analysis
* STL functions (`abs()`, `sort()`)

---

# Final Recommendation

For **LeetCode 977 – Squares of a Sorted Array**:

* ✅ **Method 1 (Two Pointer)** → Best for interviews and the optimal solution with **O(n)** time complexity.
* ✅ **Method 2 (Square Then Sort)** → Simpler to understand but less efficient due to sorting.

Whenever possible, prefer the **Two Pointer** approach because it fully leverages the sorted property of the input array and achieves the optimal linear-time solution.
