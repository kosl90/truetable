#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <main.h>
#include <eval.h>

void test(const char* str)
{
    int i;
    bstring expr = bfromcstr(str);

    if (!is_valid_expression(expr)) {
        printf("error expression\n");
        return;
    }

    bstring suf_expr = infix2suffix(expr);
    printf("%s: ", bdata(suf_expr));

    struct expr_info* info = parse(expr);

    for (i = 0; i < pow(2, info->element_num); ++i) {
        bool val[26] = {0};
        size_t j;
        dec2bin(i, val, info->element_num);
        for (j = 0; j < info->element_num; ++j) {
            printf("%d", val[j]);
        }
        printf(":%d ", eval(suf_expr, val, info));
    }
    printf("\n");

    free(info);
}

int main(void)
{
    test("A"); //01
    test("!A"); //10
    test("A^B");//0001
    test("AvB");//0111
    test("A>B");//1101
    test("A#B");//1001
    test("C#A^B");//1001

    return 0;
}
