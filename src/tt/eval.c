#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <main.h>
#include <eval.h>
#include <rela.h>
#include <stack.h>
#include <bstrlib.h>
#include <dbg.h>


static bool not_warp(bool dummy, bool val)
{
    return not(val);
}


typedef bool (*funcp)(bool, bool);


static funcp rela_func[] = {
    NULL,
    equal,
    imply,
    or,
    and,
    not_warp
};


bstring remove_space(bstring expr)
{
    bstring backup = bstrcpy(expr);
    char c;
    size_t idx;

    btrunc(expr, 0);

    for (idx = 0; (c = bchar(backup, idx)) != '\0'; ++idx) {
        if (!isspace(c)) {
            bconchar(expr, c);
        }
    }

    bdestroy(backup);

    return expr;
}


bool is_valid_expression(const_bstring expr)
{
    char last = '!';
    char c;
    size_t idx;
    int bn = 0;  // count '(' and ')', if bn is 0, matched

    if (blength(expr) == 0) {
        return false;
    }

    for (idx = 0; (c = bchar(expr, idx)); ++idx) {
        if (c == '(') {
            bn++;
        } else if (c == ')') {
            bn--;
        }

        if ((is_element(c) && (is_operator(last) || last == '('))
                || (c == '(' && (is_operator(last) || last == '('))
                || (c == ')' && (is_element(last) || last == ')'))
                || (c == '!' && (is_operator(last)))
                || (is_operator(c) && (is_element(last) || last == ')'))) {
            last = c;
        } else {
            return false;
        }
    }

    if (bn != 0) {
        return false;
    }

    return true;
}


ExprInfo* parse(const_bstring expr)
{
    int idx;
    char c;
    ExprInfo* info = NULL;
    info = calloc(1, sizeof(ExprInfo));
    check_mem(info);

    for (idx = 0; (c = bchar(expr, idx)) != '\0'; ++idx) {
        if (is_element(c) && !info->element[c - 'A']) {
            info->element[c - 'A'] = true;
            info->element_num++;
        }

        info->expr_len++;
    }

    info->cond_num = pow(2, info->element_num);

error:
    return info;
}


bstring infix2suffix(const_bstring expr)
{
    bstring suffix = bfromcstr("");
    Stack stk = stack_create();
    char c;
    size_t idx = 0;

    for (idx = 0; (c = bchar(expr, idx)) != '\0'; ++idx) {
        if (is_element(c)) {
            bconchar(suffix, c);
        } else if (c == '('){
            stack_push(stk, c);
        } else if (c == ')') {
            while (stack_top(stk) != '(') {
                bconchar(suffix, stack_top(stk));
                stack_pop(stk);
            }

            stack_pop(stk);
        } else if (is_operator(c)) {
            rel_priority pri = priority(c);

            /*
             * when stack is not empty, and the priority of top element in stack
             * is greater than or equal to the priority of current operator,
             * pop the top element and push it back to suffix expression.
             * **NOTE**:
             * NOT is an unary operator, it differs from other operators, NOT
             * mustn't pop from stack.
             */
            while (!stack_is_empty(stk) && pri != NOT && priority(stack_top(stk)) >= pri) {
                bconchar(suffix, stack_top(stk));
                stack_pop(stk);
            }

            stack_push(stk, c);
        }
    }

    while (!stack_is_empty(stk)) {
        bconchar(suffix, stack_top(stk));
        stack_pop(stk);
    }

    stack_destroy(stk);

    return suffix;
}


void dec2bin(size_t num, bool* bin, int bits_num)
{

    do {
        bin[--bits_num] = (bool)(num % 2);
        num /= 2;
    } while (num != (size_t)0 && bits_num >= 0);
}


int eval(const_bstring suffix_expr, const bool* val, const ExprInfo* info)
{
    Stack stk = stack_create();

    bool elem_val[26] = {false};
    bool result = 0;
    size_t idx;
    size_t i;
    char c;

    for (i = 0, idx = 0; i < info->element_num && idx < 26; ++idx) {
        if (info->element[idx]) {
            elem_val[idx] = val[i++];
        }
    }

    for (idx = 0; (c = bchar(suffix_expr, idx)) != '\0'; ++idx) {
        if (is_element(c)) {
            stack_push(stk, elem_val[c - 'A']);
        } else {
            bool rhs = stack_top(stk);
            stack_pop(stk);
            bool lhs = false;
            rel_priority pri = priority(c);

            if (pri != NOT) {
                lhs = stack_top(stk);
                stack_pop(stk);
            }

            result = rela_func[pri](lhs, rhs);
            stack_push(stk, result);
        }
    }

    result = stack_top(stk);
    stack_destroy(stk);

    return result;
}

