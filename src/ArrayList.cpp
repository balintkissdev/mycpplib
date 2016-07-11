#include "ArrayList.h"

#include <exception>

template <typename T>
ArrayList<T>::ArrayList()
{
    last_index_ = -1;
    capacity_ = 1000;
    dynamic_array_ = new T[capacity_];
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    clear();
    delete[] dynamic_array_;
}

template <typename T>
bool ArrayList<T>::add(const T& element)
{
    dynamic_array_[++last_index_] = element;
}

template <typename T>
void ArrayList<T>::clear()
{
    for (std::size_t i = 0; i < last_index_; ++i)
    {
        erase(dynamic_array_[i]);
    }
}

// TODO
template <typename T>
bool ArrayList<T>::contains()
{
    return true;
}

template <typename T>
T ArrayList<T>::get(std::size_t index)
{
    if (index <= last_index_)
    {
        return dynamic_array_[index];
    }
    else
    {
        throw std::exception();
    }
}

template <typename T>
T ArrayList<T>::operator[](std::size_t index)
{
    return get(index);
}

template <typename T>
bool ArrayList<T>::isEmpty()
{
    return -1 < last_index_;
}

template <typename T>
std::size_t ArrayList<T>::size()
{
    return last_index_ + 1;
}

template <typename T>
std::size_t ArrayList<T>::capacity()
{
    return capacity_;
}

template <typename T>
void ArrayList<T>::resize(std::size_t new_size)
{
    // Reallocate
    capacity_ = new_size;
    T* realloc = new T[capacity_];

    // Copy
    for (std::size_t i = 0; i < new_size; ++i)
    {
        realloc[i] = dynamic_array_[i];
    }
    delete[] dynamic_array_;
    dynamic_array_ = realloc;
}

/**
 * For value type
 */
template <typename T>
void ArrayList<T>::erase(T& value)
{
    value = 0;
}

/**
 * For pointer type
 */
template <typename T>
void ArrayList<T>::erase(T*& ptr)
{
    delete ptr;
    ptr = 0;
}

