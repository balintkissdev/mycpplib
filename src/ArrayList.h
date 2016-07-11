#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "List.h"

// FIXME: can't hold unique_ptrs
template <typename T>
class ArrayList : public List<T>
{
    public:
        ArrayList();
        ~ArrayList();

        /**
         * Copies
         */
        bool add(const T& element);

        void clear();

        // TODO
        bool contains();

        T get(std::size_t index);

        T operator[](std::size_t index);

        bool isEmpty();

        std::size_t size();

        std::size_t capacity();

    private:
        int last_index_;
        std::size_t capacity_;
        T* dynamic_array_;

        void resize(std::size_t new_size);

        /**
         * For value type
         */
        void erase(T& value);

        /**
         * For pointer type
         */
        void erase(T*& ptr);
};

#endif
