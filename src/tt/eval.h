#ifndef _EVAL_H_
#define _EVAL_H_

#include <stdbool.h>
#include <main.h>
#include <bstrlib.h>


/**
 * @brief remove_space - remove blank characters in expression.
 *
 * @param expr - bstring, the expression whose blank characters will be removed.
 *
 * @return - bstring, return the new expression.
 */
bstring remove_space(bstring epxr);


/**
 * @brief is_valid_expression - judge whether this expression is valid.
 *
 * @param expr - const_bstring, expression to be judged.
 *
 * @return - bool, if expression is valid return true, otherwise, false.
 */
bool is_valid_expression(const_bstring expr);


/**
 * @brief parse - parse expression to get useful infomation.
 *
 * @param epxr - const_bstring, expression to be parsed.
 *
 * @return - ExprInfo*, return the useful infomation.
 */
ExprInfo* parse(const_bstring epxr);


/**
 * @brief infix2suffix - convert infix expression to suffix expression.
 *
 * @param epxr - const_bstring, expression to be converted.
 *
 * @return - bstring, suffix expression.
 */
bstring infix2suffix(const_bstring epxr);


/**
 * @brief dec2bin - convert decimal number to binary number.
 *
 * @param num - size_t, a positive number to be converted.
 * @param bin - bool[], an array to store binary number.
 * @param bit_num - int, the bit number of binary number.
 */
void dec2bin(size_t num, bool* bin, int bits_num);


/**
 * @brief eval - evaluate expression.
 *
 * @param expr - const_bstring, suffix expression to be evaluated.
 * @param val - bool[], the value of each element in expression.
 * @param info - ExprInfo*, the useful infomation of expression.
 *
 * @return - bool, the result of expression.
 */
int eval(const_bstring expr, const bool* val, const ExprInfo* info);

#endif /* end of include guard: _EVAL_H_ */
