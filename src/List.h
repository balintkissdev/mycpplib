#ifndef LIST_H
#define LIST_H

#include <cstddef>

/**
 * List interface
 */
template <typename T>
class List
{
    public:
        virtual ~List() {};
        virtual bool add(const T& element)      = 0;
        virtual void clear()                    = 0;
        virtual bool contains()                 = 0;
        virtual T get(std::size_t index)        = 0;
        virtual T operator[](std::size_t index) = 0;
        virtual bool isEmpty()                  = 0;
        // Iterator<T> iterator()   = 0;
        //T remove(int index) =0;
        virtual std::size_t size()              = 0;
        virtual std::size_t capacity()          = 0;
};

#endif
