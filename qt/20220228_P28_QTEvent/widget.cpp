#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
    id1 = startTimer(1000);

    id2 = startTimer(2000);

    //定时器第二种方式
    QTimer * timer = new QTimer(this);
    //启动定时器
    timer->start(500);
    connect(timer,&QTimer::timeout,[=](){
        //label4 每隔0.5s+1
        static int num = 1;
        ui->label_4->setText(QString::number(num++));
    });

    connect(ui->btn,&QPushButton::clicked,[=](){
        timer->stop();
    });

//    //给label安装事件过滤器
//    //步骤1 安装事件过滤器
//    ui->label->installEventFilter(this);
//    //步骤2 重写eventFilter事件
//    bool eventFilter(QObject * obj, QEvent * e){
//        if(obj == ui->label){
//            if(e->type() == QEvent::MouseButtonPress){
//                QMouseEvent * ev = static_cast<QMouseEvent*>(e);
//                QString str = QString("鼠标按下了 x=%1, y=%2, g_x=%3, g_y=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
//                qDebug() << str;
//            }
//        }

//        return QWidget::eventFilter(obj,e);
//    }
//}


//重写定时器的事件
void Widget::timerEvent(QTimerEvent * Ev){

    if(Ev->timerId() == id1){
        //label2 每隔1s+1
        static int num = 1;
        ui->label_2->setText(QString::number(num++));
    }

    if(Ev->timerId() == id2){
        // //label3 每隔2s+1
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }
}

Widget::~Widget()
{
    delete ui;
}

