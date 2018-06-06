#pragma once

#include "baseException.h"

class cBaseFacadeException: public cBaseException
{
public:
    explicit cBaseFacadeException() { }

    explicit cBaseFacadeException(const char* message)
        : cBaseException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "scene::(base exception)!" : message.c_str();
    }
};

class cFacadeNoObjIterator: public cBaseFacadeException
{
public:
    explicit cFacadeNoObjIterator() { }

    explicit cFacadeNoObjIterator(const char* message)
        : cBaseFacadeException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "scene::(Iterator have no object)!" : message.c_str();
    }
};
