#include "controllerObject.h"

namespace app
{
    using namespace System::Windows::Forms;

    cControllerObj::cControllerObj(int _countFloor)
    {
        countFloor = _countFloor;
        state = eFree;
        floors = new bool [countFloor];

        for (int i = 0; i < countFloor; i++)
            floors[i] = false;

        evFree += gcnew dEventHandler(this, &cControllerObj::onFree);
    }

    eDirection cControllerObj::findDirection(eDirection curDir)
    {
        if (floors[curFloor]) return eNone;

        int nu = needUp();
        int nd = needDown();

        eDirection newDir = eNone;

        switch (curDir)
        {
        case eUp:
            if (nu >= 0)
                newDir = eUp;
            else if (nd >= 0)
                newDir = eDown;
            break;
        case eDown:
            if (nd >= 0)
                newDir = eDown;
            else if (nu >= 0)
                newDir = eUp;
            break;
        case eNone:
            if (nu >= 0 && nd < 0)
                newDir = eUp;
            else if (nu < 0 && nd >= 0)
                newDir = eDown;
            else if (nu >= 0 && nd >= 0)
            {
                if (abs(curFloor - nu) > abs(curFloor - nd))
                    newDir = eUp;
                else
                    newDir = eDown;
            }
            break;
        }

        return newDir;
    }

    void cControllerObj::update()
    {
        if (!screen) return;

        Label ^lbl = (Label ^) screen;

        switch (state)
        {
        case eAddNewFloor:
            lbl->Text = String::Format("{0} addNewFloor", curFloor);
            break;
        case eFloorPass:
            lbl->Text = String::Format("{0} floorPass", curFloor);
            break;
        case eGetNewTarget:
            lbl->Text = String::Format("{0} getNewFloor", curFloor);
            break;
        case eFree:
            lbl->Text = String::Format("{0} free", curFloor);
            break;
        }
    }

    void cControllerObj::onAddNewFloor(cBaseObj ^sender, uInputData *data)
    {
        if (state != eFree) return;

        state = eAddNewFloor;
        update();

        floors[data->floor] = true;

        uInputData newData;

        if (data->floor == curFloor)
        {
            floors[data->floor] = false;
            evStopLift(this);

            newData.floor = curFloor;
            evResetButton(this, &newData);
        }
        else if (data->floor > curFloor)
        {
            newData.dir = eUp;
            evMoveLift(this, &newData);
        }
        else
        {
            newData.dir = eDown;
            evMoveLift(this, &newData);
        }

        evFree(this);
    }

    void cControllerObj::onFloorPass(cBaseObj ^sender, uInputData *data)
    {
        if (state != eFree) return;

        state = eFloorPass;
        update();

        updateCurFloor(data->dir);
        uInputData newData;

        if (floors[curFloor])
        {
            floors[curFloor] = false;
            evStopLift(this);

            newData.floor = curFloor;
            evResetButton(this, &newData);
        }
        else
        {
            eDirection newDir = findDirection(data->dir);
            newData.dir = newDir;

            switch (newDir)
            {
            case eNone:
                evWaitLift(this);
                break;
            default:
                evMoveLift(this, &newData);
                break;
            }
        }

        evFree(this);
    }

    void cControllerObj::onGetNewTarget(cBaseObj ^sender, uInputData *data)
    {
        if (state != eFree) return;

        state = eGetNewTarget;
        update();

        uInputData newData;

        eDirection newDir = findDirection(data->dir);
        newData.dir = newDir;

        switch (newDir)
        {
        case eNone:
            evWaitLift(this);
            break;
        default:
            evMoveLift(this, &newData);
            break;
        }

        evFree(this);
    }

    void cControllerObj::onFree(cBaseObj ^sender)
    {
        if (state == eFree) return;

        state = eFree;
        update();
    }

    void cControllerObj::updateCurFloor(eDirection dir)
    {
        switch (dir)
        {
        case eUp:
            curFloor++;
            break;
        case eDown:
            curFloor--;
            break;
        }
    }

    int cControllerObj::needUp()
    {
        int f = -1;

        for (int i = curFloor + 1; i < countFloor && f < 0; i++)
            if (floors[i])
                f = i;

        return f;
    }

    int cControllerObj::needDown()
    {
        int f = -1;

        for (int i = curFloor - 1; i > -1 && f < 0; i--)
            if (floors[i])
                f = i;

        return f;
    }
}
