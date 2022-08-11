#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

//绘图事件
void Widget::paintEvent(QPaintEvent *){
//    //实例化画家对象 this指定的是绘图设备
//    QPainter painter(this);

//    //设置画笔
//    QPen pen(QColor(255,0,0));
//    //画家使用这个笔
//    pen.setWidth(3);
//    pen.setStyle(Qt::DotLine);
//    painter.setPen(pen);

//    //设置画刷
//    QBrush brush(Qt::green);
//    brush.setStyle(Qt::Dense1Pattern);
//    painter.setBrush(brush);

//    //划线
//    painter.drawLine(QPoint(0,0),QPoint(100,100));

//    //画圆
//    painter.drawEllipse(QPoint(100,100),50,50);

//    //画矩形
//    painter.drawRect(QRect(20,20,50,50));

//    //画文字
//    painter.drawText(QRect(10,200,100,50),"好好学习，天天向上");

    //高级设置
    QPainter painter(this);
//    painter.drawEllipse(QPoint(100,50),50,50);
//    //设置抗锯齿 效率低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200,50),50,50);


//    painter.drawRect(QRect(20,20,50,50));
//    //移动画家
//    painter.translate(100,0);
//    //保存画家状态
//    painter.save();
//    painter.drawRect(QRect(20,20,50,50));
//    painter.restore();
//    painter.drawRect(QRect(20,20,50,50));

    //利用画家画资源图片
    painter.drawPixmap(20,100,QPixmap(":/IMG_1"));
}

Widget::~Widget()
{
    delete ui;
}



