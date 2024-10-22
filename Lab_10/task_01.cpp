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

void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->value << " ";
    inOrderTraversal(root->right);
}

int main()
{
    Node *root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout << "\nIn-order Traversal:\n";
    inOrderTraversal(root);

    return 0;
}
