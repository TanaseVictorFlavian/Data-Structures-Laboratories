#include <iostream>

using namespace std;

struct Tree
{
    int data;
    Tree *left;
    Tree *right;
};

Tree *createNode(int data)
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
Tree *insertElement(Tree *root, int data)
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
Tree *deleteNode(Tree *root, int data)
{

    if (root == NULL)
        return NULL;

    else if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {
        // no children
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // 1 child
        else if (root->left == NULL)
        {
            Tree *auxNode = root;
            root = root->right;
            delete auxNode;
        }
        else if (root->right == NULL)
        {
            Tree *auxNode = root;
            root = root->left;
            delete auxNode;
        }
        // 2 children
        else
        {
            Tree *auxNode = findSuccesor(root->right);
            root->data = auxNode->data;
            root->right = deleteNode(root->right, auxNode->data);
        }
    }
    return root;
}
void inOrderTraversal(Tree *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << ' ';
    inOrderTraversal(root->right);
}

int main()
{
    Tree *root = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        root = insertElement(root, x);
    }
    // inOrderTraversal(root);
    cout << "Element to be deleted : ";
    cin >> x;
    root = deleteNode(root, x);
    cout << "Tree after removal : ";
    inOrderTraversal(root);
}