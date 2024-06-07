#ifndef RPNCALCULATOR_OPERATOR_FACTORY_H
#define RPNCALCULATOR_OPERATOR_FACTORY_H

#include <functional>
#include <unordered_map>

#include "token.h"

namespace rpncalculator {
using UnaryOperator = std::function<double(double)>;
using BinaryOperator = std::function<double(double, double)>;
/*!

*/
class OperatorFactory {
 public:
  /*!
      \brief Returns a unary operator
      \param type Token type
      \return Function is a similar object that accepts a single number
  */
  static UnaryOperator GetUnaryOperator(Token::Type type);
  /*!
      \brief Returns a binary operator
      \param type Token type
      \return Function is a similar object that accepts two numbers
  */
  static BinaryOperator GetBinaryOperator(Token::Type type);

 private:
  static const std::unordered_map<Token::Type, BinaryOperator> kBinaryOperators;
  static const std::unordered_map<Token::Type, UnaryOperator> kUnaryOperators;
};  // class OperatorFactory
}  // namespace rpncalculator
#endif  // RPNCALCULATOR_OPERATOR_FACTORY_H