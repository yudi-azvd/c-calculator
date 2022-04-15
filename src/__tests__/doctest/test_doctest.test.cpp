#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../lib/doctest/doctest.h"

using std::string;

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


int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("testing the factorial function") {
  CHECK(factorial(1) == 1);
  CHECK(factorial(2) == 2);
  CHECK(factorial(3) == 6);
  CHECK(factorial(10) == 3628800);
}

TEST_CASE("list") {
  char* data;
  char* result;
  t_list* list;

  char expression[] = "3*(8+4)/2";

  list = tokenize(expression);

  std::cout << "this is working" << std::endl;

  evaluate(list, &result);
  CHECK(string(result) == "18.000000");

  clear(list); // liberar os nós e os data's
  free(list);

  free(result);
}