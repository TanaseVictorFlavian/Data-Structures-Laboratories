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
// pre-order traversal

void postOrderTraversal(Tree *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << ' ';
}

void preOrderTraversal(Tree *root)
{
    if (root == NULL)
        return;
    cout << root->data << ' ';
    // first the left sub-tree
    preOrderTraversal(root->left);
    // then the right sub-tree
    preOrderTraversal(root->right);
}

// in-order traversal
void inOrderTraversal(Tree *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << ' ';
    inOrderTraversal(root->right);
}

// post-order traversal

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
    cout << "Pre-order traversal : ";
    preOrderTraversal(root);
    cout << '\n';
    cout << "In-order traversal : ";
    inOrderTraversal(root);
    cout << '\n';
    cout << "Post-order traversal : ";
    postOrderTraversal(root);

    return 0;
}
