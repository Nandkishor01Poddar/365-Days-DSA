# LeetCode 11 - Container With Most Water

## 🎯 Problem Statement

You are given an array `height[]`, where each element represents the
height of a vertical line.

Choose **two lines** such that together with the x-axis they form a
container that stores the **maximum amount of water**.

### Formula

``` text
Area = min(height[i], height[j]) × (j - i)
```

------------------------------------------------------------------------

# Approach 1: Brute Force

## 💡 Idea

-   Check every possible pair of lines.
-   Calculate the area for each pair.
-   Keep the maximum area.

## Algorithm

1.  Run two nested loops.
2.  Pick every pair `(i, j)` where `i < j`.
3.  Compute:
    -   Width = `j - i`
    -   Height = `min(height[i], height[j])`
    -   Area = `width × height`
4.  Update the maximum area.
5.  Return the answer.

### Time Complexity

-   **O(n²)**

### Space Complexity

-   **O(1)**

------------------------------------------------------------------------

# Approach 2: Two Pointer (Optimal)

## 💡 Idea

-   Place one pointer at the beginning (`left`).
-   Place another pointer at the end (`right`).
-   Compute the current area.
-   Move the pointer with the **smaller height**.
-   Continue until both pointers meet.

## 🤔 Why move the smaller pointer?

The area depends on: - Width - Smaller of the two heights

When we move a pointer: - Width always decreases. - The only chance to
increase the area is to find a taller minimum height.

If we move the taller pointer: - Width decreases. - Minimum height does
**not** increase.

Therefore:

``` cpp
if(height[left] < height[right])
    left++;
else
    right--;
```

### Time Complexity

-   **O(n)**

### Space Complexity

-   **O(1)**

------------------------------------------------------------------------

# Is Dynamic Programming Applicable?

**No.**

Dynamic Programming requires:

-   Overlapping subproblems
-   Optimal substructure

This problem does not have useful overlapping subproblems. A DP solution
would still examine almost all pairs:

-   **Time:** O(n²)
-   **Space:** O(n²)

So the Two Pointer approach remains the optimal solution.

------------------------------------------------------------------------

# Interview Discussion

### Q1. Why does the Two Pointer approach work?

The shorter line limits the current area. Moving the taller line only
reduces the width and cannot increase the limiting height.

### Q2. Why not move both pointers?

You would skip candidate pairs and might miss the optimal answer.

### Q3. Why can't we sort the array?

Sorting changes the original indices, but the width depends on:

``` text
j - i
```

Therefore sorting makes the calculation invalid.

### Q4. How should you explain it in an interview?

1.  Explain the brute-force solution.
2.  Mention its O(n²) complexity.
3.  Explain the key observation.
4.  Derive the Two Pointer solution.
5.  Mention the final complexity.

------------------------------------------------------------------------

# Complexity Summary

  Approach      Time    Space
  ------------- ------- -------
  Brute Force   O(n²)   O(1)
  Two Pointer   O(n)    O(1)

------------------------------------------------------------------------

# Common Mistakes

-   Using `max()` instead of `min()`.
-   Moving the taller pointer.
-   Forgetting to update the maximum area.
-   Sorting the array.

------------------------------------------------------------------------

# ✅ Revision Checkpoint

## Concept Check

-   [ ] Can I explain the problem without reading it?
-   [ ] Do I know why the formula uses `min()`?
-   [ ] Can I derive the brute-force solution?
-   [ ] Can I explain why brute force is O(n²)?

## Two Pointer Check

-   [ ] Why do we move the smaller pointer?
-   [ ] Why don't we move the taller pointer?
-   [ ] Why does width decrease every iteration?
-   [ ] Can I dry-run the algorithm on paper?

## Coding Check

-   [ ] Can I code the brute-force solution without help?
-   [ ] Can I code the two-pointer solution in under 5 minutes?
-   [ ] Do I remember `while(left < right)`?
-   [ ] Do I update the answer every iteration?

## Interview Check

-   [ ] Why is DP not suitable?
-   [ ] Why isn't sorting allowed?
-   [ ] Why is the shorter line the limiting factor?
-   [ ] Can I prove the two-pointer solution?
-   [ ] Do I know the TC & SC?

------------------------------------------------------------------------

# ⭐ Final Takeaway

**Expected Interview Solution**

-   **Pattern:** Two Pointers
-   **Time Complexity:** O(n)
-   **Space Complexity:** O(1)

Explain the brute-force approach first, then derive the optimized
solution. This shows strong problem-solving skills during interviews.


## 📖 Revision History
eg :- no revision any more right now
- [x] Revision 1 (15 Jul 2026)
- [ ] Revision 2
- [ ] Revision 3
- [ ] Revision 4
- [ ] Revision 5

Last Revised:
15 Jul 2026