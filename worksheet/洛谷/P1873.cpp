#include <bits/stdc++.h>
using namespace std;

int a[1000005] = {};

int main(void){
    long long N = 0;
    long long M = 0;
    cin >> N >> M;
    long long ans = 0;

    long long maxH = 0;
    long long minH = 0;
    
    for(int i = 0; i < N; i++){
        cin >> a[i];
        if(a[i] > maxH){
            maxH = a[i];
        }
    }
    long long mid = 0;
    while(minH <= maxH){
        long long total = 0;
        mid = minH + (maxH - minH)/2;
        for(int i = 0; i < N ; i++){
            if(a[i] > mid){
                total += a[i] - mid;
            }
        }
        if(total < M){
            maxH = mid - 1;
        }else{
            ans = mid;
            minH = mid + 1;
        }
    }
    cout << ans;
    
	return 0;
}