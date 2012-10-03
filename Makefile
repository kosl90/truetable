all: debug

TARGET=truetable.exe
CC=gcc
STD=c99
INCLUDE=include
LIBDIR=.
LIB=tt
CFLAGS=-std=$(STD) -L$(LIBDIR) -l$(LIB)

truetable: main.c
	$(CC) -o $(TARGET) $@ $(CFLAGS)

debug: main.c
	$(CC) -g -o $(TARGET) $@ $(CFLAGS)

lib: stack.o bstrlib.o
	ar rvs libtt.a $@


.PHONY: clean dist-clean
clean:
	rm -rf a.out *.~ *.swp *.o

distclean: clean
	rm -rf *.a
