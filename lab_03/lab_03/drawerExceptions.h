#pragma once

#include "baseException.h"

class cBaseDrawerException: public cBaseException
{
public:
    explicit cBaseDrawerException() { }

    explicit cBaseDrawerException(const char* message)
        : cBaseException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "drawer::(base exception)!" : message.c_str();
    }
};

class cDrawerNoCamera: public cBaseDrawerException
{
public:
    explicit cDrawerNoCamera() { }

    explicit cDrawerNoCamera(const char* message)
        : cBaseDrawerException(message) {}

    virtual const char* what()
    {
        return message.empty() ? "drawer::(Drawer has not camera)!" : message.c_str();
    }
};
