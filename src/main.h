#ifndef _MAIN_H_
#define _MAIN_H_

#define VERSION "2.0"
#define HELP_INFO \
"USAGE:\n" \
"\ttruetable [ -e expression | -f FILE ]\n" \
"\ttruetable -h|--help\n" \
"\ttruetable -v|--version\n" \
"\n" \
"DESCRIPTION\n" \
"\tThis is a program which prints true table according to the given expression.\n" \
"\n" \
"\t`!`: not\n" \
"\t`^`: and\n" \
"\t`v`: or\n" \
"\t`>`: implication\n" \
"\t`#`: double implication\n" \
"\t`A-Z`: element\n" \
"\n" \
"OPTIONS\n" \
"-?|-h|--help\n" \
"\tprint help message.\n" \
"\n" \
"-v|--version\n" \
"\tprint version\n" \
"\n" \
"-e expression\n" \
"\tprint true table accoriding each expresion.\n" \
"\n" \
"-f FILE\n" \
"\tread FILE, each line is an expression, then print all true tables.\n" \
"\n" \
"NOTE:\n" \
"\tif no option is given, program will read expression from standard input.\n\n" \

#endif /* end of include guard: _MAIN_H_ */
