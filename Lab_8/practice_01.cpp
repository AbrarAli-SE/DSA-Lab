#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int size;
    int *stack;

public:
    Stack(int s)
    {
        size = s;
        stack = new int[size];
        top = -1;
    }

    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "Stack is full!" << endl;
        }
        else
        {
            top++;
            stack[top] = value;
            cout << value << " pushed onto the stack" << endl;
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
            cout << stack[top] << " popped from the stack" << endl;
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
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--)
            {
                cout << stack[i] << " ";
            }
            cout << endl;
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
    int choice, value;

    do
    {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a value to push: ";
            cin >> value;
            s.push(value);
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
