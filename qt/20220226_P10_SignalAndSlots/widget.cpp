#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->t = new Teacher(this);
    this->s = new Student(this);
//    connect(t,&Teacher::hungry,s,&Student::treat);
//    classIsOver();

    //连接带参数的信号
    //指针 -> 地址
    //函数指针 -> 函数地址
//    void (Teacher :: *teacherSignal)(QString) = &Teacher :: hungry;
//    void (Student :: *studentSignal)(QString) = &Student :: treat;

//    connect(t,teacherSignal,s,studentSignal);
//    classIsOver();

//    //点击一个按钮，再触发下课
//    QPushButton *btn = new QPushButton("下课",this);
//    connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);

    //无参版本
    void (Teacher :: *teacherSignal)(void) = &Teacher :: hungry;
    void (Student :: *studentSignal)(void) = &Student :: treat;
    QPushButton *btn = new QPushButton("下课",this);
    connect(t,teacherSignal,s,studentSignal);
    connect(btn,&QPushButton::clicked,t,teacherSignal);

    //断开信号
    //disconnect(btn,&QPushButton::clicked,t,teacherSignal);

    //拓展
    //1.信号可以链接信号
    //2.一个信号可以链接多个槽函数
    //3.多个信号可以链接同一个槽函数
    //4.信号和槽函数的参数必须一一对应
    //5.信号和槽的参数个数：信号参数个数可以多于槽函数参数个数

    [=](){
        btn->setText("abc");
    }();

    //mutable 可以修改按值传递进来的拷贝（注意是能修改拷贝，而不是值本身）。
//    QPushButton * myBtn = new QPushButton (this);
//    QPushButton * myBtn2 = new QPushButton (this);
//    myBtn2->move(100,100);
//    int m = 10;
//    connect(myBtn,&QPushButton::clicked,this,[m] ()mutable { m = 100 + 10; qDebug() << m; });
//    connect(myBtn2,&QPushButton::clicked,this,[=] ()  { qDebug() << m; });

    //lambada表达式，点击按钮，关闭窗口
    QPushButton *btn2 = new QPushButton("关闭",this);
    btn2->move(100,0);
    connect(btn2,&QPushButton::clicked,this,[=](){
        //this->close();
        emit t->hungry();
    });
}
void Widget::classIsOver(){
    emit t->hungry("宫保鸡丁");
}
Widget::~Widget()
{
    delete ui;
}

