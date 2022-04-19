#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int Grade, Coef;
    Node* next;
    Node(int, int);
    Node();
};

Node :: Node(int grade, int coef) : next(NULL)
{
    this -> Grade = grade;
    this -> Coef = coef;
}
Node :: Node () {};

void appendNode(Node*&, int, unsigned int);

void inputList(Node*& gradeZero, int len)
{   
    int x;
    
    Node* node = gradeZero;
    
    for(int i = 1 ; i <= len ; ++i)
    {   
        cin >> x;
        appendNode(node, x, i);
    }

}

void appendNode(Node*& last, int value, unsigned int grade)
{
    Node* aux = new Node(grade, value);
    last -> next = aux;
    last = aux;
}
int valueInFixedPoint(int point, Node* startNode)
{   
    int result = 0;
    Node* node = startNode;
    while(node != NULL)
    {   
        result += node -> Coef * pow(point, node -> Grade);
        node = node -> next;
    }
    return result;
}


int main()
{   
    int n, m, x, a;

    cout << "Enter the polynom grade : ";
    cin >> n ;
    cout << "Polynom : ";
    cin >> x;
    Node* gradeZero = new Node(0, x);
    inputList(gradeZero,n);
    

    cout << "Enter the point : ";
    cin >> x;
    
    cout << valueInFixedPoint(x, gradeZero);

   
    return 0;
    

}