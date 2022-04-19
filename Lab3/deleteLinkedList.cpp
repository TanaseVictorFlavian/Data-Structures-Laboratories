#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void printList(Node* node)
{
    while(node -> next != NULL)
    {
        cout << node -> data << ' ';
        node = node -> next;
    }
    cout << node -> data << endl;
}

void appendNode(Node*& last, int value)
{
    Node* aux = new Node;

    aux -> data = value;
    aux -> next = NULL;
    last -> next = aux;
    last = aux;
}

void deleteNode(Node*& prevNode, Node*& node)
{
    prevNode -> next = node -> next;
    delete node;
}
int main()
{   
    int x, n, value, input;
    Node* first = new Node;
    cin >> n >> x;
    
    first -> data = x;
    first -> next = NULL;

    Node* node = first;

    for(int i = 1 ; i < n ; ++i)
    {   
        cin >> x;
        appendNode(node, x);
    }

    node = first -> next;

    while(node != NULL)
    {
        deleteNode(first, node);
        node = first -> next;
    }
    delete first;
    return 0;
}