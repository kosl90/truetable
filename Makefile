TARGET=build/libtt.a
CC=gcc
STD=c99
LIBDIR=build
LIB=tt
INCLUDE=src
CFLAGS=-std=$(STD) -I$(INCLUDE) -Wall -Wextra -rdynamic -static -g -O2 -DNODEBUG

SOURCES=$(wildcard src/*.c)
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))

TESTS_SOURCES=$(wildcard tests/*.c)
TESTS=$(patsubst %.c, %, $(TESTS_SOURCES))

all: $(TARGET)

$(TARGET): build $(OBJECTS)
	ar rvs $@ $(OBJECTS)
	ranlib $@

build:
	mkdir -p build
	mkdir -p bin

.PHONY: clean distclean
clean:
	cd src/; rm -rf a.out *.~ *.swp *.o
	rm -rf build/

distclean: clean
	cd src/; rm -rf *.a

.PHONY: tests
#tests: CFLAGS += $(TARGET)
tests: $(TESTS)

tests/test_infix2suffix: tests/test_infix2suffix.c $(OBJECTS)
	gcc $(CFLAGS) -o tests/test_infix2suffix tests/test_infix2suffix.c $(OBJECTS)
