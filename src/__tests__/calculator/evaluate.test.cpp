#include "catch2/catch.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_CALCULATOR
#define _TEST_CALCULATOR
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include "../../core/calculator.h"

#ifdef _TEST_CALCULATOR
}
#endif


TEST_CASE("evaluate 0", "[evaluate]") {
    char* data;
    char* result;
    t_list* list;

    char expression[] = "3*(8+4)/2";

    list = tokenize(expression);

    evaluate(list, &result);
    REQUIRE(string(result) == "18.000000");

    clear(list); // liberar os nós e os data's
    free(list);

    free(result);
}

TEST_CASE("evaluate 1", "[evaluate]") {
    char* data;
    char* result;
    t_list* list;

    char expression[] = "-30.0*(8+4)/2";

    list = tokenize(expression);

    evaluate(list, &result);
    REQUIRE(string(result) == "-180.0000");

    clear(list); // liberar os nós e os data's
    free(list);

    free(result);
}

TEST_CASE("evaluate 2", "[evaluate]") {
    char* data;
    char* result;
    t_list* list;

    char expression[] = "2";

    list = tokenize(expression);

    evaluate(list, &result);
    REQUIRE(string(result) == "2");

    clear(list); // liberar os nós e os data's
    free(list);

    free(result);
}

TEST_CASE("evaluate 3", "[evaluate]") {
    char* data;
    char* result;
    t_list* list;

    char expression[] = "-2";

    list = tokenize(expression);

    evaluate(list, &result);
    REQUIRE(string(result) == "-2");

    clear(list); // liberar os nós e os data's
    free(list);

    free(result);
}

// https://www.rhyscitlema.com/algorithms/expression-parsing-algorithm/
// http://www2.lawrence.edu/fast/GREGGJ/CMSC150/071Calculator/Calculator.html
TEST_CASE("evaluate 4", "[evaluate]") {
    char* data;
    char* result;
    t_list* list;

    char expression[] = "-3*8*(0-7)";

    list = tokenize(expression);

    evaluate(list, &result);
    REQUIRE(string(result) == "168.00000");

    clear(list); // liberar os nós e os data's
    free(list);

    free(result);
}

// 3-1*2+3-1
TEST_CASE("evaluate 5", "[evaluate]") {
    char* data;
    char* result;
    t_list* list;

    char expression[] = "3-1*2+3-1";

    list = tokenize(expression);

    evaluate(list, &result);
    REQUIRE(string(result) == "3.000000");

    clear(list); // liberar os nós e os data's
    free(list);

    free(result);
}

