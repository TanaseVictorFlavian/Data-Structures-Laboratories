#include <iostream> 
using namespace std;

int poz = 0;

bool itBinarySearch (int value, int arr[], int lenArr)
{      
    int left = 0, right = lenArr - 1;

    while(left <= right)
    {
        int m = left + (right - left) / 2;
        if (arr[m] == value)
        {   
            poz = m;
            return true;
        }
        else if (value < arr[m])
            right = m - 1;
        else
            left = m + 1; 
    }
    return false;

}
int main()

{
    int n, v[10], m, nr, left, right; 
    cin >> n >> nr; 
    for(int i = 0; i < n; ++i)
        cin >> v[i];    

    bool found = itBinarySearch(nr, v, n); 
    if (found)
        cout << "Nr se afla pe pozitia " << poz + 1;
    else
        cout << "Numarul nu se afla in sir";
    
    return 0; 

}