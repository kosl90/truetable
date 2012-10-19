#ifndef _STACK_H_
#define _STACK_H_

#define STACK_TYPE int /* ��ջ���洢��ֵ������ */

typedef struct STACKNODE {
    STACK_TYPE value;
    struct STACKNODE* next;
} StackNode;

typedef struct Stack {
    int size;
    StackNode* head;
} *Stack;

/*
 * stack_create
 * ����һ����ջ���������ʧ���򷵻�NULL
 */
Stack stack_create();

/*
** stack_is_empty
** �����ջΪ�գ�����TRUE�����򷵻�FALSE
*/
int stack_is_empty(Stack stk);

/*
** stack_push
** ��һ����ֵѹ����ջ�С����Ĳ�������Ҫ��ѹ���ֵ��
*/
void stack_push(Stack stk, STACK_TYPE value);

/*
** stack_pop
** �Ӷ�ջ�е���һ��ֵ�������䶪����
*/
void stack_pop(Stack stk);

/*
** stack_top
** ���ض�ջ����Ԫ�ص�ֵ�������Զ�ջ�����޸ġ�
*/
STACK_TYPE stack_top(Stack stk);

/*
** stack_destroy
** ���ٶ�ջ
*/
void stack_destroy(Stack stk);

#endif
