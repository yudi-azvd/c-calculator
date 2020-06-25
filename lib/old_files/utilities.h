/*
	some random functions
*/

#ifndef UTILITIES
#define UTILITIES

#include <stdio.h>
#include "utilities.h"
#include "strlist.h"
#include "charlist.h"

int power(int base, int exp) {
	int i, result = 1;

	for(i = 0; i < exp; i++)
		result *= base;
	return result;
}

int len_n1(int n) {
	int counter = 1;

	n = n > 0 ? n : -n;

	if(n == 0)
		return 1;

	while(n - power(10, counter) >= 0)
		counter++;
	return counter;
}

int len_n2(int n) {
	if(n == 0)
		return 1;
	return (int) log10(n)+1;
}

void itoa(int n, char str[]) {
	int i = 0, j, len, pw, digit;

	if(n < 0) {
		n = -n;
		str[i] = '-';
		i++;
	}

	len = len_n2(n);

	for(j = len-1; j >= 0; j--, i++) {
		digit = 0;
		pw = power(10, j);

		while(n - digit*pw >= pw) {
			digit++;
		}

		str[i] = '0' + digit;
		n -= digit*pw;
	}

	str[i] = '\0';
}

// int copy_to(char dest[], char src[], int start, int end) {
// 	int i = start, count = 0;
//
// 	for(; i < end; i++, count++)
// 		dest[count] = src[i];
// 	dest[count] = '\0';
//
// 	return count-1; // adjustment
// }

// int is_operator(char c) {
// 	if     (c == '+')
// 		return 1;
// 	else if(c == '-')
// 		return 1;
// 	else if(c == '*')
// 		return 1;
// 	else if(c == '/')
// 		return 1;
// 	return 0;
// }

// void removespc(char str[]) {
// 	int i;
// 	t_char_list* char_list = create_char_list();
// 	t_char_node* node;
//
// 	for(i = 0; i < strlen(str); i++) {
// 		if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
// 			add_char_tail(str[i], char_list);
// 		}
// 	}
//
// 	i = 0;
// 	node = char_list->head;
// 	while(node != NULL) {
// 		str[i] = node->data;
// 		node = node->next;
// 		i++;
// 	}
// 	str[i] = '\0';
//
// 	clear_char_list(char_list);
// }

// int is_number(char c) {
// 	if('0' <= c && c <= '9')
// 		return 1;
// 	return 0;
// }

int priority(char c) {
	if     (c == '*' || c == '/')
		return 1;
	else if(c == '+' || c == '-')
		return 0;
	else if(is_number(c))
		return -1;
	else
		return -2;
}

// int match(char c1,  char c2) {
// 	if(c1 == '(' && c2 == ')')
// 		return 1;
// 	if(c1 == '[' && c2 == ']')
// 		return 1;
// 	if(c1 == '{' && c2 == '}')
// 		return 1;
// 	return 0;
// }

// int is_bracket(char c) {
// 	if(c == '(' || c == '[' || c == '{')
// 		return -1;
// 	if(c == ')' || c == ']' || c == '}')
// 		return 1;
// 	return 0;
// }

// reduce redundancy... if possible
// int balanced(char expression[]) {
// 	int i;
// 	t_char_list* stack = create_char_list();
//
// 	for(i = 0; i < strlen(expression); i++) {
// 		if(is_bracket(expression[i]) < 0)
// 			add_char_head(expression[i], stack);
//
// 		if(is_bracket(expression[i]) > 0) {
// 			if(!empty_char_list(stack)) {
// 				if(match(stack->head->data, expression[i]))
// 					remove_char_head(stack);
// 				else {
// 					clear_char_list(stack);
// 					return 0;
// 				}
// 			}
// 			else {
// 				clear_char_list(stack);
// 				return 0;
// 			}
// 		}
// 	}
//
// 	if(empty_char_list(stack))
// 		return 1;
// 	clear_char_list(stack);
// 	return 0;
// }


// int find_number_end(char str[], int start) {
// 	int end = start, number_of_dots=0;
//
// 	while(1) {
// 		if (is_number(str[end])) {
// 			end++;
// 		}
// 		else if(str[end] == '.') {
// 			if(number_of_dots > 1) {
// 				printf("smthng went wrong in validation\n");
// 				return -1;
// 			}
// 			else {
// 				end++;
// 			}
// 		}
// 		else if (str[end] == '\0') {
// 			break;
// 		}
// 		else {
// 			break;
// 		}
// 	}
//
// 	return end;
// }

t_str_list* to_str_list(char expression[]) {
	int i, end;
	char element[SIZE]; // assuming numbers will not have more than 49 digits
	t_str_list* expr = create_str_list();

	for(i = 0; i < strlen(expression); i++) {
		element[0] = '\0'; // reset string
		if(is_bracket(expression[i]) != 0) {
			copy_to(element, expression, i, i+1);
		}
		else if(is_operator(expression[i])) {
			copy_to(element, expression, i, i+1);
		}
		else if(is_number(expression[i])){ // is as number
			end = find_number_end(expression, i+1); // expression[i] is always a number
			i += copy_to(element, expression, i, end);
		}
		else {
			printf("it's a function: for the future\n");
		}

		add_str_tail(element, expr);
	}

	return expr;
}

#endif
