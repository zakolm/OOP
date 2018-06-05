#include "liftObject.h"

namespace app
{
    using namespace System;
    using namespace System::Windows::Forms;

    cLiftObj::cLiftObj()
    {
        state = eWait;
        direction = eNone;
    }

    void cLiftObj::update()
    {
        if (screen)
        {
            Label ^lbl = (Label ^) screen;

            switch (state)
            {
            case eMove:
                lbl->Text = "move";
                break;
            //case eStayClose:
            //    lbl->Text = "stayClose";
            //    break;
            case eStayNotClose:
                lbl->Text = "stop";//"stayNotClose";
                break;
            case eWait:
                lbl->Text = "wait";
                break;
            }
        }
    }

    void cLiftObj::linkTim(Timer ^_tim)
    {
        tLiftMove = _tim;
        tLiftMove->Enabled = false;
        tLiftMove->Interval = TIME_MOVE;

        tLiftMove->Tick += gcnew EventHandler(this, &cLiftObj::moveTick);
    }

    void cLiftObj::onMove(cBaseObj ^sender, uInputData *data)
    {
        if (state != eStayNotClose && !tLiftMove->Enabled)
        {
            state = eMove;
            update();
            direction = data->dir;

            tLiftMove->Start();
        }
    }

    void cLiftObj::onWait(cBaseObj ^sender)
    {
        if (state == eStayClose)
        {
            state = eWait;
            update();
            direction = eNone;
        }
    }

    void cLiftObj::onStayClose(cBaseObj ^sender)
    {
        if (state != eStayNotClose) return;

        state = eStayClose;
        update();

        uInputData newData;
        newData.dir = direction;

        evGetNewTarget(this, &newData);
    }

    void cLiftObj::Stop(cBaseObj ^sender)//onStayNotClose(cBaseObj ^sender)
    {
        if (state == eStayNotClose) return;

		state = eStayClose;//eStayNotClose;
        update();
		//evGetNewTarget(this, &newData);
		//onStayClose();
		state = eStayNotClose;
		update();

        evDoorWork(this);
    }

    void cLiftObj::moveTick(Object ^sender, EventArgs ^e)
    {
        uInputData newData;
        newData.dir = direction;

        evFloorPass(this, &newData);
    }
}
