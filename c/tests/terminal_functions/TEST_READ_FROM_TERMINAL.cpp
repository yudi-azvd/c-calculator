#include <iostream>
#include "catch2/catch.hpp"

using std::string;
using std::cout;
// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TERMINAL_FUNCTIONS
#define _TERMINAL_FUNCTIONS
extern "C" {
#endif
    #include "terminal_functions.h"
#ifdef _TERMINAL_FUNCTIONS
}
#endif


TEST_CASE("test ungetc function") {
    char g = 'g';
    char test_char;

    ungetc('g', stdin);
    scanf("%c", &test_char);

    REQUIRE(g == test_char);
}


TEST_CASE("test ungetstr") {
    char str[] = "hey world";
    char test_str[10];

    ungetstr(str, stdin);
    scanf("%[^\n]%*c", test_str);
    // scanf(" %s", test_str);
    // scanf(" %s", test_str);

    REQUIRE("hey world" == string(str));
    REQUIRE(string(test_str) == "hey world");
}
