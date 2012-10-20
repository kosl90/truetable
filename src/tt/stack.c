#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stack.h>
#include <dbg.h>

Stack stack_create()
{
    Stack stk = (Stack)calloc(1, sizeof(struct Stack));
    check_mem(stk);

error:
    return stk;
}

int stack_size(Stack stk)
{
    return stk->size;
}


int stack_is_empty(Stack stk)
{
    return stk->head == NULL;
}

void stack_push(Stack stk, STACK_TYPE value)
{
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    check_mem(new_node);

    new_node->value = value;
    new_node->next = stk->head;
    stk->head = new_node;
    stk->size++;

error:
    return;
}


void stack_pop(Stack stk)
{
    StackNode* first;
    assert(!stack_is_empty(stk));
    first = stk->head;
    stk->head = first->next;
    stk->size--;
    free(first);
}


STACK_TYPE stack_top(Stack stk)
{
    /*assert(!stack_is_empty(stk));*/
    return stk->head->value;
}


void stack_destroy(Stack stk)
{
    while (!stack_is_empty(stk)) {
        stack_pop(stk);
    }

    free(stk);
}
