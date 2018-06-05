#pragma once

namespace app
{
    using namespace System;

	//
	// ������� ����������� ������
	//
    ref class cBaseObj abstract
    {
    public:
        cBaseObj() { screen = nullptr; }

		//
		// �������� ���������� �� ������
		//
        virtual void update() = 0;

		//
		// ����� � ���������
		//
        bool linkTo(Object^ to)
        {
            screen = to;
            update();

            return true;
        }

    protected:
		//
		//
		//
        Object ^screen;
    };
}
