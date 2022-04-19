#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void appendNode(Node*&, int);



void inputList(Node*& first)
{   
    int x, n;
    cout << "List length : ";
    cin >> n;
    
    cout << "List : ";
    cin >> x;
    first -> data = x;
    first -> next = NULL;
    Node* node = first;

    for(int i = 1 ; i < n ; ++i)
    {   
        cin >> x;
        appendNode(node, x);
    }

}

void appendNode(Node*& last, int value)
{
    Node* aux = new Node;

    aux -> data = value;
    aux -> next = NULL;
    last -> next = aux;
    last = aux;
}

void addRemainder(Node*& elementPointer, int p, int carry, int& result)
{
    while(elementPointer != NULL)
    {
        result += (elementPointer -> data + carry) * p;
        p*= 10;
        carry = 0 ;
        elementPointer = elementPointer -> next;
    }
}

int main()
{   
    int x, value, input;
    Node* first1 = new Node;
    Node* first2 = new Node;
    
    
    inputList(first1);
    inputList(first2);
   
    int carry = 0;
    int result = 0, p = 1;
    while(first1 != NULL && first2 != NULL)
    {   
        int s = first1 -> data + first2 -> data + carry;
        if (s > 9)
            carry = 1;
        else 
            carry = 0;
        
        result += (s % 10) * p;
        p *= 10;
        first1 = first1 -> next;
        first2 = first2 -> next;
    }
    addRemainder(first1, p, carry, result);
    addRemainder(first2, p, carry, result);

    cout << result;
    
    return 0;    
}