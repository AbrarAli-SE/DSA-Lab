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

void insertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Delete a node by its value
void deleteByValue(Node *&head, int val)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;
    Node *prev = NULL;

    if (head->value == val)
    {
        if (head->next == head)
        {  
            delete head;
            head = NULL;
        }
        else
        {
            while (temp->next != head)
            { 
                temp = temp->next;
            }
            Node *toDelete = head;
            temp->next = head->next;
            head = head->next;
            delete toDelete;
        }
        return;
    }

    do
    {
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->value != val);

    if (temp->value == val)
    {
        prev->next = temp->next;
        delete temp;
    }
    else
    {
        cout << "Value not found in the list." << endl;
    }
}

void display(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->value << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD" << endl;
}

int main()
{
    Node *head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    display(head);

    deleteByValue(head, 20);
    display(head);

    deleteByValue(head, 50); // Trying to delete a non-existing value
    display(head);

    return 0;
}
