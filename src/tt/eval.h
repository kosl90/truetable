#ifndef _EVAL_H_
#define _EVAL_H_

#include <stdbool.h>
#include <main.h>
#include <bstrlib.h>

bstring remove_space(bstring);

bool is_valid_expression(const_bstring);

ExprInfo* parse(const_bstring);

bstring infix2suffix(const_bstring);

void dec2bin(size_t, bool*, size_t);

int eval(const_bstring expr, const bool* val, const ExprInfo* info);

void print_head(const_bstring, const ExprInfo* info);

void print_table(const_bstring);

#endif /* end of include guard: _EVAL_H_ */
