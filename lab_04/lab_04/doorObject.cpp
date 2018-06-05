#include "doorObject.h"

namespace app
{
    using namespace System;
    using namespace System::Windows::Forms;

    cDoorObj::cDoorObj()
    {
        state = eClose;
    }

    void cDoorObj::update()
    {
        if (!screen) return;

        Label ^lbl = (Label ^) screen;

        switch (state)
        {
        case eOpen:
            lbl->Text = "open";
            break;
        case eClose:
            lbl->Text = "close";
            break;
        case eOpening:
            lbl->Text = "opening...";
            break;
        case eClosing:
            lbl->Text = "closing...";
            break;
        }
    }

    void cDoorObj::linkTimers(Timer ^_tDoorMove, Timer ^_tDoorOpen)
    {
		tDoorClosing = _tDoorMove;
		tDoorOpening = _tDoorMove;
		tDoorOpen = _tDoorOpen;

		tDoorClosing->Enabled = false;
		tDoorOpening->Enabled = false;
		tDoorOpen->Enabled = false;

		tDoorClosing->Interval = TIME_DOOR;
		tDoorOpening->Interval = TIME_DOOR;
		tDoorOpen->Interval = TIME_OPEN;
        
		tDoorClosing->Tick += gcnew EventHandler(this, &cDoorObj::onOpen);
		tDoorClosing->Tick += gcnew EventHandler(this, &cDoorObj::onClose);
		tDoorOpening->Tick += gcnew EventHandler(this, &cDoorObj::onOpen);
		tDoorOpening->Tick += gcnew EventHandler(this, &cDoorObj::onClose);
		tDoorOpen->Tick += gcnew EventHandler(this, &cDoorObj::onClosing);
    }

    void cDoorObj::onOpen(Object^  sender, EventArgs^  e)
    {
        if (state == eOpening)
        {
            state = eOpen;
            update();

            tDoorOpen->Start();
        }
    }

    void cDoorObj::onClose(Object^  sender, EventArgs^  e)
    {
        if (state == eClosing)
        {
            state = eClose;
            update();

            evRetLift(this);
        }
    }

    void cDoorObj::onOpening(cBaseObj ^sender)
    {
        if (state == eClose)
        {
            state = eOpening;
            update();

            tDoorOpening->Start();
        }
    }

    void cDoorObj::onClosing(Object^  sender, EventArgs^  e)
    {
        if (state == eOpen)
        {
            state = eClosing;
            update();

			tDoorClosing->Start();
        }
    }
}
