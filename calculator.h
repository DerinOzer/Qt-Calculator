#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    void numberPressed();
    void mathButtonPressed();
    void equalButtonPressed();
    void pointButtonPressed();
    void changeNumberSignPressed();
    void clearPressed();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
};

#endif // CALCULATOR_H
