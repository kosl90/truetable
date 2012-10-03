/*
** 一个堆栈模块的接口
*/
#ifndef _STACK_H_
#define _STACK_H_

#define STACK_TYPE int /* 堆栈所存储的值的类型 */

/*
** 定义一个结构体以存储堆栈元素，其中next字段将指向下一个元素
*/
typedef struct STACKNODE {
    STACK_TYPE value;
    struct STACKNODE* next;
} StackNode;

/*
** is_empty
** 如果堆栈为空，返回TRUE，否则返回FALSE
*/
int is_empty(StackNode* stack);

/*
** push
** 把一个新值压到堆栈中。它的参数是需要被压入的值。
*/
void push(StackNode** stackp, STACK_TYPE value);

/*
** pop
** 从堆栈中弹出一个值，并将其丢弃。
*/
void pop(StackNode** stackp);

/*
** top
** 返回堆栈顶部元素的值，但不对堆栈进行修改。
*/
STACK_TYPE top(StackNode* stack);

/*
** destroy_stack
** 销毁堆栈
*/
void destroy_stack(StackNode** stackp);

#endif
