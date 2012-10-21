#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <main.h>
#include <eval.h>
#include <bstrlib.h>
#include <dbg.h>

void do_print(bstring expr, int count);

int main(int argc, char* argv[])
{
    bstring expr = NULL;

    if (argc < 2) {
        int count = 0;

        while (1) {
            if (count++ != 0) {
                printf("\n");
            }

            printf("please enter you expression: ");
            fflush(stdout);

            if ((expr = bgets((bNgetc)fgetc, stdin, '\n')) == NULL) {
                break;
            }

            do_print(expr, 0);
            bdestroy(expr);
        }
    } else if (argc < 3 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, HELP_INFO);
    } else if (strcmp(argv[1], "-e") == 0) {
        int i;

        for (i = 2; i < argc; ++i) {
            expr = bfromcstr(argv[i]);
            do_print(expr, i - 2);
            bdestroy(expr);
        }
    } else if (strcmp(argv[1], "-f") == 0) {
        FILE* fp = fopen(argv[2], "r");
        check(fp != NULL, "%s", argv[2]);

        int count = 0;

        while ((expr = bgets((bNgetc)fgetc, fp, '\n')) != NULL) {
            do_print(expr, count++);
            bdestroy(expr);
        }
    } else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
        printf("truetable.exe v%s\n", VERSION);
    } else {
        fprintf(stderr, "Does not know this option \"%s\", use -?/-h/--help for help\n",
                argv[1]);
    }

error:
    return 0;
}

void do_print(bstring expr, int count)
{
    remove_space(expr);

    if (count != 0) {
        printf("\n");  // table separator
    }

    if (!is_valid_expression(expr)) {
        fprintf(stderr, "Invalid Expression: %s\n", bdata(expr));
        return;
    }

    print_table(expr);

}
