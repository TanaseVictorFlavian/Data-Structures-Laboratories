#include <iostream>
//#include <cstdlib> //rand() for pivot choice
//#include <ctime> //for rand()

using namespace std;


// int random(unsigned int left, unsigned int right)
// {
//     return rand() % right + left;
// }

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
    auto i = left - 1;
    auto j = right;
    while(i < j)
    {   
        do 
        {
           ++i;
        }while(arr[i] >= pivot);
        do 
        {    
           --j;
        }while(arr[j] < pivot); 
       
        if(i < j)
            swap(arr[i], arr[j]);
            
    }
    
    swap(arr[left], arr[j]);
    return j;
}

void quickSort(int arr[],  int left,  int right)
{   
    
    if(left < right)
    {   
        int p = partition(arr, left, right);
        quickSort(arr, left, p);
        quickSort(arr, p + 1, right);
    }
}
int main()
{   
    //srand(time(0)); //setting the seed in order to make rand() work properly
    int n, arr[100000];
    cin >> n;
    for(int i = 0 ; i < n; ++i)
        cin >> arr[i];
    quickSort(arr, 0, n);
    printArr(arr, n);
    return 0;
}