#include "calculator.h"

void calculate(char expression[], char** result) {
    sanitize(expression);

    if (is_valid(expression)) {
        // tokenize
        t_list* list = expression_to_list(expression);

        evaluate(list, result);
        clear(list);
        free(list);
    }
    else {
        /* como retornar um erro daqui?
        é necessário? */
        return;
    }
}


void evaluate(t_list* expression, char** result) {
    char* element;
    t_node* curr_node;

    t_list* postfix = to_postfix(expression);
    t_stack* stack = create_stack("char*");

    // print(postfix);

    for(curr_node=postfix->head; curr_node!=NULL; curr_node=curr_node->next) {
        element = (char*) curr_node->data;

        if(is_number(element[0])
            || ( element[0] == '-' && is_number(element[1]))
            ) {

            char* copied_element = calloc(strlen(element)+1, sizeof(char));
            strcpy(copied_element, element);
            push(stack, copied_element);
            // push(stack, element);
        }
        else if(is_operator(element[0])) {
            // char* operand1 = soft_pop(stack);
            // char* operand2 = soft_pop(stack);

            char* operand1 = soft_pop(stack);
            char* operand2 = soft_pop(stack);
            char* result = NULL;

            result = operate(operand1, operand2, element);
            free(operand1);
            free(operand2);

            // printf("result %s\n", result);
            push(stack, result);
        }
    }

    soft_clear(postfix);
    free(postfix);

    // printf("RESULTADO FINAL: %s\n", (char*) peek(stack));
    if (stack->length != 1) {
        printf("%s\n", "ALGUMA COISA DEU ERRADO");
    }

    *result = (char*) calloc(RESULT_MAX_SIZE, sizeof(char));
    strcpy(*result, (char*) peek(stack));

    clear(stack);
    free(stack);
}


t_list* to_postfix(t_list* expression) {
    if(is_empty(expression))
        return NULL;

    char* element = NULL;
    t_node* curr_node;
    t_list* output = create_list("char*");
    t_stack* stack = create_stack("char*");

    for(curr_node = expression->head; curr_node!= NULL; curr_node=curr_node->next) {
        element = (char*) curr_node->data;

        if(is_number(*element)  ) {
            insert_tail(output, element);
        }

        else if(is_operator(*element)) {
            char* last_operator = (char*) peek(stack);

            while(!is_empty(stack) && get_priority(*last_operator) 
                >= get_priority(*element)) {

                insert_tail(output, soft_pop(stack));
            }
            push(stack, element);
        }

        else if(is_bracket(*element) < 0) {
            push(stack, element);
        }

        else if(is_bracket(*element) > 0) {
            while(1) {
                char* poped = (char*) soft_pop(stack);

                if (is_bracket(*poped) < 0)
                    break;
                insert_tail(output, poped);
            }

            // if (is_bracket(*(char*)peek(stack)) < 0) {
            //     soft_pop(stack);
            // }
        }
        else {

        }
    }

    while(!is_empty(stack))
        insert_tail(output, soft_pop(stack));

    soft_clear(stack);
    free(stack);

    return output;
}


void sanitize(char expression[]) {
    remove_whitespace(expression);
    remove_illegalchars(expression);
    /*
    remove double points
    remove double operations?
    remove illegal chars
    */
}


int is_valid(char expression[]) {
    /*
    int expr_lentgh = strlen(expression);
    int balanced = is_balanced(expression);
    balanceada
    não tem mais de dois pontos seguidos
    não tem virgulas?
    tem operações/funções conhecidas
    */
    return 1;
}


int is_bracket(char c) {
    if(c == '(' || c == '[' || c == '{')
		return -1;
	if(c == ')' || c == ']' || c == '}')
		return 1;
	return 0;
}


int match(char c1, char c2) {
	if(c1 == '(' && c2 == ')')
		return 1;
	if(c1 == '[' && c2 == ']')
		return 1;
	if(c1 == '{' && c2 == '}')
		return 1;
	return 0;
}


int is_balanced(char expression[]) {
    int i, expr_lentgh = strlen(expression);
    t_stack* brackets_stack = create_stack("char");

    for(i = 0; i < expr_lentgh; i++) {
        if(is_bracket(expression[i]) < 0)
            push(brackets_stack, &expression[i]);
        if(is_bracket(expression[i]) > 0) {
            if(!is_empty(brackets_stack)) {
                if(match(expression[i], *((char*) peek(brackets_stack))))
                    remove_head(brackets_stack);
                else {
                    soft_clear(brackets_stack);
                    free(brackets_stack);
                    return 0;
                }
            }
            else {
                soft_clear(brackets_stack);
                free(brackets_stack);
                return 0;
            }
        }
    }

    if (is_empty(brackets_stack)) {
        free(brackets_stack);
        return 1;
    }

    soft_clear(brackets_stack);
    free(brackets_stack);
    return 0;
}


int get_priority(char c) {
    if     (1 == 0)
    // if     (c == '(' || c == ')')
		return 3;
    else if(c == '^')
		return 2;
    else if(c == '*' || c == '/')
		return 1;
	else if(c == '+' || c == '-')
		return 0;
	else if(is_number(c))
		return -1;
	else
		return -2;
}
