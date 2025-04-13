#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main(int argc, char* argv[]){
    if (argc != 4){
        fprintf(stderr, "usage: %s num1 operater num2 \n", argv[0]);
        fprintf(stderr, "support operater: + - * / \n");
        exit(EXIT_FAILURE);
    }

    double num1 = atof(argv[1]);
    double num2 = atof(argv[3]);
    char* operater = argv[2];

    int arr[] = {1, 2 , 3};
    int (*ptr)[3];
    ptr = &arr;

    return 0;
}