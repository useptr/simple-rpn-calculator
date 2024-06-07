#include "token.h"

#include <cmath>  // fabs in operator ==
namespace rpncalculator {
std::unordered_map<Token::Type, int> Token::InitPriorities() {
  using Type = Token::Type;

  std::unordered_map<Token::Type, int> priorities;
  int priority = 0;
  priorities[Type::kNumber] = priority;
  priorities[Type::kX] = priority;
  priorities[Type::kOpenBracket] = priority;
  priority = 1;
  priorities[Type::kAddition] = priority;
  priorities[Type::kSubtraction] = priority;
  priority = 2;
  priorities[Type::kMultiplication] = priority;
  priorities[Type::kDivision] = priority;
  priorities[Type::kModulus] = priority;
  priority = 3;
  priorities[Type::kUnaryPlus] = priority;
  priorities[Type::kUnaryMinus] = priority;
  priority = 4;
  priorities[Type::kPower] = priority;
  priority = 5;
  priorities[Type::kCos] = priority;
  priorities[Type::kSin] = priority;
  priorities[Type::kTan] = priority;
  priorities[Type::kAcos] = priority;
  priorities[Type::kAsin] = priority;
  priorities[Type::kAtan] = priority;
  priorities[Type::kSqrt] = priority;
  priorities[Type::kLn] = priority;
  priorities[Type::kLog] = priority;

  return priorities;
}
const std::unordered_map<std::string, Token::Type> Token::kStringToType = {
    {"(", Token::Type::kOpenBracket},
    {")", Token::Type::kCloseBracket},
    {"x", Type::kX},
    {"+", Token::Type::kAddition},
    {"-", Type::kSubtraction},
    {"*", Type::kMultiplication},
    {"/", Type::kDivision},
    {"^", Type::kPower},
    {"mod", Type::kModulus},
    {"cos", Type::kCos},
    {"acos", Type::kAcos},
    {"sin", Type::kSin},
    {"asin", Type::kAsin},
    {"tan", Type::kTan},
    {"atan", Type::kAtan},
    {"sqrt", Type::kSqrt},
    {"ln", Type::kLn},
    {"log", Type::kLog}};
const std::unordered_map<Token::Type, int> Token::kPriorities =
    InitPriorities();

bool Token::operator==(const Token& other) const {
  if (Type::kNumber == type)
    return type == other.type &&
           std::fabs(value - other.value) < rpncalculator::kTolerance;
  return type == other.type;
}

Token::Type Token::TypeFromString(const std::string& str) {
  return kStringToType.at(str);
}
int Token::Priority(Type type) { return kPriorities.at(type); }
bool Token::RightAssociative(Type type) {
  using Type = Token::Type;

  return Type::kPower == type || Type::kUnaryMinus == type ||
         Type::kUnaryPlus == type;
}
bool Token::Number(Type type) {
  return Type::kNumber == type || Type::kX == type;
}
// bool Token::Operator(Type type)
// {
//     return Type::kNone != type && !Number(type);
// }
bool Token::BinaryOperator(Type type) {
  return Type::kAddition == type || Type::kSubtraction == type ||
         Type::kMultiplication == type || Type::kDivision == type ||
         Type::kPower == type || Type::kModulus == type;
}
// bool Token::Function(Type type)
// {
//     using Type = Token::Type;
//     return Type::kCos == type || Type::kSin == type || Type::kTan == type ||
//     Type::kAcos == type || Type::kAsin == type || Type::kAtan == type ||
//     Type::kSqrt == type || Type::kLn == type || Type::kLog == type;
// }
}  // namespace rpncalculator
