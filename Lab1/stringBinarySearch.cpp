//ex 3.4

#include <iostream>
#include <cstring>

using namespace std;

int strBinarySearch (string sir[], string cuvant, int left, int right)
{   
    int maxRight = right;
    int minLeft = left; 
    int m = left + (right - left) / 2;
    if (sir[m] == "") 
    {
        left = m - 1;
        right = m + 1;
    }
    while(true)
    {
        if(right == maxRight || left < minLeft) 
            return -1;
        if(sir[right] != "")
        {  
            m = right;
            break;
        }
        if(sir[left] != "")       
        {  
            m = left;
            break;
        }

        right ++;
        left --;

    }
    if (sir[m] == cuvant)
        return m;
    else if (sir[m] < cuvant)
        return strBinarySearch(sir, cuvant, m + 1, maxRight);
    else 
        return strBinarySearch(sir, cuvant, minLeft, right - 1);

}

int main()
{
    string sir_initial[100] = {"arena", "", "", "","da", "", "", "la", "", "", "minge", ""}, cuvant;
    //sir_initial[100] = {"arena", "", "", "","da", "", "", "la", "", "", "minge", ""}
    int n;
    cin >> n;
    for(int i = 0; i < n ; ++i)
        cin >> sir_initial[i];
    
    cin >> cuvant;
    cout << strBinarySearch(sir_initial, cuvant,  0, n);

     

    return 0;
}

