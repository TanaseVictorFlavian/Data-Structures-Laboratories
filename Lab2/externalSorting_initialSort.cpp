#include <iostream>
#include <algorithm>
#include <fstream>
ifstream file1("file1.in");
ifstream file2("file2.in");
ifstream file3("file3.in");
ifstream file4("file4.in");
ifstream file5("file5.in");
ifstream file6("file6.in");
ifstream file7("file7.in");
ifstream file8("file8.in");

ofstream file1_sorted("file1_sorted.out");
ofstream file2_sorted("file2_sorted.out");
ofstream file3_sorted("file3_sorted.out");
ofstream file4_sorted("file4_sorted.out");
ofstream file5_sorted("file5_sorted.out");
ofstream file6_sorted("file6_sorted.out");
ofstream file7_sorted("file7_sorted.out");
ofstream file8_sorted("file8_sorted.out");


using namespace std;

string arr[25000000];
int main()
{   
    int i = 1; 
    while(i <= 25000000)
        file1 >> arr[i++];
    sort(arr, arr + 25000000);
    for(i = 1 ; i < 25000000 ; ++i)
        file1_sorted << arr[i];

    i = 1; 
    while(i <= 25000000)
        file2 >> arr[i++];
    sort(arr, arr + 25000000);
    for(i = 1 ; i < 25000000 ; ++i)
        file2_sorted << arr[i];

    i = 1; 
    while(i <= 25000000)
        file3 >> arr[i++];
    sort(arr, arr + 25000000);
    for(i = 1 ; i < 25000000 ; ++i)
        file3_sorted << arr[i];

    i = 1; 
    while(i <= 25000000)
        file4 >> arr[i++];
    sort(arr, arr + 25000000);
    for(i = 1 ; i < 25000000 ; ++i)
        file5_sorted << arr[i];

    i = 1; 
    while(i <= 25000000)
        file6 >> arr[i++];
    sort(arr, arr + 25000000);
    for(i = 1 ; i < 25000000 ; ++i)
        file6_sorted << arr[i];

    i = 1; 
    while(i <= 25000000)
        file7 >> arr[i++];
    sort(arr, arr + 25000000);
    for(i = 1 ; i < 25000000 ; ++i)
        file7_sorted << arr[i];

    i = 1; 
    while(i <= 25000000)
        file8 >> arr[i++];
    sort(arr, arr + 25000000);
    for(i = 1 ; i < 25000000 ; ++i)
        file8_sorted << arr[i];


    

}