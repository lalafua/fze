#include <stdio.h>
#include "calculator.h"

int main(){
    float a = 0.f;
    float b = 0.f;

    scanf("%f", &a);
    scanf("%f", &b);

    double result = 0.0;
    calc(a, "+", b, &result);
    fprintf(stdout, "%f", result);

    return 0;
}