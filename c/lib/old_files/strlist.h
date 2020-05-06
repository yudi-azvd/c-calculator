/*
	Yudi Yamane de Azevedo

a possible implementation of linked lists
with strings

*/

#ifndef STRLIST
#define STRLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strlist.h"

#define SIZE 50

/* ## INT NODE DEFINITION ############################################ */
typedef struct str_node{
	char data[SIZE];
	struct str_node* next;
} t_str_node;

t_str_node* create_str_node() {
	t_str_node* node = (t_str_node*) malloc(sizeof(t_str_node));
	node->next = NULL;
	return node;
}

t_str_node* create_str_node_with(char data[SIZE]) {
	t_str_node* new_node = create_str_node(); 
	strcpy(new_node->data, data);
	return new_node;
}

/* ## INT LIST DEFINITION ########################################### */
typedef struct str_list {
	t_str_node* head;	
	t_str_node* tail;	
}t_str_list;

t_str_list* create_str_list() {
	t_str_list* list = (t_str_list*) malloc(sizeof(t_str_list));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

/* ## ESSENTIAL FUNCTIONS ############################################ */
int empty_str_list(t_str_list* list) {
	if(list->head == NULL)
		return 1;
	return 0;
}

void print_str_list(t_str_list* list) {
	t_str_node* node;

	if(!empty_str_list(list)) {
		node = list->head;

		while(node != NULL) {
			printf("\"%s\" ", node->data);
			node = node->next;
		}

		printf("NULL\n");
	}
}

void add_str_head(char data[SIZE], t_str_list* list) {
	// t_str_node* new_node = 	t_str_node* node = (t_str_node*) malloc(sizeof(t_str_node));
	// new_node->next = data;
	t_str_node* new_node = create_str_node_with(data);
	new_node->next = list->head;
	list->head = new_node;

	if(list->tail == NULL)
		list->tail = new_node;
}

void add_str_tail(char data[SIZE], t_str_list* list) {
	t_str_node* new_node = create_str_node_with(data);

	if(empty_str_list(list))
		list->head = new_node;
	else 
		list->tail->next = new_node;
	list->tail = new_node;
}

// return WARNING
void remove_str_head(t_str_list* list, char str[]) {
	t_str_node* node = list->head;

	if(!empty_str_list(list)) {
		strcpy(str, node->data);
		list->head = node->next;
		free(node);
	}
}

// return WARNING
void remove_str_tail(t_str_list* list, char str[]) {
	t_str_node* node = list->head;

	if(empty_str_list(list)) {
		// do what ?
	}
	else if(node == NULL) {
		strcpy(str, node->data);
		free(list->head);
		free(list->tail);
		list->head = NULL;
		list->tail = NULL;
	}
	else {
		while(node->next->next != NULL)
			node = node->next;
		strcpy(str, node->next->data);
		free(node->next);
		list->tail = node;
		node->next = NULL;
	}
}

/* ## ADITIONAL FUNCTIONS ####################################### */
int str_list_length(t_str_list* list) {
	int len = 0;
	t_str_node* node = list->head;

	while(node != NULL) {
		len++;
		node = node->next;
	}

	return len;
}

int equal_str_lists(t_str_list* list1, t_str_list* list2) {
	t_str_node* node1 = list1->head;
	t_str_node* node2 = list2->head;

	if(str_list_length(list1) != str_list_length(list2))
		return 0;

	while(node1 != NULL) {
		if(node1->data != node2->data)
			return 0;

		node1 = node1->next;
		node2 = node2->next;
	}

	return 1;
}

t_str_list* str_list_cpy(t_str_list* list) {
	t_str_list*  copy = create_str_list();

	return copy;
}

void clear_str_list(t_str_list* list) {
	char trash[SIZE];
	while(!empty_str_list(list))
		remove_str_head(list, trash);
}



#endif
