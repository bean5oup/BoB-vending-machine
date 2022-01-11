#include "widget.h"
#include "ui_widget.h"
#include "qmessagebox.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbReset_clicked()
{
    int total = money;
    int cnt500 = 0, cnt100 = 0, cnt50 = 0, cnt10 = 0;

    while(money >= 500){
        changeMoney(-500);
        cnt500++;
    }
    while(money >= 100){
        changeMoney(-100);
        cnt100++;
    }
    while(money >= 50){
        changeMoney(-50);
        cnt50++;
    }
    while(money){
        changeMoney(-10);
        cnt10++;
    }
    auto msg = QString("total: %1 \n500: %2 \n100: %3 \n50: %4 \n10: %5").arg(total).arg(cnt500).arg(cnt100).arg(cnt50).arg(cnt10);
    QMessageBox::information(this, "Reset", msg);
}

