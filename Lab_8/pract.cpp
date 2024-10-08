#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};
void inseartAtBeginning(Node **head, int newData)
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = (*head);

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}
void printreverse(Node *&head)
{
    if (head == NULL)
        return;
    printreverse(head->next);
    cout << head->data << " ";
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    inseartAtBeginning(&head, 10);
    inseartAtBeginning(&head, 20);
    inseartAtBeginning(&head, 30);

    cout << "Doubly Linked List: ";
    display(head);

    cout << "Reversed List: ";
    printreverse(head);

    return 0;
}