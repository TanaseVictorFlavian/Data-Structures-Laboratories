#include <iostream>

using namespace std;

struct Tree
{
    string data;
    Tree *left;
    Tree *right;
};

Tree *createNode(string data)
{
    Tree *newNode = new Tree;
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}
Tree *findSuccesor(Tree *root)
{
    if (root->left == NULL)
        return root;
    else
        findSuccesor(root->left);
}
// creating the tree
Tree *insertElement(Tree *root, string data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data >= root->data)
    {
        root->right = insertElement(root->right, data);
    }
    else
    {
        root->left = insertElement(root->left, data);
    }
    return root;
}

void inOrderTraversal(Tree *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->right);
    cout << root->data << ' ';
    inOrderTraversal(root->left);
}

int main()
{

    Tree *root = NULL;
    int n;
    string x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        root = insertElement(root, x);
    }
    inOrderTraversal(root);

    return 0;
}