#include <stdio.h>
#include <string.h>

#include "main.h"
#include "bstrlib.h"

int main(int argc, char* argv[])
{
    if (argc != 1) {
        bstring expr = NULL;
        /*expr = ();*/
        /*bdestroy(expr);*/
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, HELP_INFO);
    } else if (strcmp(argv[1], "-e") == 0) {
    } else if (strcmp(argv[1], "-f") == 0) {
    } else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
        printf("truetable.exe v%s\n", VERSION);
    } else {
        fprintf(stderr, "Does not know this option \"%s\", use -?/-h/--help for help\n",
                argv[1]);
    }

    return 0;
}
