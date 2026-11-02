#include <bits/stdc++.h>
using namespace std;

int main(void){
    float s = 0.0;
    float x = 2;
    float total = 0.0;
    int n = 0;
    cin >> s;

    while(total < s){
        total = total + x;
        x = x * 0.98;
        n++;
    }
    cout << n;
        
    return 0;
}