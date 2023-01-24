#ifndef THTEST_H
#define THTEST_H

#include <QObject>


class ThTest : public QObject
{

    Q_OBJECT
public:
    ThTest();
    ~ThTest();
    void Func(void);

    bool running=true;
signals:
void sendInt(int);
};


#endif // THTEST_H
