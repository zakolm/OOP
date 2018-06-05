#ifndef CLIFT_H
#define CLIFT_H

#include <QObject>
#include "times.h"
#include "ccontroller.h"
#include "ccabin.h"

class CLift : public QObject
{
    Q_OBJECT
public:
    explicit CLift(QObject *parent = 0);

    QWidget* GetWidget();

signals:

public slots:

private:
    CController control;
    CCabin      cabina;
};

#endif // CLIFT_H
