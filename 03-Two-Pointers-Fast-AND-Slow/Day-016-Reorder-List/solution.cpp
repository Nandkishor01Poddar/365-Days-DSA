#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Function to reorder the linked list
void reorderList(ListNode* head) {
    // If list has 0 or 1 node, no need to reorder
    if (head == nullptr || head->next == nullptr)
        return;

    // -----------------------------
    // Step 1: Find the middle node
    // -----------------------------
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // -----------------------------
    // Step 2: Reverse second half
    // -----------------------------
    ListNode* second = slow->next;
    slow->next = nullptr;   // Break the list into two halves

    ListNode* prev = nullptr;
    ListNode* curr = second;

    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    second = prev; // New head of reversed second half

    // -----------------------------
    // Step 3: Merge two halves
    // -----------------------------
    ListNode* first = head;

    while (second != nullptr) {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

// Function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0)
        return 0;

    // Create linked list dynamically
    cout << "Enter node values: ";

    int value;
    cin >> value;

    ListNode* head = new ListNode(value);
    ListNode* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> value;
        tail->next = new ListNode(value);
        tail = tail->next;
    }

    cout << "\nOriginal List:\n";
    printList(head);

    reorderList(head);

    cout << "\nReordered List:\n";
    printList(head);

    return 0;
}