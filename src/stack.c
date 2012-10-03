#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stack.h"

/*
** is_empty
** �����ջΪ�գ�����TRUE�����򷵻�FALSE
*/
int is_empty(StackNode* stack)
{
    return stack == NULL;
}

/*
** push
** ��һ����ֵѹ����ջ�С����Ĳ�������Ҫ��ѹ���ֵ��
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
** �Ӷ�ջ�е���һ��ֵ�������䶪����
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
** ���ض�ջ����Ԫ�ص�ֵ�������Զ�ջ�����޸ġ�
*/
STACK_TYPE top(StackNode* stack)
{
    assert(!is_empty(stack));
    return stack->value;
}

/*
** destroy_stack
** ���ٶ�ջ
*/
void destroy_stack(StackNode** stackp)
{
    while (!is_empty(*stackp)) {
        pop(stackp);
    }
}
