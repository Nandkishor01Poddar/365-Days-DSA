#include <iostream>
#include <utility>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Insert node at end of circular linked list
Node *insert(Node *head, int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Split circular linked list
pair<Node *, Node *> splitList(Node *head)
{
    if (head == NULL || head->next == head)
    {
        return {head, NULL};
    }

    Node *slow = head;
    Node *fast = head;

    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head)
    {
        fast = fast->next;
    }

    Node *head1 = head;
    Node *head2 = slow->next;

    fast->next = head2;
    slow->next = head1;

    return {head1, head2};
}

// Print circular linked list
void printList(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty List\n";
        return;
    }

    Node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main()
{
    Node *head = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        head = insert(head, value);
    }

    cout << "\nOriginal Circular Linked List:\n";
    printList(head);

    pair<Node *, Node *> ans = splitList(head);

    cout << "\nFirst Circular List:\n";
    printList(ans.first);

    cout << "\nSecond Circular List:\n";
    printList(ans.second);

    return 0;
}