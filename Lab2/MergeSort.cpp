#include <iostream>

using namespace std;

int arr[1000];

void merge(int mainArr[], unsigned int left, unsigned int middle, unsigned int right)
{
    
    int i = left , j = middle + 1 , k = 0;
    int auxArr[1000]; 

    //interclasare 
    while(i <= middle && j <= right) 
    {   
        if(mainArr[i] < mainArr[j])
            auxArr[k++] = mainArr[i++];
        else if(mainArr[j] < mainArr[i])
            auxArr[k++] = mainArr[j++];
        else
        {
            auxArr[k++] = mainArr[i++];
            auxArr[k++] = mainArr[j++];
        }  
    }
    //completam cu elementele ramase
    while(i <= middle)
        auxArr[k++] = mainArr[i++];
    while(j <= right)
        auxArr[k++] = mainArr[j++];
    k = 0;
    //trecem in array-ul principal elementele sortate din array-ul auxiliar
    for(i = left ; i <= right ; ++i)
        arr[i] = auxArr[k++]; 
}

void mergeSort(int v[], unsigned int left, unsigned int right)
{   
    if(left < right)
    {   
        int m = left + (right - left) / 2;
        mergeSort(v, left, m);
        mergeSort(v, m + 1, right);
        merge(v, left, m, right);

    }
}

int main()

{
    int v[1000], n;

    cin >> n;
    for (unsigned int i = 0 ; i < n ; ++i)
        cin >> arr[i];


    mergeSort(arr, 0, n - 1);
    for (unsigned int i = 0 ; i < n ; ++i)
        cout << arr[i] << ' ';
    return 0;
}