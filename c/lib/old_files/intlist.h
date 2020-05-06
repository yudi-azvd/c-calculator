/*
	Yudi Yamane de Azevedo

a possible implementation of linked lists
with integers

*/

#ifndef INTLIST
#define INTLIST

#include <stdio.h>
#include <stdlib.h>
/*#include "intlist.h"
*/
/* ## INT NODE DEFINITION ############################################ */
typedef struct int_node {
	int data;
	struct int_node* next;
}t_int_node;

t_int_node* create_int_node() {
	t_int_node* node = (t_int_node*) malloc(sizeof(t_int_node));
	node->next = NULL;
	return node;
}

t_int_node* create_int_node_with(int data) {
	t_int_node* new_node = create_int_node();
	new_node->data = data;
	return new_node;
}

/* ## INT LIST DEFINITION ########################################### */
typedef struct int_list {
	t_int_node* head;	
	t_int_node* tail;	
}t_int_list;

t_int_list* create_int_list() {
	t_int_list* list = (t_int_list*) malloc(sizeof(t_int_list));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

/* ## ESSENTIAL FUNCTIONS ############################################ */
int empty_int_list(t_int_list* list) {
	if(list->head == NULL)
		return 1;
	return 0;
}

void print_int_list(t_int_list* list) {
	t_int_node* node;

	if(!empty_int_list(list)) {
		node = list->head;

		while(node != NULL) {
			printf("%d-> ", node->data);
			node = node->next;
		}

		printf("NULL\n");
	}
}

void add_int_head(int data, t_int_list* list) {
	// t_int_node* new_node = 	t_int_node* node = (t_int_node*) malloc(sizeof(t_int_node));
	// new_node->next = data;
	t_int_node* new_node = create_int_node_with(data);
	new_node->next = list->head;
	list->head = new_node;

	if(list->tail == NULL)
		list->tail = new_node;
}

void add_int_tail(int data, t_int_list* list) {
	t_int_node* new_node = create_int_node_with(data);

	if(empty_int_list(list))
		list->head = new_node;
	else 
		list->tail->next = new_node;
	list->tail = new_node;
}

int remove_int_head(t_int_list* list) {
	int data;
	t_int_node* node = list->head;

	if(!empty_int_list(list)) {
		data = node->data;
		list->head = node->next;
		free(node);
		return data;
	}

	return -1;
}

int remove_int_tail(t_int_list* list) {
	int data;
	t_int_node* node = list->head;

	if(empty_int_list(list))
		return -1;
	else if(node == NULL) {
		data = node->data;
		free(list->head);
		free(list->tail);
		list->head = NULL;
		list->tail = NULL;
	}
	else {
		while(node->next->next != NULL)
			node = node->next;
		data = node->next->data;
		free(node->next);
		list->tail = node;
		node->next = NULL;
	}

	return data;
}

/* ## ADITIONAL FUNCTIONS ####################################### */
int int_list_length(t_int_list* list) {
	int len = 0;
	t_int_node* node = list->head;

	while(node != NULL) {
		len++;
		node = node->next;
	}

	return len;
}

int equal_int_lists(t_int_list* list1, t_int_list* list2) {
	t_int_node* node1 = list1->head;
	t_int_node* node2 = list2->head;

	if(int_list_length(list1) != int_list_length(list2))
		return 0;

	while(node1 != NULL) {
		if(node1->data != node2->data)
			return 0;

		node1 = node1->next;
		node2 = node2->next;
	}

	return 1;
}

t_int_list* int_list_cpy(t_int_list* list) {
	t_int_list*  copy = create_int_list();

	return copy;
}

t_int_list* sum_of_two_numbers_represented_by_lists(t_int_list* list1, t_int_list* list2) {
	t_int_list* sum = create_int_list();

	return sum;
}

#endif
