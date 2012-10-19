#ifndef _EVAL_H_
#define _EVAL_H_

#include "main.h"
#include "bstrlib.h"

struct expr_info* parse(const_bstring);

int eval(const_bstring expr, const bool* val, const struct expr_info* info);

bstring remove_space(bstring);

bstring infix2suffix(const_bstring);

#endif /* end of include guard: _EVAL_H_ */
