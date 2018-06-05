#pragma once

#include "baseObject.h"
#include "myDelegates.h"
#include <assert.h>

#include <math.h>

namespace app
{
    using namespace System;

    enum eControllerStates
    {
        eAddNewFloor,
        eFloorPass,
        eGetNewTarget,
        eFree
    };

    ref class cControllerObj : cBaseObj
    {
    public:
        explicit cControllerObj(int _countFloor);

        eDirection findDirection(eDirection curDir);
        
        virtual void update() override;
        
        event dEventHandler ^evFree;
        event dEventHandlerParam ^evMoveLift;
        event dEventHandler ^evStopLift;
        event dEventHandlerParam ^evResetButton;
        event dEventHandler ^evWaitLift;

        void onAddNewFloor(cBaseObj ^sender, uInputData *data);
        void onFloorPass(cBaseObj ^sender, uInputData *data);
        void onGetNewTarget(cBaseObj ^sender, uInputData *data);
        void onFree(cBaseObj ^sender);
        
    protected:
        void updateCurFloor(eDirection dir);
        int needUp();
        int needDown();

    private:
        int curFloor;
        int countFloor;
        bool *floors;
        eControllerStates state;
    };
}
