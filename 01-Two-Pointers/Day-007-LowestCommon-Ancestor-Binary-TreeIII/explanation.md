# source(NeetCode) :- Lowest Common Ancestor (LCA) with Parent Pointer

In this problem, every node contains a pointer to its **parent**.

The goal is to find the **Lowest Common Ancestor (LCA)** of two given nodes.

The **Lowest Common Ancestor (LCA)** is the **lowest (deepest) node** that is an ancestor of both nodes.

Example:

```
          3
         / \
        5   1
       / \
      6   2
```

For

```
p = 6
q = 2
```

Answer:

```
LCA = 5
```

---

# Method 1 : Brute Force

## Intuition

The first thing that comes into our mind is:

- Find every ancestor of node **p**.
- Compare each ancestor with every ancestor of **q**.
- The first matching ancestor is the answer.

Since every node has a parent pointer, we can move upward until we reach the root.

---

## How to Think

Suppose

```
p = 6
q = 2
```

Ancestors of 6

```
6 → 5 → 3
```

Ancestors of 2

```
2 → 5 → 3
```

Now compare

```
6 with 2
6 with 5
6 with 3

5 with 2
5 with 5   ← Match Found
```

Hence,

```
LCA = 5
```

---

## Algorithm

1. Start from node p.
2. For every ancestor of p
   - Traverse every ancestor of q.
3. If both nodes are same, return it.
4. Otherwise continue.
5. If nothing matches return NULL.

---

## Code

```cpp
Node* m1(Node* p, Node* q)
{
    while(p != nullptr)
    {
        Node* temp = q;

        while(temp != nullptr)
        {
            if(p == temp)
                return p;

            temp = temp->parent;
        }

        p = p->parent;
    }

    return nullptr;
}
```

---

## Time Complexity

Let

- h1 = height of p from root
- h2 = height of q from root

For every ancestor of p we traverse all ancestors of q.

```
TC = O(h1 × h2)
```

Worst Case

```
O(n²)
```

(for a skewed tree)

---

## Space Complexity

Only pointers are used.

```
SC = O(1)
```

---

## Interview Discussion

### Advantages

- Very easy to think.
- No extra memory.

### Disadvantages

- Very slow.
- Repeated comparisons.
- Rarely accepted for optimized interview solutions.

---

# Method 2 : Hashing (unordered_set)

## Intuition

Instead of comparing ancestors repeatedly,

Store all ancestors of one node inside a Hash Set.

Then while traversing the second node,

simply check whether it already exists in the Hash Set.

Since Hash Set lookup is O(1),

the solution becomes much faster.

---

## How to Think

For

```
p = 6
q = 2
```

Store ancestors of 6

```
6
5
3
```

Hash Set

```
{
6,
5,
3
}
```

Now move upward from node 2

```
2
```

Present?

```
No
```

Move upward

```
5
```

Present?

```
Yes
```

Answer

```
LCA = 5
```

---

## Algorithm

1. Create Hash Set.
2. Store every ancestor of p.
3. Traverse ancestors of q.
4. If current ancestor exists inside Hash Set return it.
5. Otherwise move upward.

---

## Code

```cpp
Node* m2(Node* p, Node* q)
{
    unordered_set<Node*> visited;

    while(p != nullptr)
    {
        visited.insert(p);
        p = p->parent;
    }

    while(q != nullptr)
    {
        if(visited.count(q))
            return q;

        q = q->parent;
    }

    return nullptr;
}
```

---

## Time Complexity

Traversing p

```
O(h1)
```

Traversing q

```
O(h2)
```

Overall

```
TC = O(h1 + h2)
```

Worst Case

```
O(n)
```

---

## Space Complexity

Hash Set stores ancestors of p.

```
SC = O(h1)
```

Worst Case

```
O(n)
```

---

## Interview Discussion

### Advantages

- Much faster than brute force.
- Easy to code.
- Very popular interview solution.

### Disadvantages

- Requires extra memory.

---

# Method 3 : Two Pointer (Optimal)

## Intuition

This is exactly the same idea as

**Intersection of Two Linked Lists.**

Suppose

```
p = 6
q = 2
```

Pointer A starts from

```
6
```

Pointer B starts from

```
2
```

Whenever a pointer reaches NULL,

start it from the other node.

Eventually both pointers travel exactly the same total distance.

They will meet at the Lowest Common Ancestor.

---

## How to Think

Imagine

```
A path

6 → 5 → 3 → NULL → 2 → 5 → 3
```

Pointer B

```
2 → 5 → 3 → NULL → 6 → 5 → 3
```

Notice both pointers travel equal distance.

Eventually both become

```
5
```

So

```
LCA = 5
```

---

## Why does it work?

Suppose

Distance from p to LCA = x

Distance from q to LCA = y

Common path to root = z

Pointer A travels

```
x + z + y
```

Pointer B travels

```
y + z + x
```

Both travel exactly equal distance.

Hence they meet at the LCA.

---

## Algorithm

1. Create two pointers.
2. One starts from p.
3. One starts from q.
4. Move upward.
5. If pointer becomes NULL
   move it to the other node.
6. Continue until both pointers become equal.

---

## Code

```cpp
Node* m3(Node* p, Node* q)
{
    Node* a = p;
    Node* b = q;

    while(a != b)
    {
        a = (a == nullptr) ? q : a->parent;
        b = (b == nullptr) ? p : b->parent;
    }

    return a;
}
```

---

## Time Complexity

Each pointer visits every path at most twice.

```
TC = O(h1 + h2)
```

Worst Case

```
O(n)
```

---

## Space Complexity

No extra data structure.

```
SC = O(1)
```

---

## Interview Discussion

### Advantages

- Best solution.
- No extra memory.
- Elegant.
- Frequently asked in FAANG interviews.

### Disadvantages

- Slightly difficult to derive during interview.
- Requires understanding of linked list intersection logic.

---

# Comparison Table

| Method | Approach | Time | Space | Interview Rating |
|---------|----------|------|--------|------------------|
| **m1** | Brute Force | O(h1 × h2) | O(1) | ⭐⭐ |
| **m2** | Hashing | O(h1 + h2) | O(h1) | ⭐⭐⭐⭐ |
| **m3** | Two Pointer | O(h1 + h2) | O(1) | ⭐⭐⭐⭐⭐ |

---

# Which One Should You Tell in Interviews?

### Step 1

Explain the brute-force idea first.

It shows the interviewer that you can derive a straightforward solution.

---

### Step 2

Improve it using a Hash Set.

Mention that repeated comparisons can be avoided by storing ancestors.

---

### Step 3

Finally present the optimal Two Pointer approach.

Explain that it is identical to the **Intersection of Two Linked Lists** technique.

This progression (Brute Force → Hashing → Optimal) demonstrates problem-solving ability and optimization skills, which interviewers value highly.