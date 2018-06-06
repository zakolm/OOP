#pragma once

#include <exception>
#include <string>

class cBaseException : public std::exception
{
public:
    explicit cBaseException() { }

    explicit cBaseException(const char* message)
        : message(message) { }

    virtual const char* what()
    {
        return message.c_str();
    }
protected:

    std::string message;
};
