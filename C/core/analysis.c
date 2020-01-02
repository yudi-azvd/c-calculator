#include "analysis.h"


/**
 * Talvez eu tenha que fazer outra função pra aceitar
 * string 
 */
int is_number(char c) {
    return ('0' <= c && c <= '9');
}


int is_operator(char c) {
    if     (c == '+')
        return 1;
    else if (c == '-')
        return 1;
    else if (c == '*')
        return 1;
    else if (c == '/')
        return 1;
    else if (c == '^')
        return 1;
    return 0;
}


/* definido originalmente em calculator.h
onde essa função deve ficar? */
int is_bracket(char c);

int is_function(char c) {
    /* fazendo nada. */
    return 0;
}


int copy_to(char dest[], char src[], int start, int end) {
    int i = start, count = 0;

    for(; i < end; i++, count++)
        dest[count] = src[i];
    dest[count] = '\0';

    return count-1; // adjustment
}


/* o índice retornado é sempre o do último dígito
+ 1. */
int find_number_end(char str[], int start) {
    int end = start, number_of_dots = 0;

    while(1) {
        if (is_number(str[end])) {
            end++;
        }
        else if (str[end] == '.') {
            if (number_of_dots > 1) {
                printf("smthng went wrong in validation\n");
                return -1;
            }
            else {
                end++;
            }
        }
        else if (str[end] == '\0') {
            break;
        }
        else {
            break;
        }
    }

    return end;
}


t_list* expression_to_list(char expression[]) {
    int i, end, expr_len = strlen(expression);
    char* element;
    t_list* list = create_list("char*");

    for(i = 0; i < expr_len; i++) {
        if (is_bracket(expression[i]) != 0) {
            element = (char*) calloc(2, sizeof(char));
            element[0] = expression[i];
            element[1] = '\0';

            insert_tail(list, element);
        }
        else if (is_operator(expression[i])) {
            if (expression[i] == '-' && is_number(expression[i+1])) {
                end = find_number_end(expression, i+1);
                element = (char*) calloc(end-i+1, sizeof(char));
                i += copy_to(element, expression, i, end) + 1;

                void* data = get_tail(list);
                if (data && is_number(*((char*) data)) ) {
                    char* plus_element = calloc(2, sizeof(char));
                    plus_element[0] = '+';
                    plus_element[1] = '\0';
                    insert_tail(list, element);
                    insert_tail(list, plus_element);
                }
                else {
                    insert_tail(list, element);
                }
            }

            element = (char*) calloc(2, sizeof(char));
            element[0] = expression[i];
            element[1] = '\0';

            insert_tail(list, element);
        }
        else if (is_function(expression[i])) {
            /**
             * Pra pegar termos como:
             * 3.0*log(1.5689)+4^atan2(3, 4)
             *     ^^^^^^^^^^^   ^^^^^^^^^^^ 
             */
        }
        else if (is_number(expression[i])) {
            end = find_number_end(expression, i);
            element = (char*) calloc(end-i+1, sizeof(char));
            i += copy_to(element, expression, i, end);

            insert_tail(list, element);
        }
        else {
            printf("o que é então? [%c]\n", expression[i]);
        }
    }

    return list;
}
