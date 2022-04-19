#include <iostream>
using namespace std;

void printArr(int v[], int n)
{   
    for(int i = 0 ; i < n ; i++)
        cout << v[i] << ' ';
    cout << endl;

}

void shiftArr(int arr[], int start, unsigned int newLenArr)
{   // shifts elements from start to newLenArr with 1 position 
    int i = newLenArr - 1;
    while(i >= start)
    {    
        arr[i + 1] = arr[i];
        --i;
    }
}

int main()

{
    int arr1[2001], arr2[1000], n, m;
    cin >> n >> m;
    int newLen = m + n;
    // n length for arr1 
    // m length for arr2 
    // newlen length for arr1 after merging arr2 into it
   
    int i = 0, j = 0;    
    // i index for arr1, j index for arr2
    while(n < newLen)
    {   
        //ok is used for not comparing twice the same values if we shift the array
        bool ok = false;
        //we look for the index of the current element of arr2 in arr1
        while(arr1[i] < arr2[j] && i < n)
        {   
            ok = true;
            ++i;
        }
        shiftArr(arr1, i, ++n);
        arr1[i] = arr2[j];
        
        ++j;
        if(ok)
            ++i;
    }
    printArr(arr1, n);
    return 0;
}