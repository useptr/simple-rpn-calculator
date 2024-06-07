#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <string>

#include "../calculator/calculator.h"
#include "../calculator/credit_calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  static constexpr size_t kExprLen = 255;

 public:
  void addLexem(QString& lex);
  void updateExpr();
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
 private slots:

  void on_pushButton_sqrt_clicked();

  void on_pushButton_power_clicked();

  void on_pushButton_mod_clicked();

  void on_pushButton_open_bracket_clicked();

  void on_pushButton_ac_clicked();

  void on_pushButton_close_bracket_clicked();

  void on_pushButton_ln_clicked();

  void on_pushButton_log_clicked();

  void on_pushButton_sin_clicked();

  void on_pushButton_asin_clicked();

  void on_pushButton_cos_clicked();

  void on_pushButton_acos_clicked();

  void on_pushButton_tan_clicked();

  void on_pushButton_atan_clicked();

  void on_pushButton_x_clicked();

  void on_pushButton_point_clicked();

  void on_pushButton_add_clicked();

  void on_pushButton_sub_clicked();

  void on_pushButton_mul_clicked();

  void on_pushButton_div_clicked();

  void on_pushButton_0_clicked();

  void on_pushButton_1_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_7_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_9_clicked();

  void on_pushButton_equal_clicked();

  void on_pushButton_plot_clicked();

  void on_lineEdit_expr_textEdited(const QString& arg1);

  void on_pushButton_exponent_clicked();
  void on_pushButton_credit_eval_clicked();

 private:
  QString expr;
  Ui::MainWindow* ui;
  rpncalculator::Calculator calculator_;

 private:
  void HideCreditError();
  void ShowReport(rpncalculator::AnnuityReport& report);
  void ShowReport(rpncalculator::DifferentiatedReport& report);
  static constexpr size_t kPlotSize = 101;
  void CalcPlot(double min, double max, QVector<double>& x, QVector<double>& y);
  void Replot(double x_min, double x_max, double y_min, double y_max,
              QVector<double>& x, QVector<double>& y);
};
#endif  // MAINWINDOW_H
