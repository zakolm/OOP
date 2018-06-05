#pragma once

#include "baseObject.h"
#include "timeDefines.h"
#include "myDelegates.h"
#include <assert.h>

namespace app
{
    using namespace System;
    using namespace System::Windows::Forms;

    enum eDoorStates
    {
        eOpen,
        eClose,
        eOpening,
        eClosing
    };

    ref class cDoorObj : cBaseObj
    {
    public:
        cDoorObj();

		//
		// Привязка таймеров
		//
        void linkTimers(Timer ^_tDoorMove, Timer ^_tDoorOpen);

        event dEventHandler ^evRetLift;

        virtual void update() override;

        void onOpen(Object^  sender, EventArgs^  e);
        void onClose(Object^  sender, EventArgs^  e);
        void onOpening(cBaseObj ^sender);
        void onClosing(Object^  sender, EventArgs^  e);

    private:
        enum eDoorStates state;
        Timer ^tDoorOpen;
		Timer ^tDoorClosing;
		Timer ^tDoorOpening;
    };
}
