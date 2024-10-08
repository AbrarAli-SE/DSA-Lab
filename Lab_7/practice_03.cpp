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
    // Create a new node
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Otherwise, traverse to the last node
    Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    // Adjust pointers for the new node
    last->next = newNode;
    newNode->prev = last;
}
void deletefromEnd(Node **head)
{
    if (*head == NULL)
        return;
    Node *temp = *head;
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
        *head = NULL;
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

    cout << "Before Delete: ";
    printList(head);

    deletefromEnd(&head);

    cout << "\nAfter Delete: ";
    printList(head);
    return 0;
}