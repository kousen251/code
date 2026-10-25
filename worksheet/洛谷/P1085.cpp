#include <iostream>
using namespace std;

int main(void){
    int hour1[7] = {};
    int hour2[7] = {};
     for(int i = 0 ; i < 7; i++){
         cin >> hour1[i] >> hour2[i];
     }

    int total = 0;
    int day = 0;
    
    for(int i = 0 ; i < 7; i++){
        if(hour1[i] + hour2[i] > 8 && hour1[i] + hour2[i] > total){
            total = hour1[i] + hour2[i];
            day = i + 1;
        }
    }

    cout << day;
    return 0;
}