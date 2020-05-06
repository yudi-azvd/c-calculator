/*
	Yudi Yamane - 2018

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "lib/utilities.h"
#include "lib/intlist.h"
#include "lib/doublelist.h"
#include "lib/charlist.h"
#include "lib/strlist.h"

#define TAM 1000000

/* ## READ INPUT  ################################################################ */
/* Reads input directly from commandline */
void read_cmdline(char expression[]) {
	fgets(expression, strlen(expression), stdin);
}

/* Reads input from files passed in argv */
int read_files(char expression[], char answ[], char* argv[]) {
	char expr_filename[30];
	char answ_filename[30];

	strcpy(expr_filename, argv[1]);
	strcpy(answ_filename, argv[2]);

	FILE* fp_expr = fopen(expr_filename, "r");
	FILE* fp_answ = fopen(answ_filename, "r");

	if(!fp_expr || !fp_answ) {
		printf("NOT possible to open %s or %s\n", expr_filename, answ_filename);
		return -1;
	}

	fgets(expression, TAM, fp_expr);
	fgets(answ, 	  50, 	  fp_answ);

	fclose(fp_expr);
	fclose(fp_answ);

	return 1;
}

/* ## VALIDATION ################################################################ */
/* Checks if expression[] is valid */
int valid(char expression[]) {
	int i;

	removespc(expression);

	for(i = 0; i < strlen(expression); i++) {
		// check for:
		// 		signs
		//		valid numbers
		//		balanced brackets
		printf("%s", "\0");
	}
	
	if(balanced(expression))
		return 1;
	return 0;	
}

/* ## EVALUATION ################################################################ */
/* Converts a infix expression to a postfix. Still not working. */
t_str_list* to_postfix(t_str_list* expression) {
	// check br priority
	// maybe keep just paretheses
	char aux_str[SIZE];
	t_str_node* current = expression->head;
	t_str_list* stack = create_str_list();
	t_str_list* postfix_expression = create_str_list();
	//          STACK

	while(current != NULL) {
		aux_str[0] = '\0';

		// printf("current    %s\n", current->data);
		// printf("current[0] %c\n", current->data[0]);

		if(is_number(current->data[0])) {
			add_str_tail(current->data, postfix_expression);
		}
		else if(is_operator(current->data[0])) {
			// printf("IT'S AN OPERATOR |%c| |%c|\n", postfix_expression->head->data[0], current->data[0]);
			while(!empty_str_list(stack) 
				&& priority(postfix_expression->head->data[0]) >= priority(current->data[0])) {
				remove_str_head(stack, aux_str); // aux_str should be an operator
				add_str_tail(aux_str, postfix_expression);
			}
		}
		else if(is_bracket(current->data[0]) < 0) {
			add_str_tail(current->data, stack);
		}
		else if(is_bracket(current->data[0]) > 0) {
			do {
				// printf("%c", current->data[0]);
				// print_str_list(stack);
				remove_str_head(stack, aux_str);
				if(is_bracket(aux_str[0]) == 0) // the the br will not be added
					add_str_tail(aux_str, postfix_expression);
				// if(empty_str_list(stack))
				// 	break;
				// printf("%s\n", aux_str);
				// printf("%c | %c\n", aux_str[0], current->data[0]);
				getchar();
			} while(!match(aux_str[0], current->data[0]));
		}

		current = current->next;
	}

	// printf("stack ");
	// print_str_list(stack);

	while(!empty_str_list(stack)) {
		remove_str_head(stack, aux_str);
		add_str_tail(aux_str, postfix_expression);
	}

	printf("postfix_expression ");
	print_str_list(postfix_expression);

	// printf("end of to_postfix\n");
	// print_str_list(postfix_expression);
	// clear expression;
	return postfix_expression;
}

/* Evaluates the expression */
double evaluate(char expression[]) {
	t_str_list* expr = create_str_list();
	t_str_list* postfix_expression = create_str_list();

	expr = to_str_list(expression);
	print_str_list(expr);

	postfix_expression = to_postfix(expr);

	return 100.1;
}

/* ## SCORE ##################################################################### */
/* Updates the score (just a number, nothing fancy) wich is storaged in score.txt */
void score_update() {
	int int_score;
	char str_score[5];
	char score_filename[] = "score.txt";
	FILE* fp = fopen(score_filename, "r");

	if(!fp) {
		printf("not possible to open %s\n", score_filename);
		return;
	}

	fscanf(fp, "%s", str_score);
	int_score = atoi(str_score)+1;
	fclose(fp);

	// erase file content
	fp = fopen(score_filename, "w");

	if(!fp) {
		printf("not possible to open %s\n", score_filename);
		return;
	}

	itoa(int_score, str_score); // change the value str_score

	fprintf(fp, "%s", str_score);
	fclose(fp);
}

/* Checks if result is correct */
int is_result_correct(double result, char answ[]) {
	char res[SIZE];

	itoa(result, res);

	if(strcmp(res, answ) == 0)
		return 1;
	return 0;
}

/* Main function: reads expression, checks for the validity of the expression,
   evaluates the expression (if valid), outputs the result 					   */
int main(int argc, char* argv[]) {
	double result;
	char expression[TAM];
	char answ[TAM/2];

	read_files(expression, answ, argv);
	// read_cmdline(expression, argv);

	// printf("expression: %s\n", expression);
	/*	
	
	read expression
	while expression not valid
		read expression
	*/
	if(valid(expression)) {
		result = evaluate(expression);
	}

	printf("result : %.2lf\n", result);

	if(is_result_correct(result, answ))
		score_update();

	return 0;
}