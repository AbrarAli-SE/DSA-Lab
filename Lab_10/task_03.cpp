#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *left, *right;
};

Node *createNewNode(int val)
{
    Node *newNode = new Node();
    newNode->value = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *&root, int val)
{
    if (root == NULL)
    {
        return createNewNode(val);
    }
    if (val < root->value)
    {
        root->left = insertNode(root->left, val);
    }
    else if (val > root->value)
    {
        root->right = insertNode(root->right, val);
    }
    return root;
}

bool searchNode(Node *&root, int val)
{
    if (root == NULL)
    {
        return false; 
    }
    if (root->value == val)
    {
        return true; 
    }
    if (val < root->value)
    {
        return searchNode(root->left, val);
    }
    else
    {
        return searchNode(root->right, val);
    }
}

int main()
{
    Node *root = NULL;
    int size, value, searchVal;

    cout << "How many values do you want to store in the list: ";
    cin >> size;

    for (int i = 1; i <= size; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "Enter the value to search in the BST: ";
    cin >> searchVal;

    if (searchNode(root, searchVal))
    {
        cout << searchVal << " is found in the BST.\n";
    }
    else
    {
        cout << searchVal << " is not found in the BST.\n";
    }

    return 0;
}
