#ifndef BKSTL_ITERATOR_H
#define BKSTL_ITERATOR_H

#include <../container/List.h>

namespace bkstl
{
    template <typename T>
    class Iterator
    {
        public:
            Iterator(const List<T>& list) : index_(0), list_(list) {};
            ~Iterator() {};
            T first();
            T next();
            bool hasNext() const;
            T get();

        private:
            int index_;
            const List<T>& list_;
    };

    template <typename T>
    inline T Iterator<T>::first()
    {
        index_ = 0;
        return get();
    }

    template <typename T>
    inline T Iterator<T>::next()
    {
        ++index_;
        get();
    }

    template <typename T>
    inline bool Iterator<T>::hasNext() const
    {
        return index_ < list_.size();
    }

    template <typename T>
    inline T Iterator<T>::get()
    {
        if (!hasNext())
        {
            throw std::exception();     // TODO
        }
        return list_[index_];
    }
} // namespace bkstl

#endif  // BKSTL_ITERATOR_H
