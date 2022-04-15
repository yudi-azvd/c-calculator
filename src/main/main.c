#include <stdio.h>

#include "calculator.h"
#include "user_interface.h"

#define EXPRESSION_MAX_SIZE 50
#define MAIN_LOOP 1


int main() {
    // char expression[] = "3-1*(8+3.5)/1.2";
    // char expression[] = "3-1*5+9";
    char expression[EXPRESSION_MAX_SIZE];
    char* result;

    // Simulate scanf/user input: https://pubs.opengroup.org/onlinepubs/009695399/functions/freopen.html
    while (MAIN_LOOP) {
        printf("> ");
        get_expression(expression);

        if(is_quit(expression))
            return 0;

        calculate(expression, &result);

        // if (global error variable is set to true)
        //      print error message
        // else
        display(result);
        free(result);
    }

    return 0;
}
