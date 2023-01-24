#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QObject>
#include <QDebug>
#include "thtest.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:

    void ToThread(); // 信号

private slots:

    void on_pbStart_clicked();

    void getInt(int);

    void on_intSum_clicked();

private:
    Ui::MainWindow *ui;
    QThread *qThTest;
    ThTest *th1;

};

#endif // MAINWINDOW_H
