#include "mainwindow.h"

#include <algorithm>
#include <cctype>  // tolower isspace
#include <cmath>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->label_monthly_payment->hide();
  ui->tableWidget_mounthly_payments->hide();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_lineEdit_expr_textEdited(const QString& arg1) {
  expr = arg1;
}

void MainWindow::on_pushButton_sqrt_clicked() {
  QString lex = "sqrt(";
  addLexem(lex);
}

void MainWindow::on_pushButton_power_clicked() {
  QString lex = "^";
  addLexem(lex);
}

void MainWindow::on_pushButton_mod_clicked() {
  QString lex = "mod";
  addLexem(lex);
}

void MainWindow::on_pushButton_open_bracket_clicked() {
  QString lex = "(";
  addLexem(lex);
}
void MainWindow::on_pushButton_close_bracket_clicked() {
  QString lex = ")";
  addLexem(lex);
}

void MainWindow::on_pushButton_ac_clicked() {
  expr.clear();
  updateExpr();
}

void MainWindow::on_pushButton_ln_clicked() {
  QString lex = "ln(";
  addLexem(lex);
}

void MainWindow::on_pushButton_log_clicked() {
  QString lex = "log(";
  addLexem(lex);
}

void MainWindow::on_pushButton_sin_clicked() {
  QString lex = "sin(";
  addLexem(lex);
}

void MainWindow::on_pushButton_asin_clicked() {
  QString lex = "asin(";
  addLexem(lex);
}

void MainWindow::on_pushButton_cos_clicked() {
  QString lex = "cos(";
  addLexem(lex);
}

void MainWindow::on_pushButton_acos_clicked() {
  QString lex = "acos(";
  addLexem(lex);
}

void MainWindow::on_pushButton_tan_clicked() {
  QString lex = "tan(";
  addLexem(lex);
}

void MainWindow::on_pushButton_atan_clicked() {
  QString lex = "atan(";
  addLexem(lex);
}

void MainWindow::on_pushButton_x_clicked() {
  QString lex = "x";
  addLexem(lex);
}

void MainWindow::on_pushButton_point_clicked() {
  QString lex = ".";
  addLexem(lex);
}

void MainWindow::on_pushButton_add_clicked() {
  QString lex = "+";
  addLexem(lex);
}

void MainWindow::on_pushButton_sub_clicked() {
  QString lex = "-";
  addLexem(lex);
}

void MainWindow::on_pushButton_mul_clicked() {
  QString lex = "*";
  addLexem(lex);
}

void MainWindow::on_pushButton_div_clicked() {
  QString lex = "/";
  addLexem(lex);
}

void MainWindow::on_pushButton_0_clicked() {
  QString lex = "0";
  addLexem(lex);
}

void MainWindow::on_pushButton_1_clicked() {
  QString lex = "1";
  addLexem(lex);
}

void MainWindow::on_pushButton_2_clicked() {
  QString lex = "2";
  addLexem(lex);
}

void MainWindow::on_pushButton_3_clicked() {
  QString lex = "3";
  addLexem(lex);
}

void MainWindow::on_pushButton_4_clicked() {
  QString lex = "4";
  addLexem(lex);
}

void MainWindow::on_pushButton_5_clicked() {
  QString lex = "5";
  addLexem(lex);
}

void MainWindow::on_pushButton_6_clicked() {
  QString lex = "6";
  addLexem(lex);
}

void MainWindow::on_pushButton_7_clicked() {
  QString lex = "7";
  addLexem(lex);
}

void MainWindow::on_pushButton_8_clicked() {
  QString lex = "8";
  addLexem(lex);
}

void MainWindow::on_pushButton_9_clicked() {
  QString lex = "9";
  addLexem(lex);
}

void MainWindow::on_pushButton_exponent_clicked() {
  QString lex = "e";
  addLexem(lex);
}
#include <algorithm>
void MainWindow::on_pushButton_equal_clicked() {
  bool x_is_number = false;
  double x = ui->lineEdit_x->text().toDouble(&x_is_number);
  if (!x_is_number) {
    expr = "X is not a number";
    return;
  }
  QString modifyed = expr.remove(' ');
  modifyed = modifyed.toLower();
  std::string expression = modifyed.toStdString();
  calculator_.SetX(x);
  try {
    double result = calculator_.Eval(expression);
    expr = QString::fromStdString(std::to_string(result));
  } catch (std::exception& e) {
    expr = "Invalid expression";
  }

  updateExpr();
}

void MainWindow::addLexem(QString& lex) {
  bool can_add = expr.length() + lex.length() < ui->lineEdit_expr->maxLength();
  if (!can_add)
    expr = "Max expression len is " +
           QString::number(ui->lineEdit_expr->maxLength());
  else
    expr += lex;
  updateExpr();
}
void MainWindow::updateExpr() { ui->lineEdit_expr->setText(expr); }

void MainWindow::on_pushButton_plot_clicked() {
  bool x_min_is_number = false, x_max_is_number = false;
  double x_min = ui->lineEdit_x_min->text().toDouble(&x_min_is_number);
  double x_max = ui->lineEdit_x_max->text().toDouble(&x_max_is_number);
  if (!x_min_is_number || !x_max_is_number) {
    expr = "X min or x max is not a number";
    return;
  }
  if (x_min > x_max) {
    expr = "X min more than x max";
    return;
  }
  if (abs(x_max) + abs(x_min) < 0.5) {
    expr = "Domain of a function is too short";
    return;
  }
  try {
    QVector<double> x(kPlotSize), y(kPlotSize);
    CalcPlot(x_min, x_max, x, y);

    double y_min = *std::min_element(y.constBegin(), y.constEnd());
    double y_max = *std::max_element(y.constBegin(), y.constEnd());
    if (abs(y_max) - abs(y_min) < 0.0000001) {
      y_min -= 1;
      y_max += 1;
    }
    Replot(x_min, x_max, y_min, y_max, x, y);

  } catch (std::exception& e) {
    expr = "Invalid expression";
  }

  updateExpr();
}
// TODO replace to span
void MainWindow::Replot(double x_min, double x_max, double y_min, double y_max,
                        QVector<double>& x, QVector<double>& y) {
  ui->qcustomplot->addGraph();
  ui->qcustomplot->graph(0)->setData(x, y);
  // give the axes some labels:
  ui->qcustomplot->xAxis->setLabel("x");
  ui->qcustomplot->yAxis->setLabel("y");
  // set axes ranges, so we see all data:
  ui->qcustomplot->xAxis->setRange(x_min, x_max);
  ui->qcustomplot->yAxis->setRange(y_min, y_max);
  ui->qcustomplot->replot();
}

void MainWindow::CalcPlot(double min, double max, QVector<double>& x,
                          QVector<double>& y) {
  double offset = min;
  double step = (abs(min) + abs(max)) / (kPlotSize - 1);
  std::string expression = expr.toStdString();
  for (size_t i = 0; i < kPlotSize; ++i) {
    x[i] = offset;
    calculator_.SetX(offset);
    y[i] = calculator_.Eval(expression);
    offset += step;
  }
}
void MainWindow::HideCreditError() { ui->label_credit_error_msg->setText(""); }
void MainWindow::ShowReport(rpncalculator::AnnuityReport& report) {
  ui->label_monthly_payment->setText(QString::number(report.payment));
  ui->label_overpayment->setText(QString::number(report.overpayment));
  ui->label_total_payment->setText(QString::number(report.total));

  ui->label_monthly_payment->show();
  ui->tableWidget_mounthly_payments->hide();
}
void MainWindow::ShowReport(rpncalculator::DifferentiatedReport& report) {
  ui->label_overpayment->setText(QString::number(report.overpayment));
  ui->label_total_payment->setText(QString::number(report.total));

  ui->tableWidget_mounthly_payments->clear();
  ui->tableWidget_mounthly_payments->setHorizontalHeaderItem(
      0, new QTableWidgetItem("payment"));
  auto rows = report.payments.size();
  ui->tableWidget_mounthly_payments->setRowCount(rows);
  for (size_t i = 0; i < rows; ++i) {
    ui->tableWidget_mounthly_payments->setItem(
        i, 0, new QTableWidgetItem(QString::number(report.payments[i])));
  }

  ui->label_monthly_payment->hide();
  ui->tableWidget_mounthly_payments->show();
}
void MainWindow::on_pushButton_credit_eval_clicked() {
  bool amount_is_number{false}, term_is_number{false},
      interest_rate_is_number{false};
  double amount = ui->lineEdit_amount->text().toDouble(&amount_is_number);
  size_t term = ui->lineEdit_term->text().toULong(&term_is_number);
  size_t interest_rate =
      ui->lineEdit_interest_rate->text().toULong(&interest_rate_is_number);

  if (!amount_is_number || !term_is_number || !interest_rate_is_number) {
    ui->label_credit_error_msg->setText("Invalid input");
    return;
  }

  if (amount <= 0 || term < 1 || interest_rate < 1 || interest_rate > 100) {
    ui->label_credit_error_msg->setText("Invalid input");
    return;
  }
  if ("years" == ui->comboBox_term->currentText()) term *= 12;

  HideCreditError();
  if ("annuity" == ui->comboBox_credit_type->currentText()) {
    rpncalculator::AnnuityReport report(amount, interest_rate, term);
    ShowReport(report);
    return;
  }

  rpncalculator::DifferentiatedReport report(amount, interest_rate, term);
  ShowReport(report);
}
