#include "catch2/catch.hpp"
#include <iostream>
#include <string.h>


// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_LIST
#define _TEST_LIST
extern "C" {
#endif
    #include "list.h"
#ifdef _TEST_LIST
}
#endif

TEST_CASE("tests on get_at_index", "[get_at_index]") {
    t_list* list;

    SECTION("integers") {
        // preenchendo a lista
        int* data = (int*) calloc(1, sizeof(int));
        list = create_list("int");

        *data = 0;
        insert_tail(list, data);

        data = (int*) calloc(1, sizeof(int));
        *data = 1;
        insert_tail(list, data);

        data = (int*) calloc(1, sizeof(int));
        *data = 9;
        insert_head(list, data);

        print(list);
        // int head = *((int*) list->head->data);
        // std::cout << "head: " << head << '\n';
        // head = *((int*) get_head(list));
        // std::cout << "head: " << head << '\n';

        // REQUIRE(*((int*) get_at_index(list, 0)) == 9);
        // REQUIRE(*((int*) get_at_index(list, 1)) == 0);
        // REQUIRE(*((int*) get_at_index(list, 2)) == 2);

        int a = *((int*) get_at_index(list, 0));
        REQUIRE(a == 9);

        a = *((int*) get_at_index(list, 1));
        REQUIRE(a == 0);

        a = *((int*) get_at_index(list, 2));
        REQUIRE(a == 1);
    }

    clear(list);
    free(list);
}
