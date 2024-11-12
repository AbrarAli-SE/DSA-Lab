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

void bubbleSort(Node *head, bool ascending = true)
{
    if (head == NULL)
        return;

    bool swapped;
    do
    {
        swapped = false;
        Node *current = head;

        while (current->next != NULL)
        {
            if ((ascending && current->id > current->next->id) ||
                (!ascending && current->id < current->next->id))
            {

                swap(current->id, current->next->id);

                swap(current->name, current->next->name);

                for (int i = 0; i < 10; i++)
                {
                    swap(current->marks[i], current->next->marks[i]);
                }

                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
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

int main()
{
    Node *head = NULL;

    loadDataFromFile(head, "students.txt");

    cout << "Original List:\n";
    display(head);

    bubbleSort(head, true);
    cout << "\n\nList Sorted in Ascending Order:\n";
    display(head);

    bubbleSort(head, false);
    cout << "\n\nList Sorted in Descending Order:\n";
    display(head);
    cout << "\n\n\tAbrar Ali\n\tID: 55843";

    return 0;
}
