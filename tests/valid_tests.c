#include <stdio.h>
#include <bstrlib.h>
#include <eval.h>

int main(void)
{
    // 1
    printf("%d\n", is_valid_expression(bfromcstr("!A")));
    // 1
    printf("%d\n", is_valid_expression(bfromcstr("!(A)")));
    // 1
    printf("%d\n", is_valid_expression(bfromcstr("!(A^(BvC))")));
    // 1
    printf("%d\n", is_valid_expression(bfromcstr("!!!!(!!A^(!BvC))")));
    // 1
    printf("%d\n", is_valid_expression(bfromcstr("(!!!!(!!A^(!BvC)))")));
    // 0
    printf("%d\n", is_valid_expression(bfromcstr("!!!!(!!A^(!BvC)))")));
    // 0
    printf("%d\n", is_valid_expression(bfromcstr("^A^(!BvC)")));
    // 0
    printf("%d\n", is_valid_expression(bfromcstr("A^)(!BvC)")));
    // 0
    printf("%d\n", is_valid_expression(bfromcstr("A^(!BvC)()")));

    return 0;
}
