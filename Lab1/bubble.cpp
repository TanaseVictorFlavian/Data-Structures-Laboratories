#include <iostream>

using namespace std;

int main()

{
    int v[1000], n, i, m;
    bool sorted = false;
    cout << "n = " ; cin >> n; 
    for(i = 0 ; i < n ; ++i)
    {
        cout << "v[" << i << "] = "; cin >> v[i];  
    }
    m = n - 1;
    while (!sorted)
    {   
        sorted = true;
        for(i = 0; i < m; ++i)
        {
            if(v[i] > v[i + 1])
            {
                sorted = false;
                swap(v[i], v[i + 1]);
            }
        }
        m-- ;
    }
    for(i = 0 ; i < n ; ++i)
        cout << v[i] << ' ';  
    

    return 0; 

}