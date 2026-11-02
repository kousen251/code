#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N = 0;
    int ans = 0;
    cin >> N;

    while(N != 0){
        ans = ans * 10 + N % 10;
        N = N / 10;
    }
    cout << ans;
    
    return 0;
}