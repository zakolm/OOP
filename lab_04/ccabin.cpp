#include "ccabin.h"

CCabin::CCabin(QObject *parent)
{
    state = FREE;
    currentFloor = 0;
    targetFloor = 0;
    direct = NO_DIRECTION;
    QObject::connect(&door, SIGNAL(DoorIsClosed()), this, SLOT(slotMoving()));
    QObject::connect(&timerMoveFloor, SIGNAL(timeout()), this, SLOT(slotMoving()));
    QObject::connect(this, SIGNAL(FloorAchieved()), this, SLOT(slotFree()));
    QObject::connect(this, SIGNAL(Move()), this, SLOT(slotMoving()));
}

void CCabin::slotMoving()
{
    if(state == MOVING || state == BUSY)  {
        state = MOVING;
        qDebug() << "move, floor" << currentFloor;
        if(currentFloor == targetFloor) {
            emit FloorAchieved();
        }
        else {
            timerMoveFloor.start(TIME_MOVING_FLOOR);
            emit FloorVisited(currentFloor, direct);
            if(currentFloor < targetFloor) {
                direct = UP;
                currentFloor += 1;
            }
            else {
                direct = DOWN;
                currentFloor -= 1;
            }
        }
    }

}

void CCabin::slotFree()
{
    //qDebug() << "slotFree";
    state = FREE;
    timerMoveFloor.stop();
    emit FloorTargetAchieved(currentFloor, direct);
    emit door.OpenDoor();

}

void CCabin::slotBusy(int floor)
{
    //qDebug() << "slotBusy";
    state = BUSY;
    targetFloor = floor;
    if(currentFloor == targetFloor) {
        emit FloorAchieved();
    }
    else {
        if(currentFloor < targetFloor) {
            direct = UP;
        }
        else {
            direct = DOWN;
        }
        emit Move();
    }
}
