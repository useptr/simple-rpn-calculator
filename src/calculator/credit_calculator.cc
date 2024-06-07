#include "credit_calculator.h"

#include <cmath>
#include <numeric>

namespace rpncalculator {
AnnuityReport::AnnuityReport(double principal, double annual_rate,
                             size_t months)
    : payment(Payment(principal, annual_rate, months)),
      total(payment * months),
      overpayment(total - principal) {}

double AnnuityReport::Payment(double principal, double annual_rate,
                              size_t months) const {
  const double monthly_rate = annual_rate / 12 / 100;
  return principal * monthly_rate * std::pow(1 + monthly_rate, months) /
         (std::pow(1 + monthly_rate, months) - 1);
}

DifferentiatedReport::DifferentiatedReport(double principal, double annual_rate,
                                           size_t months)
    : payments(Payments(principal, annual_rate, months)),
      total(Total(payments)),
      overpayment(total - principal) {}
std::vector<double> DifferentiatedReport::Payments(double principal,
                                                   double annual_rate,
                                                   size_t months) const {
  const double monthly_rate = annual_rate / 12 / 100;
  const double monthly_principal = principal / months;
  std::vector<double> payments;
  payments.reserve(months);
  for (size_t i = 0; i < months; ++i) {
    double overpayment = (principal - monthly_principal * i) * monthly_rate;
    double total_payment = monthly_principal + overpayment;
    payments.push_back(total_payment);
  }
  return payments;
}
double DifferentiatedReport::Total(const std::vector<double> &payments) const {
  return std::accumulate(payments.begin(), payments.end(), 0.0);
}
}  // namespace rpncalculator