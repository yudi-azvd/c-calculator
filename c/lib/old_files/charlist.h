/*
	Yudi Yamane de Azevedo

a possible implementation of linked lists
with characters

*/

#ifndef CHARLIST
#define CHARLIST

#include <stdio.h>
#include <stdlib.h>
#include "charlist.h"

/* ## INT NODE DEFINITION ############################################ */
typedef struct char_node {
	char data;
	struct char_node* next;
} t_char_node;

t_char_node* create_char_node() {
	t_char_node* node = (t_char_node*) malloc(sizeof(t_char_node));
	node->next = NULL;
	return node;
}

t_char_node* create_char_node_with(char data) {
	t_char_node* new_node = create_char_node();
	new_node->data = data;
	return new_node;
}

/* ## INT LIST DEFINITION ########################################### */
typedef struct char_list {
	t_char_node* head;	
	t_char_node* tail;	
}t_char_list;

t_char_list* create_char_list() {
	t_char_list* list = (t_char_list*) malloc(sizeof(t_char_list));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

/* ## ESSENTIAL FUNCTIONS ############################################ */
int empty_char_list(t_char_list* list) {
	if(list->head == NULL)
		return 1;
	return 0;
}

void print_char_list(t_char_list* list) {
	t_char_node* node;

	if(!empty_char_list(list)) {
		node = list->head;

		printf("'");
		while(node != NULL) {
			printf("%c", node->data);
			node = node->next;
		}

		printf("' NULL\n");
	}
}

void add_char_head(char data, t_char_list* list) {
	// t_char_node* new_node = 	t_char_node* node = (t_char_node*) malloc(sizeof(t_char_node));
	// new_node->next = data;
	t_char_node* new_node = create_char_node_with(data);
	new_node->next = list->head;
	list->head = new_node;

	if(list->tail == NULL)
		list->tail = new_node;
}

void add_char_tail(char data, t_char_list* list) {
	t_char_node* new_node = create_char_node_with(data);

	if(empty_char_list(list))
		list->head = new_node;
	else 
		list->tail->next = new_node;
	list->tail = new_node;
}

char remove_char_head(t_char_list* list) {
	char data;
	t_char_node* node = list->head;

	if(!empty_char_list(list)) {
		data = node->data;
		list->head = node->next;
		free(node);
		return data;
	}

	return -1;
}

char remove_char_tail(t_char_list* list) {
	char data;
	t_char_node* node = list->head;

	if(empty_char_list(list))
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
void clear_char_list(t_char_list* list) {
	while(!empty_char_list(list))
		remove_char_head(list);
}

int char_list_length(t_char_list* list) {
	int len = 0;
	t_char_node* node = list->head;

	while(node != NULL) {
		len++;
		node = node->next;
	}

	return len;
}

int equal_char_lists(t_char_list* list1, t_char_list* list2) {
	t_char_node* node1 = list1->head;
	t_char_node* node2 = list2->head;

	if(char_list_length(list1) != char_list_length(list2))
		return 0;
	
	while(node1 != NULL) {
		if(node1->data != node2->data)
			return 0;

		node1 = node1->next;
		node2 = node2->next;
	}

	return 1;
}


t_char_list* char_list_cpy(t_char_list* list) {
	t_char_list*  copy = create_char_list();

	return copy;
}

#endif
