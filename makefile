CC = g++ -fsanitize=address #-Wextra -Wall -Werror
GCOVFLAGS=-fprofile-arcs -ftest-coverage 
CHECKFLAGS = -lgtest -pthread -lgtest_main
OS=$(shell uname -s)
.PHONY: all clean test s21_matrix_oop.a gcov_report linter cppcheck mem val

all: gcov_report

clean:
	@rm -rf *.o *.gch *.gcda *.gcno main test *.a *.out *.info
	@rm -rf report/

s21_matrix_oop.a: s21_matrix_oop.o
	@ar rcs s21_matrix_oop.a s21_matrix_oop.o
	@cp s21_matrix_oop.a libs21_matrix_oop.a
	@ranlib libs21_matrix_oop.a

s21_matrix_oop.o:
	@$(CC) -c s21_matrix_oop.cpp s21_matrix_oop.h


test: clean s21_matrix_oop.a
ifeq ($(OS), Darwin)
	@$(CC) tests.cpp s21_matrix_oop.a -o test $(CHECKFLAGS) --coverage
	@./test
else
	@$(CC) tests.cpp s21_matrix_oop.a -o test $(CHECKFLAGS) 
	@./test
endif

gcov_report: tests.cpp s21_matrix_oop.cpp
	@$(CC) $(GCOVFLAGS) tests.cpp s21_matrix_oop.cpp $(CHECKFLAGS) -o gcov_rep.out
	@./gcov_rep.out
	@lcov -t "gcov_rep" --output-file=coverag.info --capture --directory .
	lcov --remove coverag.info  '/usr/*' -o GcovReport_clear.info
	@genhtml -o ./report  GcovReport_clear.info

linter:
	@cp ../materials/linters/CPPLINT.cfg .
	@python3 ../materials/linters/cpplint.py --extensions=cpp *.cpp *.h
	@rm CPPLINT.cfg

cppcheck:
	@cppcheck --enable=all --suppress=missingIncludeSystem *.cpp

mem: test
	@CK_FORK=no leaks --atExit -- ./test


val: s21_matrix_oop.a
	@cp ../materials/linters/CPPLINT.cfg .
	@$(CC) tests_for_valgrind.cpp s21_matrix_oop.a -o tests_for_valgrind $(CHECKFLAGS) -g
	@valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./tests_for_valgrind
	@rm tests_for_valgrind CPPLINT.cfg *.a *.o *.gch

