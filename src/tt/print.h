#ifndef _PRINT_H_
#define _PRINT_H_

#include <main.h>
#include <bstrlib.h>

/**
 * @brief print_head - print the header of true table.
 *
 * @param expr - const_bstring, expression evaluated.
 * @param info - const ExprInfo*, useful infomation of expression.
 */
void print_head(const_bstring expr, const ExprInfo* info);


/**
 * @brief print_table - print the whole true table.
 *
 * @param expr - const_bstring, expression evaluated.
 */
void print_table(const_bstring expr);

#endif /* end of include guard: _PRINT_H_ */
