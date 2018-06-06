#pragma once

#include "baseException.h"

class cBaseBuilderException: public cBaseException
{
public:
    explicit cBaseBuilderException() { }

    explicit cBaseBuilderException(const char* message)
        : cBaseException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "builder::(base exception)!" : message.c_str();
    }
};

class cBuilderNoObject: public cBaseBuilderException
{
public:
    explicit cBuilderNoObject() { }

    explicit cBuilderNoObject(const char* message)
        : cBaseBuilderException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "builder::(No object to build)!" : message.c_str();
    }
};
