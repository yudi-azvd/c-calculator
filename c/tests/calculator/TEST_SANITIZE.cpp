#include "catch2/catch.hpp"

using std::string;



// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_CALCULATOR
#define _TEST_CALCULATOR
extern "C" {
#endif

#include <string.h>
#include "calculator.h"

#ifdef _TEST_CALCULATOR
}
#endif


TEST_CASE("tests on sanitize 0", "[sanitize]") {
    char test[] = "\n\t    ";
    sanitize(test);
    REQUIRE(string(test) == "");
}


TEST_CASE("tests on sanitize 1", "[sanitize]") {
    char test[] = "5 * 8 + @asas";
    sanitize(test);
    REQUIRE(string(test) == "5*8+asas");
}

TEST_CASE("tests on sanitize 2", "[sanitize]") {
    char test[] = "5' * 8 + @asas";
    sanitize(test);
    REQUIRE(string(test) == "5*8+asas");
}
