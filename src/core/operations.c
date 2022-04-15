#include "operations.h"


char* operate(char* operand1, char* operand2, char* operation) {
    double op1, op2, result;
    char* str_result = NULL;

    sscanf(operand1, "%lf", &op1);
    sscanf(operand2, "%lf", &op2);

    if     (*operation == '+') {
        result = op2+op1;
    }
    else if(*operation == '-') {
        result = op2-op1;
    }
    else if(*operation == '*') {
        result = op2*op1;
    }
    else if(*operation == '/') {
        result = op2/op1;
    }
    else {
        // eu sempre deixo um else de precaução
        // funções
        //      exp | ^
        //      cos
        //      sin
        //      tan
        //      log
        //      log2
    }

    str_result = calloc(OPERAND_MAX_SIZE+1, sizeof(char));
    snprintf(str_result, OPERAND_MAX_SIZE, "%lf", result);

    return str_result;
}
