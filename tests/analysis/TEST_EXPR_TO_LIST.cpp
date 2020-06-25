#include "catch2/catch.hpp"
#include <iostream>
#include <string.h>

using namespace std;

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_ANALYSIS
#define _TEST_ANALYSIS
extern "C" {
#endif
    #include "analysis.h"
#ifdef _TEST_ANALYSIS
}
#endif

TEST_CASE("expression_to_list", "[expression_to_list]") {
    t_list* list;

    SECTION("1") {
        char expression[] = "3*1.5+4";

        list = expression_to_list(expression);

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

        list = expression_to_list(expression);

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

    clear(list);
    free(list);
}
