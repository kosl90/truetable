#include <ctype.h>
#include <rela.h>

bool not(bool e)
{
    return !e;
}


bool and(bool lhs, bool rhs)
{
    return lhs & rhs;
}


bool or(bool lhs, bool rhs)
{
    return lhs | rhs;
}


bool imply(bool lhs, bool rhs)
{
    return or(not(lhs), rhs);
}


bool equal(bool lhs, bool rhs)
{
    return and(imply(lhs, rhs), imply(rhs, lhs));
}


rel_priority priority(const char opr)
{
    switch (opr) {
        case '!':
            return NOT;
        case '^':
            return CONJUNCTION;
        case 'v':
            return DISJUNCTION;
        case '>':
            return IMPLICATION;
        case '#':
            return EQUALITY;
        default:
            return UNKNOWN;
    }
}


bool is_operator(const char opr)
{
    return opr == '^' || opr == 'v'
        || opr == '>' || opr == '#'
        || opr == '!' || opr == '('
        || opr == ')';
}


bool is_element(const char elem)
{
    return isupper(elem);
}
