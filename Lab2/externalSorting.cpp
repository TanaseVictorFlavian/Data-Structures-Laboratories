#include <iostream>
#include <fstream>
using namespace std;

// ifstream f1("file1_sorted.out");
// ifstream f2("file1_sorted.out");
// ifstream f3("file1_sorted.out");
// ifstream f4("file1_sorted.out");
// ifstream f5("file1_sorted.out");
// ifstream f6("file1_sorted.out");
// ifstream f7("file1_sorted.out");
// ifstream f8("file1_sorted.out");

// ofstream f1_s("f1_s.out");
// ofstream f2_s("f2_s.out");
// ofstream f3_s("f3_s.out");
// ofstream f4_s("f4_s.out");
// ofstream f5_s("f5_s.out");
// ofstream f6_s("f6_s.out");
// ofstream f7_s("f7_s.out");
// ofstream f8_s("f8_s.out");


//external sort
//take chunks of the size of your RAM memory 
//sort each chunk
//for each chunk we take another smaller chunk and place it into a matrix and place the elements on the matrix columns
//the first row should contain the current minimum of each smaller chunk
//we use min-heaps to extract the minimum from the first row 
//we send the minimum to an external file which will contain the k-chunks k-way sorted
//we then replace the minimum with the second minimum of the modified file and so on
//we repeat the same proces with the chunks until there's no data left
//the result will be sorted FILE_SIZE/RAM_MEMORY-files the size of your RAM memory stored on your disk

//heapTree[9],  matrix[9][312501] ;
string heapTree[5];
string matrix[6][6];

//freqArr[9], treeLen = 8;
int freqArr[5], treeLen = 4, endOfMatrixIndexCounter = 0; //with this counter we check if the merge should end

void extractMinimum(int value);

void printArr(string v[], int n)
{   
    for(int i = 1 ; i <= n ; ++i)
        cout << v[i] << ' ';
    cout << endl;

}

int secvSearch(string value)
{
    for(int i = 1; i <= 4; ++i)
        if(value == matrix[1][i])
            return i;
}

void createMinHeap()
{   
    
    for (int i = 1; i <= treeLen ; ++i)
        freqArr[i] = 1;
    heapTree[1] = matrix[1][1];
    int minHeapPos = 1;
    for(unsigned int i = 2 ; i <= treeLen ; ++i)
    {   
        int indexCopy = i;
        heapTree[i] = matrix[1][i];
        while(heapTree[i] < heapTree[i / 2] && i != 1)
        {   
            swap(heapTree[i], heapTree[i / 2]);
            i /= 2;
        }
        if (i == 1)
            minHeapPos = indexCopy;
        i = indexCopy;
    }
    //file_output1 << heapTree[1];
    cout << heapTree[1] << endl;
    extractMinimum(minHeapPos);
}
void heapify(string newElement)
{
    unsigned int crtPos = 1;
    heapTree[1] = newElement;
    while(2 * crtPos <= treeLen)
    {   
        string leftSon, rightSon;
        leftSon = heapTree[2 * crtPos];
        //we test the existence of the right son 
        if (2 * crtPos + 1 <= treeLen)
            rightSon = heapTree[2 * crtPos + 1];
        else
            rightSon = "ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ"; //very high value, very unlikely to be found 
        //we search for the new root's index in the array
        //we end up with another min heap
        if(heapTree[crtPos] > min(leftSon, rightSon))
            if(leftSon < rightSon)
                {
                    swap(heapTree[crtPos], heapTree[2 * crtPos]);
                    crtPos *= 2;
                } 
            else
                {
                    swap(heapTree[crtPos], heapTree[2 * crtPos + 1]);
                    crtPos = 2 * crtPos + 1;
                }
        else 
            break;
        
    }
    //printArr(heapTree, 4);
    cout << heapTree[1] << endl;
    extractMinimum(secvSearch(heapTree[1]));
    
}

void extractMinimum(int index)
{   
    
    //we search for the index of the minimum in the first row of the matrix
    freqArr[index]++;
    matrix[1][index] = matrix[freqArr[index]][index];
    //if(freqArr[index] == 312500)
    if(freqArr[index] == 5)
        endOfMatrixIndexCounter ++;
    //if(endOfMatrixIndexCounter != 8)
    if(endOfMatrixIndexCounter != 4)
        heapify(matrix[1][index]);
    
}



int main ()

{   
    // jj ff aa bb  ll gg  cc ee  vv xx  ee hh  xx zz  ff kk
    //read from files
    //...

    // int i = 1;
    // while(i < 312500);
    // {
    //     f1 >> matrix[i][1];
    // }
    // i = 1;
    // while(i < 312500);
    // {
    //     f2 >> matrix[i][2];
    // }
    // i = 1;
    // while(i < 312500);
    // {
    //     f3 >> matrix[i][3];
    // }
    // i = 1;
    // while(i < 312500);
    // {
    //     f4 >> matrix[i][4];
    // }
    // i = 1;
    // while(i < 312500);
    // {
    //     f5 >> matrix[i][5];
    // }
    // i = 1;
    // while(i < 312500);
    // {
    //     f6 >> matrix[i][6];
    // }
    // i = 1;
    // while(i < 312500);
    // {
    //     f7 >> matrix[i][7];
    // }
     // while(i < 312500);
    // {
    //     f8 >> matrix[i][8];
    // }

    // for(i = 1 ; i < 9; ++i)
    //     matrix[312501][i] =  "ÿÿÿÿÿ";
    for(int i = 1 ; i <= 4 ; ++i)
        for(int j = 1 ; j <= 4 ; ++j)
            cin >> matrix[i][j];

    for(int i = 1 ; i <= 4; ++i)
        matrix[5][i] = "ÿÿÿÿÿ";
    createMinHeap();
    // j f a b  
    // l g c e 
    // v x e h
    // x z f k
    
    //afisare : aa, bb, cc, ee, ee, ff, ff, gg, hh, jj, kk, ll, vv, xx, xx, zz  
    return 0;
}

