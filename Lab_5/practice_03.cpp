#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};
void insertValueAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
void insertValueAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << " -> " << temp->value;
        temp = temp->next;
    }
    cout << endl;
}
int main()
{

    Node *head = NULL;
    insertValueAtHead(head,0);
    insertValueAtTail(head, 5);
    insertValueAtTail(head, 15);
    insertValueAtTail(head, 25);
    insertValueAtTail(head, 35);

    display(head);
}