#include "catch.hpp"
#include <iostream>
#include <string.h>

using namespace std;

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_PARSER
#define _TEST_PARSER
extern "C" {
#endif
    #include "../../core/scanner.h"
#ifdef _TEST_PARSER
}
#endif

TEST_CASE("tokenize", "[tokenize]") {
    t_list* list;

    SECTION("1") {
        char expression[] = "3*1.5+4";

        list = tokenize(expression);

        string str = ((char*) get_at_index(list, 0));
        REQUIRE(str == "3");

        str = ((char*) get_at_index(list, 1));
        REQUIRE(str == "*");

        str = ((char*) get_at_index(list, 2));
        REQUIRE(str == "1.5");

        str = ((char*) get_at_index(list, 3));
        REQUIRE(str == "+");

        str = ((char*) get_at_index(list, 4));
        REQUIRE(str == "4");
    }

    SECTION("2") {
        char expression[] = "3.000*1.5689+4^";

        list = tokenize(expression);

        string str = ((char*) get_at_index(list, 0));
        REQUIRE(str == "3.000");

        str = ((char*) get_at_index(list, 1));
        REQUIRE(str == "*");

        str = ((char*) get_at_index(list, 2));
        REQUIRE(str == "1.5689");

        str = ((char*) get_at_index(list, 3));
        REQUIRE(str == "+");

        str = ((char*) get_at_index(list, 4));
        REQUIRE(str == "4");

        str = ((char*) get_at_index(list, 5));
        REQUIRE(str == "^");
    }

    // https://github.com/yudi-azvd/c-calculator/issues/2
    SECTION("issue GH#2") {
        char expression[] = "3*3-6/2";

        list = tokenize(expression);

        string str = (char*) get_at_index(list, 0);
        REQUIRE(string(str) == "3");

        str = (char*) get_at_index(list, 1);
        REQUIRE(string(str) == "*");

        str = (char*) get_at_index(list, 2);
        REQUIRE(string(str) == "3");

        str = (char*) get_at_index(list, 3);
        REQUIRE(string(str) == "-");

        str = (char*) get_at_index(list, 4);
        REQUIRE(string(str) == "6");

        str = (char*) get_at_index(list, 5);
        REQUIRE(string(str) == "/");

        str = (char*) get_at_index(list, 6);
        REQUIRE(string(str) == "2");
    }

    clear(list);
    free(list);
}
