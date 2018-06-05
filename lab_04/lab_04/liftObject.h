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
		// �������� ���������� �� ������
		//
        virtual void update() override;

		//
		// �������� �������
		//
        void linkTim(Timer ^_tim);

		//
		// �������� �����
		//
        void onMove(cBaseObj ^sender, uInputData *data);
        //
		// �������� �����
		//
		void onWait(cBaseObj ^sender);
        //
		// ����� � ��������� �������
		//
        void onStayClose(cBaseObj ^sender);
        //
		// ����� � ��������� �������
		//
		void Stop(cBaseObj ^sender);//onStayNotClose(cBaseObj ^sender);

        void moveTick(Object ^sender, EventArgs ^e);

    private:
        eLiftStates state;
        eDirection direction;

        Timer ^tLiftMove;
    };
}
