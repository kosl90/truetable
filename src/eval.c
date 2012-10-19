#include <ctype.h>
#include "eval.h"
#include "rela.h"
#include "stack.h"
#include "bstrlib.h"
#include "dbg.h"

bstring infix2suffix(const_bstring expr)
{
    bstring suffix = bfromcstr("");
    Stack stk = stack_create();
    char c;
    size_t idx = 0;

    for (idx = 0; (c = bchar(expr, idx)) != '\0'; ++idx) {
        if (is_element(c)) {
            bconchar(suffix, c);
        } else if (c == '('){
            stack_push(stk, c);
        } else if (c == ')') {
            while (stack_top(stk) != '(') {
                bconchar(suffix, stack_top(stk));
                stack_pop(stk);
            }

            stack_pop(stk);
        } else if (is_operator(c)) {
            rel_priority pri = priority(c);

            /*
             * when stack is not empty, and the priority of top element in stack
             * is greater than or equal to the priority of current operator,
             * pop the top element and push it back to suffix expression.
             * **NOTE**:
             * NOT is unary operator, it differs from other operators, NOT
             * mustn't pop from stack.
             */
            while (!stack_is_empty(stk) && pri != NOT && priority(stack_top(stk)) >= pri) {
                bconchar(suffix, stack_top(stk));
                stack_pop(stk);
            }

            stack_push(stk, c);
        }
    }

    while (!stack_is_empty(stk)) {
        bconchar(suffix, stack_top(stk));
        stack_pop(stk);
    }

    stack_destroy(stk);

    return suffix;
}

