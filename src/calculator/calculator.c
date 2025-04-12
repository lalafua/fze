#include <stdio.h>
#include <string.h>
#include "calculator.h"

calc_status_t calc(double num1, const char* operator_str, double num2, double* result){
    if (strcmp(operator_str, "+") == 0){
        *result = num1 + num2;
    }
    
    else if (strcmp(operator_str, "-") == 0){
        *result = num1 - num2;
    }
    
    else if (strcmp(operator_str, "*") == 0){
        *result = num1 * num2;
    }
    
    else if (strcmp(operator_str, "/") == 0){
        if (num2 == 0){
            fprintf(stderr, "error: can't division by s0. \n");
            return CALC_ERROR_DIVISION_BY_ZERO;
        }
        *result = num1 / num2;
    }
    
    else {
        fprintf(stderr, "invailed operator '%s'. \n ", operator_str);
        fprintf(stderr, "supported operator: + - * /. \n");
        return CALC_ERROR_INVALD_OPERATOR;
    }

    return CALC_SUCCESS;
}