#include "catch2/catch.hpp"

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_CALCULATOR
#define _TEST_CALCULATOR
extern "C" {
#endif

#include "calculator.h"
#include <string.h>

#ifdef _TEST_CALCULATOR
}
#endif


TEST_CASE("is_bracket random tests", "[is_bracket]") {
    REQUIRE(is_bracket('0') == 0);

    REQUIRE(is_bracket('}') == 1);
    REQUIRE(is_bracket('{') == -1);

    REQUIRE(is_bracket('a') == 0);

    REQUIRE(is_bracket(')') == 1);
    REQUIRE(is_bracket('(') == -1);

    REQUIRE(is_bracket('{') == -1);
    REQUIRE(is_bracket('}') == 1);
}
