#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmath.h>

int currentFunction = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (currentFunction == 0) {
        ui->label_4->setText("Choose your function  ");
    }


    ui->lineEdit->setDisabled(true);
    ui->label_6->setText("");
//    toggleStateButtons(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    currentFunction = 1;
    ui->label_4->setText("You chose y = tg3x - tgx - 4sinx");
    ui->label_6->setText("");
    ui->lineEdit->setDisabled(false);
}


void MainWindow::on_pushButton_2_clicked()
{
    currentFunction = 2;
    ui->label_4->setText("You chose y = 2^(1+x^7) - 2^(1-x^3)");
    ui->label_6->setText("");
    ui->lineEdit->setDisabled(false);
}



void MainWindow::on_pushButton_3_clicked()
{
    QString inputValue = ui->lineEdit->text();
    double inputValueToDouble = inputValue.toDouble();
    double result = 0;

    if (currentFunction == 1) {
            result = tan(3*inputValueToDouble) - tan(inputValueToDouble) *  (4 * sin(inputValueToDouble));

            ui->label_6->setText(QString("The result for function y = tg3x - tgx - 4sinx in point %2 = %3")
                                 .arg(inputValue).arg(result));
    }
    if (currentFunction == 2) {
            result = pow(2, 1 + pow(inputValueToDouble, 7)) - pow(2, 1 - pow(inputValueToDouble, 3));

            ui->label_6->setText(QString("The result for function y = 2^(1+x^7) - 2^(1-x^3) in point %2 = %3")
                                 .arg(inputValue).arg(result));
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->setText("");
    ui->label_6->setText("");
}
