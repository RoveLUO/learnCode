#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //栈控件使用
    //设置默认定位到scrollBox
    ui->stackedWidget->setCurrentIndex(0);
    //scrollArea按钮
    connect(ui->btn_ScrollBox,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    //toolBox按钮
    connect(ui->btn_ToolBox,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
    //tabWidget
    connect(ui->btn_TabWidget,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //下拉框
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("拖拉机");
    ui->comboBox->addItem("奥迪");
    //点击按钮，选中拖拉机
    connect(ui->btn_TuoLaJi,&QPushButton::clicked,[=](){
        ui->comboBox->setCurrentIndex(1);
    });

    //利用Label显示图片、显示动图

}

Widget::~Widget()
{
    delete ui;
}

