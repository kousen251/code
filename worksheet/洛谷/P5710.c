#include <stdio.h>

int main(void)
{
    int x = 0;
    scanf("%d", &x);

    if(x > 4 && x <= 12){
        if(x % 2 == 0){
            printf("1 1 0 0");
        }else{
            printf("0 1 1 0");
        }
    }else{
        if(x % 2 == 0){
            printf("0 1 1 0");
        }else{
            printf("0 0 0 1");
        }
    }
    return 0;
}