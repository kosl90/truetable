#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <main.h>
#include <eval.h>
#include <bstrlib.h>


void print_head(const_bstring expr, const ExprInfo* info)
{
    size_t i;

    for (i = 0; i < 26; ++i) {
        if (info->element[i]) {
            printf("%c  ", i + 'A');
        }
    }

    printf("%s\n", bdata(expr));
}


void print_table(const_bstring expr)
{
    size_t i, j;
    int space_width;
    bstring suffix_expr = infix2suffix(expr);

    ExprInfo* info = parse(expr);
    space_width = info->expr_len / 2;

    print_head(expr, info);

    for (i = 0; i < info->cond_num; ++i) {
        bool val[26] = {false};
        dec2bin(i, val, info->element_num);

        // print one line
        for (j = 0; j < info->element_num; ++j) {
            printf("%d  ", val[j]);
        }

        printf("%*s%d\n", space_width, "", eval(suffix_expr, val, info));
    }

    printf("\n");  // separator between tables

    free(info);
    info = NULL;
}


