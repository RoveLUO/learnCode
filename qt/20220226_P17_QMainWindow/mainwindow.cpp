#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //菜单栏创建 只能一个
    QMenuBar * bar = new QMenuBar();
    //将菜单栏放入窗口
    setMenuBar(bar);
    //创建菜单
    QMenu* fileMenu = bar->addMenu("文件");
    QMenu* editMenu = bar->addMenu("编辑");

    //创建菜单项
    QAction * newAction = fileMenu->addAction("新建");
    //添加分割线
    fileMenu->addSeparator();
    QAction * openAction =fileMenu->addAction("打开");
    fileMenu->addSeparator();
    fileMenu->addAction("保存");
    fileMenu->addSeparator();
    fileMenu->addAction("另存为");

    //工具栏可有多个
    QToolBar* toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolBar);

    //只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //设置浮动
    toolBar->setFloatable(false);
    //设置移动（总开关）
    toolBar->setMovable(false);

    //工具栏中设置内容
    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    //工具栏中添加小控件
    QPushButton * btn = new QPushButton("按钮",this);
    toolBar->addWidget(btn);

    //状态栏 最多一个
    QStatusBar* statusBar = new QStatusBar();
    setStatusBar(statusBar);
    //放标签控件
    QLabel * qLabel1 = new QLabel("提示信息",this);
    statusBar->addWidget(qLabel1);
    QLabel * qLabel2 = new QLabel("右侧提示信息",this);
    statusBar->addPermanentWidget(qLabel2);

    //铆接部件（浮动窗口）
    QDockWidget* dockWidget = new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
    //设置停靠区域，只允许上下
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    //设置中心部件
    QTextEdit* textEdit = new QTextEdit();
    setCentralWidget(textEdit);





}

MainWindow::~MainWindow()
{
    delete ui;
}

