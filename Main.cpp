#include <stdio.h>
#include <iostream>
using namespace std;

void IsKPeriodic(const string str) {
     int n = str.size();
     char nc = str[n-1];
     string patt;
     int k=0;
     int i=0;
    // находим паттерн 
     while  (str[i] != nc) {
        patt[i] = str[i];
        i++;
        k++;
        
    }
    //последний символ паттерна
    if (str[i] == nc && str[i+1] == str[0]) {
        patt[i] = str[i];
        k++;
        i++;
    }
    int d = patt.size();
    bool err = 0;
    //проверяем паттерны
    while (i < n) {
        for (int j=0; j<d; j++) {
            if (patt[j] != str[i]) err=1; 
            i++;
        }
        
    }
    if (!err) cout << "Pattern found at index " << k << endl;
}

int main()
{
    string str="abcabcabcabc";
    IsKPeriodic(str);
    return 0;
}
