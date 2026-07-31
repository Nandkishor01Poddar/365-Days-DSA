#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Function to insert a node at the end of the linked list
void insertNode(ListNode*& head, int value) {

    // If list is empty
    if (head == nullptr) {
        head = new ListNode(value);
        return;
    }

    // Traverse to the last node
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Insert new node
    temp->next = new ListNode(value);
}

// Print linked list
void printList(ListNode* head) {

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

class Solution {

public:

    //-------------------------------------------------------
    // Method 1 : Store values in vector + Two Pointer
    // Time  : O(n)
    // Space : O(n)
    //-------------------------------------------------------

    int pairSumVector(ListNode* head) {

        vector<int> values;

        // Traverse linked list and store every value
        ListNode* current = head;

        while (current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }

        // Two pointers
        int left = 0;
        int right = values.size() - 1;

        int maximumSum = INT_MIN;

        while (left < right) {

            int twinSum = values[left] + values[right];

            maximumSum = max(maximumSum, twinSum);

            left++;
            right--;
        }

        return maximumSum;
    }

    //-------------------------------------------------------
    // Reverse Linked List
    //-------------------------------------------------------

    ListNode* reverse(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;

            curr = nextNode;
        }

        return prev;
    }

    //-------------------------------------------------------
    // Method 2 : Slow Fast Pointer + Reverse
    // Time  : O(n)
    // Space : O(1)
    //-------------------------------------------------------

    int pairSumOptimal(ListNode* head) {

        // Step 1 : Find middle

        ListNode* slow = head;
        ListNode* fast = head;

        /*
            Example (Even Length)

            5 -> 4 -> 2 -> 1

            Initially

            slow = 5
            fast = 5

            Iteration 1

            slow = 4
            fast = 2

            Iteration 2

            slow = 2
            fast = nullptr

            slow points to beginning of second half.
        */

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;

            fast = fast->next->next;
        }

        // Step 2 : Reverse second half

        ListNode* secondHalf = reverse(slow);

        // Step 3 : Compare first half and reversed second half

        ListNode* firstHalf = head;

        int maximumSum = INT_MIN;

        while (secondHalf != nullptr) {

            int twinSum = firstHalf->val + secondHalf->val;

            maximumSum = max(maximumSum, twinSum);

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return maximumSum;
    }
};

int main() {

    ListNode* head = nullptr;

    int n;

    cout << "Enter number of nodes (Even): ";
    cin >> n;

    cout << "Enter values:\n";

    for (int i = 0; i < n; i++) {

        int x;
        cin >> x;

        insertNode(head, x);
    }

    cout << "\nLinked List : ";
    printList(head);

    Solution obj;

    cout << "\nMaximum Twin Sum (Vector Method) : "
         << obj.pairSumVector(head);

    cout << "\nMaximum Twin Sum (Optimal Method): "
         << obj.pairSumOptimal(head);

    return 0;
}