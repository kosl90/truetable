#ifndef _EVAL_H_
#define _EVAL_H_

#include <main.h>
#include <bstrlib.h>

bstring remove_space(bstring);

bool is_valid_expression(const_bstring);

struct expr_info* parse(const_bstring);

bstring infix2suffix(const_bstring);

void dec2bin(size_t, int*);

int eval(const_bstring expr, const bool* val, const struct expr_info* info);

#endif /* end of include guard: _EVAL_H_ */
