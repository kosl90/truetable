#include <ctype.h>
#include "eval.h"
#include "rela.h"
#include "stack.h"
#include "bstrlib.h"
#include "dbg.h"

bstring infix2suffix(const_bstring expr)
{
    bstring suffix = bfromcstr("");
    StackNode* stack = NULL;
    char c;
    size_t idx = 0;

    for (idx = 0; (c = bchar(expr, idx)) != '\0'; ++idx) {
        if (isupper(c)) {
            bconchar(suffix, c);
        } else if (is_empty(stack)) {
            push(&stack, c);
        } else if (c == '('){
            push(&stack, c);
            printf("%c\n", top(stack));
        } else if (c == ')') {
            while (/*!is_empty(stack) && */top(stack) != '(') {
                bconchar(suffix, top(stack));
                pop(&stack);
            }

            /*if (!is_empty(stack) && top(stack) == '(')*/
            /*pop(&stack);*/
        } else if (is_operator(c)) {
            rel_priority pri = priority(c);

            /*
             * when stack is not empty, and the priority of top element in stack
             * is greater than or equal to the priority of current operator,
             * pop the top element and push it back to suffix expression.
             * **NOTE**:
             * NOT is single operator, it differs from other operators, NOT
             * mustn't pop from stack.
             */
            while (!is_empty(stack) && pri != NOT && priority(top(stack)) <= pri) {
                bconchar(suffix, top(stack));
                pop(&stack);
            }

            push(&stack, c);
        }
    }

    /*bcstrfree(c_expr);*/
    while (!is_empty(stack)) {
        bconchar(suffix, top(stack));
        pop(&stack);
    }

    return suffix;
}

