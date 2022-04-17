#include "list_util.h"

// https://stackoverflow.com/questions/4513316/split-string-in-c-every-white-space
t_list* create_char_list_from(char* str) {
	t_list* l = create_list("char*");

	char* delimeters = " \t\n";
	char* last_token_found = strtok(str, delimeters);
	while (last_token_found != NULL) {
		char* s = calloc(1, strlen(last_token_found)+1);
		strcpy(s, last_token_found);
		insert_tail(l, s);

		last_token_found = strtok(NULL, delimeters);
	}

	return l;
}

void calloc_set_int(int** data, int value) {
	*data = (int*) calloc(1, sizeof(int));
	**data = value;
}

void char_list_to_str(t_list* l) {
	char_list_str[0] = '\0';
	int offset = 0;
	t_node* curr = l->head;
	while (curr) {
		int str_len = strlen((char*) curr->data);
		strcat(char_list_str+offset, (char*) curr->data);
		offset += str_len;
		strcat(char_list_str+offset, " ");
		curr = curr->next;
	}
	char_list_str[offset] = '\0';
}