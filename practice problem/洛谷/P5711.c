#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    if(n >= 1582 && n <= 2020){
        if(n % 4 == 0 && n % 100 != 0){
            printf("1");
        }else if(n % 100 == 0 && n % 400 == 0){
            printf("1");
        }else{
            printf("0");
        }
    }else{
        printf("0");
    }
    
    return 0;
}