#pragma once

#include "baseObject.h"
#include "myDelegates.h"
#include <assert.h>

namespace app
{
	//
	// Состояния кнопки: 1)нажата 2)отжата
	//
    enum eButtonStates
    {
		//
		// Состояние нажата
		//
        ePress,
		//
		// Состояние отжата
		//
        eReleased
    };

	//
	// Кнопка
	//
    ref class cButtonObj : cBaseObj
    {
    public:
		//
		// Конструктор кнопки
		//
        explicit cButtonObj(int _floor);

		//
		// Перевести в состояние отжата
		//
        event dEventHandlerParam ^evPress;
		//
		// Перевести в состояние нажата
        //
		event dEventHandler ^evClick;

		//
		// Обновить данные
		//
        virtual void update() override;

		//
		// Нажатие кнопки
		//
        void onPress(cBaseObj ^sender);
        //
		// Отжатие кнопки
		//
		void onReleased(cBaseObj ^sender, uInputData *data);

		//
		// События нажатия
		//
        void onClick();

    private:
		//
		// Этаж
		//
        int floor;
        //
		// Состояние кнопки
		//
		enum eButtonStates state;
    };
}
