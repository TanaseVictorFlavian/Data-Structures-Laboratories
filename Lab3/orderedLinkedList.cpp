#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void assignFirstLast(int x, int y, Node*& first, Node*& last)
{
    first -> data = x;
    first -> next = last; 
    last -> data = y;
    last -> next = NULL;
}

void insertNode(Node*& left, Node*& right, int value)
{
    Node* aux = new Node;
    aux -> data = value;
    aux -> next = right;
    left -> next = aux;
}

void insertNodeFirst(Node*& first, int value)
{
   Node* aux = new Node;
   aux -> data = value;
   aux -> next = first;
   first = aux;
}

void insertNodeLast(Node*& last, int value)
{
    Node* aux = new Node;

    aux -> data = value;
    aux -> next = NULL;
    last -> next = aux;
    last = aux;
  

}

int main()
{   
    int x, y, n;
    Node* first = new Node;
    Node* last = new Node;

    cin >> n >> x >> y; 
   
    if(x < y) 
        assignFirstLast(x, y, first, last);
    
    else
        assignFirstLast(y, x, first, last);


    for(int i = 2 ; i < n ; ++i)
    {   
        
        cin >> x;

        if (x < first -> data)
            insertNodeFirst(first, x);
        
        else if(x > last -> data)
            insertNodeLast(last, x);

        else 
        { 
            Node* node = first -> next;
            Node* prevNode = first;
            while(node != NULL && x > node -> data)
            {   
                prevNode = node; 
                node = node -> next;
            }
            insertNode(prevNode, node, x);

        }
    }
    Node* node = first;
    while(node != last)
    {
        cout << node -> data <<' ';
        node = node -> next;
    }
    cout << node -> data << endl;
    
    return 0;
}