#include <iostream> 
using namespace std;

struct Node
{
    char data;
    Node* next;
    Node* prev;
};

void assignNode(Node*& node, Node* prev, Node*next, int c)
{
    node -> data = c;
    node -> next = next;
    node -> prev = prev;
}

char pop(Node*& top)
{
    Node* aux = top;
    char aux2 = top -> data;
    top = top -> prev;
    delete aux;
    return aux2;
}

void push(Node*& top, char data)
{
    Node* aux = new Node;
    aux -> data = data;
    aux -> next = NULL;
    aux -> prev = top;
    top = aux;
}

int createNumber(Node*& top)
{   
    int nr = 0, p = 1;
    while(top -> data >= '0' && top -> data <= '9')
    {
        nr += p * (int)(top -> data - '0');
        p *= 10;
        pop(top); 
    }


}
int main()
{
    char sir[1000];
    bool paranthesis = false;
    cin >> sir;
    Node* base = new Node;
    Node* top = new Node;

    if(sir[0] == '(' || sir[1] == '(')
        paranthesis = true;

    assignNode(base, NULL, top, sir[0]);
    assignNode(top, base, NULL, sir[1]);

    for(int i = 2; sir[i] ; ++i)
    {   
        if (top -> data == '+' && sir[i] >= '0' && sir[i] <= '9' && paranthesis == false)
        {   
            int nr1 = 0;
            while(sir[i] >= '0' && sir[i] <= '9')
            {   
                nr1 = nr1 * 10 + (int)(sir[i] - '0');
                i++;
            }
            pop(top);
            
            int nr2 = createNumber(top);
            int sum = nr1 + nr2;
            int mirr = 0;
            while(sum)
            {
                mirr = mirr * 10 + sum % 10;
                sum / 10;
            } 
            
            while(mirr)
            {
                push(top, (char)(mirr % 10 + '0'));
                mirr /= 10;
            }

        }    
        else if (top -> data == '-' && sir[i] >= '0' && sir[i] <= '9' && paranthesis == false)
        {   
            int nr1 = 0, p = 1;
            while(sir[i] >= '0' && sir[i] <= '9')
            {   
                nr1 = nr1 * 10 + (int)(sir[i] - '0');
                i++;
            }
            pop(top);
            
            int nr2 = createNumber(top);
            int dif = nr1 - nr2;
            int mirr = 0;
            while(dif)
            {
                mirr = mirr * 10 + dif % 10;
                dif / 10;
            } 
            
            while(mirr)
            {
                push(top, (char)(mirr % 10 + '0'));
                mirr /= 10;
            }
            
        }    
        else if(sir[i] >= '0' && sir[i] <= '9' || sir[i] == '+' || sir[i] == '-')
            push(top, sir[i]);   
        else if(sir[i] == '(')
        {
            push(top, '(');
            paranthesis = true;
        }
        else if(sir[i] == ')')
        {
            while(top -> data != '(')
            {
            int nr1 = 0;
            while(top -> data >= '0' && top -> data <= '9')
            {   
                nr1 = nr1 * 10 + (int)(top -> data - '0');
                pop(top);
            }
            char sign = pop(top); 
            int nr2 = 0;
            while(top -> data >= '0' && top -> data <= '9')
            {
                nr2 = nr2 * 10 + (int)(top -> data - '0');
                pop(top); 
            }
            if(sign == '+')
            {
                int sum = nr1 + nr2;
                int mirr = 0;
                while(sum)
                {
                    mirr = mirr * 10 + sum % 10;
                    sum / 10;
                } 
                
                while(mirr)
                {
                    push(top, (char)(mirr % 10 + '0'));
                    mirr /= 10;
                }
            }
            else if(sign == '-')
                        {
                int dif = nr1 - nr2;
                int mirr = 0;
                while(dif)
                {
                    mirr = mirr * 10 + dif % 10;
                    dif / 10;
                } 
                
                while(mirr)
                {
                    push(top, (char)(mirr % 10 + '0'));
                    mirr /= 10;
                }
            }


        }    


            
        }
    }

    return 0;
}
