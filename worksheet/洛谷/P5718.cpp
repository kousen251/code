#include <iostream>
using namespace std;

int main(void){
    int n;
    int a[105];
    int ans = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ans = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] < ans){
            ans = a[i];
        }
    }
    cout << ans;
    
    return 0;
}