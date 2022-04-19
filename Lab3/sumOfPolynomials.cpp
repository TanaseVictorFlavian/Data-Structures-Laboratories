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

void appendNode(Node*& last, int value, unsigned int grade)
{
    Node* aux = new Node(grade, value);
    last -> next = aux;
    last = aux;
}

   

void printPolynomial(Node* gradeZero)
{
    while(gradeZero -> next != NULL)
    {
        cout << gradeZero -> Coef << " * x ^ "<< gradeZero -> Grade << " + ";
        gradeZero = gradeZero -> next;
    }
    cout << gradeZero -> Coef << " * x ^ "<< gradeZero -> Grade << endl;
}




int main()
{   
    int n, m, x;

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

    Node* summedPolynomialsStart = new Node(0, gradeZeroP -> Coef + gradeZeroQ -> Coef);
    Node* summedPolynomials = summedPolynomialsStart;
    gradeZeroP = gradeZeroP -> next;
    gradeZeroQ = gradeZeroQ -> next;
    
    int len = min(m, n);
    int i;
    for(i = 1; i <= len; ++i)
    {
        appendNode(summedPolynomials, gradeZeroP -> Coef + gradeZeroQ -> Coef, i);
        gradeZeroP = gradeZeroP -> next;
        gradeZeroQ = gradeZeroQ -> next;
    }

    if(len == n)
        while(gradeZeroQ != NULL)
        {
            appendNode(summedPolynomials, gradeZeroQ -> Coef, i);
            gradeZeroQ = gradeZeroQ -> next;
        }
    
    else   
        while(gradeZeroP != NULL)
        {
            appendNode(summedPolynomials, gradeZeroP -> Coef, i);
            gradeZeroP = gradeZeroP -> next;
        }


    printPolynomial(summedPolynomialsStart);
   
    return 0;
    

}