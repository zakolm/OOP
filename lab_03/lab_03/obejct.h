#pragma once

#include <string>

class cObject
{
public:
    cObject(std::string _name)
        : objName(_name)
    { }

    virtual ~cObject() { };

    virtual bool visible() = 0;
    virtual bool isComposite() = 0;
	virtual void Run() = 0;

    std::string getName() { return objName; }

protected:
    std::string objName;
};
