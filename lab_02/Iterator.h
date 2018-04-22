//
// Created by Максим on 19.04.2018.
//

#ifndef OOP_LAB_02_ITERATOR_H
#define OOP_LAB_02_ITERATOR_H

template <class T>
class iterator
{
public:
    iterator (T* ptr_=0) : ptr(ptr_) {}
    T& operator*() {return *ptr;}
    T* operator->() const {return ptr;}
    T* operator++() {return ++ptr;}
    T* operator--() {return --ptr;}
    bool operator<(const iterator<T>& b) {return this->operator->() <= b.operator->() ? true : false;}
private:
    T *ptr;
};

#endif //OOP_LAB_02_ITERATOR_H