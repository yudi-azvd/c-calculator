#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "list.h"
#include "analysis.h"
#include "util.h"
#include "operations.h"


#define EXPRESSION_OK      0
#define EXPRESSION_INVALID 1

#define RESULT_MAX_SIZE 10


/* talvez seja melhor retornar um char** */
void calculate(char expression[], char** result);

void sanitize(char expression[]);

void evaluate(t_list* list, char** result);

t_list* to_postfix(t_list* list);

/* retornar um código de erro */
int is_valid(char expression[]);

/* tem mais cara de estar em ANALYSIS.H? */
int is_bracket(char c);

/* tem mais cara de estar em ANALYSIS.H? */
int match(char c1, char c2);

/* tem mais cara de estar em ANALYSIS.H? */
int is_balanced(char expression[]);

/* compilador reclama se o argumento for "operator" */
int get_priority(char op);

/*
t_list* to_infix(t_list* list);
*/

#endif
