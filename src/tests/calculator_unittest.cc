#include "../calculator/calculator.h"

#include <gtest/gtest.h>

#include <cmath>
#include <string>

namespace {
const double kTolerance = 1e-7;
class CalculatorTest : public testing::Test {
 protected:
  // CalculatorTest() {
  // }
  rpncalculator::Calculator calculator_;
};
TEST_F(CalculatorTest, AddingTwoNumbers) {
  // Arrange
  std::string expr{"1+2"};
  double expected = 3;
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, AddingTwoNumbersWithSpaces) {
  // Arrange
  std::string expr{"1 + 2"};
  double expected = 3;
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, UnaryMinus) {
  // Arrange
  std::string expr{"+2"};
  double expected = 2;
  // Act
  // Assert
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, MabyUnaryMinuses) {
  // Arrange
  std::string expr{"++++++2"};
  double expected = 2;
  // Act
  // Assert
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, AddingWithUnaryMinus) {
  // Arrange
  std::string expr{"1++2"};
  double expected = 1 + 2;
  // Act
  // Assert
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, NumbersInExponentialNotation) {
  // Arrange
  std::string expr{"3.14e2+.2e2-2e3"};
  // Act
  double expected = 3.14e2 + .2e2 - 2e3;
  // Assert
  EXPECT_NEAR(expected, calculator_.Eval(expr), kTolerance);
}
TEST_F(CalculatorTest, IncorrectNumbersInExponentialNotation) {
  // Arrange
  std::string expr{"3.14e2+.2.e2-2e3"};
  // Act
  // Assert
  EXPECT_THROW(calculator_.Eval(expr), std::exception);
}
TEST_F(CalculatorTest, Expression1) {
  // Arrange
  std::string expr{"-10+1*2"};
  double expected = -10 + 1 * 2;
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression2) {
  // Arrange
  std::string expr{"1.1234567+2.7492649"};
  double expected = 1.1234567 + 2.7492649;
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression3) {
  // Arrange
  std::string expr{"2.7492649/5.7894573"};
  double expected = 2.7492649 / 5.7894573;
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression4) {
  // Arrange
  std::string expr{"2^2^3"};  // ^ is right asociative 2^(2^3) = 2^8 = 256
  double expected = std::pow(2, std::pow(2, 3));
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression5) {
  // Arrange
  std::string expr{"2.7492649mod5.7894573"};
  double expected = std::fmod(2.7492649, 5.7894573);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression6) {
  // Arrange
  std::string expr{"-5.7894573"};
  double expected = -5.7894573;
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression7) {
  // Arrange
  std::string expr{"10mod3"};
  double expected = std::fmod(10, 3);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression8) {
  // Arrange
  std::string expr{"5.7894573--2.7492649"};
  double expected = 5.7894573 - (-2.7492649);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression9) {
  // Arrange
  std::string expr{"5.7894573-(-2.7492649)"};
  double expected = 5.7894573 - (-2.7492649);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression10) {
  // Arrange
  std::string expr{"cos(-2.7492649)"};
  double expected = std::cos(-2.7492649);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression11) {
  // Arrange
  std::string expr{"sin(1)"};
  double expected = std::sin(1);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression12) {
  // Arrange
  std::string expr{"cos(1)"};
  double expected = std::cos(1);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression13) {
  // Arrange
  std::string expr{"sin(-2.7492649)"};
  double expected = std::sin(-2.7492649);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression14) {
  // Arrange
  std::string expr{"tan(5.7894573)"};
  double expected = std::tan(5.7894573);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression15) {
  // Arrange
  std::string expr{"tan(1)"};
  double expected = std::tan(1);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression16) {
  // Arrange
  std::string expr{"acos(1)"};
  double expected = std::acos(1);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression17) {
  // Arrange
  std::string expr{"acos(0.7492649)"};
  double expected = std::acos(0.7492649);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression18) {
  // Arrange
  std::string expr{"asin(0.7492649)"};
  double expected = std::asin(0.7492649);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression19) {
  // Arrange
  std::string expr{"asin(1)"};
  double expected = std::asin(1);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression20) {
  // Arrange
  std::string expr{"atan(1)"};
  double expected = std::atan(1);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression21) {
  // Arrange
  std::string expr{"atan(2.7492649)"};
  double expected = std::atan(2.7492649);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression22) {
  // Arrange
  std::string expr{"sqrt(25)"};
  double expected = std::sqrt(25);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression23) {
  // Arrange
  std::string expr{"sqrt(5.7894573)"};
  double expected = std::sqrt(5.7894573);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression24) {
  // Arrange
  std::string expr{"ln(5.7894573)"};
  double expected = std::log(5.7894573);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression25) {
  // Arrange
  std::string expr{"log(0.7894573)"};
  double expected = std::log10(0.7894573);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression26) {
  // Arrange
  std::string expr{"---3"};
  double expected = -(-(-3));
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression27) {
  // Arrange
  double x = 2;
  calculator_.SetX(x);
  std::string expr{"(1+2)*(3+x)-4"};
  double expected = (1 + 2) * (3 + x) - 4;
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression28) {
  // Arrange
  double x = 2.7463924;
  calculator_.SetX(x);
  std::string expr{"(1.3469823+2.5678764)*(3.8696432+x)-4.7599021"};
  double expected = (1.3469823 + 2.5678764) * (3.8696432 + x) - 4.7599021;
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression29) {
  // Arrange
  std::string expr{"-(68)*(-1-(23*(-(-(-(-876))))))"};
  double expected = -(68) * (-1 - (23 * (-(-(-(-876))))));
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression30) {
  // Arrange
  std::string expr{
      "(82.7891423+2.*5.2030103)/(1.1112223+3.8965472*245-4.9842612)"};
  double expected =
      (82.7891423 + 2. * 5.2030103) / (1.1112223 + 3.8965472 * 245 - 4.9842612);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression31) {
  // Arrange
  std::string expr{"(1+2)*4*cos(10*5-3)+sin(2*8)"};
  double expected = (1 + 2) * 4 * std::cos(10 * 5 - 3) + std::sin(2 * 8);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression32) {
  // Arrange
  std::string expr{"cos(5-3)"};
  double expected = std::cos(5 - 3);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression33) {
  // Arrange
  std::string expr{"4*cos(10*5-3)"};
  double expected = 4 * std::cos(10 * 5 - 3);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression34) {
  // Arrange
  std::string expr{
      "(1.2345632+2)*4.6579362*cos(10.4321891*5-3)+sin(2.2341234*8.1231234)"};
  double expected = (1.2345632 + 2) * 4.6579362 * std::cos(10.4321891 * 5 - 3) +
                    std::sin(2.2341234 * 8.1231234);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression35) {
  // Arrange
  std::string expr{"5^acos(1.0/4.0)/tan(2.0*2.0)"};
  double expected = std::pow(5, std::acos(1.0 / 4.0)) / std::tan(2.0 * 2.0);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression36) {
  // Arrange
  std::string expr{"ln(57/(1+sqrt(67)))"};
  double expected = std::log(57 / (1 + std::sqrt(67)));
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression37) {
  // Arrange
  double x = 2.7463924;
  calculator_.SetX(x);
  std::string expr{"-sqrt(x^log(5-x))+ln(55/(2+x))"};
  double expected =
      -std::sqrt(std::pow(x, std::log10(5 - x))) + std::log(55 / (2 + x));
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression38) {
  // Arrange
  double x = 2.7463924;
  calculator_.SetX(x);
  std::string expr{
      "(1.3+2.45)*4.67*(cos(x*5.678-2.543)+sin(2.456*x))+70.65678^(-10.5457)+5."
      "5787-(-3)"};
  double expected = (1.3 + 2.45) * 4.67 *
                        (std::cos(x * 5.678 - 2.543) + std::sin(2.456 * x)) +
                    std::pow(70.65678, (-10.5457)) + 5.5787 - (-3);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression39) {
  // Arrange
  double x = 2.7463924;
  calculator_.SetX(x);
  std::string expr{"asin(1.3456/x)mod(x)+atan(x)"};
  double expected = std::fmod(std::asin(1.3456 / x), (x)) + std::atan(x);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression40) {
  // Arrange
  std::string expr{"2^(5^2)"};
  double expected = std::pow(2, (std::pow(5, 2)));
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression41) {
  // Arrange
  std::string expr{"(8.123+10.124*5.3456)/((10.3455+3.7465)*2.4667)-(4.4657)"};
  double expected =
      (8.123 + 10.124 * 5.3456) / ((10.3455 + 3.7465) * 2.4667) - (4.4657);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression42) {
  // Arrange
  std::string expr{"ln(22.5674)/log(53.567)/sqrt(100.3453)"};
  double expected =
      std::log(22.5674) / std::log10(53.567) / std::sqrt(100.3453);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression43) {
  // Arrange
  std::string expr{"-sqrt(625)"};
  double expected = -std::sqrt(625);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression44) {
  // Arrange
  std::string expr{"-2^2"};
  double expected = -std::pow(2, 2);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression45) {
  // Arrange
  std::string expr{"-10mod3"};
  double expected = -std::fmod(10, 3);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression46) {
  // Arrange
  std::string expr{"-4*2"};
  double expected = -4 * 2;
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression47) {
  // Arrange
  std::string expr{"-4+2"};
  double expected = -4 + 2;
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression48) {
  // Arrange
  std::string expr{"-4--2"};
  double expected = -4 - (-2);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression49) {
  // Arrange
  std::string expr{"-4-(-2)"};
  double expected = -4 - (-2);
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression50) {
  // Arrange
  std::string expr{"5"};
  double expected = 5;
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, Expression51) {
  // Arrange
  std::string expr{"((5))"};
  double expected = ((5));
  // Act
  double result = calculator_.Eval(expr);
  // Assert
  EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, InvalidExpression1) {
  // Arrange
  std::string expr{"33(22+3)"};
  // Act
  // Assert
  EXPECT_THROW(calculator_.Eval(expr), std::exception);
  // EXPECT_NEAR(expected, result, kTolerance);
}
TEST_F(CalculatorTest, InvalidNumberInExpression) {
  // Arrange
  std::string expr{"11.1245.145-3556"};
  // Act
  // Assert
  EXPECT_THROW(calculator_.Eval(expr), std::exception);
}
TEST_F(CalculatorTest, InvalidExpression3) {
  // Arrange
  std::string expr{"(1+5)7(cos(x*9-2)+sin(2*x))51^(-10)"};
  // Act
  // Assert
  EXPECT_THROW(calculator_.Eval(expr), std::exception);
}
TEST_F(CalculatorTest, InvalidExpression4) {
  // Arrange
  std::string expr{"1*2 3"};
  // Act
  // Assert
  EXPECT_THROW(calculator_.Eval(expr), std::exception);
}
TEST_F(CalculatorTest, InvalidExpression5) {
  // Arrange
  std::string expr{"1*2(3)"};
  // Act
  // Assert
  EXPECT_THROW(calculator_.Eval(expr), std::exception);
}
TEST_F(CalculatorTest, InvalidExpression6) {
    // Arrange
    std::string expr {"(2)3+"};
    // Act
    // Assert
    EXPECT_THROW(calculator_.Eval(expr), std::exception);
}
// TEST_F(CalculatorTest, InvalidExpression7) {
//     // Arrange
//     std::string expr {""};
//     // Act
//     // Assert
//     EXPECT_THROW(calculator_.Eval(expr), std::exception);
// }

// TEST_F(CalculatorTest, Expression) {
//     // Arrange
//     std::string expr {""};
//     double expected = ;
//     // Act
//     double result = calculator_.Eval(expr);
//     // Assert
//     EXPECT_NEAR(expected, result, kTolerance);
// }
}  // namespace