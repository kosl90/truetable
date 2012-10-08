#ifndef _EVAL_H_
#define _EVAL_H_

#include "main.h"
#include "bstrlib.h"

int parse(const bstring);

int** eval(const bstring expr, const struct expr_info info);

#endif /* end of include guard: _EVAL_H_ */
