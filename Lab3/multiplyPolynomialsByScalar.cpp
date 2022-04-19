#include <iostream>

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

void printPolynomials(Node* gradeZero)
{
    while(gradeZero -> next != NULL)
    {
        cout << gradeZero -> Coef << " * x ^ "<< gradeZero -> Grade << " + ";
        gradeZero = gradeZero -> next;
    }
    cout << gradeZero -> Coef << "* x ^ "<< gradeZero -> Grade << endl;
}

void appendNode(Node*& last, int value, unsigned int grade)
{
    Node* aux = new Node(grade, value);
    last -> next = aux;
    last = aux;
}

void multiplyByScalar(int a, Node* startNode)
{
    Node* node = startNode;
    while(node != NULL)
    {   
        node -> Coef *= a;
        node = node -> next;
    }
}


int main()
{   
    int n, m, x, a;

    cout << "Enter the P polynom grade : ";
    cin >> n ;
    cout << "Polynom : ";
    cin >> x;
    Node* gradeZeroP = new Node(0, x);
    inputList(gradeZeroP,n);
    
    cout << "Enter the Q polynom grade : ";
    cin >> m;
    cout << "Polynom : ";
    cin >> x;
    Node* gradeZeroQ = new Node(0, x);
    inputList(gradeZeroQ, m);

    cout << "Enter the scalar : ";
    cin >> a;

    multiplyByScalar(a, gradeZeroP);
    printPolynomials(gradeZeroP);

    multiplyByScalar(a, gradeZeroQ);
    printPolynomials(gradeZeroQ);
   
    return 0;
    

}