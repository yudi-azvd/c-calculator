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


TEST_CASE("create_char_list_from", "[create_char_list_from]") {
	t_list* list;
	char* s = nullptr;

	SECTION("only data type is provided") {
	    char expression[] = "";
		list = create_char_list_from(expression);
		REQUIRE(list != NULL);
		REQUIRE(list->length == 0);
	}

	SECTION("should create a list with multiple strings") {
		char expression[] = "2 * 3";
		list = create_char_list_from(expression);
		
		s = get_char_at(list, 0);
		REQUIRE(string(s) == "2");

		s = get_char_at(list, 1);
		REQUIRE(string(s) == "*");

		s = get_char_at(list, 2);
		REQUIRE(string(s) == "3");
	}

	SECTION("using multiple spaces") {
	    char expression[] = " 2\t * \n  3  ";
		list = create_char_list_from(expression);

		REQUIRE(list->length == 3);
		
		s = get_char_at(list, 0);
		REQUIRE(string(s) == "2");

		s = get_char_at(list, 1);
		REQUIRE(string(s) == "*");

		s = get_char_at(list, 2);
		REQUIRE(string(s) == "3");
	}

	clear(list);
	free(list);
}