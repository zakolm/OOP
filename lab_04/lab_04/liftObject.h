#pragma once

#include "baseObject.h"
#include "timeDefines.h"
#include "myDelegates.h"
#include <assert.h>

namespace app
{
    using namespace System;
    using namespace System::Windows::Forms;

    enum eLiftStates
    {
        eMove,
        eStayClose,
        eStayNotClose,
        eWait
    };

    ref class cLiftObj : cBaseObj
    {
    public:
        cLiftObj();

        event dEventHandler ^evDoorWork;
        event dEventHandlerParam ^evFloorPass;
        event dEventHandlerParam ^evGetNewTarget;
		
		//
		// Обновить информацию на экране
		//
        virtual void update() override;

		//
		// Привязка таймера
		//
        void linkTim(Timer ^_tim);

		//
		// Движение лифта
		//
        void onMove(cBaseObj ^sender, uInputData *data);
        //
		// Ожидание лифта
		//
		void onWait(cBaseObj ^sender);
        //
		// Стоит с закрытыми дверьми
		//
        void onStayClose(cBaseObj ^sender);
        //
		// Стоит с открытыми дверьми
		//
		void Stop(cBaseObj ^sender);//onStayNotClose(cBaseObj ^sender);

        void moveTick(Object ^sender, EventArgs ^e);

    private:
        eLiftStates state;
        eDirection direction;

        Timer ^tLiftMove;
    };
}
