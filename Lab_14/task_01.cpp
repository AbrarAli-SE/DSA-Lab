#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int size;
    int *stack;

public:
    Stack(int ignored = 0)
    {
        size = 10; // Default size for the stack
        stack = new int[size];
        top = -1;
        cout << "Stack created with default size 10." << endl;
    }

    ~Stack()
    {
        delete[] stack;
        cout << "Stack memory deallocated." << endl;
    }

    void push(const int value)
    {
        if (top == size - 1)
        {
            cout << "Stack is full!" << endl;
        }
        else
        {
            stack[++top] = value;
            cout << value << " pushed onto the stack." << endl;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! Cannot pop." << endl;
        }
        else
        {
            cout << stack[top--] << " popped from the stack." << endl;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! Nothing to peek." << endl;
            return -1; // Return a placeholder value
        }
        else
        {
            return stack[top];
        }
    }

    void clear()
    {
        top = -1;
        cout << "Stack cleared." << endl;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; --i)
            {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack s; // Default constructor with ignored parameter
    int choice, value;

    do
    {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Clear\n5. Display\n6. IsEmpty\n7. Exit\n";
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
            cout << "Element at top: " << s.peek() << endl;
            break;
        case 4:
            s.clear();
            break;
        case 5:
            s.display();
            break;
        case 6:
            cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}
