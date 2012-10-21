#include <stdio.h>
#include <stdlib.h>
#include <eval.h>
#include <print.h>

void test(const char* cexpr)
{
    bstring expr = bfromcstr(cexpr);
    struct expr_info* info = parse(remove_space(expr));
    print_head(expr, info);
    free(info);
}


int main(void)
{
    test("A");
    test("A^B");
    test("!A^B");
    test("A^Bv(C#D>E");

    return 0;
}
