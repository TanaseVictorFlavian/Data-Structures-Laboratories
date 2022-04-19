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
    
    cout << "Choose the value you would like to delete : "; 
    cin >> input;
    
    if(input == first -> data)
        {   
            Node* aux = first;
            first = first -> next;
            delete aux;
        
        }

    Node* prevNode = first;
    node = prevNode -> next;
    bool found = false;
    while(node -> next != NULL)
    {
        if(node -> data == input)
            {
                deleteNode(prevNode, node);
                node = prevNode -> next;
                found = true;
          
            }
        else
        {
            prevNode = prevNode -> next;
            node = node -> next;
        }
        
    }
    if(node -> data == input)
            {
                prevNode -> next = NULL;
                delete node;
            }
    if(!found)
        cout << "The element doesn't exist in the list";
    else
        printList(first);

    
    return 0;
}