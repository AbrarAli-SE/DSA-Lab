#include <iostream>
using namespace std;

class Queue
{
private:
    int front, rear, size, count;
    int *queue;

public:
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        count = 0;
        queue = new int[size];
    }

    void enqueue(int value)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue overflow! Cannot add " << value << "." << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % size;
            queue[rear] = value;
            count++;
            cout << value << " added to the queue." << endl;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty! Cannot dequeue." << endl;
        }
        else
        {
            cout << queue[front] << " removed from the queue." << endl;
            front = (front + 1) % size;
            count--;
            if (count == 0)
            {
                front = rear = -1;
            }
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << "Queue elements: ";
            int i = front;
            for (int c = 0; c < count; c++)
            {
                cout << queue[i] << " ";
                i = (i + 1) % size;
            }
            cout << endl;
        }
    }

    int countElements()
    {
        return count;
    }

    void clear()
    {
        front = rear = -1;
        count = 0;
        cout << "Queue cleared." << endl;
    }

    bool isEmpty()
    {
        return count == 0;
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
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Count Elements\n5. Clear Queue\n6. Exit\n";
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
            cout << "Number of elements in the queue: " << q.countElements() << endl;
            break;
        case 5:
            q.clear();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
