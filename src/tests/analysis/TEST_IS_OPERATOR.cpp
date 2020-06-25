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


TEST_CASE("is_operator 1", "[is_operator]") {
    REQUIRE(is_operator('c') == 0);
    REQUIRE(is_operator('1') == 0);
    REQUIRE(is_operator('(') == 0);

    REQUIRE(is_operator('+') == 1);
    REQUIRE(is_operator('-') == 1);
    REQUIRE(is_operator('/') == 1);
    REQUIRE(is_operator('*') == 1);
    REQUIRE(is_operator('^') == 1);
}
