#include "singlewindow1.h"
#include "ui_singlewindow1.h"
#include "iostream"

singlewindow1::singlewindow1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::singlewindow1)
{

    ui->setupUi(this);
   connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));

}

singlewindow1::~singlewindow1()
{
    delete ui;
}

void singlewindow1::on_back_to_main_clicked()
{
    emit pressedmain(1);
}

void singlewindow1::on_pushButton_clicked()
{
    std::cout <<"No";

}


