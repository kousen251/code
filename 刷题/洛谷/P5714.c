#include <stdio.h>
#include <math.h>

int main(void)
{
    float m;
    float h;
    scanf("%f %f", &m, &h);
    
    float BMI = 0;
    round ;BMI = m / (h * h);

    if(BMI < 18.5){
        printf("Underweight");
    } else if(BMI >= 18.5 &&BMI < 24){
        printf("Normal");
    } else if (BMI >= 24){
        printf("%f\n", BMI);
        printf("Overweight");
    }
    
    return 0;
}