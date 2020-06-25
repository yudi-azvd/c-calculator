cmake_minimum_required(VERSION 3.10.2)

# project(calculator LANGUAGES C CXX)
project(calculator)

include_directories(
	lib/
	lib/list
	lib/terminal_functions

	src/core/

	src/__tests__/terminal_functions/
	src/__tests__/list/
	src/__tests__/random_tests/
)

file(GLOB CORE
	"src/core/*.c"
	"src/core/*.h"

	"src/user_interface/*.h"
	"src/user_interface/*.c"
)

file(GLOB LIBS
	"lib/list/*.h"
	"lib/list/*.c"
)

add_library(libs ${LIBS})

# file(GLOB TEST_SOURCES_TERMINAL_FUNCTIONS
# 	"src/__tests__/terminal_functions/*.test.cpp"
# )

file(GLOB TEST_SOURCES_RANDOM_TESTS
	"src/__tests__/random_tests/*.test.c"
)

file(GLOB TEST_SOURCES_LIST
	"src/__tests__/list/*.test.cpp"
)

file(GLOB TEST_SOURCES_UTIL
	"src/__tests__/util/*.test.cpp"
)

file(GLOB TEST_SOURCES_ANALYSIS
	"src/__tests__/analysis/*.test.cpp"
)

file(GLOB TEST_SOURCES_USER_INTERFACE
	"src/__tests__/user_interface/*.test.cpp"
)

file(GLOB TEST_SOURCES_CALCULATOR
	"src/__tests__/calculator/*.test.cpp"
)

set_source_files_properties(
	TEST_SOURCES_RANDOM_TESTS
	PROPERTIES
		LANGUAGE C
		COMPILE_FLAGS "-Wall -ansi"
)
# set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -ansi -std=c99")
# é o jeito que deu certo compilar código em C no padrão ANSI.
set(CMAKE_C_FLAGS "-Wall -ansi -std=c99")

# message(STATUS "random tests: ${TEST_SOURCES_RANDOM_TESTS}")

# add_library(includes ${INC_SOURCES} ${INC_HEADERS})

add_executable(calculator ${CORE} src/main/main.c)
target_link_libraries(calculator ${LIBS})

add_executable(
	test_main ${LIBS} src/main/test_main.c
)


############################
## Executáveis dos testes ##
############################
add_executable(
	test_list
 	${TEST_SOURCES_LIST}
	${LIBS}
)

add_executable(
	test_util
	${CORE}
 	${TEST_SOURCES_UTIL}
	${LIBS}
)

add_executable(
	test_analysis
	${CORE}
 	${TEST_SOURCES_ANALYSIS}
	${LIBS}
)

add_executable(
	test_user_interface
	${CORE}
 	${TEST_SOURCES_USER_INTERFACE}
	${LIBS}
)

add_executable(
	test_calculator
	${CORE}
 	${TEST_SOURCES_CALCULATOR}
	${LIBS}
)


# Compilar os testes aletórios
# foreach(src_file ${TEST_SOURCES_RANDOM_TESTS})
# 	get_filename_component(executable ${src_file} NAME_WE)
# 	message(STATUS "exec ${executable}")
# 	add_executable(${executable} ${src_file} ${CORE})
# 	target_link_libraries(${executable} ${LIBS})
# endforeach(src_file TEST_SOURCES_RANDOM_TESTS)
