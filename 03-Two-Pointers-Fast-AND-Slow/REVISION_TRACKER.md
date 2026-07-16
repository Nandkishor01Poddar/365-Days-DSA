# 🔄 Fast & Slow Pointers - Revision Tracker

> Pattern Goal: Master the Fast & Slow Pointer (Floyd's Cycle Detection) technique and know when to apply it in interviews.

---

# 📚 Pattern Overview

## Core Concepts

- Fast Pointer
- Slow Pointer
- Floyd's Cycle Detection Algorithm
- Finding the Middle Node
- Detecting Cycles
- Linked List Traversal
- Space Optimization

---

# 📋 Problems

| Day | LC | Problem | Difficulty | Solved | R1 | R2 | R3 | R4 | R5 | Confidence | Interview Ready |
|-----|----|---------|------------|:------:|:--:|:--:|:--:|:--:|:--:|:----------:|:---------------:|
| 10 | 202 | Happy Number | Easy | ✅ | ⬜ | ⬜ | ⬜ | ⬜ | ⬜ | ⭐⭐⭐☆☆ | ⬜ |
| 10 | 876 | Middle of the Linked List | Easy | ✅ | ⬜ | ⬜ | ⬜ | ⬜ | ⬜ | ⭐⭐⭐☆☆ | ⬜ |

---

# 🧠 Pattern Checklist

Before moving to the next pattern, I should be able to answer:

- [ ] Why do Fast & Slow pointers work?
- [ ] When should I use this technique?
- [ ] How does Floyd's Cycle Detection Algorithm work?
- [ ] How can I find the middle node in one traversal?
- [ ] Can I explain the time complexity?
- [ ] Can I explain the space complexity?
- [ ] Can I code both problems without looking?

---

# 🎯 Common Interview Questions

- What is Floyd's Cycle Detection Algorithm?
- Why does moving one pointer twice as fast detect a cycle?
- Why does the slow pointer stop at the middle?
- What are the advantages over using extra memory?
- When would you prefer HashSet instead?

---

# 📖 Revision Notes

### Happy Number (LC 202)

Key Idea:

- Transform the number into the sum of the squares of its digits.
- If a cycle exists, Fast & Slow pointers will eventually meet.
- If the number becomes 1, it is a Happy Number.

Pattern:
- Floyd's Cycle Detection

---

### Middle of the Linked List (LC 876)

Key Idea:

- Move `slow` by one step.
- Move `fast` by two steps.
- When `fast` reaches the end, `slow` is at the middle.

Pattern:
- Fast & Slow Pointer

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

- [ ] I can solve LC 202 without looking.
- [ ] I can solve LC 876 without looking.
- [ ] I can explain Floyd's Cycle Detection.
- [ ] I can recognize Fast & Slow Pointer problems quickly.
- [ ] I can teach this pattern to someone else.

---

## 🚀 Pattern Status

```
Problems Solved : 2 / 2

Revision Progress : 0 / 10

Confidence : ⭐⭐⭐☆☆

Status : 🟡 Learning
```

---

> **"Don't memorize the solution. Memorize the pattern."**