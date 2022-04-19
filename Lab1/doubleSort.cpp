#include <iostream>
using namespace std;

int main()
{
    unsigned int v[100][3], n;
    cin >> n;
    for (unsigned int i = 0 ; i < n ; ++i)
    {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = v[i][0] + v[i][1];
    }
    bool sorted = false;
    int m = n - 1;
    //sortam descrescator dupa ht + wt
    
    while (!sorted)
    {   
        sorted = true;
        for(unsigned int i = 0; i < m; ++i)
        {
            if(v[i][2] < v[i + 1][2])
            {
                sorted = false;
                swap(v[i], v[i + 1]);
            }
        }
        m-- ;
    }
    
    //primul element din vectorul sortat va face mereu parte dintr-o solutie corecta
    unsigned int solutie[100][2], index_sol = 0; 
    solutie[0][0] = v[0][0];
    solutie[0][1] = v[0][1];
    
    //alegem din vectorul sortat solutiile compatibile 
    
    for (unsigned int i = 1 ; i < n ; ++i)
        if (v[i][0] <= solutie[index_sol][0] && v[i][1] <= solutie[index_sol][1])
        {    
            solutie[++index_sol][0] = v[i][0];
            solutie[index_sol][1] = v[i][1];
        }
    cout << "Secventa de lungime maxima (" << index_sol + 1 << "):\n";
    for (unsigned int i = 0 ; i <= index_sol ; ++i)
        cout << solutie[i][0] << ' ' << solutie[i][1] << endl;

    return 0;

}