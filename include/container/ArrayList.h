#ifndef BKSTL_ARRAY_LIST_H
#define BKSTL_ARRAY_LIST_H

#include <exception>

#include "List.h"

namespace bkstl
{
    // FIXME: can't hold unique_ptr yet
    // TODO: dynamic grow
    /**
     * A dynamic list, with automatically growing array under the hood (not implemented yet)
     */
    template <typename T>
    class ArrayList : public List<T>
    {
        public:
            ArrayList(std::size_t capacity = 1000)
                : last_index_(-1)
                , capacity_(capacity)
                , dynamic_array_(new T[capacity_])
                {};
            ~ArrayList();

            bool add(const T element);
            void clear();
            bool contains(const T& element);    // TODO: not implemented yet
            T get(int index);
            T operator[](int index);
            bool isEmpty();
            std::size_t size();

            /**
             * Query currently allocated capacity
             */
            std::size_t capacity();

        private:
            int last_index_;
            std::size_t capacity_;
            T* dynamic_array_;

            /**
             * Resizing helper
             */
            void resize(std::size_t new_size);

            /**
             * Eraser for value types used in clear()
             */
            void erase(T& value);

            /**
             * Eraser for pointer type used in clear()
             */
            void erase(T*& ptr);
    };

    /*template <typename T>
    inline ArrayList<T>::ArrayList()
    {
        last_index_ = -1;
        capacity_ = 1000;
        dynamic_array_ = new T[capacity_];
    }*/

    template <typename T>
    inline ArrayList<T>::~ArrayList()
    {
        clear();
        delete[] dynamic_array_;
    }

    template <typename T>
    inline bool ArrayList<T>::add(const T element)
    {
        // FIXME: error-prone, dynamic resizing needs testing
        if (capacity_ < last_index_)
        {
            resize(capacity_ + 1000);
        }
        dynamic_array_[++last_index_] = element;
        return true;
    }

    template <typename T>
    inline void ArrayList<T>::clear()
    {
        for (int i = 0; i < last_index_; ++i)
        {
            erase(dynamic_array_[i]);
        }
    }

    template <typename T>
    T ArrayList<T>::get(const int index)
    {
        if (-1 < index && index <= last_index_)
        {
            return dynamic_array_[index];
        }
        else
        {
            throw std::exception(); // TODO
        }
    }

    template <typename T>
    inline T ArrayList<T>::operator[](const int index)
    {
        return get(index);
    }

    template <typename T>
    inline bool ArrayList<T>::isEmpty()
    {
        return -1 < last_index_;
    }

    template <typename T>
    inline std::size_t ArrayList<T>::size()
    {
        return last_index_ + 1;
    }

    template <typename T>
    inline std::size_t ArrayList<T>::capacity()
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

    template <typename T>
    inline void ArrayList<T>::erase(T& value)
    {
        value = 0;
    }

    template <typename T>
    inline void ArrayList<T>::erase(T*& ptr)
    {
        delete ptr;
        ptr = 0;
    }
} // namespace bkstl

#endif  // BKSTL_ARRAY_LIST_H
