#ifndef RPNCALCULATOR_TOKENIZER_H
#define RPNCALCULATOR_TOKENIZER_H

#include <list>
#include <string>

#include "token.h"

namespace rpncalculator {
/*!
    \brief Converts a string containing a mathematical expression into a list
   tokens \warning throws an exception in case of an incorrect mathematical
expression \param expr A string containing a mathematical expression \return List
   tokens
*/
std::list<Token> Tokenize(std::string &expr);
}  // namespace rpncalculator
#endif  // RPNCALCULATOR_TOKENIZER_H