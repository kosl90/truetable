#ifndef _STACK_H_
#define _STACK_H_

#define STACK_TYPE int /* 堆栈所存储的值的类型 */

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
 * 创建一个堆栈，如果创建失败则返回NULL
 */
Stack stack_create();

/*
** stack_is_empty
** 如果堆栈为空，返回TRUE，否则返回FALSE
*/
int stack_is_empty(Stack stk);

/*
** stack_push
** 把一个新值压到堆栈中。它的参数是需要被压入的值。
*/
void stack_push(Stack stk, STACK_TYPE value);

/*
** stack_pop
** 从堆栈中弹出一个值，并将其丢弃。
*/
void stack_pop(Stack stk);

/*
** stack_top
** 返回堆栈顶部元素的值，但不对堆栈进行修改。
*/
STACK_TYPE stack_top(Stack stk);

/*
** stack_destroy
** 销毁堆栈
*/
void stack_destroy(Stack stk);

#endif
