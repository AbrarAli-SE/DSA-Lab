#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node() {}
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};
void insert(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    free(temp);
    cout << endl;
}
void reverse(Node *&head)
{
    if (head == NULL)
        return;
    reverse(head->next);
    cout << head->value << " ";
}
int main()
{
    Node *head = NULL;
    int size,value;
    cout << "How much value that you want to store in list : ";
    cin >> size;
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> value;
        insert(head, value);
    }
    cout << "\nOrignal List : ";
    display(head);

    cout << "\nReverse List : ";
    reverse(head);
}
// done