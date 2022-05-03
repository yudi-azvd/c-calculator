#include "catch.hpp"
#include <iostream>
#include <string.h>

using std::string;

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_LIST_UTIL
#define _TEST_LIST_UTIL
extern "C" {
#endif
	#include "list_util.h"
#ifdef _TEST_LIST_UTIL
}
#endif


TEST_CASE("char_list_to_str", "[char_list_to_str]") {
	t_list* list;
	char* s = nullptr;

	SECTION("empty string") {
		char expression[] = "";
		list = create_char_list_from(expression);
		char_list_to_str(list);
		REQUIRE(string("") == string(char_list_str));
	}

	SECTION("sss") {
		char expression[] = "3 * 3";
		list = create_char_list_from(expression);
		char_list_to_str(list);
		REQUIRE(string("3 * 3") == string(char_list_str));
	}

	clear(list);
	free(list);
}