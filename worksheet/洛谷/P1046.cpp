#include <bits/stdc++.h>
using namespace std;

int main(void){
    int high[15] = {};
    int hand = 0;
    int n = 0;

    for(int i=0; i<10 ; i++){
        cin >> high[i];
    }
    cin >> hand;
    for(int i = 0; i<10 ; i++){
        if(hand >= high[i]){
            n++;
        }else if(hand + 30 >= high[i]){
            n++;
        }
    }
    
    cout << n;
    
    return 0;
}