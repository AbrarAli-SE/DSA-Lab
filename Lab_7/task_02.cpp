#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *prev;
    Node *next;

    Node(int val)
    {
        value = val;
        prev = NULL;
        next = NULL;
    }
};

// Function to insert at the end
void insertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to traverse forward
void traverseForward(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to traverse backward
void traverseBackward(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
        return;

    // Move to the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Traverse backward
    while (temp != NULL)
    {
        cout << temp->value << " -> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "Traversing Forward: ";
    traverseForward(head);

    cout << "Traversing Backward: ";
    traverseBackward(head);

    return 0;
}
