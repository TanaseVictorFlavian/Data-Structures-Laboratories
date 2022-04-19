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

void deleteNode(Node*& node)
{   


    while(node -> next != NULL)
    {
        node -> data = node -> next -> data;
        if(node -> next -> next == NULL)
        {   
            delete node -> next;
            node -> next = NULL;
            break;
        }
        node = node -> next;
    }

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
    

    node = first -> next;
    bool found = false;

    while(node -> next != NULL)
    {
        if(node -> data == input)
            {
                deleteNode(node);
                found = true;
                break;
            }
       
        node = node -> next;
    }
    if(!found)
        cout << "The element doesn't exist in the list";
    else
        printList(first);
    
    return 0;
}