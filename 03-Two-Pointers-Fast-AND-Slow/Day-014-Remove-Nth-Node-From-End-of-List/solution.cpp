#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to remove the nth node from the end
ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create a dummy node to handle edge cases
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move fast pointer (n + 1) steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Node to be deleted
    ListNode* temp = slow->next;

    // Remove the node
    slow->next = slow->next->next;

    // Free memory
    delete temp;

    // Store the new head
    ListNode* newHead = dummy->next;

    // Delete dummy node
    delete dummy;

    return newHead;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int size;

    // Input size of linked list
    cout << "Enter number of nodes: ";
    cin >> size;

    if (size == 0) {
        cout << "Linked List is empty." << endl;
        return 0;
    }

    ListNode* head = NULL;
    ListNode* tail = NULL;

    cout << "Enter " << size << " elements: ";

    // Create linked list
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        ListNode* newNode = new ListNode(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int n;
    cout << "Enter n (node to remove from end): ";
    cin >> n;

    // Remove nth node from the end
    head = removeNthFromEnd(head, n);

    // Display updated linked list
    cout << "Linked List after deletion: ";
    printList(head);

    return 0;
}