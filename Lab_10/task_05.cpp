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
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the array elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        root = insertNode(root, arr[i]);
    }

    cout << "\nSorted array (in-order traversal of BST):\n";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
