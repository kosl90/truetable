#ifndef _RELATION_H_
#define _RELATION_H_

#include <stdbool.h>

typedef enum {
    UNKNOWN, NOT, CONJUNCTION, DISJUNCTION,
    IMPLICATION, EQUALITY
} rel_priority;


/**
 * @brief not - return not element
 *
 * @param e - bool, the truth value of element
 *
 * @return - bool, false if e is true else true
 */
bool not(bool e);

/**
 * @brief and - return the conjunction value of lhs and rhs
 *
 * @param lhs - bool, the truth value of element
 * @param rhs - bool, the truth value of element
 *
 * @return - bool, true only if both lhs and rhs are true else false
 */
bool and(bool lhs, bool rhs);

/**
 * @brief or - return the truth value of disjunction
 *
 * @param lhs - bool, the truth value of element
 * @param rhs - bool, the truth value of element
 *
 * @return - bool, false only if both lhs and rhs are false else true
 */
bool or(bool lhs, bool rhs);

/**
 * @brief imply - return the truth value of implication
 *
 * @param lhs - bool, the truth value of element
 * @param rhs - bool, the truth value of element
 *
 * @return - bool, return false only if lhs is true and rhs is false else true
 */
bool imply(bool lhs, bool rhs);


/**
 * @brief equal - return the truth value of equality
 *
 * @param lhs - bool, the truth value of element
 * @param rhs - bool, the truth value of element
 *
 * @return - bool, true only if both lhs and rhs are true or false else false
 */
bool equal(bool lhs, bool rhs);


/**
 * @brief priority - return the priority of operator
 *
 * @param opr - char, the character standing for corresponding operator
 *
 * @return - rel_priority, the priority of corresponding operator, otherwise UNKNOWN
 */
rel_priority priority(const char opr);

bool is_operator(const char opr);

#endif /* end of include guard: _RELATION_H_ */
