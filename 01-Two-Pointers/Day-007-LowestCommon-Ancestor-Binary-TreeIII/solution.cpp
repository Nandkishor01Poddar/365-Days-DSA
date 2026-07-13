#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

// Structure for each node
struct Node {
    int data;
    Node* parent;

    Node(int val) {
        data = val;
        parent = nullptr;
    }
};


//========================================================
// Method 1 : Brute Force
//========================================================
// Compare every ancestor of p with every ancestor of q.
// First common ancestor found is the LCA.
//
// Time Complexity : O(h1 * h2)
// Space Complexity: O(1)
//========================================================
Node* m1(Node* p, Node* q) {

    // Traverse all ancestors of p
    while (p != nullptr) {

        Node* temp = q;

        // Compare current ancestor of p
        // with every ancestor of q
        while (temp != nullptr) {

            if (p == temp)
                return p;

            temp = temp->parent;
        }

        p = p->parent;
    }

    return nullptr;
}


//========================================================
// Method 2 : Hashing (Using unordered_set)
//========================================================
// Store all ancestors of p in a hash set.
// Traverse ancestors of q.
// First node already present in the set is the LCA.
//
// Time Complexity : O(h1 + h2)
// Space Complexity: O(h1)
//========================================================
Node* m2(Node* p, Node* q) {

    unordered_set<Node*> visited;

    // Store all ancestors of p
    while (p != nullptr) {
        visited.insert(p);
        p = p->parent;
    }

    // Check ancestors of q
    while (q != nullptr) {

        if (visited.count(q))
            return q;

        q = q->parent;
    }

    return nullptr;
}


//========================================================
// Method 3 : Two Pointer Approach
//========================================================
// Similar to Intersection of Two Linked Lists.
//
// Pointer a starts from p.
// Pointer b starts from q.
//
// When a reaches NULL,
// move it to q.
//
// When b reaches NULL,
// move it to p.
//
// Eventually both pointers meet at LCA.
//
// Time Complexity : O(h1 + h2)
// Space Complexity: O(1)
//========================================================
Node* m3(Node* p, Node* q) {

    Node* a = p;
    Node* b = q;

    while (a != b) {

        if (a == nullptr)
            a = q;
        else
            a = a->parent;

        if (b == nullptr)
            b = p;
        else
            b = b->parent;
    }

    return a;
}


int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    unordered_map<int, Node*> mp;
    vector<int> nodes;

    // Create nodes
    for (int i = 1; i <= n; i++) {

        int val;

        cout << "Enter value of node " << i << ": ";
        cin >> val;

        nodes.push_back(val);

        mp[val] = new Node(val);
    }

    int rootVal;

    cout << "Enter root node value: ";
    cin >> rootVal;

    cout << "\nEnter parent of each node (-1 for root):\n";

    // Take parent information
    for (int nodeVal : nodes) {

        if (nodeVal == rootVal)
            continue;

        int parentVal;

        cout << "Parent of " << nodeVal << ": ";
        cin >> parentVal;

        mp[nodeVal]->parent = mp[parentVal];
    }

    int p, q;

    cout << "\nEnter first node: ";
    cin >> p;

    cout << "Enter second node: ";
    cin >> q;

    if (mp.find(p) == mp.end() || mp.find(q) == mp.end()) {

        cout << "Invalid Node Value";
        return 0;
    }

    Node* ans1 = m1(mp[p], mp[q]);
    Node* ans2 = m2(mp[p], mp[q]);
    Node* ans3 = m3(mp[p], mp[q]);

    cout << "\nBrute Force LCA : ";
    if (ans1)
        cout << ans1->data;
    else
        cout << "Not Found";

    cout << "\nHashing LCA     : ";
    if (ans2)
        cout << ans2->data;
    else
        cout << "Not Found";

    cout << "\nTwo Pointer LCA : ";
    if (ans3)
        cout << ans3->data;
    else
        cout << "Not Found";

    return 0;
}