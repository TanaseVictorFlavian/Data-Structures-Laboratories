#include <iostream>

using namespace std;

int main()
{    
    int v[1000], n, i, j, el; 
    cout << "n = " ; cin >> n; 
    for(i = 0 ; i < n ; ++i)
    {
        cout << "v[" << i << "] = " ; cin >> v[i];
    }
    for(i = 1; i < n ; ++i)
    {   
        el = v[i];
        j = i - 1;
        while (j >= 0 && el < v[j])
            {
            v[j + 1] = v[j];
            j --;
            }
        v[j + 1] = el;
        
    }
    for(i = 0 ; i < n ; ++i)
    {
        cout << v[i] << ' ';  
    }
    return 0;
}