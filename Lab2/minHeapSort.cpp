#include <iostream>
#include <climits>
using namespace std;

int sortedArr[1000], sortedArrCounter = 0;

void printArr(int v[], int n)
{   
    for(int i = 1 ; i <= n ; i++)
        cout << v[i] << ' ';
    cout << endl;

}

void heapify(int arr[], unsigned int lenArr)
{
    unsigned int crtPos = 1;
    while(2 * crtPos <= lenArr)
    {   
        int leftSon, rightSon;
        leftSon = arr[2 * crtPos];
        if (2 * crtPos + 1 <= lenArr)
            rightSon = arr[2 * crtPos + 1];
        else
            rightSon = INT_MAX;
        //we search for the new root's index in the array
        //we end up with another max heap
        if(sortedArr[crtPos] > min(leftSon, rightSon))
            if(leftSon < rightSon)
                {
                    swap(sortedArr[crtPos], sortedArr[2 * crtPos]);
                    crtPos *= 2;
                } 
            else
                {
                    swap(sortedArr[crtPos], sortedArr[2 * crtPos + 1]);
                    crtPos = 2 * crtPos + 1;
                }
        else 
            break;
        
    }
    
    swap(sortedArr[1], sortedArr[lenArr]);
    if(lenArr > 1) 
        heapify(sortedArr, lenArr - 1);
}

void heapSort(int arr[], unsigned int lenArr)
{
    sortedArr[1] = arr[1];
    
    for(unsigned int i = 2 ; i <= lenArr ; ++i)
    {   
        int indexCopy = i;
        sortedArr[i] = arr[i];
        while(sortedArr[i] < sortedArr[i / 2] && i != 1)
        {   
            swap(sortedArr[i], sortedArr[i / 2]);
            i /= 2;
        }
        i = indexCopy;
    }
    swap(sortedArr[1], sortedArr[lenArr]);
    heapify(sortedArr, lenArr - 1);
}

int main()
{   
    int v[1000] , n;
    cin >> n;
    for (int i = 1 ; i <= n ; ++i)
        cin >> v[i];
    heapSort(v,n);
    //array is sorted descending after the heapsort
    //we swap first elemen with the last, 2nd with 2nd last and so on 

    for(int i = 1 ; i <= n / 2 ; ++i)
        swap(sortedArr[i], sortedArr[n - i + 1]);
    
    printArr(sortedArr,n);
    return 0; 

}