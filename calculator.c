#include<stdio.h>
#include "calculator.h"

void cal() {
    char op;
    double num1, num2, result;

    printf("--- Calculator ---\n");
    printf("Choose an operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Give first number = ");
    scanf(" %lf",&num1);
    printf("Give second number = ");
    scanf(" %lf",&num2);
     switch (op) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
            } else {
                printf("Error: You can not divide zero (0)\n");
            }
            break;
        default:
            printf("Error: Wrong Operator!\n");
    }
}

