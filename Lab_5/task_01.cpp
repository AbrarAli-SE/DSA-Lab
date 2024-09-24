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
void deletationAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
}

void deletationAtSpacificPoint(Node *&head, int pos)
{
    if (pos == 0)
    {
        deletationAtHead(head);
        return;
    }
    Node *previous = head;
    int currentPos = 0;
    while (currentPos != pos - 1)
    {
        previous = previous->next;
        currentPos++;
    }
    if (previous->next == NULL)
    {
        cout << "Position out of bounds!" << endl;
        return;
    }
    Node *temp = previous->next;
    previous->next = previous->next->next;
    cout << "Deletation Successful!" << endl;

    free(temp);
}
bool search(Node *head, int key) {
    Node *temp = head;
    
    while (temp != NULL) {
        if (temp->value == key)
            return true;
        temp = temp->next;
    }
    return false;
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

    int size = 5, value;
    Node *head = NULL;
    // insertaion
    cout << "Enter 5 values for Linked List: \n\n";
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> value;
        insertValueAtHead(head, value);
    }
    cout << "\nLinked List: ";
    display(head);

    // deletation
    cout<<""

    // searching
}