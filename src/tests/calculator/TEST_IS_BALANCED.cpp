#include "catch2/catch.hpp"
#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::endl;

using std::ifstream;
using std::getline;
using std::ios;

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_CALCULATOR
#define _TEST_CALCULATOR
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include "calculator.h"

#ifdef _TEST_CALCULATOR
}
#endif


TEST_CASE("tests on is_balanced", "[is_balanced]") {
    const int NUMBER_OF_TESTS = 58;
    const int EXPRESSION_LEN_MAX = 100500; // Cem mil e quinhentos caracteres
                                           // é o maior número nos casos de teste.

    char test_filename[FILENAME_MAX];   // Vem de stdio.h
    char answer_filename[FILENAME_MAX]; // Vem de stdio.h
    char expression[EXPRESSION_LEN_MAX];

    // Se os executáveis mudarem de diretório, tem que mudar essas linhas.
    const char filename1[] = "../tests/calculator/check_brackets_in_code/%02d";
    const char filename2[] = "../tests/calculator/check_brackets_in_code/%02d.a";

    string test_line, answer_line;

    ifstream test_file;
    ifstream answer_file;

    for (int i = 1; i <= NUMBER_OF_TESTS; i++) {
        snprintf(test_filename,   FILENAME_MAX, filename1, i);
        snprintf(answer_filename, FILENAME_MAX, filename2, i);

        SECTION(string(test_filename)) {
            test_file.open(test_filename);
            answer_file.open(answer_filename);

            if(test_file.is_open() && answer_file.is_open()) {
                getline(test_file, test_line);
                getline(answer_file, answer_line);

                snprintf(expression, EXPRESSION_LEN_MAX, "%s", test_line.c_str());

                if (answer_line == "Success\n")
                    // Quase que eu começo a perder a cabeça por causa do barra n.
                    REQUIRE(is_balanced(expression) == 1);
                else
                    REQUIRE(is_balanced(expression) == 0);

                test_file.close();
                answer_file.close();
            }
        }
    }
}
