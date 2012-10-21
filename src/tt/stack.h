#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

#define STACK_TYPE int /* 堆栈所存储的值的类型 */

typedef struct STACKNODE {
    STACK_TYPE value;
    struct STACKNODE* next;
} StackNode;

typedef struct Stack {
    size_t size;
    StackNode* head;
} *Stack;

/**
 * @brief stack_create - create a stack.
 *
 * @return - Stack, return a handler to a new stack, if failed, return NULL.
 */
Stack stack_create();


/**
 * @brief stack_size - return the size of stack.
 *
 * @param stk - Stack, a handler to stack.
 *
 * @return - size_t, return the size of stack.
 */
size_t stack_size(Stack stk);


/**
 * @brief stack_is_empty - judge whether a stack is empty.
 *
 * @param stk - Stack, a handler to stack.
 *
 * @return - bool, return true if stack is empty, otherwise false.
 */
bool stack_is_empty(Stack stk);


/**
 * @brief stack_push - push a element into stack.
 *
 * @param stk - Stack, a handler to stack.
 * @param value - STACK_TYPE, a element to be pushed.
 */
void stack_push(Stack stk, STACK_TYPE value);


/**
 * @brief stack_pop - pop the top element of stack.
 *
 * @param stk - Stack, a handler to stack.
 */
void stack_pop(Stack stk);


/**
 * @brief stack_top - return the top element of stack.
 *
 * @param stk - Stack, a handler to stack.
 *
 * @return - STACK_TYPE, the value of top element.
 */
STACK_TYPE stack_top(Stack stk);


/**
 * @brief stack_destroy - destroy the whole stack.
 *
 * @param stk - Stack, a handler to stack.
 */
void stack_destroy(Stack stk);

#endif
