#include <assert.h>
#include <stdio.h>
#include "../src/bstrlib.h"
#include "../src/eval.h"

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
    /*puts((char*)(suffix->data));*/
}

int main(void)
{
    // A!!!!
    tests("!!!!A");

    // AB^
    tests("A^B");

    // ABv
    tests("AvB");

    // AB>
    tests("A>B");

    // ABC^v
    tests("AvB^C");

    // ABv!CDE>#^
    tests("!(AvB)^(C#D>E)");

    return 0;
}
