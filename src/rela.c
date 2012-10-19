#include <ctype.h>
#include "rela.h"

/**
 * @brief not - return not element
 *
 * @param e - bool, the truth value of element
 *
 * @return - bool, false if e is true else true
 */
bool not(bool e)
{
    return !e;
}


/**
 * @brief and - return the conjunction value of lhs and rhs
 *
 * @param lhs - bool, the truth value of element
 * @param rhs - bool, the truth value of element
 *
 * @return - bool, true only if both lhs and rhs are true else false
 */
bool and(bool lhs, bool rhs)
{
    return lhs & rhs;
}


/**
 * @brief or - return the truth value of disjunction
 *
 * @param lhs - bool, the truth value of element
 * @param rhs - bool, the truth value of element
 *
 * @return - bool, false only if both lhs and rhs are false else true
 */
bool or(bool lhs, bool rhs)
{
    return lhs | rhs;
}


/**
 * @brief imply - return the truth value of implication
 *
 * @param lhs - bool, the truth value of element
 * @param rhs - bool, the truth value of element
 *
 * @return - bool, return false only if lhs is true and rhs is false else true
 */
bool imply(bool lhs, bool rhs)
{
    return or(not(lhs), rhs);
}


/**
 * @brief equal - return the truth value of equality
 *
 * @param lhs - bool, the truth value of element
 * @param rhs - bool, the truth value of element
 *
 * @return - bool, true only if both lhs and rhs are true or false else false
 */
bool equal(bool lhs, bool rhs)
{
    return and(imply(lhs, rhs), imply(rhs, lhs));
}


/**
 * @brief priority - return the priority of operator
 *
 * @param opr - char, the character standing for corresponding operator
 *
 * @return - rel_priority, the priority of corresponding operator, otherwise UNKNOWN
 */
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
