#include "catch2/catch.hpp"
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


TEST_CASE("double 1", "[list_double]") {
    t_list* doubles = create_list("double");

    double a = 5.67;

    insert_head(doubles, &a);
    remove_head(doubles);

    insert_head(doubles, &a);
    remove_head(doubles);

    free(doubles);
}


TEST_CASE("double 4", "[list_double]") {
    double i = .59;
    double* ptr_double = (double*) calloc(1, sizeof(double));
    t_list* list = create_list("double");

    *ptr_double = i;
    insert_head(list, ptr_double);
    ptr_double = (double*) calloc(1, sizeof(double));
    i += 0.59;

    *ptr_double = i;
    insert_head(list, ptr_double);
    ptr_double = (double*) calloc(1, sizeof(double));
    i += 0.59;

    REQUIRE(list->length == 2);

    // print(list);
    clear(list);
    free(list);
    free(ptr_double);
}
