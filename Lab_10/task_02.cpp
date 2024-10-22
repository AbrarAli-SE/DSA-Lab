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

void inOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->value << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;
    cout << root->value << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->value << " ";
}

int main()
{
    Node *root = NULL;
    int size, value;

    cout << "How many values do you want to store in the list: ";
    cin >> size;

    for (int i = 1; i <= size; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "\nIn-order Traversal:\n";
    inOrderTraversal(root);

    cout << "\nPre-order Traversal:\n";
    preOrderTraversal(root);

    cout << "\nPost-order Traversal:\n";
    postOrderTraversal(root);

    return 0;
}
