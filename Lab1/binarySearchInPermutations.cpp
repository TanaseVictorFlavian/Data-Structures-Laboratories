//3.3
#include <iostream>
#include <climits>

using namespace std;

void program_exit(int value)
{
    cout << value; 
    exit(0);
}
bool check_found(int found)
{
    return found != -1;
}

int itBinarySearch (int value, int arr[], int left, int right)
{      

    while(left <= right)
    {
        int m = left + (right - left) / 2;
        if (arr[m] == value)
            return m;
            
    
        else if (value < arr[m])
            right = m - 1;
        else
            left = m + 1; 
    }
    return -1;

}

int main()
{
    int n, v[1000], nr;
    cin >> n >> nr; 
    int minim = INT_MAX, min_index;
    for (int i = 0 ; i < n ; ++i)
    {   
        cin >> v[i];
        if (v[i] < minim) 
        {    
            minim = v[i];
            min_index = i;
        }   
    }
    int found = itBinarySearch(nr, v, 0, min_index - 1);
    if (check_found(found)) 
        program_exit(found);
    
    found = itBinarySearch(nr, v, min_index, n - 1);
    if (check_found(found))
        program_exit(found);

    cout << "Numarul nu se afla in sir";
    return 0;

}