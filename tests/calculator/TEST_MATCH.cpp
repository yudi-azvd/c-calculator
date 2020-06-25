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


TEST_CASE("tests on match()", "[match]") {
    REQUIRE(match('(', ')') == 1);
    REQUIRE(match('(', '(') == 0);
    REQUIRE(match('(', 'a') == 0);

    REQUIRE(match('{', '}') == 1);
    REQUIRE(match('[', ']') == 1);

    REQUIRE(match(']', '[') == 0);
}
