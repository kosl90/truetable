#include <stdio.h>
#include <stdlib.h>
#include "../src/main.h"
#include "../src/eval.h"

int main(void)
{
    int i;
    struct expr_info* info = parse(bfromcstr("A^DvC#A"));
    printf("%d\n", info->element_num);

    for (i = 0; i < 26; ++i) {
        printf("%d", info->element[i]);
    }

    printf("\n");

    free(info);

    return 0;
}
