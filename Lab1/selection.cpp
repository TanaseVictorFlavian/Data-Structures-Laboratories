#include <iostream>
using namespace std;

int main()

{
    int v[1000], n, i;
    cout << "n = " ; cin >> n; 
    n--;
    for(i = 0 ; i <= n ; ++i)
    {
        cout << "v[" << i << "] = "; cin >> v[i];  
    }
    int m = 0;
    while(m < n)
        {   
            int minim = v[m];
            int min_index = m ;
            for(i = m + 1 ; i <= n ; ++i)
                if (v[i] < minim)
                {    
                    minim = v[i];
                    min_index = i; 
                }
            swap(v[m], v[min_index]);
            ++m ; 
                
            
        }
    for(i = 0 ; i <= n ; ++i)
    {
        cout << v[i] << ' ';  
    }

return 0;
}