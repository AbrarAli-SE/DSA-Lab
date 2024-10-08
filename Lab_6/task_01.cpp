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

// Function to insert at the beginning
void insertAtBeginning(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}

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

// Function to insert at a specific position
void insertAtPosition(Node *&head, int val, int pos)
{
    if (pos == 1)
    {
        insertAtBeginning(head, val);
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Position out of bounds\n";
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
        return;
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
        return;
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

// Function to delete from a specific position
void deleteFromPosition(Node *&head, int pos)
{
    if (head == NULL || pos <= 0)
        return;
    Node *temp = head;
    for (int i = 1; temp != NULL && i < pos; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

// Function to display the list
void display(Node *head)
{
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

    // Test insertion
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtEnd(head, 30);
    insertAtPosition(head, 25, 3); // Insert at position 3
    cout << "After Insertion: ";
    display(head);

    // Test deletion from beginning
    deleteFromBeginning(head);
    cout << "After Deleting from Beginning: ";
    display(head);

    // Test deletion from end
    deleteFromEnd(head);
    cout << "After Deleting from End: ";
    display(head);

    // Test deletion from a specific position
    deleteFromPosition(head, 2); // Delete from position 2
    cout << "After Deleting from Position 2: ";
    display(head);

    return 0;
}