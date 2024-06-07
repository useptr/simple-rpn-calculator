#include "../calculator/credit_calculator.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

namespace {
constexpr double kTolerance = 1e-1;
TEST(CreditCalculator, Annuity1) {
  // Arrange
  double principal{10'000}, annual_rate{10};
  size_t months{10};
  double expected_payment{1'046.40}, expected_total{10'464},
      expected_overpayment{464.05};
  // Act
  rpncalculator::AnnuityReport report(principal, annual_rate, months);
  // Assert
  EXPECT_NEAR(expected_payment, report.payment, kTolerance);
  EXPECT_NEAR(expected_total, report.total, kTolerance);
  EXPECT_NEAR(expected_overpayment, report.overpayment, kTolerance);
}
TEST(CreditCalculator, Annuity2) {
  // Arrange
  double principal{200'000}, annual_rate{16};
  size_t months{12};
  double expected_payment{18'146.17}, expected_total{217'754.04},
      expected_overpayment{17'754.04};
  // Act
  rpncalculator::AnnuityReport report(principal, annual_rate, months);
  // Assert
  EXPECT_NEAR(expected_payment, report.payment, kTolerance);
  EXPECT_NEAR(expected_total, report.total, kTolerance);
  EXPECT_NEAR(expected_overpayment, report.overpayment, kTolerance);
}
TEST(CreditCalculator, Differentiated1) {
  // https://calcus.ru/kreditnyj-kalkulyator?input=eyJjdXJyZW5jeSI6IlJVQiIsInR5cGUiOiIyIiwiY2FsY190eXBlIjoiMSIsImNyZWRpdF9zdW0iOiIyMDAwMDAiLCJwZXJpb2QiOiIzIiwicGVyaW9kX3R5cGUiOiJNIiwicGVyY2VudCI6IjE2IiwicGF5bWVudF90eXBlIjoiMiJ9
  // Arrange
  double principal{200'000}, annual_rate{16};
  size_t months{3};
  const std::vector<double> expected_payments{69'333.33, 68'444.44, 67'555.56};
  double expected_total{205'333.33}, expected_overpayment{5'333.33};
  // Act
  rpncalculator::DifferentiatedReport report(principal, annual_rate, months);
  // Assert
  EXPECT_THAT(
      expected_payments,
      ::testing::Pointwise(::testing::DoubleNear(kTolerance), report.payments));
  EXPECT_NEAR(expected_total, report.total, kTolerance);
  EXPECT_NEAR(expected_overpayment, report.overpayment, kTolerance);
}
}  // namespace