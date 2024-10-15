#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int size;
    int capacity;

public:
    Queue(int cap)
    {
        front = rear = NULL;
        size = 0;
        capacity = cap;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void addQueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int removeQueue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        Node *temp = front;
        int value = front->data;
        front = front->next;
        delete temp;
        size--;
        if (isEmpty())
        {
            rear = NULL;
        }
        return value;
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *current = front;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue queue1(5), queue2(5);
    int choice, value;

    do
    {
        cout << "\n1. Insert in Queue 1\n2. Remove from Queue 1 and Insert in Queue 2\n3. Remove from Queue 2\n4. Display Queue 1\n5. Display Queue 2\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert in Queue 1: ";
            cin >> value;
            queue1.addQueue(value);
            break;
        case 2:
            value = queue1.removeQueue();
            if (value != -1)
            {
                queue2.addQueue(value);
                cout << "Value moved to Queue 2" << endl;
            }
            break;
        case 3:
            value = queue2.removeQueue();
            if (value != -1)
            {
                cout << "Removed from Queue 2: " << value << endl;
            }
            break;
        case 4:
            cout << "Queue 1: ";
            queue1.displayQueue();
            break;
        case 5:
            cout << "Queue 2: ";
            queue2.displayQueue();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 6);

    return 0;
}
