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


TEST_CASE("char list w/ soft_clear", "[list-char]") {
    char* data = (char*) calloc(1, sizeof(char));
    t_list* chars = create_list("char");

    *data = 'a';
    insert_head(chars, data);

    (*data)++;
    insert_head(chars, data);

    (*data)++;
    insert_head(chars, data);

    REQUIRE(*(char*) (get_head(chars)) == 'c');

    // print(chars);
    soft_clear(chars);
    free(chars);
    free(data);
}


TEST_CASE("char list", "[list-char]") {
    char* data = (char*) calloc(1, sizeof(char));
    t_list* chars = create_list("char");

    *data = 'a';
    insert_head(chars, data);

    data = (char*) calloc(1, sizeof(char));
    *data = 'b';
    insert_head(chars, data);

    data = (char*) calloc(1, sizeof(char));
    *data = 'c';
    insert_head(chars, data);

    REQUIRE(*(char*) (get_head(chars)) == 'c');
    // REQUIRE(*(char*) (peek(chars)) == 'c');

    // print(chars);
    clear(chars);
    free(chars);
    // free(data); // clear() já cuida desse ponteiro.
}
