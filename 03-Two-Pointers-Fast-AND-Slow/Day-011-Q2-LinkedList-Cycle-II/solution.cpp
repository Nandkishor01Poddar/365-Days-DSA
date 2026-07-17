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

// Function to detect the starting node of the cycle
ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Step 1: Detect if cycle exists
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // No cycle
    if (fast == nullptr || fast->next == nullptr)
        return nullptr;

    // Step 2: Find starting node of the cycle
    ListNode* n1 = head;
    ListNode* n2 = slow;

    while (n1 != n2) {
        n1 = n1->next;
        n2 = n2->next;
    }

    return n1;
}

int main() {
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) {
        cout << "Linked List is empty.\n";
        return 0;
    }

    vector<ListNode*> nodes;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nodes.push_back(new ListNode(x));
    }

    // Connect nodes
    for (int i = 0; i < n - 1; i++)
        nodes[i]->next = nodes[i + 1];

    cout << "Enter cycle position (-1 for no cycle): ";
    int pos;
    cin >> pos;

    if (pos >= 0 && pos < n)
        nodes[n - 1]->next = nodes[pos];

    ListNode* head = nodes[0];

    ListNode* ans = detectCycle(head);

    if (ans == nullptr)
        cout << "No Cycle Found\n";
    else
        cout << "Cycle starts at node with value: " << ans->data << endl;

    return 0;
}