#include "../calculator/tokenizer.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

#include "../calculator/token.h"

namespace {
using Type = rpncalculator::Token::Type;

TEST(Tokenizer, TokenX) {
  // Arrange
  std::list<rpncalculator::Token> expected{{Type::kX, 0}};
  std::string expr{"x"};
  // Act
  auto result = rpncalculator::Tokenize(expr);
  // Assert
  EXPECT_THAT(result, ::testing::ElementsAreArray(expected));
}

TEST(Tokenizer, TokenNumber1) {
  // Arrange
  std::list<rpncalculator::Token> expected{{Type::kNumber, 10}};
  std::string expr{"10"};
  // Act
  auto result = rpncalculator::Tokenize(expr);
  // Assert
  EXPECT_THAT(result, ::testing::ElementsAreArray(expected));
}
TEST(Tokenizer, TokenNumber2) {
  // Arrange
  std::list<rpncalculator::Token> expected{{Type::kNumber, 10.23}};
  std::string expr{"10.23"};
  // Act
  auto result = rpncalculator::Tokenize(expr);
  // Assert
  EXPECT_THAT(result, ::testing::ElementsAreArray(expected));
}

TEST(Tokenizer, TokenNumber3) {
  // Arrange
  std::list<rpncalculator::Token> expected{{Type::kNumber, .23}};
  std::string expr{".23"};
  // Act
  auto result = rpncalculator::Tokenize(expr);
  // Assert
  EXPECT_THAT(result, ::testing::ElementsAreArray(expected));
}

TEST(Tokenizer, TokenNumber4) {
  // Arrange
  std::list<rpncalculator::Token> expected{{Type::kNumber, 0.e13}};
  std::string expr{"0.e13"};
  // Act
  auto result = rpncalculator::Tokenize(expr);
  // Assert
  EXPECT_THAT(result, ::testing::ElementsAreArray(expected));
}
TEST(Tokenizer, Expression1) {
  // Arrange
  std::list<rpncalculator::Token> expected{
      {Type::kNumber, 1}, {Type::kAddition, 0}, {Type::kNumber, 2}};
  std::string expr{"1+2"};
  // Act
  auto result = rpncalculator::Tokenize(expr);
  // Assert
  EXPECT_THAT(result, ::testing::ElementsAreArray(expected));
}
}  // namespace