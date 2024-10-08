#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void insertAtEnd(Node **head, int newData)
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Function to insert a node at a custom position in the doubly linked list
void insertAtPosition(Node **head, int newData, int position)
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (position <= 0)
    {
        newNode->next = *head;
        if (*head != NULL)
        {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    Node *temp = *head;

    for (int i = 1; temp != NULL && i < position; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        insertAtEnd(head, newData);
        return;
    }

    newNode->prev = temp->prev;
    newNode->next = temp;

    if (temp->prev != NULL)
    {
        temp->prev->next = newNode;
    }
    temp->prev = newNode;
}

// Function to print the doubly linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " <-> ";
        node = node->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    cout << "Before Insert at Custom Position: ";
    printList(head);

    int newData = 25; // New data to insert
    int position = 2; // Example: Inserting the node at position 2
    insertAtPosition(&head, newData, position);

    cout << "\nAfter Insert at Custom Position: ";
    printList(head);


    return 0;
}
