//
// Created by Максим on 08.04.2018.
//

#ifndef OOP_LAB_02_ERRORS_H
#define OOP_LAB_02_ERRORS_H

#include <exception>
#include <string.h>

class base_exception : public std::exception
{
public:
    base_exception(std::string filename, std::string classname, int line, const char *time, std::string info)
    {
        err_info = "filename: " + filename + "\nclass name: " + classname + "\nline: " + std::to_string(line)
                   + "\ntime: " + time + "\ninfo: " + info;
    }
    virtual std::string what(void) {return "MyBaseException.\n" + this->err_info;};
protected:
    std::string err_info;
};

class IndexOutOfRangeException : public base_exception
{
public:
    IndexOutOfRangeException(std::string filename, std::string classname, int line, const char *time, std::string info)
    : base_exception(filename, classname, line, time, info) {};
    std::string what(void) {return "Index out of range.\n" + this->err_info;}
};

class IsNotEqualException : public base_exception
{
public:
    IsNotEqualException(std::string filename, std::string classname, int line, const char *time, std::string info)
            : base_exception(filename, classname, line, time, info) {};
    std::string what(void) {return "Matrix is not equal\n" + this->err_info;}
};

class IsEmptyException : public base_exception
{
public:
    IsEmptyException(std::string filename, std::string classname, int line, const char *time, std::string info)
            : base_exception(filename, classname, line, time, info) {};
    std::string what(void) {return "Matrix is empty\n" + this->err_info;}
};

class CannotMultMatrixException : public base_exception
{
public:
    CannotMultMatrixException(std::string filename, std::string classname, int line, const char *time, std::string info)
            : base_exception(filename, classname, line, time, info) {};
    std::string what(void) {return "Cannot mult matrix\n" + this->err_info;}
};

class IsNotSquareException : public base_exception
{
public:
    IsNotSquareException(std::string filename, std::string classname, int line, const char *time, std::string info)
            : base_exception(filename, classname, line, time, info) {};
    std::string what(void) {return "Matrix is not square\n" + this->err_info;}
};

#endif //OOP_LAB_02_ERRORS_H