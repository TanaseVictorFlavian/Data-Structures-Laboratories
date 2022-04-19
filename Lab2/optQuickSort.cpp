#include <iostream>

using namespace std;

void printArr(int v[], int n)
{   
    for(int i = 0 ; i < n ; i++)
        cout << v[i] << ' ';
    cout << endl;

}
int partition(int arr[], int left,  int right)
{   
    
    int pivot = arr[left];
    //i seeks for greater elements than the pivot
    //j seeks for smaller elements than the pivot
    auto i = left ;
    auto j = right;
    while(i < j)
    {   
        do 
        {
           ++i;
        }while(arr[i] <= pivot);
        do 
        {    
           --j;
        }while(arr[j] > pivot); 
       
        if(i < j)
            swap(arr[i], arr[j]);
            
    }
    
    swap(arr[left], arr[j]);
    return j;
}
void insertionSort(int arr[], int left, int right)
{   
    //cout << "I used insertionSort for an array of length " << right - left << endl;
    for(int i = left + 1; i < right ; ++i)
    {   
        //cautam pozitia elementului curent 
        int el = arr[i];
        int j = i - 1;
        while (j >= 0 && el < arr[j])
            {
            arr[j + 1] = arr[j];
            j --;
            }
        arr[j + 1] = el;
        
    }
}
void quickSort(int arr[],  int left,  int right)
{   
    
    if(left < right)
    {   
        //insertion sort for arrays of length <= 10
        if (right - left < 11)
            insertionSort(arr, left, right);
        else
        {
            int p = partition(arr, left, right);
            quickSort(arr, left, p);
            quickSort(arr, p + 1, right);
        }
    }
}
int main()
{   
    int n, arr[100000];
    cin >> n;
    for(int i = 0 ; i < n; ++i)
        cin >> arr[i];
    quickSort(arr, 0, 11);
    printArr(arr, 11);
    return 0;
}