#include "thtest.h"
#include <QDebug>
#include <QThread>

ThTest::ThTest(){
   }
ThTest::~ThTest(){
   }

void ThTest::Func(){

int NowNum = 0;
while(running){

emit sendInt(NowNum++);
QThread::sleep(1);
}
}


