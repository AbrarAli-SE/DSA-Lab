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

// Function to find the middle node
Node *findMiddleNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // Slow pointer will be at the middle node
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

    // Insert some nodes
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "Doubly Linked List: ";
    display(head);

    // Find and display the middle node
    Node *middle = findMiddleNode(head);
    if (middle != NULL)
    {
        cout << "Middle node value: " << middle->value << endl;
    }
    else
    {
        cout << "The list is empty.\n";
    }

    return 0;
}
