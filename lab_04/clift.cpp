#include "clift.h"

CLift::CLift(QObject *parent) : QObject(parent)
{
    QObject::connect(&cabina,  SIGNAL(FloorVisited(int, Direction)),
                     &control, SLOT(slotChangeCurrentFloor(int, Direction)));
    QObject::connect(&cabina,  SIGNAL(FloorTargetAchieved(int, Direction)),
                     &control, SLOT(slotAchieveFloor(int, Direction)));
    QObject::connect(&control, SIGNAL(SendTarget(int)),
                     &cabina,  SLOT(slotBusy(int)));
}

QWidget *CLift::GetWidget()
{
    return &control;
}
