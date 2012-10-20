#include <assert.h>
#include <stdio.h>
#include <bstrlib.h>
#include <eval.h>

bstring test = NULL;

void tests(const char* str)
{
    if (test != NULL)
        bdestroy(test);
    test = bfromcstr(str);

    if (!test) {
        fprintf(stderr, "Out of memory\n");
    }

    bstring suffix = infix2suffix(test);

    assert(suffix != NULL);
    assert(suffix->data != NULL);

    printf("%s\n", bdatae(suffix, "Error"));
    /*puts((char*)(suffix>data));*/
}

int main(void)
{
    // A!!!!
    tests("!!!!A");

    // AB^
    tests("A^B");

    // ABv
    tests("AvB");

    // A>
    tests(">B");

    // ABC^v
    tests("AvB^C");

    // ABv!CD>#^
    tests("!(AvB)^(C#>E)");

    bdestroy(test);

    return 0;
}
