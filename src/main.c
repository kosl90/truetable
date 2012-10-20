#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <main.h>
#include <eval.h>
#include <bstrlib.h>
#include <dbg.h>

int main(int argc, char* argv[])
{
    if (argc == 1) {
        printf("please enter you expression: ");
        fflush(stdout);
    }

    if (argc < 3 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, HELP_INFO);
    } else if (strcmp(argv[1], "-e") == 0) {
        bstring expr = NULL;
        int i;

        for (i = 2; i < argc; ++i) {
            expr = bfromcstr(argv[i]);
            remove_space(expr);

            if (!is_valid_expression(expr)) {
                fprintf(stderr, "Invalid Expression\n");
                return 1;
            }

            print_table(expr);
            bdestroy(expr);
        }
    } else if (strcmp(argv[1], "-f") == 0) {

    } else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
        printf("truetable.exe v%s\n", VERSION);
    } else {
        fprintf(stderr, "Does not know this option \"%s\", use -?/-h/--help for help\n",
                argv[1]);
    }

    return 0;
}

