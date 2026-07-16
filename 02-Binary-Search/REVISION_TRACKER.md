# 🔍 Binary Search - Revision Tracker

> **Pattern Goal:** Master Binary Search and recognize when to apply it efficiently in coding interviews.

---

# 📚 Pattern Overview

## Core Concepts

- Binary Search
- Search Space Reduction
- Lower Bound
- Upper Bound
- First Occurrence
- Last Occurrence
- Search Insert Position
- Boundary Conditions

---

# 📋 Problems

| Day | LC | Problem | Difficulty | Solved | R1 | R2 | R3 | R4 | R5 | Confidence | Interview Ready |
|-----|----|---------|------------|:------:|:--:|:--:|:--:|:--:|:--:|:----------:|:---------------:|
| 9 | 704 | Binary Search | Easy | ✅ | ⬜ | ⬜ | ⬜ | ⬜ | ⬜ | ⭐⭐⭐☆☆ | ⬜ |
| 9 | 34 | Find First and Last Position of Element in Sorted Array | Medium | ✅ | ⬜ | ⬜ | ⬜ | ⬜ | ⬜ | ⭐⭐⭐☆☆ | ⬜ |
| 9 | 35 | Search Insert Position | Easy | ✅ | ⬜ | ⬜ | ⬜ | ⬜ | ⬜ | ⭐⭐⭐☆☆ | ⬜ |

---

# 🧠 Pattern Checklist

Before moving to the next Binary Search problems, I should be able to answer:

- [ ] What conditions are required to apply Binary Search?
- [ ] Why is Binary Search O(log n)?
- [ ] How do I calculate the middle index safely?
- [ ] How do I find the first occurrence of an element?
- [ ] How do I find the last occurrence of an element?
- [ ] How do I find the insertion position of an element?
- [ ] Can I solve all three problems without looking?

---

# 🎯 Common Interview Questions

- When can Binary Search be applied?
- Why do we calculate `mid = left + (right - left) / 2`?
- How do you avoid integer overflow?
- How do you modify Binary Search to find the first occurrence?
- How do you modify Binary Search to find the last occurrence?
- What is the difference between Lower Bound and Upper Bound?
- When should Binary Search not be used?

---

# 📖 Revision Notes

## LC 704 — Binary Search

### Key Idea

- Search in a sorted array.
- Compare the middle element with the target.
- Eliminate half of the search space after every comparison.

Pattern:
- Classic Binary Search

Complexity:
- Time: **O(log n)**
- Space: **O(1)**

---

## LC 34 — Find First and Last Position of Element in Sorted Array

### Key Idea

- Perform Binary Search twice.
- First search finds the left boundary.
- Second search finds the right boundary.

Pattern:
- Modified Binary Search

Complexity:
- Time: **O(log n)**
- Space: **O(1)**

---

## LC 35 — Search Insert Position

### Key Idea

- Binary Search can also determine where an element should be inserted.
- If the target isn't found, return the current left pointer.

Pattern:
- Lower Bound

Complexity:
- Time: **O(log n)**
- Space: **O(1)**

---

# ⚠ Common Mistakes

- Forgetting the array must be sorted.
- Using `(left + right) / 2` instead of the safer midpoint calculation.
- Incorrectly updating `left` and `right`.
- Infinite loops caused by wrong conditions.
- Missing edge cases when the target doesn't exist.

---

# 📅 Revision History

| Revision | Date | Status |
|----------|------|--------|
| Revision 1 | - | ⬜ |
| Revision 2 | - | ⬜ |
| Revision 3 | - | ⬜ |
| Revision 4 | - | ⬜ |
| Revision 5 | - | ⬜ |

---

# ⭐ Mastery Checklist

Mark this pattern as mastered only when:

- [ ] I can write Binary Search from memory.
- [ ] I can explain why Binary Search works.
- [ ] I can solve LC 704 without looking.
- [ ] I can solve LC 34 without looking.
- [ ] I can solve LC 35 without looking.
- [ ] I understand Lower Bound and Upper Bound.
- [ ] I can explain all edge cases.
- [ ] I can teach this pattern to someone else.

---

# 📈 Pattern Progress

```
Problems Solved     : 3 / 3

Revision Progress   : 0 / 15

Confidence          : ⭐⭐⭐☆☆

Interview Ready     : ⬜

Pattern Status      : 🟡 Learning
```

---

# 🚀 Next Binary Search Problems

- [ ] LC 69 — Sqrt(x)
- [ ] LC 367 — Valid Perfect Square
- [ ] LC 33 — Search in Rotated Sorted Array
- [ ] LC 153 — Find Minimum in Rotated Sorted Array
- [ ] LC 162 — Find Peak Element
- [ ] LC 875 — Koko Eating Bananas
- [ ] LC 1011 — Capacity To Ship Packages Within D Days

---

> **"Binary Search isn't just about finding an element—it's about recognizing any problem where the answer lies in a searchable, ordered space."**