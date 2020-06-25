#include "catch2/catch.hpp"

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_STACK
#define _TEST_STACK
extern "C" {
#endif
    #include "list.h"
#ifdef _TEST_STACK
}
#endif


TEST_CASE("stack basic", "[stack]") {
    const int S_SIZE = 5;
    int* data = (int*) calloc(1, sizeof(int));
    t_stack* s = create_stack("int");

    SECTION("push") {
        int i = 0;
        while(i < S_SIZE) {
            *data = i;
            push(s, data);
            data = (int*) calloc(1, sizeof(int));
            i++;
        }

        REQUIRE(s->length == S_SIZE);

        SECTION("soft_pop") {
            for (size_t i = 1; i < S_SIZE; i++) {
                void* data = soft_pop(s);
                REQUIRE(*((int*) data) == S_SIZE-i);
                free(data);
            }
        }

        SECTION("pop") {
            pop(s);
            REQUIRE(s->length == S_SIZE-1);

            pop(s);
            REQUIRE(s->length == S_SIZE-2);

            pop(s);
            REQUIRE(s->length == S_SIZE-3);
        }

        SECTION("peek") {
            void* data = peek(s);

            REQUIRE(*((int*) data) == S_SIZE-1);

            REQUIRE(s->length == S_SIZE);

            // Não se faz free(data) porque peek não remove
            // o item da pilha.
        }
    }

    // print(s);
    clear(s);
    free(s);
    free(data);
}
