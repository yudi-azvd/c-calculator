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


TEST_CASE("create, insert, remove e free(list)", "[list]") {
    t_list* integers = create_list("int");

    int a = 5;

    insert_head(integers, &a);
    remove_head(integers);

    insert_head(integers, &a);
    remove_head(integers);

    free(integers);
}

// soft_clear é para listas cujas ponteiros data não foram
// alocados dinamicamente.
TEST_CASE("create, insert_head, soft_clear e free(list)", "[list]") {
    //! [soft_clear_1]
    t_list* integers = create_list("int");

    int a = 5;

    insert_head(integers, &a);
    soft_clear(integers);

    insert_head(integers, &a);
    soft_clear(integers);

    free(integers);
    //! [soft_clear_1]
}


TEST_CASE("get_head", "[list]") {
    //! [soft_clear_2]
    t_list* strings = create_list("char*");

    char str1[] = "lista";
    char str2[] = "abacaxi";
    char str3[] = "land rover";

    insert_head(strings, str1);
    insert_head(strings, str2);
    insert_head(strings, str3);

    char str[15];
    strcpy(str, (char*) get_head(strings));

    REQUIRE(strcmp(str, "land rover") == 0);

    soft_clear(strings);
    free(strings);
    //! [soft_clear_2]
}

TEST_CASE("get_tail", "[list]") {
    t_list* strings = create_list("char*");

    char str1[] = "lista";
    char str2[] = "abacaxi";
    char str3[] = "land rover";

    insert_head(strings, str1);
    insert_head(strings, str2);
    insert_head(strings, str3);

    char str[15];
    strcpy(str, (char*) get_tail(strings));

    REQUIRE(strcmp(str, "lista") == 0);

    soft_clear(strings);

    REQUIRE(get_tail(strings) == NULL);

    free(strings);
}


//! [clear_1]
TEST_CASE("multiple insert_head", "[list]") {
    int* ptr_int = (int*) calloc(1, sizeof(int));
    t_list* list = create_list("int");

    int i = 0;
    while(i < 3) {
        *ptr_int = i;
        insert_head(list, ptr_int);
        ptr_int = (int*) calloc(1, sizeof(int));
        i++;
    }

    REQUIRE(list->length == 3);

    clear(list);
    free(list);
    free(ptr_int);
}
//! [clear_1]

TEST_CASE("multiple insert_tail", "[list]") {
    int* ptr_int = (int*) calloc(1, sizeof(int));
    t_list* list = create_list("int");

    int i = 0;
    while(i < 5) {
        *ptr_int = i;
        insert_tail(list, ptr_int);
        ptr_int = (int*) calloc(1, sizeof(int));
        i++;
    }

    REQUIRE(list->length == 5);
    REQUIRE(*((int*) get_tail(list)) == 4);
    REQUIRE(*((int*) get_head(list)) == 0);

    // print(list);
    clear(list);
    free(list);
    free(ptr_int);
}


TEST_CASE("delete_head", "[list]") {
    int* ptr_int = (int*) calloc(1, sizeof(int));
    t_list* list = create_list("int");

    SECTION("created list is empty") {
        REQUIRE(is_empty(list) == true);
    }

    SECTION("add elements to list") {
        int i = 0;
        while(i < 5) {
            *ptr_int = i;
            insert_head(list, ptr_int);
            ptr_int = (int*) calloc(1, sizeof(int));
            i++;
        }

        REQUIRE(list->length == 5);

        delete_head(list);
        delete_head(list);

        REQUIRE(list->length == 3);
    }

    clear(list);
    free(list);
    free(ptr_int);
}
