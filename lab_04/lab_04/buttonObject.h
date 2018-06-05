#pragma once

#include "baseObject.h"
#include "myDelegates.h"
#include <assert.h>

namespace app
{
	//
	// ��������� ������: 1)������ 2)������
	//
    enum eButtonStates
    {
		//
		// ��������� ������
		//
        ePress,
		//
		// ��������� ������
		//
        eReleased
    };

	//
	// ������
	//
    ref class cButtonObj : cBaseObj
    {
    public:
		//
		// ����������� ������
		//
        explicit cButtonObj(int _floor);

		//
		// ��������� � ��������� ������
		//
        event dEventHandlerParam ^evPress;
		//
		// ��������� � ��������� ������
        //
		event dEventHandler ^evClick;

		//
		// �������� ������
		//
        virtual void update() override;

		//
		// ������� ������
		//
        void onPress(cBaseObj ^sender);
        //
		// ������� ������
		//
		void onReleased(cBaseObj ^sender, uInputData *data);

		//
		// ������� �������
		//
        void onClick();

    private:
		//
		// ����
		//
        int floor;
        //
		// ��������� ������
		//
		enum eButtonStates state;
    };
}
