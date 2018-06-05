#pragma once

namespace app
{
    using namespace System;

	//
	// Базовый абстрактный объект
	//
    ref class cBaseObj abstract
    {
    public:
        cBaseObj() { screen = nullptr; }

		//
		// Обновить информацию на экране
		//
        virtual void update() = 0;

		//
		// Связь с объектами
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
