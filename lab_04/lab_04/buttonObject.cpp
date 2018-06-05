#include "buttonObject.h"

namespace app
{
    using namespace System::Windows::Forms;

    cButtonObj::cButtonObj(int _floor)
    {
        floor = _floor;
        state = eReleased;

        evClick += gcnew dEventHandler(this, &cButtonObj::onPress);
    }

    void cButtonObj::update()
    {
        if (!screen) return;

        Button ^btn = (Button ^) screen;

        switch (state)
        {
        case ePress:
            btn->Enabled = false;
            break;
        case eReleased:
            btn->Enabled = true;
            break;
        }
    }

    void cButtonObj::onPress(cBaseObj ^sender)
    {
        if (state != eReleased) return;

        state = ePress;
        update();

        uInputData data;
        data.floor = floor;

        evPress(this, &data);
    }

    void cButtonObj::onReleased(cBaseObj ^sender, uInputData *data)
    {
        if ((floor == data->floor) && (state == ePress))
        {
            state = eReleased;
            update();
        }
    }

    void cButtonObj::onClick()
    {
        if (state == eReleased)
            evClick(this);
    }
}
