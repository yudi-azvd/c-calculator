#include "catch2/catch.hpp"

using std::string;

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_CALCULATOR
#define _TEST_CALCULATOR
extern "C" {
#endif

#include <string.h>
#include "util.h"

#ifdef _TEST_CALCULATOR
}
#endif


TEST_CASE("tests on remove_illegalchars 0", "[remove_illegalchars]") {
    char test[] = "\n\t    ";
    remove_illegalchars(test);
    REQUIRE(string(test) == "\n\t    ");
}


TEST_CASE("tests on remove_illegalchars 0.1", "[remove_illegalchars]") {
    char test[] = "  #  ";
    remove_illegalchars(test);
    REQUIRE(string(test) == "    ");
}


TEST_CASE("tests on remove_illegalchars 0.2", "[remove_illegalchars]") {
    char test[] = "";
    remove_illegalchars(test);
    REQUIRE(string(test) == "");
}


TEST_CASE("tests on remove_illegalchars 1", "[remove_illegalchars]") {
    char test[] = "5 * 8 + @asas";
    remove_illegalchars(test);
    REQUIRE(string(test) == "5 * 8 + asas");
}

TEST_CASE("tests on remove_illegalchars 2", "[remove_illegalchars]") {
    char test[] = "5' \"* 8 +\tasas";
    remove_illegalchars(test);
    REQUIRE(string(test) == "5 * 8 +\tasas");
}
