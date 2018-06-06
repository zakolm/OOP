#pragma once

#include "baseException.h"

class cAbsLoaderException: public cBaseException
{
public:
    explicit cAbsLoaderException() { }

    explicit cAbsLoaderException(const char* message)
        : cBaseException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "loader::(base exception)!" : message.c_str();
    }
};
