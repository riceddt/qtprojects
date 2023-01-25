#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qThTest = new QThread;
    th1 = new ThTest;
    connect(th1,SIGNAL(sendInt(int)),this,SLOT(getInt(int)));
    connect(this,&MainWindow::ToThread,th1,&ThTest::Func);
    ui->lineEdit_x->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));   //只能输入数字
    ui->lineEdit_y->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));   //只能输入数字
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbStart_clicked()
{
    bool flag = QString::compare(ui->pbStart->text(),"stop");
    qDebug()<<ui->pbStart->text();
    th1->running = flag;
    ui->pbStart->setText(flag?"stop":"start");
    if(flag){
        th1->moveToThread(qThTest);
        qThTest->start();
        emit ToThread();
    }
    else
    {
        ui->lineEdit->setText("0");
    }

}


void MainWindow::getInt(int num){

    ui->lineEdit->setText(QString::number(num));
}

void MainWindow::on_intSum_clicked()
{
    QString qx,qy,qsum;
    qx = ui->lineEdit_x->text();
    int x = qx.toInt();// int转QString
    qy = ui->lineEdit_y->text();
    int y = qy.toInt();
    int sum = x + y;
    qsum = QString::number(sum);//QString转int
    ui->lineEdit_sum->setText(qsum);
}
