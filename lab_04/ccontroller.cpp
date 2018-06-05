#include "ccontroller.h"


CController::CController(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout;
    this->setLayout(layout);
    for(int i = 0; i < FLOOR_NUMBERS; i++) {
        buttons[i] = new CButton;
        layout->addWidget(dynamic_cast<QPushButton*>(buttons[i]));
        buttons[i]->setText(QString::number(i));
        buttons[i]->SetNumberFloor(i);
        targetArray[i] = false;
        QObject::connect(buttons[i], SIGNAL(floorRequest(int)), this, SLOT(slotAddNewFloor(int)));
    }

}

CController::~CController()
{
    for(int i = 0; i < FLOOR_NUMBERS; i++) {
        delete buttons[i];
    }
    delete layout;
}

void CController::slotChangeCurrentFloor(int floor, Direction d)
{
    currentFloor = floor;
    direct = d;
}

void CController::slotAchieveFloor(int floor, Direction d)
{
    if(state == BUSY) {
    qDebug() << "Stop on floor" << floor << "-------------";
        currentFloor = floor;
        direct = d;
        targetArray[floor] = false;
        emit buttons[floor]->resetButton();
        if(GetNewTarget(floor)) {
            emit SendTarget(floor);
        }
        else {
            state = NO_TARGET;
        }
    }
}

void CController::slotAddNewFloor(int floor)
{
    state = BUSY;
    targetArray[floor] = true;
    GetNewTarget(floor);
    emit SendTarget(floor);
}

bool CController::GetNewTarget(int &newFloor)
{
    int step = direct == 0 ? -1 : direct;
    for(int i = currentFloor; i < FLOOR_NUMBERS && i >= 0; i += step) {
        if(targetArray[i])  {
            newFloor = i;
            return true;
        }
    }
    step *= -1;
    for(int i = currentFloor; i < FLOOR_NUMBERS && i >= 0; i += step) {
        if(targetArray[i])  {
            newFloor = i;
            return true;
        }
    }
    return false;
}
