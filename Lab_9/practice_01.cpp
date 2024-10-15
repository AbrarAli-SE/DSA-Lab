#include <iostream>
using namespace std;

class Queue
{
private:
    int front, rear, size;
    int *queue;

public:
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        queue = new int[size];
    }

    void enqueue(int value)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full!" << endl;
        }
        else
        {
            if (front == -1)
                front = 0;
            rear++;
            queue[rear] = value;
            cout << value << " added to the queue" << endl;
        }
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << queue[front] << " removed from the queue" << endl;
            front++;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }

    ~Queue()
    {
        delete[] queue;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);
    int choice, value;

    do
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
