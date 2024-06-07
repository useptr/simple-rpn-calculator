#include "tokenizer.h"

#include <stdexcept>  // std::logic_error in TokenizeNumber
#include <string>
#include <vector>
#include <cctype> // isspace
namespace rpncalculator {

bool UnaryMinus(Token::Type cur,
                            Token::Type prev)  // prev != number or )
{
  using Type = Token::Type;
  return Type::kSubtraction == cur &&
         (Type::kNone == prev || (Type::kNumber != prev && Type::kX != prev &&
                                  Type::kCloseBracket != prev));
}
bool UnaryPlus(Token::Type cur, Token::Type prev) {
  using Type = Token::Type;
  return Type::kAddition == cur &&
         (Type::kNone == prev || (Type::kNumber != prev && Type::kX != prev &&
                                  Type::kCloseBracket != prev));
}

//TODO switch to c++ 20 expr can be std::string_view
void TokenizeOperator(Token &token, std::string expr,
                      std::string::size_type &pos) {
  // keywords maybe const vector or array?
  const std::string keywords[]{"(",    ")",   "x",    "+",    "-",    "*",
                               "/",    "^",   "mod",  "cos",  "acos", "sin",
                               "asin", "tan", "atan", "sqrt", "ln",   "log"};
  for (auto &keyword : keywords) {
    if (expr.starts_with(keyword)) {
        token.type = Token::TypeFromString(keyword);
        pos += keyword.size();
    }
  }
}
void TokenizeNumber(Token &token, std::string &expr,
                    std::string::size_type &pos) {
  using Type = Token::Type;

  std::string::size_type sz;
  try {
    double number = std::stod(expr, &sz);
      token.type =Type::kNumber;
      token.value = number;
    pos += sz;
  } catch (std::logic_error &e) {
  }
}

std::list<Token> Tokenize(std::string &expr) {
    using Type = Token::Type;
    
  std::list<Token> tokens;
  std::string::size_type pos{0};
    Type prev = Type::kNone;
  while (pos < expr.size()) {
      if (std::isspace(expr[pos])) {
          ++pos;
          continue;
      }
      
    Token token{Type::kNone, 0};
    auto substring = expr.substr(pos);  // TODO impruve copy string
    
      TokenizeOperator(token, substring, pos);
    if (Type::kNone == token.type)
        TokenizeNumber(token, substring, pos);
    if (Type::kNone == token.type)
          throw std::exception();
      
    if (UnaryMinus(token.type, prev)) token.type = Type::kUnaryMinus;
    if (UnaryPlus(token.type, prev)) token.type = Type::kUnaryPlus;
      
    tokens.push_back(token);
    prev = token.type;
  }
  return tokens;
}

}  // namespace rpncalculator
