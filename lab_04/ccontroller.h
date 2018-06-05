#ifndef CCONTROLLER_H
#define CCONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include "cbutton.h"
#include "times.h"

class CController : public QWidget
{
    Q_OBJECT
    enum StateController {
        NO_TARGET,
        BUSY
    };

public:

    explicit CController(QWidget *parent = 0);
    ~CController();

signals:

    void SendTarget(int floor);// { qDebug() << "he;;p"; }

public slots:

    void slotChangeCurrentFloor(int floor, Direction d);
    void slotAchieveFloor(int floor, Direction d);
    
private slots:

    void slotAddNewFloor(int floor);

private:

    bool GetNewTarget(int &newFloor);

    bool         targetArray[FLOOR_NUMBERS];
    CButton*     buttons[FLOOR_NUMBERS];
    int          currentFloor;
    Direction    direct;
    QVBoxLayout* layout;
    StateController state;

};

#endif // CCONTROLLER_H
