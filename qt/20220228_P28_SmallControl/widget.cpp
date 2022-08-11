#include "widget.h"
#include "ui_widget.h"
#include "smallwidget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击获取当前值
    connect(ui->btnGet,&QPushButton::clicked,[=](){
        qDebug() << ui->widget->getValue();
    });

    //点击设置一半
    connect(ui->btnSet,&QPushButton::clicked,[=](){
        ui->widget->setValue(50);
    });
}

Widget::~Widget()
{
    delete ui;
}

