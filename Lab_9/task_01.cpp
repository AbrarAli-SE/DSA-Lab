#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    int per_id;
    string per_name;
    int per_age;

public:
    Person()
    {
        per_id = 0;
        per_name = "";
        per_age = 0;
    }
    void input()
    {
        cout << "Enter Person ID: ";
        cin >> per_id;
        cout << "Enter Person Name: ";
        cin.ignore();
        getline(cin, per_name);
        cout << "Enter Person Age: ";
        cin >> per_age;
    }
    void output() const
    {
        cout << "Person ID: " << per_id << endl;
        cout << "Person Name: " << per_name << endl;
        cout << "Person Age: " << per_age << endl;
    }
};
class Node
{
public:
    Person data;
    Node *next;
    Node(Person p)
    {
        data = p;
        next = NULL;
    }
};
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    void addQueue()
    {
        Person p;
        p.input();
        Node *newNode = new Node(p);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Person added to the queue." << endl;
    }
    void removeQueue()
    {
        if (isEmpty())
        {
            cout << "\nQueue is empty. Cannot remove person." << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;

            cout << "Person removed from the queue:\n";
            temp->data.output();

            delete temp;

            if (front == NULL)
            { 
                rear = NULL;
            }
        }
    }
    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            Node *current = front;
            cout << "Queue contents (front to rear):" << endl;
            while (current != nullptr)
            {
                current->data.output();
                cout << endl;
                current = current->next;
            }
        }
    }
    ~Queue()
    {
        while (!isEmpty())
        {
            removeQueue();
        }
    }
};

int main()
{
    Queue q;
    int choice;

    do
    {
        cout << "\n1. Add Person to Queue\n2. Remove Person from Queue\n3. Display Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.addQueue();
            break;
        case 2:
            q.removeQueue();
            break;
        case 3:
            q.displayQueue();
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