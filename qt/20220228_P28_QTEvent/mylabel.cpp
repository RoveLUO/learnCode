#include "mylabel.h"
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include "widget.h"

MyLabel::MyLabel(QWidget *parent)
    : QLabel{parent}
{
    setMouseTracking(true);
}

//鼠标进入事件
void MyLabel::enterEvent(QEnterEvent * event){
    //qDebug() << "鼠标进入！";
}

//鼠标离开事件
void MyLabel::leaveEvent(QEvent * event){
    //qDebug() << "鼠标离开！";
}

//鼠标按下
void MyLabel::mousePressEvent(QMouseEvent *ev){
    //if(ev->buttons() & Qt::LeftButton){
        QString str = QString("鼠标按下了 x=%1, y=%2, g_x=%3, g_y=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    //}

}
//鼠标释放
void MyLabel::mouseReleaseEvent(QMouseEvent *ev){
    //if(ev->button() == Qt::LeftButton){
        qDebug() << "鼠标释放！";
    //}
}
//鼠标移动
void MyLabel::mouseMoveEvent(QMouseEvent *ev){
    //if(ev->button() == Qt::LeftButton){
        qDebug() << "鼠标移动！";
    //}
}

//通过event事件分发器拦截鼠标按下事件
bool MyLabel::event(QEvent *e){
    if(e->type() == QEvent::MouseButtonPress){
        QMouseEvent * ev = static_cast<QMouseEvent*>(e);
        QString str = QString("鼠标按下了 x=%1, y=%2, g_x=%3, g_y=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }

    return QLabel::event(e);
}






















