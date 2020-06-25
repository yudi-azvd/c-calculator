/*
	Yudi Yamane de Azevedo

a possible implementation of linked lists
with double data

*/

#ifndef DOUBLELIST
#define DOUBLELIST

#include <stdio.h>
#include <stdlib.h>
#include "doublelist.h"

/* ## INT NODE DEFINITION ############################################ */
typedef struct double_node {
	double data;
	struct double_node* next;
}t_double_node;

t_double_node* create_double_node() {
	t_double_node* node = (t_double_node*) malloc(sizeof(t_double_node));
	node->next = NULL;
	return node;
}

t_double_node* create_double_node_with(double data) {
	t_double_node* new_node = create_double_node();
	new_node->data = data;
	return new_node;
}

/* ## INT LIST DEFINITION ########################################### */
typedef struct double_list {
	t_double_node* head;	
	t_double_node* tail;	
}t_double_list;

t_double_list* create_double_list() {
	t_double_list* list = (t_double_list*) malloc(sizeof(t_double_list));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

/* ## ESSENTIAL FUNCTIONS ############################################ */
int empty_double_list(t_double_list* list) {
	if(list->head == NULL)
		return 1;
	return 0;
}

void print_double_list(t_double_list* list) {
	t_double_node* node;

	if(!empty_double_list(list)) {
		node = list->head;

		while(node != NULL) {
			printf("%.2lf-> ", node->data);
			node = node->next;
		}

		printf("NULL\n");
	}
}

void add_double_head(double data, t_double_list* list) {
	// t_double_node* new_node = 	t_double_node* node = (t_double_node*) malloc(sizeof(t_double_node));
	// new_node->next = data;
	t_double_node* new_node = create_double_node_with(data);
	new_node->next = list->head;
	list->head = new_node;

	if(list->tail == NULL)
		list->tail = new_node;
}

void add_double_tail(double data, t_double_list* list) {
	t_double_node* new_node = create_double_node_with(data);

	if(empty_double_list(list))
		list->head = new_node;
	else 
		list->tail->next = new_node;
	list->tail = new_node;
}

double remove_double_head(t_double_list* list) {
	double data;
	t_double_node* node = list->head;

	if(!empty_double_list(list)) {
		data = node->data;
		list->head = node->next;
		free(node);
		return data;
	}

	return -1;
}

double remove_double_tail(t_double_list* list) {
	double data;
	t_double_node* node = list->head;

	if(empty_double_list(list))
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
int double_list_length(t_double_list* list) {
	int len = 0;
	t_double_node* node = list->head;

	while(node != NULL) {
		len++;
		node = node->next;
	}

	return len;
}

int equal_double_lists(t_double_list* list1, t_double_list* list2) {
	t_double_node* node1 = list1->head;
	t_double_node* node2 = list2->head;

	if(double_list_length(list1) != double_list_length(list2))
		return 0;
	
	while(node1 != NULL) {
		if(node1->data != node2->data)
			return 0;

		node1 = node1->next;
		node2 = node2->next;
	}

	return 1;
}


t_double_list* double_list_cpy(t_double_list* list) {
	t_double_list*  copy = create_double_list();

	return copy;
}

#endif
