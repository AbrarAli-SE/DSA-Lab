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

// Function to insert at a specific position with edge case handling
void insertAtPosition(Node *&head, int val, int pos)
{
    if (pos < 1)
    {
        cout << "Invalid position!\n";
        return;
    }

    Node *newNode = new Node(val);

    // Insert at the beginning
    if (pos == 1)
    {
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    Node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    // If the position is greater than the list length
    if (temp == NULL)
    {
        cout << "Position is out of bounds, inserting at the end.\n";
        insertAtEnd(head, val);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Function to delete from the beginning
void deleteFromBeginning(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty, nothing to delete.\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    delete temp;
}

// Function to delete from the end
void deleteFromEnd(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty, nothing to delete.\n";
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }
    delete temp;
}

// Function to delete all nodes one by one
void deleteAllNodes(Node *&head)
{
    while (head != NULL)
    {
        deleteFromBeginning(head);
    }
    cout << "All nodes deleted.\n";
}

// Function to display the list
void display(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = NULL;

    // Edge Case 1: Deleting from an empty list
    cout << "Attempt to delete from an empty list:\n";
    deleteFromBeginning(head);
    deleteFromEnd(head);

    // Insert some nodes
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "\nList after insertion: ";
    display(head);

    // Edge Case 2: Inserting at a position greater than the length of the list
    cout << "\nAttempt to insert at position 10 (greater than the list length):\n";
    insertAtPosition(head, 100, 10);
    display(head);

    // Edge Case 3: Deleting all nodes one by one and further deletion attempts
    cout << "\nDeleting all nodes one by one:\n";
    deleteAllNodes(head);
    display(head);

    cout << "\nAttempt to delete after all nodes are deleted:\n";
    deleteFromBeginning(head);
    deleteFromEnd(head);

    return 0;
}
