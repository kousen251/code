#include <iostream>

using namespace std;
int main(void){
    int a;
    int b;
    int c;

    cin >> a >> b >> c;
    if(a > b > c){
        cout<< a << b << c;
    }else if(a > c > b){
        cout<<a << c << b;
    }else if(b > a > c){
        cout<<b << a << c;
    }else if(b > c > a){
        cout<<b << c << a;
    }else if(c > a > b){
        cout<<c << a << b;
    }else if(c > b > a){
        cout<<c << b << a;
    }

    return 0;
}