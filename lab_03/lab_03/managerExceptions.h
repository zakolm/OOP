#pragma once

#include "baseException.h"

class cBaseManagerException: public cBaseException
{
public:
    explicit cBaseManagerException() { }

    explicit cBaseManagerException(const char* message)
        : cBaseException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "manager::(base exception)!" : message.c_str();
    }
};

class cManagerNoTarget: public cBaseManagerException
{
public:
    explicit cManagerNoTarget() { }

    explicit cManagerNoTarget(const char* message)
        : cBaseManagerException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "manager::(No target object)!" : message.c_str();
    }
};
