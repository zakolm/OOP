#pragma once

#include <Windows.h>
#include "baseObject.h"

namespace app
{
	//
	// Направление движения
	//
    enum eDirection
    {
        eUp,
        eDown,
        eNone
    };

	//
	// 
	//
    union uInputData
    {
        int floor;
        enum eDirection dir;
    };
    //
	//
	//
    delegate void dEventHandler(cBaseObj ^sender);
    //
	//
	//
	delegate void dEventHandlerParam(cBaseObj ^sender, uInputData *data);
}
