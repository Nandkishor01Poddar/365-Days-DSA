#include <iostream>
using namespace std;

/*
=========================================================
Problem:
Given the head of a singly linked list, return the middle
node of the linked list.

If there are two middle nodes, return the second middle.

Example 1:
Input:
1 2 3 4 5

Output:
3

Example 2:
Input:
1 2 3 4 5 6

Output:
4
=========================================================
*/

//---------------------------------------------------------
// Definition of Linked List Node
//---------------------------------------------------------
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

//---------------------------------------------------------
// Insert node at the end of linked list
//---------------------------------------------------------
void insertNode(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    ListNode *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

//---------------------------------------------------------
// Print Linked List
//---------------------------------------------------------
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

/*
=========================================================
Brute Force Approach

Idea:
1. Count total nodes.
2. Traverse again till count/2.
3. Return that node.

Time Complexity:
O(N) + O(N) = O(N)

Space Complexity:
O(1)
=========================================================
*/

ListNode *middleNodeBrute(ListNode *head)
{
    int count = 0;

    ListNode *temp = head;

    // Count total nodes
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    temp = head;

    // Move to middle node
    for (int i = 0; i < count / 2; i++)
    {
        temp = temp->next;
    }

    return temp;
}

/*
=========================================================
Optimal Approach (Slow & Fast Pointer)

Idea:

Slow Pointer -> moves one step

Fast Pointer -> moves two steps

When fast reaches the end,
slow will be at the middle.

Time Complexity:
O(N)

Space Complexity:
O(1)
=========================================================
*/

ListNode *middleNodeOptimal(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;          // Move 1 step
        fast = fast->next->next;    // Move 2 steps
    }

    return slow;
}

//---------------------------------------------------------
// Main Function
//---------------------------------------------------------
int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    ListNode *head = nullptr;

    cout << "Enter node values: ";

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insertNode(head, value);
    }

    cout << "\nLinked List: ";
    printList(head);

    ListNode *middle1 = middleNodeBrute(head);
    ListNode *middle2 = middleNodeOptimal(head);

    cout << "\nMiddle Node (Brute Force): " << middle1->val << endl;
    cout << "Middle Node (Optimal): " << middle2->val << endl;

    return 0;
}