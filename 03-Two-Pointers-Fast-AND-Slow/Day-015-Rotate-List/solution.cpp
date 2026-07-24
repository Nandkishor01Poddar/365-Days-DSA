#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int len = 1;
        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            len++;
        }

        k %= len;
        if (k == 0)
            return head;

        // Make circular
        tail->next = head;

        // Find new tail
        int steps = len - k - 1;
        ListNode* newTail = head;

        while (steps--) {
            newTail = newTail->next;
        }

        // New head
        ListNode* newHead = newTail->next;

        // Break circle
        newTail->next = nullptr;

        return newHead;
    }
};

// Create linked list
ListNode* createList(int n) {
    if (n == 0)
        return nullptr;

    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* curr = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        curr->next = new ListNode(x);
        curr = curr->next;
    }

    return head;
}

// Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter list elements: ";
    ListNode* head = createList(n);

    int k;
    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    head = obj.rotateRight(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}