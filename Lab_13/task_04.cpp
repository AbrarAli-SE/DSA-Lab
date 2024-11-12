#include <iostream>
using namespace std;

class person
{
private:
    int per_id;
    string per_name;
    int per_age;

public:
    person() : per_id(0), per_name(""), per_age(0) {}

    void input()
    {
        cout << "\nEnter person id: ";
        cin >> per_id;
        cout << "Enter person name: ";
        cin.ignore();
        getline(cin, per_name);
        cout << "Enter person age: ";
        cin >> per_age;
    }

    void output() const
    {
        cout << "\nPerson details:\n";
        cout << "ID: " << per_id << endl;
        cout << "Name: " << per_name << endl;
        cout << "Age: " << per_age << endl;
    }
};

class Node
{
public:
    person data; 
    Node *next;  

    Node(const person &p) : data(p), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head; 

public:
    LinkedList() : head(nullptr) {}

    void insertAtHead(const person &p)
    {
        Node *newNode = new Node(p);
        newNode->next = head;
        head = newNode;
        cout << "Person inserted at the head of the list!\n";
    }

    void displayList() const
    {
        if (head == nullptr)
        {
            cout << "The list is empty!\n";
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            temp->data.output();
            temp = temp->next;
        }
    }

    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList list;
    int choice;

    while (true)
    {
        cout << "\nLinked List Menu:\n";
        cout << "1. Insert a person at the head\n";
        cout << "2. Display all persons\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            person p;
            p.input();
            list.insertAtHead(p);
        }
        else if (choice == 2)
        {
            list.displayList();
        }
        else if (choice == 3)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
        }
    }
    cout << "\n\n\tAbrar Ali\n\tID: 55843";

    return 0;
}
