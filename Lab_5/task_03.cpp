#include <iostream>
using namespace std;

// Array Insertion
void arrayInsert(int arr[], int &size, int pos, int val)
{
    // Shift elements to the right
    for (int i = size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    size++;
}

// Array Deletion
void arrayDelete(int arr[], int &size, int pos)
{
    // Shift elements to the left
    for (int i = pos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Node class for linked list
class Node
{
public:
    int value;
    Node *next;
    Node(int val) : value(val), next(NULL) {}
};

// Linked List Insertion at Head
void linkedListInsertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Linked List Deletion at Head
void linkedListDeleteAtHead(Node *&head)
{
    if (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// Display array
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Display linked list
void displayLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Array example
    int arr[10] = {1, 2, 3, 4, 5};
    int size = 5;
    cout << "Array before insertion: ";
    displayArray(arr, size);

    // Insert into array at position 2 (index 2)
    arrayInsert(arr, size, 2, 99);
    cout << "Array after insertion: ";
    displayArray(arr, size);

    // Delete from array at position 2
    arrayDelete(arr, size, 2);
    cout << "Array after deletion: ";
    displayArray(arr, size);

    // Linked List example
    Node *head = NULL;
    linkedListInsertAtHead(head, 5);
    linkedListInsertAtHead(head, 10);
    linkedListInsertAtHead(head, 15);
    cout << "Linked List before deletion: ";
    displayLinkedList(head);

    // Delete head of linked list
    linkedListDeleteAtHead(head);
    cout << "Linked List after deletion: ";
    displayLinkedList(head);

    return 0;
}
