#ifndef RPNCALCULATOR_CALCULATOR_H
#define RPNCALCULATOR_CALCULATOR_H

#include <list>
#include <string>

#include "token.h"

namespace rpncalculator {
/*!
    \brief Calculator class for calculating expressions
*/
//TODO make class templates for the concept of numbers
//TODO change the exceptions so that they give out more useful information
class Calculator final {
 public:
  /*!
      \brief Calculates a mathematical expression
      \warning Throws an exception in case of an incorrect mathematical expression. The expression must be in lowercase
      \param expr A string containing a mathematical expression
      \return The result of a calculated mathematical expression
  */
  double Eval(std::string& expr);  // const
  void SetX(double x);

 private:
  double x_{0};  ///< The value of the variable x
  /*!
      \brief Calculates a mathematical expression
      \param postfix_expr List of tokens in the postfix form of the record
      \return The result of a calculated mathematical expression
  */
  double Calculate(std::list<Token>& postfix_expr);
  /*!
      \brief Converts the list of tokens into a postfix record form
      \param infix_expr List of tokens
      \return A list of tokens in the postfix form of the record
  */
  std::list<Token> ToPostfix(std::list<Token>& infix_expr);
};  // class Calculator
}  // namespace rpncalculator
#endif  // RPNCALCULATOR_CALCULATOR_H
