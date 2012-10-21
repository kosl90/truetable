#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <main.h>
#include <print.h>
#include <eval.h>
#include <bstrlib.h>
#include <dbg.h>

typedef bstring (*Get_expr_handler)(void* param);

void do_print(Get_expr_handler get_expr, void* param)
{
    bstring expr = NULL;

    while ((expr = get_expr(param)) != NULL) {
        remove_space(expr);

        if (!is_valid_expression(expr)) {
            fprintf(stderr, "Invalid Expression: %s\n\n", bdata(expr));
            continue;
        }

        print_table(expr);
        bdestroy(expr);
    }
}

bstring get_expr_from_stdin(void* param) {
    bstring expr = NULL;

    printf("please enter you expression: ");
    fflush(stdout);

    expr = bgets((bNgetc) fgetc, param, '\n');

    return expr;
}

bstring get_expr_from_argv(void* param) {
    static int i = 2;
    bstring expr = NULL;
    expr = bfromcstr(((char**)param)[i++]);

    return expr;
}

bstring get_expr_from_file(void* param) {
    bstring expr = NULL;
    expr = bgets((bNgetc) fgetc, param, '\n');

    if (expr == NULL) {
        fclose(param);
    }

    return expr;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        do_print(get_expr_from_stdin, stdin);
    } else if (argc < 3 || strcmp(argv[1], "-h") == 0
            || strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, HELP_INFO);
    } else if (strcmp(argv[1], "-e") == 0) {
        do_print(get_expr_from_argv, argv);
    } else if (strcmp(argv[1], "-f") == 0) {
        FILE* fp = fopen(argv[2], "r");
        check(fp != NULL, "%s", argv[2]);

        do_print(get_expr_from_file, fp);
    } else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
        printf("truetable.exe v%s\n", VERSION);
    }

error:
    return 0;
}

