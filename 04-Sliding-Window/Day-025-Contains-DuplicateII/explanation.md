# LeetCode 219 - Contains Duplicate II

## Problem Statement

Given an integer array `nums` and an integer `k`, return `true` if there are two distinct indices `i` and `j` such that:

- `nums[i] == nums[j]`
- `|i - j| <= k`

Otherwise, return `false`.

---

# Approach 1: Brute Force

## Idea

For every element, check the next `k` elements to see if any duplicate exists.

### Algorithm

1. Iterate through every index `i`.
2. Check all indices from `i + 1` to `min(i + k, n - 1)`.
3. If `nums[i] == nums[j]`, return `true`.
4. If no duplicate is found, return `false`.

### C++ Code

```cpp
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= min(i + k, n - 1); j++) {
            if (nums[i] == nums[j])
                return true;
        }
    }

    return false;
}
```

### Complexity

| Complexity | Value |
|------------|-------|
| Time | **O(n × k)** |
| Space | **O(1)** |

### Why It Is Not Optimal

- Repeatedly compares the same elements.
- Slow when `k` is large.
- May result in Time Limit Exceeded (TLE) for large inputs.

---

# Approach 2: Sliding Window + Hash Set (Optimal)

## Idea

Instead of comparing every nearby element, maintain a sliding window of the last `k` elements using a hash set.

If the current element already exists inside the window, we have found a duplicate within distance `k`.

### Algorithm

1. Create an empty `unordered_set`.
2. Traverse the array.
3. If the current element already exists in the set, return `true`.
4. Otherwise, insert it into the set.
5. If the window size becomes greater than `k`, remove the element leaving the window (`nums[i-k]`).
6. If traversal finishes, return `false`.

---

### Dry Run

```
nums = [1,2,3,1]
k = 3

Window = {}

i = 0
Insert 1
{1}

i = 1
Insert 2
{1,2}

i = 2
Insert 3
{1,2,3}

i = 3
1 already exists
Return true
```

---

### C++ Code

```cpp
bool containsNearbyDuplicate(vector<int>& nums, int k) {

    unordered_set<int> window;

    for (int i = 0; i < nums.size(); i++) {

        if (window.count(nums[i]))
            return true;

        window.insert(nums[i]);

        if (window.size() > k)
            window.erase(nums[i - k]);
    }

    return false;
}
```

---

## Complexity

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(k)** |

---

# Comparison

| Feature | Brute Force | Sliding Window |
|----------|-------------|----------------|
| Time Complexity | O(n × k) | O(n) |
| Space Complexity | O(1) | O(k) |
| Efficient for Large Input | ❌ No | ✅ Yes |
| Uses Extra Memory | ❌ No | ✅ Yes |
| Interview Preferred | ❌ Rarely | ✅ Yes |

---

# Why Sliding Window Works

The only elements that can form a valid answer with the current element are the previous **k** elements.

So instead of checking every possible pair, we keep only those `k` elements inside a hash set.

This reduces repeated comparisons and gives an **O(n)** solution.

---

# Interview Tips

### Tip 1
Whenever you see:
- "within k distance"
- "contiguous elements"
- "last k elements"

Think about **Sliding Window**.

---

### Tip 2
A **Hash Set** is useful when you only need to know whether an element exists.

A **Hash Map** is useful when you also need additional information like an index or frequency.

---

### Tip 3
Always ask yourself:

> "Can I avoid comparing the same elements multiple times?"

If the answer is yes, consider using a sliding window.

---

### Tip 4

For problems involving:
- duplicates
- substring
- subarray
- window size
- at most / at least k

Sliding Window is often one of the best approaches.

---

# Key Takeaways

- Brute Force is simple but inefficient.
- Sliding Window avoids unnecessary comparisons.
- Hash Set provides **O(1)** average lookup time.
- Overall complexity improves from **O(n × k)** to **O(n)**.
- This is the standard interview solution for LeetCode 219.