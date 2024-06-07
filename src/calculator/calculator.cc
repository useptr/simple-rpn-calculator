#include "calculator.h"

#include <exception>
#include <stack>

#include "operator_factory.h"  // OperatorFactory
#include "tokenizer.h"         // Tokenize
#include "validator.h"         // Valid
namespace rpncalculator {
void Calculator::SetX(double x) { x_ = x; }
std::list<Token> Calculator::ToPostfix(std::list<Token> &infix_expr) {
  using Type = Token::Type;

  std::list<Token> postfix_expr;
  std::stack<Token> stack;
  for (auto token : infix_expr) {
    if (Token::Number(token.type))  // number
      postfix_expr.push_back(token);
    else if (Type::kOpenBracket == token.type)  // (
      stack.push(token);
    else if (Type::kCloseBracket == token.type) {  // )
      while (!stack.empty() && Type::kOpenBracket != stack.top().type) {
        postfix_expr.push_back(stack.top());
        stack.pop();
      }
      if (stack.empty()) // || Type::kOpenBracket != stack.top().type
        throw std::exception();

      stack.pop();  // remove (
    } else {        // operator
      while (!stack.empty() &&
             Token::Priority(stack.top().type) >= Token::Priority(token.type)) {
        if (stack.top().type == token.type &&
            Token::RightAssociative(token.type))
          break;
        postfix_expr.push_back(stack.top());
        stack.pop();
      }
      stack.push(token);
    }
  }

  while (!stack.empty()) {
    postfix_expr.push_back(stack.top());
    stack.pop();
  }

  return postfix_expr;
}

double Calculator::Calculate(std::list<Token> &postfix_expr) {
  using Type = Token::Type;

  std::stack<double> operands;
  for (const auto token : postfix_expr) {
    if (Token::Number(token.type)) {  // number
      if (Type::kX == token.type)
        operands.push(x_);
      else
        operands.push(token.value);
    } else {                                    // operator
      if (Token::BinaryOperator(token.type)) {  // binary
        if (operands.size() < 2) throw std::exception();

        auto operation = OperatorFactory::GetBinaryOperator(token.type);

        double rhs = operands.top();
        operands.pop();
        double lhs = operands.top();
        operands.pop();
        operands.push(operation(lhs, rhs));
      } else {  // unary
        if (operands.size() < 1) throw std::exception();

        auto operation = OperatorFactory::GetUnaryOperator(token.type);

        double num = operands.top();
        operands.pop();
        operands.push(operation(num));
      }
    }
  }

  if (operands.size() != 1) throw std::exception();

  return operands.top();
}

double Calculator::Eval(std::string &expr) {
  auto infix_expr = Tokenize(expr);
    if (!Valid(infix_expr))
        throw std::exception();
  auto postfix_expr = ToPostfix(infix_expr);
  return Calculate(postfix_expr);
}

}  // namespace rpncalculator
