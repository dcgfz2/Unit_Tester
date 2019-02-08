# Makefile 1
.PHONY: main test coverage clean
CFLAGS=-Wall -Werror

main: main.o
	g++ ${CFLAGS} $^ -o main

test: testsuite
	@./testsuite

coverage: CFLAGS =-Wall -Werror -fprofile-arcs -ftest-coverage
coverage: clean testsuite
	@./testsuite
	gcov -r test_main.cpp test_list.cpp

testsuite: test_main.o test_list.o
	g++ ${CFLAGS} $^ -o testsuite

main.o: main.cpp list.h list.hpp
	g++ ${CFLAGS} -c main.cpp

test_main.o: test_main.cpp
	g++ ${CFLAGS} -c test_main.cpp

test_list.o: test_list.o
	g++ ${CFLAGS} -c test_list.cpp

clean: 
	-@rm -f main testsuite
	-@rm -f *.o
	-@rm -f *.gcov *.gcno *.gcda
