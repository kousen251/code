#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a[105]={};
    int n = 1;
    int i=0;
    
    while(n != 0){
        cin >> a[i];
        n = a[i];
        i++;
    }
    i = i - 2;
    while(i >= 0){
        cout << a[i] << " ";
        i--;
    }
    
    return 0; 
}