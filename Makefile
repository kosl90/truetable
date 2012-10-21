TARGET=build/libtt.a
CC=gcc
STD=c99
LIBDIR=build
LIB=tt
INCLUDE=src/tt
CFLAGS=-std=$(STD) -I$(INCLUDE) -Wall -Wextra -rdynamic -static -g -O2 -DNODEBUG
BIN=bin

SOURCES=$(wildcard src/tt/*.c)
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))

TESTS_SOURCES=$(wildcard tests/*.c)
TESTS=$(patsubst %.c, %.exe, $(TESTS_SOURCES))

all: $(TARGET) main $(TESTS)

main: src/main.c
	$(CC) $(CFLAGS) -o $(BIN)/main.exe src/main.c -Lbuild -ltt -lm

$(TARGET): build $(OBJECTS)
	ar rvs $@ $(OBJECTS)
	ranlib $@

build:
	mkdir -p build
	mkdir -p bin

.PHONY: clean distclean
clean:
	cd src/tt; rm -rf a.out *.~ *.swp *.o
	cd tests/; rm -rf a.out *.exe

distclean: clean
	rm -rf build/
	rm -rf bin/

.PHONY: tests
tests: $(TESTS)

tests/test_infix2suffix.exe: tests/test_infix2suffix.c
	$(CC) $(CFLAGS) -o tests/test_infix2suffix.exe tests/test_infix2suffix.c -Lbuild -l$(LIB) -lm

tests/stack_tests.exe: tests/stack_tests.c
	$(CC) $(CFLAGS) -o tests/stack_tests.exe tests/stack_tests.c -Lbuild -l$(LIB) -lm

tests/eval_tests.exe: tests/eval_tests.c
	$(CC) $(CFLAGS) -o tests/eval_tests.exe tests/eval_tests.c -Lbuild -l$(LIB) -lm

tests/parse_tests.exe: tests/parse_tests.c
	$(CC) $(CFLAGS) -o tests/parse_tests.exe tests/parse_tests.c -Lbuild -l$(LIB) -lm

tests/remove_tests.exe: tests/remove_tests.c
	$(CC) $(CFLAGS) -o tests/remove_tests.exe tests/remove_tests.c -Lbuild -l$(LIB) -lm

tests/table_tests.exe: tests/table_tests.c
	$(CC) $(CFLAGS) -o tests/table_tests.exe tests/table_tests.c -Lbuild -l$(LIB) -lm

tests/valid_tests.exe: tests/valid_tests.c
	$(CC) $(CFLAGS) -o tests/valid_tests.exe tests/valid_tests.c -Lbuild -l$(LIB) -lm
