#include <bits/stdc++.h>
using namespace std;
int n = 0;
int a[100005] = {0};

int main(void){
    int m = 0;
    cin >> n;
    int l = 0;
    int r = 0;

    for(int i = 1; i <= n ; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    
    cin >> m;
    
    for(int i = 0; i < m ; i++){
        cin >> l >> r;
        cout << a[r] - a[l - 1] << "\n" ;
    }

    return 0;
}