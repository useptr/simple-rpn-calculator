#include "operator_factory.h"

#include <cmath>

namespace rpncalculator {
const std::unordered_map<Token::Type, UnaryOperator>
    OperatorFactory::kUnaryOperators = {
        {Token::Type::kUnaryMinus, std::negate<double>()},
        {Token::Type::kUnaryPlus, [](double x) { return x; }},
        {Token::Type::kCos, static_cast<double (*)(double)>(&std::cos)},
        {Token::Type::kSin, static_cast<double (*)(double)>(&std::sin)},
        {Token::Type::kTan, static_cast<double (*)(double)>(&std::tan)},
        {Token::Type::kAcos, static_cast<double (*)(double)>(&std::acos)},
        {Token::Type::kAsin, static_cast<double (*)(double)>(&std::asin)},
        {Token::Type::kAtan, static_cast<double (*)(double)>(&std::atan)},
        {Token::Type::kSqrt, static_cast<double (*)(double)>(&std::sqrt)},
        {Token::Type::kLn, static_cast<double (*)(double)>(&std::log)},
        {Token::Type::kLog, static_cast<double (*)(double)>(&std::log10)}};

UnaryOperator OperatorFactory::GetUnaryOperator(Token::Type type) {
  return kUnaryOperators.at(type);
}

const std::unordered_map<Token::Type, BinaryOperator>
    OperatorFactory::kBinaryOperators = {
        {Token::Type::kAddition, [](double a, double b) { return a + b; }},
        {Token::Type::kSubtraction, [](double a, double b) { return a - b; }},
        {Token::Type::kMultiplication,
         [](double a, double b) { return a * b; }},
        {Token::Type::kDivision, [](double a, double b) { return a / b; }},
        {Token::Type::kPower,
         static_cast<double (*)(double, double)>(&std::pow)},
        {Token::Type::kModulus,
         static_cast<double (*)(double, double)>(&std::fmod)}};

BinaryOperator OperatorFactory::GetBinaryOperator(Token::Type type) {
  return kBinaryOperators.at(type);
}
}  // namespace rpncalculator