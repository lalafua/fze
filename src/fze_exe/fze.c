#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
#include <string.h>


int main(int argc, char * argv[]){
    int arra[3][4]={
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10 , 11, 12}
    };

    int arrb[3] = {1, 2, 3};
    
    int *ptr1_a[3];
    for(int i=0; i<3; i++){
        ptr1_a[i] = arra[i];
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
        printf("%d \n", ptr1_a[i][j]);
        }
    }

    int *ptr1_b[3];
    for (int i=0; i<3; i++){
        ptr1_b[i] = &arrb[i];
    }
    for(int i=0; i<3; i++){
        printf("%d \n", *ptr1_b[i]);
    }

    int (*ptr2_b)[3];
    ptr2_b = &arrb;
    for(int i=0; i<3; i++){
        printf("%d \n", (*ptr2_b)[i]);
    }


    int (*ptr2_a)[4];
    ptr2_a = arra;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            printf("%d \n", ptr2_a[i][j]);
        }
    }

    int (*funcptr)(int, int);

    char *str = "abcdccdeabcdoo";
    char str1[20] = "awdwaddwa";
    int n = 0;
    for(char *ptr = strstr(str, "abcd"); ptr != NULL; ptr = strstr(ptr+strlen("abcd"),"abcd")){
        n++;
    }
    printf("%d \n", n);

    fopen()

    return 0;
}

struct Student{
    char name[50];
    int age;
};

static struct Student s[3] = {0};