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
void inOrderTraversal(Tree *root, int k1, int k2)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left, k1, k2);
    if (root->data >= k1 && root->data <= k2)
        cout << root->data << ' ';
    inOrderTraversal(root->right, k1, k2);
}

int main()
{

    Tree *root = NULL;
    int n, x, k1, k2;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        root = insertElement(root, x);
    }
    cout << "k1 : ";
    cin >> k1;
    cout << "k2 : ";
    cin >> k2;

    inOrderTraversal(root, k1, k2);
}