PROJECT := s21_smart_calc
CCX=g++
CFLAGS= -Wall -Werror -Wextra -std=c++17

all: clean tests dvi install
install: clean_build
	mkdir -p build
	cd src/qt_view && qmake -o ../../build/Makefile 
	cd build && make && make clean
dist:
	rm -rf dist
	mkdir -p dist
	cp -r * dist/
	tar -cvf $(PROJECT).tar dist
	rm -rf dist
dvi: cmake_generate
	cd build && cmake --build . --target documentation
tests: cmake_generate
	cd build && make tests && ./tests
clean:
	rm -rf build/*
	rm -rf report *.tar
uninstall:
	rm -rf build/*

SRCS := src/calculator/token.cc src/calculator/tokenizer.cc src/calculator/operator_factory.cc src/calculator/calculator.cc src/calculator/credit_calculator.cc
TEST_SRCS := src/tests/tokenizer_unittest.cc src/tests/credit_calculator_unittest.cc src/tests/calculator_unittest.cc src/tests/main_unittest.cc
GCOVFLAGS := -fprofile-arcs -ftest-coverage 
# GCOVFLAGS := --coverage
# LIBS := -lcheck -lm -lpthread -lrt -lsubunit
# -lgmock -lsubunit
LIBS := -lgtest -lpthread
# ifeq ($(OS), Darwin)
# 	LIBS := -lcheck
# endif
gcov_report: 
	$(CCX) $(CFLAGS) $(GCOVFLAGS) -c $(SRCS)
	$(CCX) $(CFLAGS) $(LIBS) -c $(TEST_SRCS)  
	$(CCX) $(CFLAGS) $(LIBS) $(GCOVFLAGS) token.o tokenizer.o operator_factory.o calculator.o credit_calculator.o tokenizer_unittest.o calculator_unittest.o credit_calculator_unittest.o main_unittest.o -o tests
	./tests
	lcov -c -d . -o test.info --exclude '/usr/*'
	genhtml -o report test.info
	rm -rf *.gc* *.o *.info tests

cmake_generate: clean_build
	mkdir -p build
	cd build && cmake ..

clean_build:
	rm -rf build/*
	# touch build/.gitkeep
clang_format:
	clang-format -i -style=Google src/calculator/*.cc src/calculator/*.h
	clang-format -i -style=Google src/tests/*.cc
	clang-format -i -style=Google src/qt_view/*.cpp src/qt_view/*.h