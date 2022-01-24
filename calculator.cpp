#include "calculator.h"
#include "ui_calculator.h"

//Initialization
double calculatorValue = 0.0;
bool divPressed = false;
bool multPressed = false;
bool sumPressed = false;
bool subsPressed = false;
bool percentPressed = false;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    ui->calculatorDisplay->setText(QString::number(calculatorValue));

    connect(ui->button0,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->button1,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->button2,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->button3,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->button4,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->button5,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->button6,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->button7,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->button8,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->button9,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->buttonDivision,SIGNAL(released()),this,SLOT(mathButtonPressed()));
    connect(ui->buttonMultip,SIGNAL(released()),this,SLOT(mathButtonPressed()));
    connect(ui->buttonAddition,SIGNAL(released()),this,SLOT(mathButtonPressed()));
    connect(ui->buttonSubstract,SIGNAL(released()),this,SLOT(mathButtonPressed()));
    connect(ui->buttonPercent,SIGNAL(released()),this,SLOT(mathButtonPressed()));
    connect(ui->buttonEquals,SIGNAL(released()),this,SLOT(equalButtonPressed()));
    connect(ui->buttonPM,SIGNAL(released()),this,SLOT(changeNumberSignPressed()));
    connect(ui->buttonAC,SIGNAL(released()),this,SLOT(clearPressed()));
    connect(ui->buttonPoint,SIGNAL(released()),this,SLOT(pointButtonPressed()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::numberPressed()
{
    QPushButton *button = (QPushButton *)sender();
    QString buttonValue = button -> text();
    QString displayValue = ui->calculatorDisplay->text();
    if(displayValue.toDouble()==0 || displayValue.toDouble()==0.0){
        ui->calculatorDisplay->setText(buttonValue);
    }
    else {
        QString newValue = displayValue + buttonValue ;
        double doubleNewValue = newValue.toDouble();
        ui->calculatorDisplay->setText(QString::number(doubleNewValue,'g', 16));
    }
}

void Calculator::mathButtonPressed()
{
    divPressed = false;
    multPressed = false;
    sumPressed = false;
    subsPressed = false;
    percentPressed = false;
    QString displayValue = ui->calculatorDisplay->text();
    calculatorValue = displayValue.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString buttonValue = button -> text();

    if(QString::compare(buttonValue,"÷",Qt::CaseInsensitive) == 0){
        divPressed = true;
    }
    else if(QString::compare(buttonValue,"x",Qt::CaseInsensitive) == 0){
        multPressed = true;
    }
    else if(QString::compare(buttonValue,"+",Qt::CaseInsensitive) == 0){
        sumPressed = true;
    }
    else if(QString::compare(buttonValue,"-",Qt::CaseInsensitive) == 0){
        subsPressed = true;
    }
    else{
        percentPressed = true;
    }
    ui->calculatorDisplay->setText("");

}

void Calculator::equalButtonPressed()
{
    double result = 0;
    QString displayValue = ui->calculatorDisplay->text();
    double doubleDisplayValue = displayValue.toDouble();
    if(divPressed || multPressed || sumPressed || subsPressed || percentPressed){
        if(divPressed)
            result = calculatorValue / doubleDisplayValue;
        else if(multPressed)
            result = calculatorValue * doubleDisplayValue;
        else if(sumPressed)
            result = calculatorValue + doubleDisplayValue;
        else if(subsPressed)
            result = calculatorValue - doubleDisplayValue;
        else
            result = (calculatorValue * doubleDisplayValue)/100;
    }
    ui->calculatorDisplay->setText(QString::number(result));
}

void Calculator::pointButtonPressed()
{
    ui->calculatorDisplay->setText(ui->calculatorDisplay->text()+".");
}

void Calculator::changeNumberSignPressed()
{
    QString displayValue = ui->calculatorDisplay->text();
    QRegularExpression reg("[-]?[0-9.]*");
    if (reg.match(displayValue).hasMatch()){
        double doubleDisplayValue = displayValue.toDouble();
        double displaySign = -1*doubleDisplayValue;
        ui->calculatorDisplay->setText(QString::number(displaySign));
    }
}

void Calculator::clearPressed()
{
    calculatorValue = 0;
    ui->calculatorDisplay->setText(QString::number(calculatorValue));
}


void Calculator::on_actionExit_triggered()
{
    QApplication::quit();
}


void Calculator::on_actionAbout_triggered()
{
    QString aboutText;
    aboutText = "Creator of this app : Derin OZER\n";
    aboutText += "Date : 24/01/2022\n";
    QMessageBox::about(this,"About qtNotepad",aboutText);
}

