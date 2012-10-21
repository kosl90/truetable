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
            do_print(expr, i - 2);
            /*remove_space(expr);*/

            /*if (!is_valid_expression(expr)) {*/
                /*fprintf(stderr, "Invalid Expression\n");*/
                /*return 1;*/
            /*}*/

            /*print_table(expr);*/

            /*if (argc != 1 + i) {*/
                /*printf("\n");  // table separator*/
            /*}*/

            bdestroy(expr);
        }
    } else if (strcmp(argv[1], "-f") == 0) {
        FILE* fp = fopen(argv[2], "r");
        check(fp != NULL, "%s", argv[2]);

        bstring expr = NULL;
        int count = 0;
        while ((expr = bgets((bNgetc)fgetc, fp, '\n')) != NULL) {
            /*remove_space(expr);*/

            /*if (!is_valid_expression(expr)) {*/
                /*fprintf(stderr, "Invalid Expression\n");*/
                /*return 1;*/
            /*}*/

            /*print_table(expr);*/

            /*if (argc != 1 + i) {*/
                /*printf("\n");  // table separator*/
            /*}*/

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

    /*check(is_valid_expression(expr), "Invalid Expression: %s", bdata(expr));*/
    if (!is_valid_expression(expr)) {
        fprintf(stderr, "Invalid Expression: %s\n", bdata(expr));
        return;
    }

    print_table(expr);

/*error:*/
}
