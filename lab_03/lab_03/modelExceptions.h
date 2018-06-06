#pragma once

#include "baseException.h"

class cBaseModelException: public cBaseException
{
public:
    explicit cBaseModelException() { }

    explicit cBaseModelException(const char* message)
        : cBaseException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "model::(base exception)!" : message.c_str();
    }
};

class cModelNoPoints: public cBaseModelException
{
public:
    explicit cModelNoPoints() { }

    explicit cModelNoPoints(const char* message)
        : cBaseModelException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "model::(No model points)!" : message.c_str();
    }
};

class cModelNoEdges: public cBaseModelException
{
public:
    explicit cModelNoEdges() { }

    explicit cModelNoEdges(const char* message)
        : cBaseModelException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "model::(No model edges)!" : message.c_str();
    }
};
