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

    return expr;
}

bool is_valid_expression(const_bstring expr)
{
    char last = '!';
    char c;
    size_t idx;
    int bn = 0;

    for (idx = 0; (c = bchar(expr, idx)); ++idx) {
        if (c == '(') {
            bn++;
        } else if (c == ')') {
            bn--;
        }

        if (is_element(c) && (is_operator(last) || last == '(')
                || c == '(' && (is_operator(last) || last == '(')
                || c == ')' && (is_element(last) || last == ')')
                || c == '!' && (is_operator(last))
                || is_operator(c) && (is_element(last))) {
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

struct expr_info* parse(const_bstring expr)
{
    int idx;
    char c;
    struct expr_info* info = NULL;
    info = calloc(1, sizeof(struct expr_info));
    check_mem(info);

    for (idx = 0; (c = bchar(expr, idx)) != '\0'; ++idx) {
        if (is_element(c) && !info->element[c - 'A']) {
            info->element[c - 'A'] = true;
            info->element_num++;
        }
    }

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

void dec2bin(size_t num, int* bin)
{
    int i = 0;

    do {
        bin[i++] = num % 2;
        num /= 2;
    } while (num != 0);
}

int eval(const_bstring expr, const bool* val, const struct expr_info* info)
{
    Stack stk = stack_create();

    bool elem_val[26] = {false};
    bool result = 0;
    size_t idx;
    size_t i;
    char c;

    for (i = info->element_num, idx = 0; i != 0 && idx < 26; ++idx) {
        if (info->element[idx]) {
            elem_val[idx] = val[--i];
        }
    }

    for (idx = 0; (c = bchar(expr, idx)) != '\0'; ++idx) {
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

    stack_destroy(stk);

    return result;
}

void print_head(const_bstring expr, const struct expr_info* info)
{
    int i;

    for (i = 0; i < info->element_num; ++i) {
        if (info->element[i]) {
            printf("%c ", i + 'A');
        }
    }

    printf("%s\n", bdata(expr));
}

void print_body(const_bstring expr, const struct expr_info* info)
{
    int i;
    int total = pow(2, info->element_num);

    for (i = 0; i < total; ++i) {
        for (i = info->element_num - 1; i >= 0; --i) {
            printf("%d ", info->element[i]);
        }

        /*printf("", eval(expr));*/
    }
}

void print_table(const_bstring expr, const struct expr_info* info)
{
    print_head(expr, info);
    /*print_body();*/
}

