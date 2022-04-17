#include "catch.hpp"
#include <iostream>
#include <string.h>


// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_LIST
#define _TEST_LIST
extern "C" {
#endif
    #include "list.h"
    #include "list_util.h"
#ifdef _TEST_LIST
}
#endif


TEST_CASE("tests on get_at_index", "[get_at_index]") {
    t_list* list;
    int* data = nullptr;

    SECTION("integers") {
        list = create_list("int");

        calloc_set_int(&data, 0);
        insert_tail(list, data);

        calloc_set_int(&data, 1);
        insert_tail(list, data);

        calloc_set_int(&data, 9);
        insert_head(list, data);

        REQUIRE(9 == get_int_at(list, 0));
        REQUIRE(0 == get_int_at(list, 1));
        REQUIRE(1 == get_int_at(list, 2));
    }

    clear(list);
    free(list);
}
