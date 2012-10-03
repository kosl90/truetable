/*
** һ����ջģ��Ľӿ�
*/
#ifndef _STACK_H_
#define _STACK_H_

#define STACK_TYPE int /* ��ջ���洢��ֵ������ */

/*
** ����һ���ṹ���Դ洢��ջԪ�أ�����next�ֶν�ָ����һ��Ԫ��
*/
typedef struct STACKNODE {
    STACK_TYPE value;
    struct STACKNODE* next;
} StackNode;

/*
** is_empty
** �����ջΪ�գ�����TRUE�����򷵻�FALSE
*/
int is_empty(StackNode* stack);

/*
** push
** ��һ����ֵѹ����ջ�С����Ĳ�������Ҫ��ѹ���ֵ��
*/
void push(StackNode** stackp, STACK_TYPE value);

/*
** pop
** �Ӷ�ջ�е���һ��ֵ�������䶪����
*/
void pop(StackNode** stackp);

/*
** top
** ���ض�ջ����Ԫ�ص�ֵ�������Զ�ջ�����޸ġ�
*/
STACK_TYPE top(StackNode* stack);

/*
** destroy_stack
** ���ٶ�ջ
*/
void destroy_stack(StackNode** stackp);

#endif
