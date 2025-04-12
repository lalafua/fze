#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

typedef enum{
    CALC_SUCCESS = 0,
    CALC_ERROR_INVALD_OPERATOR = 1,
    CALC_ERROR_DIVISION_BY_ZERO = 2,
}calc_status_t;

calc_status_t calc(double num1, const char* operator_str, double num2, double* result);

#endif