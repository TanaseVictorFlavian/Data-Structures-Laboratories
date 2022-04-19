#include <iostream>
using namespace std;

struct Node
{
    int data, priority;
    Node* next;
};
void assignFirstLast(int x, int y, int xPrio , int yPrio, Node*& first, Node*& last)
{
    first -> data = x;
    first -> priority = xPrio;
    first -> next = last; 
    last -> data = y;
    last -> priority = yPrio;
    last -> next = NULL;
}

void insertNode(Node*& left, Node*& right, int value, int prio)
{
    Node* aux = new Node;
    aux -> data = value;
    aux -> priority = prio;
    aux -> next = right;
    left -> next = aux;
}

void insertNodeFirst(Node*& first, int value, int prio)
{
   Node* aux = new Node;
   aux -> data = value;
   aux -> priority = prio;
   aux -> next = first;
   first = aux;
}

void insertNodeLast(Node*& last, int value, int prio)
{
    Node* aux = new Node;

    aux -> data = value;
    aux -> priority = prio;
    aux -> next = NULL;
    last -> next = aux;
    last = aux;
}

void deleteNodeFromQueue(Node*& node)
{
    cout << "Extracting " << node -> data << " from the queue\n";
    Node* aux = node;
    node = node -> next;
    delete aux;
}

int main()
{   
    int n, x, y, prioX, prioY;
    Node* first = new Node;
    Node* last = new Node;

    cout << "Queue len : ";
    cin >> n;

    cout << "Value/Prio : ";
    cin >> x >> prioX;

    cout << "Value/Prio : ";

    cin >> y >> prioY;

   
    if(prioX < prioY) 
        assignFirstLast(x, y, prioX, prioY, first, last);
    
    else
        assignFirstLast(y, x, prioY, prioX, first, last);


    for(int i = 2 ; i < n ; ++i)
    {   
        cout << "Value/Prio : ";
        cin >> x >> prioX;

        if (prioX < first -> priority)
            insertNodeFirst(first, x, prioX);
        
        else if(prioX > last -> priority)
            insertNodeLast(last, x, prioX);

        else 
        { 
            Node* node = first -> next;
            Node* prevNode = first;
            while(node != NULL && prioX > node -> priority)
            {   
                prevNode = node; 
                node = node -> next;
            }
            insertNode(prevNode, node, x, prioX);

        }
    }
    Node* node = first;
    cout << "Queue : ";
    while(node != last)
    {
        cout << node -> data << ' ' ;
        node = node -> next;
    }
    cout << node -> data;

    cout << "\nExtracting elements : \n";
    while(first != NULL)
        deleteNodeFromQueue(first);
    

    
    return 0;
}