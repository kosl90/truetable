#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdbool.h>

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
"\t-?|-h|--help\n" \
"\t\tprint help message.\n" \
"\n" \
"\t-v|--version\n" \
"\t\tprint version\n" \
"\n" \
"\t-e expression\n" \
"\t\tprint true table accoriding each expresion.\n" \
"\n" \
"\t-f FILE\n" \
"\t\tread FILE, each line is an expression, then print all true tables.\n" \
"\n" \
"NOTE:\n" \
"\tif no option is given, program will read expression from standard input.\n\n" \

typedef struct expr_info {
    size_t expr_len;
    size_t element_num;
    size_t cond_num;
    bool element[26];
} ExprInfo;

#endif /* end of include guard: _MAIN_H_ */
