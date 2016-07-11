#include "UniquePtr.h"

template <typename T, typedef D = UniqueDeleter>
UniquePtr<T, D>::~UniquePtr()
{
    delete raw_ptr_;
}

void UniquePtr::release()
{
    raw_ptr_ = 0;
}

void UniquePtr::reset()
{
    delete raw_ptr_;
    raw_ptr_ = 0;
}

void UniquePtr::reset(T* new_ptr)
{
    reset();
    raw_ptr_ = new_ptr;
}

T* UniquePtr::get()
{
    return raw_ptr_;
}

T& UniquePtr::operator*()
{
    return *raw_ptr_;
}

T* UniquePtr::operator->()
{
    return raw_ptr_;
}

// TODO: safe bool idiom
// http://www.artima.com/cppsource/safebool.html
UniquePtr::operator bool() 
{
    return raw_ptr_;
}
