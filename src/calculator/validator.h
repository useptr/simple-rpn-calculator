#ifndef RPNCALCULATOR_VALIDATOR_H
#define RPNCALCULATOR_VALIDATOR_H

#include <list>

#include "token.h"

namespace rpncalculator {
    /*!
        \brief checks the expression for correctness
        \param infix_expr list of tokens
        \return true if the list of tokens is a valid mathematical expression
    */
    bool Valid(std::list<Token> &infix_expr) noexcept;
} // rpncalculator
#endif // RPNCALCULATOR_VALIDATOR_H
