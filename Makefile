TARGET=truetable.exe
CC=gcc
STD=c99
LIBDIR=.
LIB=tt
CFLAGS=-std=$(STD) -L$(LIBDIR) -l$(LIB)
VPATH=src

all: debug

$(TARGET): main.c
	$(CC) -o $(TARGET) $@ $(CFLAGS)

libtt.a: build stack.o bstrlib.o
	ar rvs libtt.a $@

build:
	mkdir -p build
	mkdir -p bin

.PHONY: clean distclean
clean:
	rm -rf a.out *.~ *.swp *.o

distclean: clean
	rm -rf *.a
