all: debug

TARGET=truetable.exe
CC=gcc
STD=c99
LIBDIR=.
LIB=tt
CFLAGS=-std=$(STD) -L$(LIBDIR) -l$(LIB)

$(TARGET): main.c
	$(CC) -o $(TARGET) $@ $(CFLAGS)

libtt.a: stack.o bstrlib.o
	ar rvs libtt.a $@


.PHONY: clean distclean
clean:
	rm -rf a.out *.~ *.swp *.o

distclean: clean
	rm -rf *.a
