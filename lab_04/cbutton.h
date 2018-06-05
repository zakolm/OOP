#ifndef CBUTTON_H
#define CBUTTON_H

#include <QPushButton>
#include <QObject>
#include <QDebug>

class CButton : public QPushButton
{
    Q_OBJECT
    enum StateButton {
        PRESSED,
        RELEASED
    };
public:
    explicit CButton(QWidget *parent = 0);
    void SetNumberFloor(int floor);
    virtual ~CButton();

public slots:

    void slotPressed();
    void slotReleased();

signals:

    void resetButton();
    void floorRequest(int floor);

private:

    StateButton state;
    int floorNumber;
};

#endif // CBUTTON_H
