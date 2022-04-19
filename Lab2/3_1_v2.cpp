#include <iostream>
using namespace std;

void inputData(int arr[], int lenArr)
{
    for(int i = 0; i < lenArr; ++i)
        cin >> arr[i];
}

void printArr(int v[], int n)
{   
    for(int i = 0 ; i < n ; i++)
        cout << v[i] << ' ';
    cout << endl;

}


int main()

{   
    
    int arr1[2001], arr2[1000],  n, m ;
    cin >> n >> m;
    int newLenArr = m + n;
    int pos = newLenArr - 1;

    inputData(arr1, n);
    inputData(arr2, m);
    int i = n - 1, j = m - 1;
    while(i >= 0 && j >= 0)
    {   
        if(arr1[i] > arr2[j])
            arr1[pos--] = arr1[i--];
        else
            arr1[pos--] = arr2[j--]; 
    }

    printArr(arr1, newLenArr);

    return 0;
}