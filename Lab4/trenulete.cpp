#include <iostream>
using namespace std;
/*
Ideea problemei: 
    -citim inputul intr-o stiva1
    -elementele ordonate descrescator vor fi stocate in stiva2
    -avem 3 cozi ce reprezinta liniile ajutatoare
    -la fiecare pas scoatem un element din stiva1 si il asezam intr-una din cozi astfel incat de la capat catre coada acestea sa fie ordonate crescator
    -daca elementul extras este minim, iar una dintre linii este libera, acesta este trimis direct in stiva2
    -in cazul in care elementul minim este extras dar nu are pe unde trece => nu avem o strategie posibila 
    -dupa ce punem un element in stiva2 verificam daca putem elibera un dintre cozi
*/
struct Node
{
    int data;
    Node* next;
};

int popQueue(Node*& front, Node*& rear)
{
    if(front != NULL)
    {   
        Node* auxNode = front;
        if(auxNode -> next != NULL)
        {
            int aux = front -> data;
            front = front -> next;
            delete auxNode;
            return aux; 
        }
        else
        {
            int aux = front -> data;
            front = NULL;
            rear = NULL;
            return aux;
        }
    }
}

void pushBack(Node*& front, Node*& rear, int data)
{
    Node* aux = new Node;
    if(rear != NULL)
    {
        Node* aux = new Node;
        rear -> next = aux;
        aux -> data = data;
        aux -> next = NULL;
        rear = aux;
    }
    else
    {
        rear = new Node;
        rear -> next = NULL;
        rear -> data = data;
        front = rear;
    }
}

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
    Node* front1 = NULL;
    Node* rear1 = NULL;
    Node* front2 = NULL;
    Node* rear2 = NULL;
    Node* front3 = NULL;
    Node* rear3 = NULL;
    Node* top1 = NULL;
    Node* top2 = NULL;

    int n, x, minim = 1;
    
    cout << "Nr vagoane : "; cin >> n;
    cout << "\nVagoane : ";
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> x;
        push(top1, x);
    }

    while(minim < n + 1)
    {   
        if(top1 != NULL)
            x = pop(top1);
        if(x == minim && (front1 == NULL || front2 == NULL || front3 == NULL))
        {   
            push(top2, x);
            minim ++;
        }

        else if(front1 != NULL && front1 -> data == minim)
        {    
            push(top2, popQueue(front1, rear1));
            push(top1, x);
            minim ++;
        }
        
        else if(front2 != NULL && front2 -> data == minim)
        {    
            push(top2, popQueue(front2, rear2));
            push(top1, x);
            minim ++;
        }

        else if(front3 != NULL && front3 -> data == minim)
        {    
            push(top2, popQueue(front3, rear3));
            push(top1, x);
            minim ++;
        }

        else if(rear1 != NULL && rear2 != NULL && rear3 != NULL &&(x < rear1 -> data || x < rear2 -> data || x < rear3 -> data))
        {
            cout << "Nu exista o strategie";
            return 0;
        }
        else
        {
            if(rear1 == NULL || x > rear1 -> data)
                pushBack(front1, rear1, x);
            else if(x < rear1 -> data && (rear2 == NULL || x > rear2 -> data))
                pushBack(front2, rear2, x);
            else if(x < rear2 -> data && (rear3 == NULL || x > rear3 -> data))
                pushBack(front3, rear3, x);
        }
    }

    while(top2 != NULL)
    {
        cout << pop(top2) << ' ';
    }
   
    return 0;
}