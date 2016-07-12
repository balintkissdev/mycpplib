#ifndef BKSTL_LIST_H
#define BKSTL_LIST_H

#include <cstddef>

namespace bkstl
{
    /**
     * List interface
     */
    template <typename T>
    class List
    {
        public:
            virtual ~List() {};

            /**
             * Insert object to list.
             */
            virtual bool add(const T element)      = 0;

            /**
             * Remove all elements from list.
             */
            virtual void clear()                    = 0;

            /**
             * Check if list contains a specific element.
             */
            // TODO: virtual bool contains(const T& element) = 0;

            /**
             * Access element at specified index.
             */
            virtual T get(const int index)                = 0;

            /**
             * Array subscript operator overload.
             */
            virtual T operator[](const int index)         = 0;

            /**
             * Check if list is empty
             */
            virtual bool isEmpty()                  = 0;

            /**
             * Return an iterator
             */
            // TODO: Iterator<T> iterator()         = 0;
            
            /**
             * Remove element at specified index
             */
            // TODO: T remove(int index)            = 0;
            
            /**
             * Query number of stored elements
             */
            virtual std::size_t size()              = 0;
    };
} // namespace bkstl

#endif  // BKSTL_LIST_H
