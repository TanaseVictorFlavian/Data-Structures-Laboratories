#include <iostream>

using namespace std;

int main()
{   
    int v[1000], n, nr, poz;
    bool found = false; 
    cin >> n >> nr;
    for(int i = 0 ; i < n ; ++i)
        cin >> v[i];
    
    for(int i = 0; i < n ; ++i)
        if (v[i] == nr)
        {    
            found = true;
            poz = i;
        }
    
    if (found) 
        cout << "Nr se afla pe pozitia " << poz + 1;
    else
        cout << "Numarul nu se afla in sir";
    
    return 0;
}