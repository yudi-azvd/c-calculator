#include "catch.hpp"
#include <string.h>

using namespace std;

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_PARSER
#define _TEST_PARSER
extern "C" {
#endif
    #include "../../core/parser.h"
#ifdef _TEST_PARSER
}
#endif


TEST_CASE("find_number_end 1", "[find_number_end]") {
    string str = "sdfdf1280-+!";
    // O cast para char* é só por requirimento go g++ por causa do método
    // c_str(). Em um programa em C normal ele não é necessário.
    REQUIRE(find_number_end(((char*) str.c_str()), 5) == 9);

    str = "1+1";
    REQUIRE(find_number_end(((char*) str.c_str()), 0) == 1);

    str = "1.90*23+(40)";
    REQUIRE(find_number_end(((char*) str.c_str()), 0) == 4);

    str = "1.90*23+(40)";
    REQUIRE(find_number_end(((char*) str.c_str()), 5) == 7);
}
