# Sort Two Colors (0s and 1s) - Complete Explanation

## Problem Statement
Given an array containing only **0** and **1**, sort the array so that all `0`s come before all `1`s.

---

# Approach 1: Brute Force

## Idea
Create a new array (or count the number of `0`s and `1`s), then overwrite the original array.

### Method 1: Counting
1. Count the number of `0`s.
2. Fill the first `count0` positions with `0`.
3. Fill the remaining positions with `1`.

### C++ Code
```cpp
void sortTwoColor(vector<int> &nums){
    int count0 = 0;

    for(int x : nums){
        if(x == 0)
            count0++;
    }

    for(int i = 0; i < count0; i++)
        nums[i] = 0;

    for(int i = count0; i < nums.size(); i++)
        nums[i] = 1;
}
```

### Complexity
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)` (counting method)

> If you create another vector and copy elements into it, then:
> - **Time Complexity:** `O(n)`
> - **Space Complexity:** `O(n)`

---

# Approach 2: Best Approach (Two Pointer)

## Idea

Use two pointers:
- `st` starts from the beginning.
- `end` starts from the end.

Rules:
- If `nums[st] == 0`, simply move `st`.
- Otherwise (`nums[st] == 1`), swap it with `nums[end]` and decrease `end`.
- Do **not** increment `st` after swapping because the new element at `st` has not been checked.

### Code

```cpp
void sortTwoColor(vector<int> &nums){
    int st = 0;
    int end = nums.size() - 1;

    while(st <= end){
        if(nums[st] == 0){
            st++;
        }
        else{
            swap(nums[st], nums[end]);
            end--;
        }
    }
}
```

---

## Dry Run

Input

```
1 0 1 0 1 0
```

| Step | Array | st | end | Action |
|------|-------|----|-----|--------|
|1|1 0 1 0 1 0|0|5|Swap|
|2|0 0 1 0 1 1|0|4|st++|
|3|0 0 1 0 1 1|1|4|st++|
|4|0 0 1 0 1 1|2|4|Swap|
|5|0 0 1 0 1 1|2|3|Swap|
|6|0 0 0 1 1 1|2|2|st++|

Final Output

```
0 0 0 1 1 1
```

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Why don't we increment `st` after swapping?

Example:

```
1 1 0
```

Swap first and last:

```
0 1 1
```

The element that comes to index `st` is new and has not been checked.

If we immediately do `st++`, we may skip processing that element.

Therefore:
- After finding `0` → `st++`
- After swapping `1` → only `end--`

---

# Comparison

| Approach | Time | Space | In-place |
|----------|------|-------|---------|
| Counting (Brute Force) | O(n) | O(1) | Yes |
| Extra Array | O(n) | O(n) | No |
| Two Pointer | O(n) | O(1) | Yes |

---

# Interview Preparation

### Which approach should you tell first?

1. Explain the **Brute Force** approach first.
2. Mention its time and space complexity.
3. Then optimize it using the **Two Pointer** approach.

This shows the interviewer that you can:
- Think of a simple solution.
- Analyze complexity.
- Optimize the solution.

### Best Choice in an Interview

✅ Start with **Brute Force**.

✅ Then present the **Two Pointer** solution as the optimized approach.

This is the approach most interviewers expect because it demonstrates problem-solving and optimization skills.

---

# Key Takeaways

- Brute Force is easy to understand.
- Two Pointer is the optimal solution.
- Time Complexity of the optimal solution is **O(n)**.
- Space Complexity is **O(1)**.
- This algorithm works only for arrays containing **0** and **1**.
- For arrays containing **0, 1, and 2**, use the **Dutch National Flag Algorithm**.
