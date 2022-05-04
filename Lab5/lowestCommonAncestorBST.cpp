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

Tree* LCA(Tree* root, int node1_data, int node2_data)
{
    if(node1_data <= root->data && node2_data >= root->data)
        return root;
    else if(node1_data <= root -> data && node2_data <= root->data)
        return LCA(root->left, node1_data, node2_data);
    else if (node1_data >= root->data && node2_data >= root->data)
        return LCA(root->right, node1_data, node2_data);
}

int main()
{
    Tree *root = NULL;
    int node1_data, node2_data;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        root = insertElement(root, x);
    }
    cout << "Node1 : ";
    cin >> node1_data;
    cout << "Node2 : ";
    cin >> node2_data;
    
    cout << LCA(root, node1_data, node2_data) -> data;
    return 0;
}