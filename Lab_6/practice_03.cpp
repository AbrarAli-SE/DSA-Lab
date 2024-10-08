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
    if(head==NULL)
    insertValueAtHead(head,val);
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
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{

    int size, value;
    Node *head = NULL;
    cout << "How much value that you want to store in list : ";
    cin >> size;
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> value;
        insertValueAtTail(head, value);
    }
    display(head);
}