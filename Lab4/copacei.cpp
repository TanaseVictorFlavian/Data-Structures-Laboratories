#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};


int pop(Node*& top)
{   
    if(top != NULL)
    {
        int aux = top -> data;
        top = top -> next;
        return aux;
    }   
    
}
void push(Node*& top, int data)
{   
    
    Node* aux = new Node;
    aux -> data = data;
    aux -> next = top;
    top = aux;
    
}

int main()
{   
    int n, x;  
    Node* top = NULL;
   

    cin >> n >> x;
    push(top, x);
    
    n *= 2;

    for(int i = 1; i < n ; i++)
    {
        cin >> x;
        if(top == NULL)
            push(top, x);
        else
        {
            if(x < top -> data)
            {
                cout << "Configuratie invalida";
                return 0;
            }

            else if(x > top -> data)
                push(top, x);
            else 
                pop(top);
        }
    }

    cout << "Configuratie valida";



    return 0;    


}
