#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main(int argc, char * argv[]){
    int arr[3][4]={
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10 , 11, 12}
    };

    int(*ptra)[4];
    ptra = arr;

    int* ptrb[3];
    for (int i = 0; i < 3; i++){
        ptrb[i] = arr[i];
    }

    return 0;
}