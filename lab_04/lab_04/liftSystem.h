#pragma once

#include "myDelegates.h"
#include "buttonObject.h"
#include "controllerObject.h"
#include "liftObject.h"
#include "doorObject.h"

namespace app
{
	//
	// Лифт
	//
    ref class cLiftSys
    {
    public:
		//
		// Кнопки
		//
        cButtonObj ^b0, ^b1, ^b2, ^b3;
        //
		// Контроллер
		//
		cControllerObj ^c;
        //
		// Лифт
		//
		cLiftObj ^l;
        //
		// Двери
		//
		cDoorObj ^d;

        cLiftSys()
        {
            b0 = gcnew cButtonObj(0);
            b1 = gcnew cButtonObj(1);
            b2 = gcnew cButtonObj(2);
            b3 = gcnew cButtonObj(3);

            c = gcnew cControllerObj(4);
            l = gcnew cLiftObj();
            d = gcnew cDoorObj();
            
            linkButtonController(b0, c);
            linkButtonController(b1, c);
            linkButtonController(b2, c);
            linkButtonController(b3, c);

            linkControllerLift(c, l);
            linkLiftDoor(l, d);
        }

        ~cLiftSys()
        {
            delete b0, b1, b2, b3;
            delete c, l, d;
        }

        void linkButtonController(cButtonObj ^b, cControllerObj ^c)
        {
            b->evPress += gcnew dEventHandlerParam(c, &cControllerObj::onAddNewFloor);
            c->evResetButton += gcnew dEventHandlerParam(b, &cButtonObj::onReleased);
        }

        void linkControllerLift(cControllerObj ^c, cLiftObj ^l)
        {
            c->evMoveLift += gcnew dEventHandlerParam(l, &cLiftObj::onMove);
            c->evStopLift += gcnew dEventHandler(l, &cLiftObj::Stop);//onStayNotClose);
            c->evWaitLift += gcnew dEventHandler(l, &cLiftObj::onWait);

            l->evFloorPass += gcnew dEventHandlerParam(c, &cControllerObj::onFloorPass);
            l->evGetNewTarget += gcnew dEventHandlerParam(c, &cControllerObj::onGetNewTarget);
        }

        void linkLiftDoor(cLiftObj ^l, cDoorObj ^d)
        {
            l->evDoorWork += gcnew dEventHandler(d, &cDoorObj::onOpening);
            d->evRetLift += gcnew dEventHandler(l, &cLiftObj::onStayClose);
        }

    protected:

    private:

    };
}
