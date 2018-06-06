#pragma once

#include "absLoaderExceptions.h"

class cBaseFileLoaderException: public cAbsLoaderException
{
public:
    explicit cBaseFileLoaderException() { }

    explicit cBaseFileLoaderException(const char* message)
        : cAbsLoaderException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "file loader::(base exception)!" : message.c_str();
    }
};

class cFileInputStrNotOpen: public cBaseFileLoaderException
{
public:
    explicit cFileInputStrNotOpen() { }

    explicit cFileInputStrNotOpen(const char* message)
        : cBaseFileLoaderException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "file loader::(Not open input stream)!" : message.c_str();
    }
};

class cFileOutputStrNotOpen: public cBaseFileLoaderException
{
public:
    explicit cFileOutputStrNotOpen() { }

    explicit cFileOutputStrNotOpen(const char* message)
        : cBaseFileLoaderException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "file loader::(Not open output stream)!" : message.c_str();
    }
};

class cFileStreamNotObjData: public cBaseFileLoaderException
{
public:
    explicit cFileStreamNotObjData() { }

    explicit cFileStreamNotObjData(const char* message)
        : cBaseFileLoaderException(message) { }

    virtual const char* what()
    {
        return message.empty() ? "file loader::(No object data)!" : message.c_str();
    }
};
