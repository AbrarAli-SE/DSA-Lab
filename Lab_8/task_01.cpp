#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int reg_no;
    string st_name;
    float cgpa;

public:
    Student()
    {
        reg_no = 0;
        st_name = "";
        cgpa = 0.0f;
    }
    void input()
    {
        cout << "Enter registration number: ";
        cin >> reg_no;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, st_name);
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    void output() const
    {
        cout << "Registration Number: " << reg_no << endl;
        cout << "Student Name: " << st_name << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

class Stack
{
private:
    int top;
    int size;
    Student *stack; 

public:
    Stack(int s)
    {
        size = s;
        stack = new Student[size];
        top = -1;
    }
    void push()
    {
        if (top == size - 1)
        {
            cout << "Stack is full!" << endl;
        }
        else
        {
            top++;
            cout << "Enter details for student " << top + 1 << ":\n";
            stack[top].input();
            cout << "Student object pushed onto the stack." << endl;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            cout << "Popped student details:\n";
            stack[top].output();
            top--;
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            cout << "Stack contents (top to bottom):\n";
            for (int i = top; i >= 0; i--)
            {
                cout << "Student " << i + 1 << ":\n";
                stack[i].output();
                cout << endl;
            }
        }
    }

    ~Stack()
    {
        delete[] stack;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack s(size);
    int choice;

    do
    {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
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
