#include <iostream>
#include <vector>
using namespace std;

// Definition of ListNode
struct ListNode {
    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to detect cycle
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) {
        cout << "Empty list\n";
        return 0;
    }

    vector<ListNode*> nodes;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nodes.push_back(new ListNode(x));
    }

    // Connect nodes normally
    for (int i = 0; i < n - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    // Create cycle
    int pos;
    cout << "Enter position to create cycle (-1 for no cycle): ";
    cin >> pos;

    if (pos >= 0 && pos < n) {
        nodes[n - 1]->next = nodes[pos];
    }

    ListNode* head = nodes[0];

    if (hasCycle(head))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}