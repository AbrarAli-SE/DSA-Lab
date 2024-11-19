#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseStringUsingStack(const string &input)
{
    stack<char> charStack;
    string reversed;
 
    for (char ch : input)
    {
        charStack.push(ch);
    }

    // Pop characters from the stack and append them to the reversed string
    while (!charStack.empty())
    {
        reversed += charStack.top();
        charStack.pop();
    }

    return reversed;
}

int main()
{
    string input;

    cout << "Enter a string to reverse: ";
    getline(cin, input);

    string reversed = reverseStringUsingStack(input);

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
