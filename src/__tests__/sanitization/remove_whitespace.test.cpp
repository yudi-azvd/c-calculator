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


TEST_CASE("tests on remove_whitespace 0", "[remove_whitespace]") {
    char test[] = "\n\t    ";
    remove_whitespace(test);
    REQUIRE(string(test) == "");
}


TEST_CASE("tests on remove_whitespace 0.1", "[remove_whitespace]") {
    char test[] = "     ";
    remove_whitespace(test);
    REQUIRE(string(test) == "");
}


TEST_CASE("tests on remove_whitespace 0.2", "[remove_whitespace]") {
    char test[] = "";
    remove_whitespace(test);
    REQUIRE(string(test) == "");
}


TEST_CASE("tests on remove_whitespace 1", "[remove_whitespace]") {
    char test[] = "5 * 8 + asas";
    remove_whitespace(test);
    REQUIRE(string(test) == "5*8+asas");
}


TEST_CASE("tests on remove_whitespace 2", "[remove_whitespace]") {
    char test[] = "5 * 8 +\tasas";
    remove_whitespace(test);
    REQUIRE(string(test) == "5*8+asas");
}


TEST_CASE("tests on remove_whitespace 3", "[remove_whitespace]") {
    char test[] = "5\n*    8 +\tasas";
    remove_whitespace(test);
    REQUIRE(string(test) == "5*8+asas");
}
