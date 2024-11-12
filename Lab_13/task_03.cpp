#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Node
{
public:
    int id;
    string name;
    int marks[10];
    Node *next;

    Node(int idVal, string nameVal, int marksVal[10])
    {
        id = idVal;
        name = nameVal;
        for (int i = 0; i < 10; i++)
        {
            marks[i] = marksVal[i];
        }
        next = NULL;
    }
};

void insertAtHead(Node *&head, int id, string name, int marks[10])
{
    Node *newNode = new Node(id, name, marks);
    newNode->next = head;
    head = newNode;
}

void display(Node *head)
{
    Node *temp = head;

    cout << "SAP ID\tName\t\tT1\tT2\tT3\tT4\tT5\tT6\tT7\tT8\tT9\tT10\n";
    cout << "----------------------------------------------------------------------------------------------------\n";

    while (temp != NULL)
    {
        cout << temp->id << "\t" << temp->name << "\t";
        for (int i = 0; i < 10; i++)
        {
            cout << temp->marks[i] << "\t";
        }
        cout << endl;
        temp = temp->next;
    }
}

void insertionSort(Node *&head, bool ascending = true)
{
    if (!head || !head->next)
        return;

    Node *sorted = NULL;

    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;

        if (sorted == NULL || (ascending && current->id < sorted->id) || (!ascending && current->id > sorted->id))
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Node *temp = sorted;
            while (temp->next != NULL && ((ascending && temp->next->id < current->id) || (!ascending && temp->next->id > current->id)))
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}

void loadDataFromFile(Node *&head, const string &filename)
{
    ifstream file(filename);
    string line;

    if (!file.is_open())
    {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }

    while (getline(file, line))
    {
        istringstream iss(line);

        int id;
        string name;
        int marks[10];

        iss >> id >> name;
        for (int i = 0; i < 10; i++)
        {
            iss >> marks[i];
        }

        insertAtHead(head, id, name, marks);
    }

    file.close();
}
void selectionSort(Node *&head, bool ascending = true)
{
    for (Node *i = head; i != NULL && i->next != NULL; i = i->next)
    {
        Node *minMax = i;

        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if ((ascending && j->id < minMax->id) || (!ascending && j->id > minMax->id))
            {
                minMax = j;
            }
        }

        if (minMax != i)
        {
            swap(i->id, minMax->id);
            swap(i->name, minMax->name);
            for (int k = 0; k < 10; k++)
            {
                swap(i->marks[k], minMax->marks[k]);
            }
        }
    }
}

int main()
{
    Node *head = NULL;

    loadDataFromFile(head, "students.txt");

    cout << "Original List:\n";
    display(head);

    selectionSort(head, true);
    cout << "\n\nList Sorted in Ascending Order :\n";
    display(head);

    selectionSort(head, false);
    cout << "\n\nList Sorted in Descending Order:\n";
    display(head);

    return 0;
}

