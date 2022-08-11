#include "smallwidget.h"
#include "ui_smallwidget.h"


SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);
    //QSpinBox移动， QSlider跟着移动。
    connect(ui->spinBox,&QSpinBox::valueChanged,ui->horizontalSlider,&QAbstractSlider::setValue);
    // QSlider跟着移动，QSpinBox移动。
    connect(ui->horizontalSlider,&QAbstractSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);

}

void SmallWidget::setValue(int num){
    ui->spinBox->setValue(num);
}
int SmallWidget::getValue(){
    return ui->spinBox->value();
}

SmallWidget::~SmallWidget()
{
    delete ui;
}
