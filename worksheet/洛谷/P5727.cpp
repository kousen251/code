#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n = 0;
    int change[200]={};
    int i = 0;
    cin >> n;
    
    while(n != 1){
        change[i] = n;
        if(n % 2 != 0){
            n = n * 3 + 1;
        }else{
            n = n/2;
        }
        i++;
    }
    change[i] = n;
    while(i >= 0){
        cout << change[i] << " ";
        i--;
    }
    
    return 0;
}