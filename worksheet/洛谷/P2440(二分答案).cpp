#include <bits/stdc++.h>
using namespace std;
long long L[100005] = {0};

int main(void){
    long long n = 0;
    long long k = 0;
    long long l = 0;
    cin >> n >> k;

    long long max = 1;
    long long min = 1;
    long long ans = 0;
    for(int i = 0; i < n ;i++){
        cin >> L[i];
        if(L[i] > max){
            max = L[i];
        }
    }
    while(min <= max){
        long long sum = 0;
        long long mid = min + (max - min)/2;
        for(int i = 0 ; i < n ;i++){
            sum += L[i] / mid;
        }
        if(sum < k){
            max = mid - 1;
        }else{
            ans = mid;
            min = mid + 1;
        }
    }

    cout << ans;
    return 0;
}