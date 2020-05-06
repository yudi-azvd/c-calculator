#include <stdio.h>
#include "user_interface.h"

void get_expression(char* expression) {
  scanf("%[^\n]%*c", expression);
}

int is_quit(char* input) {
	if (input[0] == 'q')
		return 1;
	return 0;
}

void display(char* to_display) {
	printf("%s\n", to_display);
}


/*
void prompt_user() {
  printf("> ");
  getusrinput();
}

void getusrinput(char *str, int size) {
    scanf("%[^\n]%*c", str);
}
*/