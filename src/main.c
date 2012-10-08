#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "main.h"
#include "bstrlib.h"

bool is_valid(const bstring);
void print(const bstring, );

int main(int argc, char* argv[])
{
    if (argc == 1) {
        printf("please enter you expression: ");
        fflush(stdout);
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, HELP_INFO);
    } else if (strcmp(argv[1], "-e") == 0) {
        bstring expr = NULL;
        expr = bfromcstr(argv[1]);

        if (!is_valid(expr)) {
            return 1;
        }

        parse(expr);
        result = eval(expr);

        print(expr, info, result);

        bdestroy(expr);
    } else if (strcmp(argv[1], "-f") == 0) {

    } else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
        printf("truetable.exe v%s\n", VERSION);
    } else {
        fprintf(stderr, "Does not know this option \"%s\", use -?/-h/--help for help\n",
                argv[1]);
    }

    return 0;
}
