#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringList>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //treeWodget树控件使用
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄介绍");

    QTreeWidgetItem * liItem = new QTreeWidgetItem(QStringList() << "力量");
    QTreeWidgetItem * zhiItem = new QTreeWidgetItem(QStringList() << "智力");
    QTreeWidgetItem * minItem = new QTreeWidgetItem(QStringList() << "敏捷");
    //加载顶层的节点
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(zhiItem);
    ui->treeWidget->addTopLevelItem(minItem);

    //追加子节点
    QStringList heroL1;
    heroL1 << "刚背猪" << "前排坦克";
    QTreeWidgetItem * i1 = new QTreeWidgetItem(heroL1);
    liItem->addChild(i1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

