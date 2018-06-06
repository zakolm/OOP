#pragma once

#include <vector>

class cPosition
{
public:
    cPosition()
    {
        pos = std::vector<double>(3, 0);
        orientation = std::vector<double>(3, 0);
    }

    std::vector<double> pos;
    std::vector<double> orientation;
};
