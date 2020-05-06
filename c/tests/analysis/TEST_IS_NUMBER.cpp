#include "catch2/catch.hpp"
#include <string.h>

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


TEST_CASE("is_number 1", "[is_number]") {
    REQUIRE(is_number('c') == 0);
    REQUIRE(is_number('1') == 1);
    REQUIRE(is_number('(') == 0);

    REQUIRE(is_number('+') == 0);
    REQUIRE(is_number('-') == 0);
    REQUIRE(is_number('/') == 0);
    REQUIRE(is_number('*') == 0);
    REQUIRE(is_number('^') == 0);
    REQUIRE(is_number(' ') == 0);

    REQUIRE(is_number('0') == 1);
    REQUIRE(is_number('1') == 1);
    REQUIRE(is_number('2') == 1);
    REQUIRE(is_number('3') == 1);
    REQUIRE(is_number('4') == 1);
    REQUIRE(is_number('5') == 1);
    REQUIRE(is_number('6') == 1);
    REQUIRE(is_number('7') == 1);
    REQUIRE(is_number('8') == 1);
    REQUIRE(is_number('9') == 1);
}
