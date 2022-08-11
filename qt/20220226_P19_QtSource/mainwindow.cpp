#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //添加QT资源 ": + 前缀名 + 文件名"
    ui->actionnew->setIcon(QIcon(":/Snipaste_2022-02-25_18-28-00"));
    ui->actionopen->setIcon(QIcon(":/Snipaste_2022-02-25_18-51-36"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

