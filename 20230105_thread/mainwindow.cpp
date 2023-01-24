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
    QString x,y,sum;
    x = ui->lineEdit_x->text();
    y = ui->lineEdit_y->text();
    sum = x+y;
    ui->lineEdit_sum->setText(sum);

}
