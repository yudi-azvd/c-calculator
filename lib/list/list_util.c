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

char* get_char_at(t_list* l, int index) {
	return (char*) get_at_index(l, index);
}

