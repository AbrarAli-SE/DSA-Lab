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

void deleteFromPosition(Node **head, int position)
{
    if (*head == NULL || position <= 0)
        return;

    Node *temp = *head;

    for (int i = 1; temp != NULL && i < position; i++)
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
        *head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " -> ";
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
    insertAtEnd(&head, 40);

    cout << "Before Delete from Custom Position: ";
    printList(head);

    int position = 2; // Example: Deleting the node at position 2
    deleteFromPosition(&head, position);

    cout << "\nAfter Delete from Custom Position: ";
    printList(head);
    return 0;
}
