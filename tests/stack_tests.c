#include <stdio.h>
#include <stack.h>

int main(void)
{
    Stack stk = stack_create();
    printf("%d\n", stack_size(stk));
    stack_push(stk, 4);
    printf("%d\n", stack_size(stk));
    printf("%d\n", stack_top(stk));
    stack_pop(stk);
    printf("%d\n", stack_size(stk));
    stack_destroy(stk);

    return 0;
}
