#ifndef RPNCALCULATOR_TOKEN_H
#define RPNCALCULATOR_TOKEN_H

#include <list>
#include <string>
#include <unordered_map>

namespace rpncalculator {
constexpr double kTolerance =
    1e-7;  ///< It is used when comparing numbers in tokens with the kNumber type
/*!
    \brief The expression passed to the calculator is converted to tokens
    \details Token class contains the type attributes for the token type (cos, addition) and
the value field for storing a number if the token has the kNumber type
*/
struct Token final {
  /*!
      \brief The set of supported tokens in the calculator
  */
  enum Type {
    kNumber,
    kX,
    kOpenBracket,
    kCloseBracket,
    kUnaryPlus,
    kAddition,
    kUnaryMinus,
    kSubtraction,
    kMultiplication,
    kDivision,
    kPower,
    kModulus,
    kCos,
    kSin,
    kTan,
    kAcos,
    kAsin,
    kAtan,
    kSqrt,
    kLn,
    kLog,
    kNone
  };

  Type type{Type::kNone};  ///< Token type
  double value{0};  ///< Number values for a token with the type kNumber

  // auto operator<=>(const Token&) const = default;
  bool operator==(const Token& other) const;
  /*!
      \details The method returns the token type by the passed string for each type
     its own constant is defined ("cos", "+") \param str String ("cos", "+")
      \return Token type
  */
  static Type TypeFromString(const std::string& str);
  /*!
      \param type Token type
      \return Token Priority
  */
  static int Priority(Type type);
  static bool Function(Type type);
  static bool Number(Type type);
  static bool Operator(Type type);
  /*!
     \brief Determines whether an operator with the specified type is
     the right associative \param Token type \return true if the operator is
     right associative, otherwise false
  */
  static bool RightAssociative(Type type);
  /*!
      \brief Determines whether the operator is binary
      \param type Token type
      \return true if the operator is binary, otherwise false
  */
  static bool BinaryOperator(Type type);

 private:
  static const std::unordered_map<std::string, Type>
      kStringToType;  ///< Stores the token type corresponding to the string, used in the TypeFromString method
  static const std::unordered_map<Type, int>
      kPriorities;  ///< Stores operator priorities
  static std::unordered_map<Type, int> InitPriorities();
};  // struct Token
}  // namespace rpncalculator
#endif  // RPNCALCULATOR_TOKEN_H
