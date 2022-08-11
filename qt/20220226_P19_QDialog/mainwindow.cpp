#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮，弹出一个对话框
    connect(ui->actionnew,&QAction::triggered,[=](){
        //对话框分类：
        //模态对话框（不可以对其它窗口进行操作） 非模态对话框（可以对其它窗口进行操作）
        //模态创建
//        QDialog dlg(this);
//        dlg.resize(300,200);
//        dlg.exec();
//        qDebug() << "打爆你的头！";

        //非模态创建
//        QDialog* dlg2 = new QDialog(this);
//        dlg2->resize(200,100);
//        dlg2->setAttribute(Qt::WA_DeleteOnClose); //55号属性
//        dlg2->show();
//        qDebug() << "打爆你的头！";

        //消息对话框
        //错误对话框
//        QMessageBox::critical(this,"critical","错误");

        //提问对话框
        //参数1：父亲 参数2：标题 参数3：提示内容 参数4：案件类型 参数5：默认关联回车按键
//       if(QMessageBox::Save == QMessageBox::information(this,"information","提问",QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Save)){
//           qDebug() << "Save";
//       }
//       else{
//           qDebug() << "Cancel";
//       }

        //警告对话框
//        QMessageBox::warning(this,"Warning","警告");

        //颜色对话框
//        QColor color = QColorDialog::getColor(QColor(255,0,0));
//        qDebug() << color.red() << color.green() << color.blue();

        //文件对话框
        //参数1：父亲 参数2：标题 参数3：默认打开路径 参数4：过滤文件格式
//          QString str = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\FU Luo\\Desktop\\aa.txt","(*.txt)");
//          qDebug() << str;

        //字体对话框
        bool flag;
        QFont font = QFontDialog::getFont(&flag,QFont("华文彩云",36));
        qDebug() << font.family() << font.pointSize() << font.bold();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

