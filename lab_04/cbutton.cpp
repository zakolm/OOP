#include "cbutton.h"


CButton::CButton(QWidget *parent) : QPushButton(parent)
{
    state = RELEASED;
    floorNumber = 0;
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(slotPressed()));
    QObject::connect(this, SIGNAL(resetButton()), this, SLOT(slotReleased()));

}

void CButton::SetNumberFloor(int floor)
{
    floorNumber = floor;
}

CButton::~CButton()
{

}

void CButton::slotPressed()
{
    if(state == RELEASED) {
        //qDebug() << "press" << floorNumber;
        state = PRESSED;
        this->setEnabled(false);
        emit floorRequest(floorNumber);
    }
}

void CButton::slotReleased() {
    if(state == PRESSED) {
        this->setEnabled(true);
        state = RELEASED;
    }
}
