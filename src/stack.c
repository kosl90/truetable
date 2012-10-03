#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stack.h"

/*
** is_empty
** 如果堆栈为空，返回TRUE，否则返回FALSE
*/
int is_empty(StackNode* stack)
{
    return stack == NULL;
}

/*
** push
** 把一个新值压到堆栈中。它的参数是需要被压入的值。
*/
void push(StackNode** stackp, STACK_TYPE value)
{
    StackNode* new_node;
    new_node = (StackNode*)malloc(sizeof(StackNode));
    assert(new_node != NULL);
    new_node->value = value;
    new_node->next = *stackp;
    *stackp = new_node;
}

/*
** pop
** 从堆栈中弹出一个值，并将其丢弃。
*/
void pop(StackNode** stackp)
{
    StackNode* first;
    assert(!is_empty(*stackp));
    first = *stackp;
    *stackp = first->next;
    free(first);
}

/*
** top
** 返回堆栈顶部元素的值，但不对堆栈进行修改。
*/
STACK_TYPE top(StackNode* stack)
{
    assert(!is_empty(stack));
    return stack->value;
}

/*
** destroy_stack
** 销毁堆栈
*/
void destroy_stack(StackNode** stackp)
{
    while (!is_empty(*stackp)) {
        pop(stackp);
    }
}
