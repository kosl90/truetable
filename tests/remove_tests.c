#include <stdio.h>
#include <eval.h>

int main(void)
{
    bstring expr = bfromcstr("ad  dsf`  fkj  ");
    printf("%s#\n", bdata(remove_space(expr)));
    bdestroy(expr);

    return 0;
}
