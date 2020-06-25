#include "catch2/catch.hpp"
#include <string.h>

// Esse pedaço é só pra incluir uma biblioteca
// que deve ser tratada como código C.
#ifndef _TEST_USER_INTERFACE
#define _TEST_USER_INTERFACE
extern "C" {
#endif
    #include "user_interface.h"
#ifdef _TEST_USER_INTERFACE
}
#endif

