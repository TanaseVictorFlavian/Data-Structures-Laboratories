#include <iostream>
#include <cstring>
using namespace std;


bool anagrams(string s1, string s2)
{   
    int v1[25] {0}, v2[25] {0}, len_s1 = s1.length(), len_s2 = s2.length();
    
    if(len_s1 != len_s2)
    return false;
    
    for(unsigned int i = 0 ; i < len_s1 ; ++i)
        v1[int(s1[i]) - 97]++ ;
    
    for(unsigned int i = 0 ; i < len_s2 ; ++i)
        v2[int(s2[i]) - 97]++ ;
    
    for(unsigned int i = 0 ; i < len_s2 ; ++i)
        if (v1[i] != v2[i])
            return false;
    
    return true;

}
int main()

{   
    string input[20];
    int n; 

    cin >> n;
    for (unsigned int i = 0 ; i < n ; ++i)
        cin >> input[i];

    unsigned int crtIndex = 1; 
    for(unsigned int i = 0 ; i < n - 1 ; ++i)
    {   
        bool swapped = false;
        for(unsigned int j = crtIndex ; j < n ; ++j)
            if (anagrams(input[i], input[j]))
            {
                swap(input[crtIndex ++], input[j]);
                swapped = true;
            }
        if (!swapped) 
            crtIndex ++; 
    }
    for (unsigned int i = 0 ; i < n ; ++i)
        cout << input[i] << ' ';
    return 0; 
    
}