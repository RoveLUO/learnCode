#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    //重写定时器的事件
    void timerEvent(QTimerEvent *);
//    bool eventFilter(QObject*, QEvent *);

    ~Widget();

    int id1;
    int id2;

private:
    Ui::Widget *ui;
};



#endif // WIDGET_H
