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

// Insert a node at the head of the linked list
void insert(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Display the linked list
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to count the number of nodes in the linked list
int countNode(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    free(temp);
    return count;
}

// Function to find the middle of the list using two-pointer approach
int midOfList(Node *head)
{
    if (head == NULL)
        return -1; // List is empty

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->value;
}

int main()
{
    Node *head = NULL;
    int size, value;
    cout << "How much value that you want to store in list : ";
    cin >> size;
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> value;
        insert(head, value);
    }
    cout << "\nGiven List: ";
    display(head);

    cout << "\nTotal Nodes: " << countNode(head) << endl;
    // Find and display the middle element
    cout << "\nMiddle Element: " << midOfList(head) << endl;

    return 0;
}
