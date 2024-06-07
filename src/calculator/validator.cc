#include <vector>

#include "validator.h"

namespace rpncalculator {

int GetAdgencyTableIndex(Token::Type type) noexcept {
    using Type = Token::Type;
    if (Token::Number(type))
        return 0;
    if (Token::BinaryOperator(type))
        return 1;
    if (Type::kOpenBracket == type)
        return 3;
    if (Type::kCloseBracket == type)
        return 4;
    return 2; // UnaryOperator
}

bool Valid(std::list<Token> &infix_expr) noexcept {
    if (infix_expr.size() == 1 && Token::Type::kNumber == infix_expr.back().type)
        return true;
    if (infix_expr.size() < 2)
        return false;
    /*
        - current token   | number | binary operator | unary operator | ( | ) |
        0 number          |    0   |        1        |        0       | 0 | 1 |
        1 binary operator |    1   |        0        |        1       | 1 | 0 |
        2 unary operator  |    1   |        0        |        1       | 1 | 0 |
        3 (               |    1   |        0        |        1       | 1 | 0 |
        4 )               |    0   |        1        |        0       | 0 | 1 |
    */
    const std::vector<std::vector<bool>> adjacency_table = {
        { false, true,  false, false, true },
        { true,  false, true,  true,  false},
        { true,  false, true,  true,  false},
        { true,  false, true,  true,  false},
        { false, true,  false, false, true }
    };
    
    auto it = infix_expr.begin();
    Token::Type prev = (*it).type; // (*it++).type;
    ++it;
    for (; it != infix_expr.end(); ++it) {
        Token::Type current = (*it).type;
        if (!adjacency_table[GetAdgencyTableIndex(prev)][GetAdgencyTableIndex(current)])
            return false;
        prev = current;
    }
    return true;
}
} // namespace rpncalculator
