cmake_minimum_required(VERSION 3.10.2)

# project(calculator LANGUAGES C CXX)
project(calculator)


include_directories(
	lib/
	lib/list
	lib/terminal_functions

	core/

	tests/terminal_functions/
	tests/list/
	tests/random_tests/
)

file(GLOB CORE
	"core/*.c"
	"core/*.h"
)

file(GLOB LIBS
	"lib/list/*.h"
	"lib/list/*.c"

	"lib/terminal_functions/*.h"
	"lib/terminal_functions/*.c"
)
add_library(libs ${LIBS})

file(GLOB TEST_SOURCES_TERMINAL_FUNCTIONS
	"tests/terminal_functions/*.cpp"
)

file(GLOB TEST_SOURCES_RANDOM_TESTS
	"tests/random_tests/*.c"
)

file(GLOB TEST_SOURCES_LIST
	"tests/list/*.cpp"
)

file(GLOB TEST_SOURCES_UTIL
	"tests/util/*.cpp"
)

file(GLOB TEST_SOURCES_ANALYSIS
	"tests/analysis/*.cpp"
)

file(GLOB TEST_SOURCES_USER_INTERFACE
	"tests/user_interface/*.cpp"
)

file(GLOB TEST_SOURCES_CALCULATOR
	"tests/calculator/*.cpp"
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

add_executable(calculator ${CORE} main/main.c)
target_link_libraries(calculator ${LIBS})

add_executable(
	test_main ${LIBS} main/test_main.c
)


add_executable(
	test_terminal_functions
	${LIBS}
 	${TEST_SOURCES_TERMINAL_FUNCTIONS}
)

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
