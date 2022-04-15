#include "catch.hpp"
#include <string.h>

using namespace std;

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_PARSER
#define _TEST_PARSER
extern "C" {
#endif
    #include "../../core/parser.h"
#ifdef _TEST_PARSER
}
#endif
