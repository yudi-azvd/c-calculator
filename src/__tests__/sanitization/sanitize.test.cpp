#include "catch.hpp"

using std::string;



// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_SANITIZATION
#define _TEST_SANITIZATION
extern "C" {
#endif

#include <string.h>
#include "sanitization.h"

#ifdef _TEST_SANITIZATION
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
