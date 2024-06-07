#ifndef RPNCALCULATOR_CREDIT_CALCULATOR_H
#define RPNCALCULATOR_CREDIT_CALCULATOR_H
#include <iostream>  // size_t
#include <vector>
namespace rpncalculator {

/*!
    \brief Structure for the annuity payments report
*/
struct AnnuityReport {
  /*!
      \brief Constructor for creating a report on annuity payments
      \param principal Loan amount
      \param annual_rate Annual interest rate
      \param months Number of months
  */
  AnnuityReport(double principal, double annual_rate, size_t months);
  /*!
      \brief Calculates the amount of the monthly annuity payment
      \param principal Loan amount
      \param annual_rate Annual interest rate
      \param months Number of months
      \return The amount of the monthly payment
  */
  double Payment(double principal, double annual_rate, size_t months) const;

 public:
  const double payment;  ///< Monthly annuity payment
  const double total;        ///< Total amount of payments
  const double overpayment;  ///< Overpayment on the loan
};
/*!
 */
struct DifferentiatedReport {
  /*!
      \brief Constructor for creating a report on differentiated payments
      \param principal Loan amount
      \param annual_rate Annual interest rate
      \param months Number of months
  */
  DifferentiatedReport(double principal, double annual_rate, size_t months);
  /*!
      \brief Calculates the amount of monthly differentiated payments
      \param principal Loan amount
      \param annual_rate Annual interest rate
      \param months Number of months
      \return Vector with the size of monthly payments
  */
  std::vector<double> Payments(double principal, double annual_rate,
                               size_t months) const;
  /*!
      \brief Calculates the total amount of payments for differentiated payments
      \param payments Vector of monthly payments
      \return Total amount of payments
  */
  double Total(const std::vector<double> &payments) const;

 public:
  const std::vector<double>
      payments;  ///< Monthly differentiated payments for each month
  const double total;        ///< Total amount of payments
  const double overpayment;  ///< Overpayment on the loan
};
}  // namespace rpncalculator
#endif  // RPNCALCULATOR_CREDIT_CALCULATOR_H